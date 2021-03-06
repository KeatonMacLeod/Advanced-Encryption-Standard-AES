#include <sstream>
#include "plaintext.h"
#include "utility.h"

void Plaintext::process_plaintext_filename(char* filename) {
    auto utility = new Utility();
    string line;
    ifstream plaintext_file;
    cout << endl << "PlainText Filename: " << filename << endl;
    plaintext_file.open(filename);
    int row = 0;
    if (plaintext_file.is_open()) {
        while (getline(plaintext_file, line) && row <= 0) {
            int col = 0;
            istringstream token_stream(line);
            for(string s; token_stream >> s;)
                plaintext_bytes[col++] = utility->hexStringToByte(s);
        }
        plaintext_file.close();
    }
}