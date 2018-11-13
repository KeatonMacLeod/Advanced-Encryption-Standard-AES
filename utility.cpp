#include <vector>
#include "utility.h"

uint8_t Utility::hex_char_to_binary(char c)
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

//THIS NEEDS to return the unsigned char that can be OR'd and AND'd in the S-box
uint8_t Utility::hex_string_to_byte(const string& hexa)
{
    uint8_t first_four_bits = hex_char_to_binary(hexa[0]);
    uint8_t last_four_bits = hex_char_to_binary(hexa[1]);
    uint8_t byte = 0x00;

    byte = first_four_bits;
    byte = byte << 4;
    byte |= last_four_bits;

    return byte;
}