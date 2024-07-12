////
//// Created by Trinh Tuan on 28/05/2024.
////
//
#include "KeyGenerator.h"
#include<vector>
#include "attribute.h"
using namespace std;
//
//void initAttribute(pairing_t pairing, keyUser *userKey) {
//    for (int i = 0; i < maxPolicy; i++) {
//        element_init_G1(userKey->au[i], pairing);
//    }
//    for (int i = 0; i < maxPolicy; i++) {
//        for (int j = 0; j < maxLevel; j++) {
//            element_init_Zr(userKey->tij[i][j], pairing);
//            element_random(userKey->tij[i][j]);
//        }
//    }
//}
//
//void
//genKeyForUser(pairing_t pairing, keyUser *userKey, public_parametter publicParametter, element_t alpha, element_t beta,
//              element_t g) {
////    for(int i = 0; i < maxPolicy;i++) {
////        for(int j = 0; j < maxLevel;j++) {
////            element_t ts;
////            element_init_Zr(ts, pairing);
////            element_add(ts, beta, publicParametter.e[i][j]);
////            element_t tempmau;
////            element_init_Zr(tempmau, pairing);
////            element_add(tempmau, alpha, publicParametter.U[i]);
////            element_pow_zn(tempmau, alpha, userKey->au[i][j]);
////            element_pow_zn(tempmau, g, tempmau);
////            element_init_Zr(userKey->du[i][j], pairing);
////            element_div(userKey->du[i][j], ts, tempmau);
////            //element_printf("%B\n", userKey->du[i][j]); nnnnnn
////        }
////    }
//    for (int i = 0; i < maxPolicy; i++) {
//        for (int j = 0; j < maxLevel; j++) {
//            element_t ts;
//            element_init_Zr(ts, pairing);
//            element_add(ts, beta, publicParametter.e[i][j]);
//            element_t tempmau;
//            element_init_Zr(tempmau, pairing);
//            element_add(tempmau, alpha, publicParametter.U[i]);
//            element_pow_zn(tempmau, alpha, userKey->tij[i][j]);
//            element_pow_zn(tempmau, g, tempmau);
//            element_init_Zr(userKey->du[i][j], pairing);
//            element_div(userKey->du[i][j], ts, tempmau);
//            //element_printf("%B\n", userKey->du[i][j]); nnnnnn
//        }
//    }
//}
void genkeyForOneUser(pairing_t pairing, int indexUser, global_parameter params, keyUser* keyUser) {
    int n = 2;
    element_s* attr[2][2] = {{params.U[0], params.U[1]},{params.U[2], params.U[3]}};

    int level[] = {3,3};

    for(int i = 0; i < 2;i++) {
        element_t betaaddEu;
        element_init_Zr(betaaddEu, pairing);
        element_add(betaaddEu, params.beta, params.e[indexUser][i]);
        element_t kqTich;
        element_init_Zr(kqTich, pairing);
        element_set1(kqTich);
        for(int j = 0; j < 2;j++) {
            element_t alphaAddUi;
            element_init_Zr(alphaAddUi, pairing);
            element_add(alphaAddUi, params.alpha, attr[i][j]);
            element_t mu;
            element_init_Zr(mu, pairing);
            element_set_si(mu, level[i]);
            element_pow_zn(alphaAddUi, alphaAddUi, mu);
            element_mul(kqTich, kqTich, alphaAddUi);
        }
        element_t gTempPow;
        element_init_G1(gTempPow, pairing);
        element_pow_zn(gTempPow, params.g, kqTich);
        element_init_G1(keyUser->du[i], pairing);
        element_div(keyUser->du[i], betaaddEu, gTempPow);
    }
}

