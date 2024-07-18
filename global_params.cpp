//
// Created by Trinh Tuan on 27/05/2024.
//
#include "global_params.h"
#include "attribute.h"
using namespace std;


void initGlobalParameter(pairing_t pairing, global_parameter* globalParams) {
    element_init_G1(globalParams->g, pairing);
    element_init_G2(globalParams->ga, pairing);
    element_init_Zr(globalParams->alpha, pairing);
    element_init_Zr(globalParams->beta, pairing);
    for (int i = 0; i < maxAttribute; i++) {
        element_init_Zr(globalParams->U[i], pairing);
        element_random(globalParams->U[i]);
        //element_printf("%B\n", globalParams.U[i]);
    }
    for (int i = 0; i < maxUser; i++) {
        for (int j = 0; j < DNFMax; j++) {
            element_init_Zr(globalParams->e[i][j], pairing);
            element_random(globalParams->e[i][j]);
        }
    }
    for (int i = 0; i < maxAttribute; i++) {
        for (int j = 0; j < maxLevelAttr[i]; j++) {
            element_init_Zr(globalParams->l[i][j], pairing);
            element_set_si(globalParams->l[i][j], (long)j);
        }
    }
    element_random(globalParams->beta);
    element_random(globalParams->g);
    element_random(globalParams->ga);
    element_random(globalParams->alpha);
}

void initPublicParameter(pairing_t pairing, global_parameter* globalParams) {
    int totalLevel = 0;
    for(int i = 0; i < maxAttribute;i++) totalLevel += maxLevelAttr[i];
    element_t alphaTemp, betaTemp, betaTemp2;
    element_init_same_as(alphaTemp, globalParams->alpha);
    element_init_same_as(betaTemp, globalParams->beta);
    element_init_same_as(betaTemp2, globalParams->beta);
    element_set1(alphaTemp);
    element_set1(betaTemp);
    element_set(betaTemp2, globalParams->beta);
    //element_printf("%B\n", betaTemp2);
    for(int i = 1; i < totalLevel;i++) {
        element_init_G2(globalParams->gaPow[i][0], pairing);
        element_init_G2(globalParams->gaPow[i][1], pairing);
        element_mul(alphaTemp, alphaTemp, globalParams->alpha);
        element_t tempPow1, tempPow2;
        element_init_Zr(tempPow1, pairing);
        element_init_Zr(tempPow2, pairing);
        element_mul(tempPow1, alphaTemp, betaTemp);
        element_mul(tempPow2, alphaTemp, betaTemp2);
        element_pow_zn(globalParams->gaPow[i][0], globalParams->ga, tempPow1);
        element_pow_zn(globalParams->gaPow[i][1], globalParams->ga, tempPow2);
        //element_printf("%B\n", globalParams->gaPow[i][1]);
    }
    element_init_G2(globalParams->gaPow[0][0], pairing);
    element_init_G2(globalParams->gaPow[0][1], pairing);
    element_set(globalParams->gaPow[0][0], globalParams->ga);
    element_pow_zn(globalParams->gaPow[0][0], globalParams->ga, globalParams->beta);

    element_t resultBetaDivAlpha;
    element_init_Zr(resultBetaDivAlpha, pairing);
    element_init_G2(globalParams->gaDivAlpha, pairing);
    element_div(resultBetaDivAlpha, globalParams->beta, globalParams->alpha);
    element_pow_zn(globalParams->gaDivAlpha, globalParams->ga, resultBetaDivAlpha);
    element_init_G1(globalParams->gPowAlpha, pairing);
    element_pow_zn(globalParams->gPowAlpha, globalParams->g, globalParams->alpha);
    element_init_GT(globalParams->pairinggga, pairing);
    element_pairing(globalParams->pairinggga, globalParams->g, globalParams->ga);
    //element_printf("%B\n",globalParams->gaDivAlpha);
//    element_init_G1(publicParams->g, pairing);
//    element_set(publicParams->g, globalParams->g);
//    for(int i = 0; i < maxAttribute;i++) {
//        element_init_Zr(publicParams->U[i], pairing);
//        element_set(publicParams->U[i], globalParams->U[i]);
//    }
//    for (int i = 0; i < maxAttribute; i++) {
//        for (int j = 0; j < maxLevel; j++) {
//            element_init_Zr(publicParams->e[i][j], pairing);
//            element_random(publicParams->e[i][j]);
//        }
//    }
//    element_t alphaTemp[maxAttribute * maxLevel];
//    element_init_Zr(alphaTemp[0], pairing);
//    element_t zeroTemp;
//    element_init_Zr(zeroTemp, pairing);
//    element_set0(zeroTemp);
//    element_pow_zn(alphaTemp[0], alphaTemp[0],zeroTemp);
//    element_init_Zr(alphaTemp[1], pairing);
//    element_set(alphaTemp[1], globalParams->alpha);
//    for(int i = 2; i < maxAttribute * maxLevel;i++) {
//        element_init_Zr(alphaTemp[i], pairing);
//        element_set(alphaTemp[i], globalParams->alpha);
//        element_pow_zn(alphaTemp[i], alphaTemp[i-1], globalParams->alpha);
//    }
//
//    element_t TTemp[2];
//    element_init_G1(TTemp[0], pairing);
//    element_set(TTemp[0], globalParams->beta);
//    element_pow_zn(TTemp[0], TTemp[0],zeroTemp);
//    element_init_G1(TTemp[1], pairing);
//    element_set(TTemp[1], globalParams->beta);
//    for(int i = 0; i < level*attribute;i++) {
//        for(int j = 0; j < 2;j++) {
//            element_init_G2(publicParams->gaPow[i][j], pairing);
//            element_t tempMul;
//            element_init_Zr(tempMul, pairing);
//            element_mul(tempMul, alphaTemp[i], TTemp[j]);
//            element_pow_zn(publicParams->gaPow[i][j], globalParams->ga, tempMul);
//        }
//    }
//    element_init_G2(publicParams->gaBetaDivAlpha, pairing);
//    element_mul(publicParams->gaBetaDivAlpha, globalParams->beta, globalParams->alpha);
//    element_init_G1(publicParams->gAlpha, pairing);
//    element_init_GT(publicParams->pairingGGa, pairing);
//    //test s
//    pairing_apply(publicParams->pairingGGa, globalParams->g, globalParams->ga, pairing);

}
