//
// Created by Trinh Tuan on 28/05/2024.
//
#include<pbc.h>
#ifndef KPABE_KEYGENERATOR_H
#define KPABE_KEYGENERATOR_H

extern const int maxPolicy = 100;
struct keyUser{
    element_t du[maxPolicy];
};
void genKeyForUser(pairing_t pairing, keyUser* keyUser);
#endif //KPABE_KEYGENERATOR_H
