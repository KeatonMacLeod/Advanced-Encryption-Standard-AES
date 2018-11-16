#include "state.h"

//Read the plaintext into "The State" as described in 3.4
void State::readPlaintextIntoState(Plaintext* plaintext) {
    int row = 0;
    int col = 0;
    for (int i=0; i<16; i++) {
        if (i != 0 && i % 4 == 0) {
            row = 0;
            col++;
        }
        state[row++][col] = plaintext->plaintext_bytes[i];
    }
}