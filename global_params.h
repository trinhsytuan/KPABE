//
// Created by Trinh Tuan on 27/05/2024.
//
#include<pbc.h>
#include<iostream>
using namespace std;
#ifndef KPABE_GLOBAL_PARAMS_H
#define KPABE_GLOBAL_PARAMS_H

const int maxUser = 10;
const int attribute = 20;
const int level = 12;

typedef struct {
    element_t g;
    element_t ga;
    element_t alpha;
    element_t beta;
    element_t U[maxUser];
    element_t e[maxUser][attribute];
} global_parameter;

struct public_parametter{
    element_t U[maxUser];
    element_t e[maxUser][attribute];
    element_t gaPow[level * attribute][2];
    element_t gaBetaDivAlpha;
    element_t gAlpha;
    element_t pairingGGa;
};

void initGlobalParameter(pairing_t pairing, global_parameter* globalParams);
void initPublicParameter(pairing_t pairing, public_parametter* publicParams, global_parameter *globalParams);



#endif //KPABE_GLOBAL_PARAMS_H
