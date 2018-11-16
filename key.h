#ifndef CRYPTOGRAPHYSCRIPTS_KEY_H
#define CRYPTOGRAPHYSCRIPTS_KEY_H

#include <fstream>
#include <iostream>

using namespace std;

class Key {
public:
    uint8_t key_bytes[16];
    void process_key_filename(char* filename);
};


#endif //CRYPTOGRAPHYSCRIPTS_KEY_H
