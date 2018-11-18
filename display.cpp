#include "display.h"

void Display::displayKeySchedule(uint8_t key_schedule[44][4]) {
    cout << endl << "Key Schedule:" << endl;
    int keys_on_line = 1;
    for (int i=0; i<44; i++) {
        for (int j=0; j<4; j++) {
            if (j+1 == 4)
                cout << hex << static_cast<int>(key_schedule[i][j]);
            else
                cout << hex << static_cast<int>(key_schedule[i][j]) << " ";
        }
        if (keys_on_line % 4 == 0)
            cout << endl;
        else
            cout << ",\t";
        keys_on_line++;
    }
}

void Display::displayEncryptionProcess() {
    cout << endl << "------------------" << endl << "ENCRYPTION PROCESS" << endl << "------------------" << endl << endl;
}

void Display::displayPlaintext(Plaintext* plaintext) {
    cout << "Plain Text:" << endl << "-----------" << endl;
    int plain_text_on_line = 1;
    for (int i=0; i<16; i++) {
        if (plain_text_on_line % 4 == 0)
            cout << hex << static_cast<int>(plaintext->plaintext_bytes[i]) << "\t";
        else
            cout << hex << static_cast<int>(plaintext->plaintext_bytes[i]) << " ";

        plain_text_on_line++;
    }
    cout << endl << endl;
}

void Display::displayEncryptionRound(State* state, int round) {
    if (round == 10)
        cout << "Last Round:" << endl << "-----------" << endl;
    else if (round == 11)
        cout << "Ciphertext:" << endl << "-----------" << endl;
    else
        cout << "Round " << round << ":" << endl << "--------" << endl;
    int cipher_text_on_lines = 1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (cipher_text_on_lines % 4 == 0)
                cout << hex << static_cast<int>(state->state[j][i]) << "\t";
            else
                cout << hex << static_cast<int>(state->state[j][i]) << " ";

            cipher_text_on_lines++;
        }
    }
    cout << endl << endl;
}

void Display::displayDecryptionProcess() {
    cout << endl << "------------------" << endl << "DECRYPTION PROCESS" << endl << "------------------" << endl << endl;
}

void Display::displayDecryptionRound(State* state, int round) {
    if (round == -1)
        cout << "Plaintext:" << endl << "----------" << endl;
    else if (round == 10)
        cout << "Ciphertext:" << endl << "-----------" << endl;
    else
        cout << "Round " << round << ":" << endl << "--------" << endl;
    int plaintext_on_lines = 1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (plaintext_on_lines % 4 == 0)
                cout << hex << static_cast<int>(state->state[j][i]) << "\t";
            else
                cout << hex << static_cast<int>(state->state[j][i]) << " ";

            plaintext_on_lines++;
        }
    }
    cout << endl << endl;
}