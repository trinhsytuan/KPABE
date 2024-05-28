//
// Created by Trinh Tuan on 27/05/2024.
//
#include "global_params.h"
#include"attribute.h"


void initGlobalParameter(pairing_t pairing, global_parameter* globalParams) {
    element_init_G1(globalParams->g, pairing);
    element_init_G1(globalParams->ga, pairing);
    element_init_Zr(globalParams->alpha, pairing);
    element_init_Zr(globalParams->beta, pairing);
    for (int i = 0; i < attribute; i++) {
        element_init_Zr(globalParams->U[i], pairing);
        element_random(globalParams->U[i]);
        //element_printf("%B\n", globalParams.U[i]);
    }
    for (int i = 0; i < maxUser; i++) {
        for (int j = 0; j < attribute; j++) {
            element_init_Zr(globalParams->e[i][j], pairing);
            element_random(globalParams->e[i][j]);
        }
    }
    element_random(globalParams->beta);
    element_random(globalParams->g);
    element_random(globalParams->ga);
    element_random(globalParams->alpha);
}

void initPublicParameter(pairing_t pairing, public_parametter* publicParams, global_parameter* globalParams) {
    for(int i = 0; i < maxUser;i++) {
        element_init_Zr(publicParams->U[i], pairing);
        element_set(publicParams->U[i], globalParams->U[i]);
    }
    for (int i = 0; i < maxUser; i++) {
        for (int j = 0; j < attribute; j++) {
            element_init_Zr(publicParams->e[i][j], pairing);
            element_random(publicParams->e[i][j]);
        }
    }
    element_t alphaTemp[level * attribute];
    element_init_Zr(alphaTemp[0], pairing);
    element_t zeroTemp;
    element_init_Zr(zeroTemp, pairing);
    element_set0(zeroTemp);
    element_pow_zn(alphaTemp[0], alphaTemp[0],zeroTemp);
    element_init_Zr(alphaTemp[1], pairing);
    element_set(alphaTemp[1], globalParams->alpha);
    for(int i = 2; i < level * attribute;i++) {
        element_init_Zr(alphaTemp[i], pairing);
        element_set(alphaTemp[i], globalParams->alpha);
        element_pow_zn(alphaTemp[i], alphaTemp[i-1], globalParams->alpha);
    }

    element_t TTemp[2];
    for(int i = 0; i < 2;i++) {
        element_init_G1(TTemp[i], pairing);
        element_set(TTemp[i], globalParams->beta);
    }
    for(int i = 0; i < level*attribute;i++) {
        for(int j = 0; j < 2;j++) {
            element_init_G1(publicParams->gaPow[i][j], pairing);
            element_t tempMul;
            element_init_Zr(tempMul, pairing);
            element_mul(tempMul, alphaTemp[i], TTemp[j]);
            element_pow_zn(publicParams->gaPow[i][j], globalParams->ga, tempMul);
        }
    }
    element_pow_zn(TTemp[0], TTemp[0],zeroTemp);
    element_init_G1(publicParams->gaBetaDivAlpha, pairing);
    element_mul(publicParams->gaBetaDivAlpha, globalParams->beta, globalParams->alpha);
    element_init_G1(publicParams->gAlpha, pairing);
    element_init_GT(publicParams->pairingGGa, pairing);
    pairing_apply(publicParams->pairingGGa, globalParams->g, globalParams->ga, pairing);
}
