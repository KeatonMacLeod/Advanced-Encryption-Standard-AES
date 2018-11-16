#include <sstream>
#include "key.h"
#include "utility.h"

void Key::process_key_filename(char* filename) {
    auto utility = new Utility();
    string line;
    ifstream plaintext_file;
    plaintext_file.open(filename);
    int row = 0;
    if (plaintext_file.is_open()) {
        while (getline(plaintext_file, line) && row <= 0) {
            int col = 0;
            istringstream token_stream(line);
            for(string s; token_stream >> s;)
                key_bytes[col++] = utility->hex_string_to_byte(s);
        }
        plaintext_file.close();
    }
}