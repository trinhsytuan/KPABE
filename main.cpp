#include <iostream>
#include<pbc.h>
#include "global_params.h"
#include"attribute.h"
#include "KeyGenerator.h"
#include "utils/utils.h"
#include"Encrypt.h"
#include<iostream>
using namespace std;
int main() {
    pairing_t pairing;
    pbc_param_t par;
    global_parameter paramsGlobal;
    public_parametter pubParametter;
    keyUser userKey;
    int sizeAtrribute = getSizeAttributesTable();


    // initialization
    pbc_param_init_a_gen(par, 160, 512);
    pairing_init_pbc_param(pairing, par);
    initGlobalParameter(pairing, &paramsGlobal);
    initPublicParameter(pairing, &pubParametter, &paramsGlobal);
    initAttribute(pairing, &userKey);
    genKeyForUser(pairing, &userKey, pubParametter, paramsGlobal.alpha, paramsGlobal.beta, paramsGlobal.g);
    encrypt(pairing, pubParametter);
    return 0;
}
