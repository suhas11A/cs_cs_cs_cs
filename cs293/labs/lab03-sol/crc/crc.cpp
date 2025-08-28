#include "crc.h"
using namespace std;

/**
 * Perform modulo-2 division of `data` by `generator` and return the remainder.
 * `data` is expected to be (message + k zeros) where k = generator.size() - 1
 */
string modulo2Division(string data, const string &generator) {
    // You can assume data.size() >= generator.size()
    // TODO
    size_t i = 0;
    for(; i <= data.size() - generator.size(); ++i)
    {
        if(data[i] == '0') continue;
        for (size_t j = 0; j < generator.size(); ++j)
        {
            data[i+j] = data[i+j] == generator[j] ? '0' : '1';
        }
    }
    return data.substr(i);
}

/**
 * Compute the CRC codeword by appending remainder to `message`.
 */
string generateCRC(const string &message, const string &generator) {
    // TODO:
    // 1) Append generator.size() - 1 zeros to message
    // 2) find remainder using above function
    // 3) return message + rem

    size_t k = generator.size() - 1;
    string data = message + string(k, '0');
    string rem = modulo2Division(data, generator);

    return message + rem;
}

/**
 * Verify if `received` is error-free under given `generator`.
 * Returns true if remainder is all zeros, false otherwise.
 */
bool checkCRC(const string &received, const string &generator) {
    // TODO:
    // Compute remainder of `received` by `generator`.
    // If remainder is all '0', return true, else false.
    string rem = modulo2Division(received, generator);
    for (auto& r : rem)
    {
        if (r == '1') return false;
    }
    return true;
}
