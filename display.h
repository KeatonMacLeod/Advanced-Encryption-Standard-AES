#ifndef CRYPTOGRAPHYSCRIPTS_DISPLAY_H
#define CRYPTOGRAPHYSCRIPTS_DISPLAY_H


#include "plaintext.h"
#include "state.h"

class Display {
public:
    void displayKeySchedule(uint8_t key_schedule[44][4]);
    void displayEncryptionProcess();
    void displayPlaintext(Plaintext* plaintext);
    void displayEncryptionRound(State* state, int round);
    void displayDecryptionProcess();
    void displayDecryptionRound(State* state, int round);
};


#endif //CRYPTOGRAPHYSCRIPTS_DISPLAY_H
