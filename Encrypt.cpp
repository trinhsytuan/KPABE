////
//// Created by Trinh Tuan on 28/05/2024.
////
//
#include<iostream>
#include<vector>
#include"Encrypt.h"
#include"utils/utils.h"

using namespace std;

void encrypt(pairing_t pairing, global_parameter params, keyUser userKey, vector<vector<element_s> > attribute) {
    element_t s;
    element_init_Zr(s, pairing);
    element_random(s);
    element_t kem;
    element_init_GT(kem, pairing);
    pairing_apply(kem, params.g, params.ga, pairing);
    element_pow_zn(kem, kem, s);
    element_t C0;
    element_init_G1(C0, pairing);
    element_pow_zn(C0, params.ga, s);
    element_invert(C0, C0);
    element_t AllUiPow[10000];
    element_t UiParamsSaved[10000];
    int n = 0;
    //test



    for (int i = 0; i < 1; i++) { //Attribute one can decrypt, replace and process if you encrypt > 1 Attribute
        for (int j = 0; j < attribute[i].size(); j++) {
            for (int k = 0; k < 3; k++) { //3 is level DNF, replace
                element_init_Zr(AllUiPow[n], pairing);
                element_set(AllUiPow[n], &attribute[i][j]);
                n++;
            }
        }
    }


    vietaFormular(AllUiPow, n, UiParamsSaved, pairing);
    element_t gaTemp;
    element_init_G2(gaTemp, pairing);
    //element_set(gaTemp, params.gaPow[1][0]);


    element_t C1;
    element_init_G2(C1, pairing);
    for (int i = n - 1; i > 0; i--) {
        //element_printf("%B\n", UiParamsSaved[i]);
        element_mul(gaTemp, gaTemp, params.gaPow[1][0]);
       // element_printf("%B\n%B\n", gaTemp, params.gaPow[2][0]);
        element_t tinhTemp;
        element_init_G2(tinhTemp, pairing);
        element_pow_zn(tinhTemp, gaTemp, UiParamsSaved[i]);

        element_mul(C1, C1, tinhTemp);

    }
    element_mul(gaTemp, gaTemp, params.gaPow[1][0]);
    element_mul(C1, C1, gaTemp);
    element_t notAlpha;
    element_init_G2(notAlpha, pairing);
    element_pow_zn(notAlpha, params.ga, UiParamsSaved[n]);
    element_mul(C1, C1, notAlpha);
    element_pow_zn(C1, C1, s);
    element_printf("%B\n%B\n", C0, C1);



//    //element_printf("%B\n", kem);
//    element_t C0;
//    element_init_G1(C0, pairing);
//    element_t temp;
//    element_init_G1(temp, pairing);
//    element_pow_zn(temp, publicParametter.g, s);
//    element_mul(C0, temp, publicParametter.gAlpha);
//    //element_printf("%B\n", C0);
//
//    //element_printf("%B\n", C0);
//    element_t C1;
//    element_init_G2(C1, pairing);
//    element_t tichnhan, temp1;
//    element_init_G2(tichnhan, pairing);
//    element_init_G2(temp1, pairing);
//    for(int i = 0; i < lengtt;i++) {
//        powCoefficient(publicParametter.gaPow[1][0], publicParametter.U[i], pairing, temp1);
//
//        element_t temptam;
//        element_init_Zr(temptam, pairing);
//        element_set_si(temptam, level);
//        element_pow_zn(temp1,temp1, temptam);
//
//        element_mul(tichnhan,tichnhan,temp1);
//    }
//    element_pow_zn(C1,tichnhan,s);
//    element_printf("%B\n", C0);
//    element_printf("%B\n", C1);

}