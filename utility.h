#ifndef CRYPTOGRAPHYSCRIPTS_UTILITY_H
#define CRYPTOGRAPHYSCRIPTS_UTILITY_H

#include <string>

using namespace std;

class Utility {
public:
    uint8_t hexCharToBinary(char c);
    uint8_t hexStringToByte(const std::string& hex);
    uint8_t galoisMultiply(uint8_t byte_one, uint8_t byte_two);
};

#endif //CRYPTOGRAPHYSCRIPTS_UTILITY_H
