#include "totp.h"
#include "common.h"
// --- Helper Functions ---

// Performs a circular left shift on a 32-bit integer.
uint32_t rotate_left(uint32_t value, size_t count) {
    return (value << count) | (value >> (32 - count));
}

// Converts a 32-bit integer from host byte order to big-endian.
// On little-endian systems (most common), this will swap the byte order.
// On big-endian systems, this will do nothing.
uint32_t to_big_endian(uint32_t value) {
    uint8_t bytes[4];
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

/*
Takes in a base32 encoded string and returns its corresponding ASCII string (RFC 4648)
 */
std::string base32_to_ascii(const std::string& base32_input) {
    // The static constexpr lookup table is created only once and is highly efficient.
    static constexpr int DECODE_TABLE[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, 26, 27, 28, 29, 30, 31, -1, -1, -1, -1, -1, -1, -1, -1, // '2'-'7'
        -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, // 'A'-'O'
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, // 'P'-'Z'
        -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, // 'a'-'o'
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1  // 'p'-'z'
    };

    std::vector<uint8_t> decoded_bytes;
    decoded_bytes.reserve(base32_input.length() * 5 / 8);

    int buffer = 0;
    int bits_in_buffer = 0;

    for (char c : base32_input) {
        if (c == '=') { // Stop at padding
            break;
        }

        int char_value = -1;
        if (c >= 0) {
            char_value = DECODE_TABLE[(int)c];
        }
        
        if (char_value == -1) {
            throw std::runtime_error("Invalid character in Base32 string.");
        }

       
        buffer = (buffer << 5) | char_value;
        bits_in_buffer += 5;

        // If the buffer has at least 8 bits, extract a full byte
        if (bits_in_buffer >= 8) {
            decoded_bytes.push_back(static_cast<uint8_t>(buffer >> (bits_in_buffer - 8)));
            bits_in_buffer -= 8;
        }
    }

    return std::string(decoded_bytes.begin(), decoded_bytes.end());
}
// --- Part 1: SHA-1 Implementation ---

/**
 * @brief Computes the SHA-1 hash of a given message.
 * @param message The input message as a vector of bytes.
 * @return A 20-byte vector representing the SHA-1 digest.
 */
std::vector<uint8_t> sha1(const std::vector<uint8_t>& message) {
    // 1. Initialize variables
    uint32_t h[] = {
        0x67452301,
        0xEFCDAB89,
        0x98BADCFE,
        0x10325476,
        0xC3D2E1F0
    };

    // 2. Pre-processing (Padding)
    std::vector<uint8_t> padded_message = message;
    uint64_t original_len_bits = message.size() * 8;

    // Append the bit '1' (0x80 byte)
    padded_message.push_back(0x80);

    // Append '0's until length is 64 bytes shy of a 512-bit (64-byte) multiple
    while (padded_message.size() % 64 != 56) {
        padded_message.push_back(0x00);
    }

    // Append original message length as a 64-bit big-endian integer
    for (int i = 7; i >= 0; --i) {
        padded_message.push_back((original_len_bits >> (i * 8)) & 0xFF);
    }

    // 3. Process the message in successive 512-bit (64-byte) chunks
    for (size_t chunk_start = 0; chunk_start < padded_message.size(); chunk_start += 64) {
        uint32_t w[80];

        // a. Break chunk into sixteen 32-bit big-endian words
        for (int i = 0; i < 16; ++i) {
            w[i] = (padded_message[chunk_start + i * 4] << 24) |
                   (padded_message[chunk_start + i * 4 + 1] << 16) |
                   (padded_message[chunk_start + i * 4 + 2] << 8) |
                   (padded_message[chunk_start + i * 4 + 3]);
        }

        // b. Extend the sixteen words into eighty words
        for (int i = 16; i < 80; ++i) {
            w[i] = rotate_left(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
        }

        // c. Initialize hash value for this chunk
        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];

        // d. Main loop
        for (int i = 0; i < 80; ++i) {
            uint32_t f, k;
            if (i < 20) {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            } else if (i < 40) {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t temp = rotate_left(a, 5) + f + e + k + w[i];
            e = d;
            d = c;
            c = rotate_left(b, 30);
            b = a;
            a = temp;
        }
        
        // e. Add this chunk's hash to result so far
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
    }

    // 4. Produce the final hash value
    std::vector<uint8_t> hash_result;
    for (int i = 0; i < 5; ++i) {
        hash_result.push_back((h[i] >> 24) & 0xFF);
        hash_result.push_back((h[i] >> 16) & 0xFF);
        hash_result.push_back((h[i] >> 8) & 0xFF);
        hash_result.push_back(h[i] & 0xFF);
    }
    
    return hash_result;
}


// --- Part 2: HMAC-SHA1 Implementation ---

/**
 * @brief Computes the HMAC-SHA1 of a message.
 * @param key The secret key.
 * @param msg The message to authenticate.
 * @return A 20-byte vector representing the HMAC-SHA1 digest.
 */
std::vector<uint8_t> hmac_sha1(std::vector<uint8_t> key, const std::vector<uint8_t>& msg) {
    const size_t block_size = 64;
    
    // 1. Adjust key size
    if (key.size() > block_size) {
        key = sha1(key);
    }
    if (key.size() < block_size) {
        key.resize(block_size, 0x00);
    }

    // 2. Create inner and outer padded keys
    std::vector<uint8_t> o_key_pad(block_size);
    std::vector<uint8_t> i_key_pad(block_size);

    // 3. XOR key with ipad (0x36) and opad (0x5C)
    for (size_t i = 0; i < block_size; ++i) {
        o_key_pad[i] = key[i] ^ 0x5C;
        i_key_pad[i] = key[i] ^ 0x36;
    }

    // 4. Perform inner hash
    std::vector<uint8_t> inner_payload = i_key_pad;
    inner_payload.insert(inner_payload.end(), msg.begin(), msg.end());
    std::vector<uint8_t> inner_hash = sha1(inner_payload);

    // 5. Perform outer hash
    std::vector<uint8_t> outer_payload = o_key_pad;
    outer_payload.insert(outer_payload.end(), inner_hash.begin(), inner_hash.end());
    
    return sha1(outer_payload);
}


// --- Part 3: T-OTP Implementation ---

/**
 * @brief Generates a 6-digit T-OTP code.
 * @param secret_key_str The shared secret key as an Base32 string.
 * @param time_step The time-step value (T).
 * @return A 6-digit T-OTP code as a string.
 */
std::string generate_totp(const std::string& secret_key_str_base32, uint64_t time_step) {
    
    uint64_t temp_step = time_step; 

    // 0. Convert Base32 string to ASCII string
    std::string secret_key_str = base32_to_ascii(secret_key_str_base32);
    // 1. Convert secret key and time_step to byte vectors
    std::vector<uint8_t> secret_key(secret_key_str.begin(), secret_key_str.end());
    
    
    std::vector<uint8_t> time_step_bytes(8);
    for (int i = 7; i >= 0; --i) {
        time_step_bytes[i] = temp_step & 0xFF;
        temp_step >>= 8;
    }
    
    // 2. Compute the HMAC-SHA1 hash
    std::vector<uint8_t> hash = hmac_sha1(secret_key, time_step_bytes);

   
    // 3. Dynamic Truncation
    uint8_t offset = hash.back() & 0x0F;
    
    uint32_t truncated_hash = 
        (hash[offset]     & 0x7F) << 24 |
        (hash[offset + 1] & 0xFF) << 16 |
        (hash[offset + 2] & 0xFF) << 8  |
        (hash[offset + 3] & 0xFF);

    // 4. Compute the 6-digit OTP
    uint32_t otp_code = truncated_hash % 1000000;

    // 5. Format the code as a 6-digit string
    std::stringstream ss;
    ss << std::setw(6) << std::setfill('0') << otp_code;
    return ss.str();
}




