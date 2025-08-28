# Problem: Cyclic Redundancy Check (CRC)

Cyclic Redundancy Check (CRC) is an error-detection method used in networking and data transmission. It appends a **remainder** (computed from a generator polynomial) to the message so that the receiver can detect if errors occurred during transmission.

Your goal is to implement the **CRC algorithm** in C++.

# The CRC Algorithm

CRC works like long division in binary (using XOR instead of subtraction).  

### Steps:
1. **Message + Zeros**:  
   Given a message `M` (binary string) and generator polynomial `G` (binary string of length `r+1`), append `r = len(G)-1` zeros to the message.  
   Example:  
   - Message: `1101011011`  
   - Generator: `10011` (degree = 4, so `r=4`)  
   - Data for division: `1101011011 0000`

2. **Modulo-2 Division**:  
   Perform binary division of `data` by `G` using XOR (like long division).  
   - At each step, if the current leading bit is `1`, XOR the next `len(G)` bits with `G`.  
   - Otherwise, move to the next bit.  
   Continue until the end.  
   The final `r` bits are the **remainder**.

3. **Codeword (Transmitted Message)**:  
   Append the remainder to the original message.  
   Example:  
   - Remainder: `1110`  
   - Codeword: `1101011011 1110`

4. **Verification (at Receiver)**:  
   The receiver performs the same division (`codeword ÷ G`).  
   - If the remainder is all `0`s → message is **error-free**.  
   - Otherwise → **error detected**.


### Example 1
Message = `1101011011`  
Generator G = `10011` (deg = 4 → append `0000`)  
Data = `11010110110000`  (length = 14 throughout)

Process windows of size 5 from i = 0 … 9:

i=0: window 11010 → XOR G → 01001  
      data: 01001110110000

i=1: window 10011 → XOR G → 00000  
      data: 00000010110000

i=2: window 00001 → leading 0 → skip  
      data: 00000010110000

i=3: window 00010 → leading 0 → skip  
      data: 00000010110000

i=4: window 00101 → leading 0 → skip  
      data: 00000010110000

i=5: window 01011 → leading 0 → skip  
      data: 00000010110000

i=6: window 10110 → XOR G → 00101  
      data: 00000000101000

i=7: window 01010 → leading 0 → skip  
      data: 00000000101000

i=8: window 10100 → XOR G → 00111  
      data: 00000000001110

i=9: window 01110 → leading 0 → skip  
      data: 00000000001110

Remainder = last 4 bits = **1110**  
Codeword = `1101011011` + `1110` = **`11010110111110`**


### Example 2
Message = `1011`  
Generator G = `1101` (deg = 3 → append `000`)  
Data = `1011000`  (length = 7 throughout)

i=0: window 1011 → XOR G → 0110  
      data: 0110000

i=1: window 1100 → XOR G → 0001  
      data: 0000100

i=2: window 0010 → leading 0 → skip  
      data: 0000100

i=3: window 0100 → leading 0 → skip  
      data: 0000100

Remainder = last 3 bits = **100**  
Codeword = `1011` + `100` = **`1011100`**
---

# Your Task

In **crc.cpp**:
- Complete the following functions:
  1. `string modulo2Division(const string &data, const string &generator)`  
     → Perform binary division and return the remainder.
  2. `string generateCRC(const string &message, const string &generator)`  
     → Return the transmitted codeword.
  3. `bool checkCRC(const string &received, const string &generator)`  
     → Verify if the received message is error-free.

Do **not** modify any other files.  
The provided `main.cpp` handles input/output.

---
