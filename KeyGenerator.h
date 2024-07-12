//
// Created by Trinh Tuan on 28/05/2024.
//

#include "global_params.h"
#ifndef KPABE_KEYGENERATOR_H
#define KPABE_KEYGENERATOR_H
using namespace std;
const int maxDNF = 20;
struct keyUser{
    element_t du[maxUser];
};
void initAttribute(pairing_t pairing, keyUser* userKey);
void genkeyForOneUser(pairing_t pairing, int indexUser, global_parameter params, keyUser* keyUser);
#endif //KPABE_KEYGENERATOR_H
