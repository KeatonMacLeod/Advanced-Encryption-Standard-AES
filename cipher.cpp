#include "cipher.h"

//CONFIRMED WORKING PROPERLY
void Cipher::addRoundKey(State* state, uint8_t key_schedule[44][4], int start, int end) {
    for (int i=start; i<=end; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = state->state[j][i] ^ key_schedule[i][j];
        }
    }
}

//CONFIRMED WORKING PROPERLY
void Cipher::subBytes(State* state, SBox* s_box) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = s_box->lookup(state->state[j][i]);
        }
    }
}

void Cipher::shiftRows(State* state) {
    //We can start at index 1 since the 0th row never shifts
    for (int i=1; i<4; i++) {
        uint8_t temp_array[4];
        copy(begin(state->state[i]), end(state->state[i]), begin(temp_array));
        for (int j=0; j<4; j++) {
            state->state[i][j] = temp_array[(j+i)%4];
        }
    }
}

void Cipher::mixColumns() {

}