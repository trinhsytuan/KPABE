//
// Created by Trinh Tuan on 01/07/2024.
//
#include"Decrypt.h"
#include"utils/utils.h"
void decrypt(pairing_t pairing, global_parameter params, element_t C1, element_t C2, keyUser keyUser, int maxLevel, int userLevel, int indexUser) {
    element_t Z1;
    element_init_G2(Z1, pairing);
    element_t GUi;
    element_init_G1(GUi, pairing);
    element_add(GUi, params.ga, params.U[indexUser]);

    for(int i = 1; i <= maxLevel;i++) {

    }

}