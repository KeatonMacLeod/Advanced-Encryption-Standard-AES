#ifndef CRYPTOGRAPHYSCRIPTS_PLAINTEXT_H
#define CRYPTOGRAPHYSCRIPTS_PLAINTEXT_H

#include <fstream>
#include <iostream>

using namespace std;

class Plaintext {
public:
    uint8_t plaintext_bytes[16];
    void process_plaintext_filename(char* filename);
};


#endif //CRYPTOGRAPHYSCRIPTS_PLAINTEXT_H
