#include <vector>
#include <sstream>
#include "s_box.h"
#include "utility.h"

SBox::SBox() {
    utility = new Utility();
}

void SBox::initializeSBox() {
    string line;
    ifstream s_box_file;
    s_box_file.open("C:\\Users\\Jeeves\\C++Projects\\CryptographyScripts\\sbox.txt");
    int row = 0;
    if (s_box_file.is_open()) {
        while (getline(s_box_file, line) && row <= 15) {
            int col = 0;
            istringstream token_stream(line);
            for(string s; token_stream >> s;)
                substitutionTable[row][col++] = utility->hex_string_to_byte(s);

            row++;
        }
        s_box_file.close();
    }
}