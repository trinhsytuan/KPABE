//
// Created by Trinh Tuan on 28/05/2024.
//
#include<pbc.h>
#include "global_params.h"
#ifndef KPABE_KEYGENERATOR_H
#define KPABE_KEYGENERATOR_H
using namespace std;
const int maxPolicy = 20;
const int maxLevel = 6;
struct keyUser{
    element_t du[maxPolicy][maxLevel];
    element_t tij[maxPolicy][maxLevel];
    element_t au[maxPolicy];
};
void initAttribute(pairing_t pairing, keyUser* userKey);
void genKeyForUser(pairing_t pairing, keyUser* userKey, public_parametter publicParametter, element_t alpha, element_t beta, element_t g);
#endif //KPABE_KEYGENERATOR_H
