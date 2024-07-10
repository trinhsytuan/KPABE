//
// Created by Trinh Tuan on 27/05/2024.
//
#include<pbc.h>
#include<iostream>

using namespace std;
#ifndef KPABE_GLOBAL_PARAMS_H
#define KPABE_GLOBAL_PARAMS_H

const int maxAttribute = 6;
const int maxLevel = 6;
const int maxUser = 20;
const int DNFMax = 20;

typedef struct {
    element_t g;
    element_t ga;
    element_t alpha;
    element_t beta;
    element_t U[maxAttribute];
    element_t e[maxUser][DNFMax];
    element_t l[maxAttribute][maxLevel];
} global_parameter;

struct public_parametter{
    element_t U[maxAttribute];
    element_t e[maxAttribute][maxLevel];
    element_t gaPow[maxAttribute * maxLevel][2];
    element_t l[maxAttribute][maxLevel];
    element_t gaBetaDivAlpha;
    element_t gAlpha;
    element_t pairingGGa;
    element_t g;
};

void initGlobalParameter(pairing_t pairing, global_parameter* globalParams);
void initPublicParameter(pairing_t pairing, public_parametter* publicParams, global_parameter *globalParams);



#endif //KPABE_GLOBAL_PARAMS_H
