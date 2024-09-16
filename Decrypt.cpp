//
// Created by Trinh Tuan on 01/07/2024.
//
#include"Decrypt.h"
#include"utils/utils.h"
#include<vector>
void decrypt(pairing_t pairing, global_parameter params, element_t C1, element_t C2, keyUser keyUser, int maxLevel, int userLevel, int indexUser, vector<vector<element_s> > attribute) {
    element_s* attr[2][2] = {{params.U[0], params.U[1]}, {params.U[2], params.U[3]}};
    element_t Z1;
    element_init_G2(Z1, pairing);
    element_t Ui[1000];
    int num = 0;
    for (int i = 0; i < 1; i++) { //Attribute one can decrypt, replace and process if you encrypt > 1 Attribute
        for (int j = 0; j < attribute[i].size(); j++) {
            for (int k = 0; k < maxLevel - userLevel; k++) { //3 is level DNF, replace
                element_init_Zr(Ui[num], pairing);
                element_set(Ui[num], &attribute[i][j]);
                num++;
            }
        }
    }

    for(int i = 0; i < 2;i++) {
        for(int k = 0; k < 3;k++) {
            element_init_Zr(Ui[num], pairing);
            element_set(Ui[num], attr[1][i]);
            num++;
        }
    }

    element_t res1[1000];
    vietaFormular(Ui, num, res1, pairing);



}