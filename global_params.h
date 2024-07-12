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
const int DNFMax = 6;

typedef struct {
    element_t g;
    element_t ga;
    element_t alpha;
    element_t beta;
    element_t gPowAlpha;
    element_t pairinggga;
    element_t U[maxAttribute];
    element_t e[maxUser][DNFMax];
    element_t l[maxAttribute][maxLevel];
    element_t gaPow[maxAttribute * maxLevel][2];
    element_t gaDivAlpha;
} global_parameter;



void initGlobalParameter(pairing_t pairing, global_parameter* globalParams);
void initPublicParameter(pairing_t pairing,  global_parameter *globalParams);



#endif //KPABE_GLOBAL_PARAMS_H
