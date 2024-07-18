#include <iostream>
#include<pbc.h>
#include<vector>
#include"attribute.h"
#include "global_params.h"

#include "KeyGenerator.h"
#include "utils/utils.h"
#include"Encrypt.h"
#include<iostream>
using namespace std;
int main() {
    pairing_t pairing;
    pbc_param_t par;
    global_parameter paramsGlobal;
    int tt[] = {1,2,3};
    keyUser userKey;

    // initialization
    pbc_param_init_a_gen(par, 160, 512);
    pairing_init_pbc_param(pairing, par);
    initGlobalParameter(pairing, &paramsGlobal);
    initPublicParameter(pairing,  &paramsGlobal);
    genkeyForOneUser(pairing, 1, paramsGlobal, &userKey);
    vector<vector<element_s>> attribute = generateAttributes(paramsGlobal);
    encrypt(pairing, paramsGlobal, userKey, attribute);
//    initAttribute(pairing, &userKey);
//    genKeyForUser(pairing, &userKey, pubParametter, paramsGlobal.alpha, paramsGlobal.beta, paramsGlobal.g);
//    encrypt(pairing, pubParametter, tt ,3,6);
    return 0;
}
