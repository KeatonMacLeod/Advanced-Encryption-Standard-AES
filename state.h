#ifndef CRYPTOGRAPHYSCRIPTS_STATE_H
#define CRYPTOGRAPHYSCRIPTS_STATE_H

#include <fstream>
#include <iostream>
#include "plaintext.h"

class State {
public:
    uint8_t state[4][4];
    void readPlaintextIntoState(Plaintext* plaintext);
};


#endif //CRYPTOGRAPHYSCRIPTS_STATE_H
