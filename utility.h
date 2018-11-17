#ifndef CRYPTOGRAPHYSCRIPTS_UTILITY_H
#define CRYPTOGRAPHYSCRIPTS_UTILITY_H

#include <string>

using namespace std;

class Utility {
public:
    uint8_t hexCharToBinary(char c);
    uint8_t hexStringToByte(const std::string& hex);
    void clearArray(uint8_t* matrix[], const int& rows, const int& cols);
};

#endif //CRYPTOGRAPHYSCRIPTS_UTILITY_H
