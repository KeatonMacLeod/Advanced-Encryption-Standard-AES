#include <vector>
#include <iostream>
#include "utility.h"

uint8_t Utility::hexCharToBinary(char c)
{
    switch(toupper(c))
    {
        case '0': return 0x0;
        case '1': return 0x1;
        case '2': return 0x2;
        case '3': return 0x3;
        case '4': return 0x4;
        case '5': return 0x5;
        case '6': return 0x6;
        case '7': return 0x7;
        case '8': return 0x8;
        case '9': return 0x9;
        case 'A': return 0xa;
        case 'B': return 0xb;
        case 'C': return 0xc;
        case 'D': return 0xd;
        case 'E': return 0xe;
        case 'F': return 0xf;
    }
}

uint8_t Utility::hexStringToByte(const string& hexa)
{
    uint8_t first_four_bits = hexCharToBinary(hexa[0]);
    uint8_t last_four_bits = hexCharToBinary(hexa[1]);
    uint8_t byte = 0x00;

    byte = first_four_bits;
    byte = byte << 4;
    byte |= last_four_bits;

    return byte;
}

// Computes byte_one * byte_two and performs necessary modulo calculations if
// an overflow took place according to Galois Field finite field mathematics
uint8_t Utility::galoisMultiply(uint8_t byte_one, uint8_t byte_two) {
    uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        if ((byte_two & 1) != 0) {
            result ^= byte_one;
        }

        bool highest_bit = (byte_one & 0x80) != 0;
        byte_one <<= 1;
        if (highest_bit) {
            byte_one ^= 0x1B;
        }
        byte_two >>= 1;
    }

    return result;
}