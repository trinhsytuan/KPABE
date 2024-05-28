#include <iostream>
#include<pbc.h>
#include "global_params.h"
#include<iostream>
using namespace std;
int main() {
    pairing_t pairing;
    pbc_param_t par;
    global_parameter paramsGlobal;
    public_parametter pubParametter;
    // initialization
    pbc_param_init_a_gen(par, 160, 512);
    pairing_init_pbc_param(pairing, par);
    initGlobalParameter(pairing, &paramsGlobal);
    initPublicParameter(pairing, &pubParametter, &paramsGlobal);

    return 0;
}
