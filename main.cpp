#include "s_box.h"
#include "s_box_inverse.h"

using namespace std;

int main() {

    auto s_box = new SBox();
    auto s_box_inverse = new SBoxInverse();

    //Setup substitution tables for each s-box
    s_box->initializeSBox();
    s_box_inverse->initializeSBox();

    return 0;
}