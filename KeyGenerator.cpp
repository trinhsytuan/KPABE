//
// Created by Trinh Tuan on 28/05/2024.
//

#include "KeyGenerator.h"
#include"global_params.h"
using namespace std;
void initAttribute(pairing_t pairing, keyUser* userKey) {
    for(int i = 0; i < maxPolicy;i++) {
        for(int j = 0; j < maxLevel;j++) {
            element_init_Zr(userKey->au[i][j], pairing);
            element_random(userKey->au[i][j]);
        }
    }

}
void genKeyForUser(pairing_t pairing, keyUser* userKey, public_parametter publicParametter, element_t alpha, element_t beta, element_t g) {
    for(int i = 0; i < maxPolicy;i++) {
        for(int j = 0; j < maxLevel;j++) {
            element_t ts;
            element_init_Zr(ts, pairing);
            element_add(ts, beta, publicParametter.e[i][j]);
            element_t tempmau;
            element_init_Zr(tempmau, pairing);
            element_add(tempmau, alpha, publicParametter.U[i]);
            element_pow_zn(tempmau, alpha, userKey->au[i][j]);
            element_pow_zn(tempmau, g, tempmau);
            element_init_Zr(userKey->du[i][j], pairing);
            element_div(userKey->du[i][j], ts, tempmau);
            //element_printf("%B\n", userKey->du[i][j]);
        }
    }

}