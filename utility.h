#ifndef CRYPTOGRAPHYSCRIPTS_UTILITY_H
#define CRYPTOGRAPHYSCRIPTS_UTILITY_H

#include <string>

using namespace std;

class Utility {
public:
    uint8_t hex_char_to_binary(char c);
    uint8_t hex_string_to_byte(const std::string& hex);
};

#endif //CRYPTOGRAPHYSCRIPTS_UTILITY_H
