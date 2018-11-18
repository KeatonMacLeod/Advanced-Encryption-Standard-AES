#include "cipher_inverse.h"
#include "s_box_inverse.h"

CipherInverse::CipherInverse() {
    utility = new Utility();
}

//CONFIRMED WORKING PROPERLY
void CipherInverse::addRoundKey(State* state, uint8_t key_schedule[44][4], int key_schedule_offset) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = state->state[j][i] ^ key_schedule[i+key_schedule_offset][j];
        }
    }
}

//CONFIRMED WORKING PROPERLY
void CipherInverse::invShiftRows(State* state) {
    //We don't need to process the 0th row hence i > 0
    for (int i=3; i>0; i--) {
        uint8_t temp_array[4];
        copy(begin(state->state[i]), end(state->state[i]), begin(temp_array));
        for (int j=3; j>=0; j--) {
            if (j-i < 0) {
                if (j-i == -1) state->state[i][j] = temp_array[3];
                else if (j-i == -2) state->state[i][j] = temp_array[2];
                else if (j-i == -3) state->state[i][j] = temp_array[1];
            }
            else {
                state->state[i][j] = temp_array[j-i];
            }
        }
    }
}

//CONFIRMED WORKING PROPERLY
void CipherInverse::invSubBytes(State* state, SBoxInverse* s_box_inverse) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[j][i] = s_box_inverse->lookup(state->state[j][i]);
        }
    }
}

void CipherInverse::invMixColumns(State* state) {
    uint8_t temp[4][4];

    for (int i=0; i<4; i++) {
        temp[0][i] = utility->galoisMultiply(state->state[0][i], 0x0e) ^ utility->galoisMultiply(state->state[1][i], 0x0b) ^ utility->galoisMultiply(state->state[2][i], 0x0d) ^ utility->galoisMultiply(state->state[3][i], 0x09);
        temp[1][i] = utility->galoisMultiply(state->state[0][i], 0x09) ^ utility->galoisMultiply(state->state[1][i], 0x0e) ^ utility->galoisMultiply(state->state[2][i], 0x0b) ^ utility->galoisMultiply(state->state[3][i], 0x0d);
        temp[2][i] = utility->galoisMultiply(state->state[0][i], 0x0d) ^ utility->galoisMultiply(state->state[1][i], 0x09) ^ utility->galoisMultiply(state->state[2][i], 0x0e) ^ utility->galoisMultiply(state->state[3][i], 0x0b);
        temp[3][i] = utility->galoisMultiply(state->state[0][i], 0x0b) ^ utility->galoisMultiply(state->state[1][i], 0x0d) ^ utility->galoisMultiply(state->state[2][i], 0x09) ^ utility->galoisMultiply(state->state[3][i], 0x0e);
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            state->state[i][j] = temp[i][j];
        }
    }
}