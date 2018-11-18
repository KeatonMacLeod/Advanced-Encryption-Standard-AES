#include <sstream>
#include "key.h"
#include "utility.h"

void Key::process_key_filename(char* filename) {
    auto utility = new Utility();
    string line;
    ifstream key_file;
    cout << "Key Filename: " << filename << endl;
    key_file.open(filename);
    int row = 0;
    if (key_file.is_open()) {
        while (getline(key_file, line) && row <= 0) {
            int col = 0;
            istringstream token_stream(line);
            for(string s; token_stream >> s;)
                key_bytes[col++] = utility->hexStringToByte(s);
        }
        key_file.close();
    }
}