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

    //Initialize regular S-Box
    auto s_box = new SBox();
    s_box->initializeSBox();

    //Initialize inverse S-Box
    auto s_box_inverse = new SBoxInverse();
    s_box_inverse->initializeSBox();

    //Initialize the encryption scheme
    auto aes = new AES();

    //Encrypt the plaintext
    aes->encrypt(plaintext, key);

    return 0;
}