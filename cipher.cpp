#include "cipher.h"

void Cipher::subBytes() {

}

void Cipher::shiftRows() {

}

void Cipher::mixColumns() {

}

//CONFIRMED WORKING PROPERLY
void Cipher::addRoundKey(State* state, uint8_t key_schedule[44][4], int start, int end) {
    for (int i=start; i<=end; i++) {
        state->state[0][i] = state->state[0][i] ^ key_schedule[i][0];
        state->state[1][i] = state->state[1][i] ^ key_schedule[i][1];
        state->state[2][i] = state->state[2][i] ^ key_schedule[i][2];
        state->state[3][i] = state->state[3][i] ^ key_schedule[i][3];
    }
}