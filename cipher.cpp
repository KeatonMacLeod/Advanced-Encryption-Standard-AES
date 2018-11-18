#include "cipher.h"

Cipher::Cipher() {
    utility = new Utility();
}

//CONFIRMED WORKING PROPERLY
void Cipher::addRoundKey(State* state, uint8_t key_schedule[44][4], int key_schedule_offset) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = state->state[j][i] ^ key_schedule[i+key_schedule_offset][j];
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

//CONFIRMED WORKING PROPERLY
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

void Cipher::mixColumns(State* state) {

    uint8_t temp[4][4];

    for (int i=0; i<4; i++) {
        temp[0][i] = utility->galoisMultiply(state->state[0][i], 0x02) ^ utility->galoisMultiply(state->state[1][i], 0x03) ^ state->state[2][i] ^ state->state[3][i];
        temp[1][i] = state->state[0][i] ^ utility->galoisMultiply(state->state[1][i], 0x02) ^ utility->galoisMultiply(state->state[2][i], 0x03) ^ state->state[3][i];
        temp[2][i] = state->state[0][i] ^ state->state[1][i] ^ utility->galoisMultiply(state->state[2][i], 0x02) ^ utility->galoisMultiply(state->state[3][i], 0x03);
        temp[3][i] = utility->galoisMultiply(state->state[0][i], 0x03) ^ state->state[1][i] ^ state->state[2][i] ^ utility->galoisMultiply(state->state[3][i], 0x02);
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[i][j] = temp[i][j];
        }
    }
}