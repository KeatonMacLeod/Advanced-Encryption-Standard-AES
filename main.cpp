#include "plaintext.h"
#include "key.h"
#include "s_box.h"
#include "s_box_inverse.h"
#include "aes.h"

using namespace std;

int main(int argc, char** argv) {

    //Initialize plaintext (argv[1] = plaintext filename)
    auto plaintext = new Plaintext();
    plaintext->process_plaintext_filename(argv[1]);

    //Initialize key (argv[2] = key filename)
    auto key = new Key();
    key->process_key_filename(argv[2]);

    //Initialize the encryption scheme
    auto aes = new AES();

    //Encrypt the plaintext and print out the encryption process
    aes->encrypt(plaintext, key);

    //Decrypt the cipher text and print out the decryption process
    aes->decrypt();
    return 0;
}