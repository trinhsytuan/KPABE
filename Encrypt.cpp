//
// Created by Trinh Tuan on 28/05/2024.
//

#include<iostream>
#include"Encrypt.h"
using namespace std;
void pow(element_t &t1, int sl){
    for(int i = 1; i <= sl;i++) {
        element_pow_zn(t1, t1, t1);
    }
}
element_t* powElement(element_t t1, element_t t2, int tongmu){

    for(int i = 1; i <= tongmu;i++) {


    }
}
void encrypt(pairing_t pairing, public_parametter publicParametter) {
    element_t s;
    element_init_Zr(s, pairing);
    element_random(s);
    element_t kem;
    element_init_GT(kem, pairing);
    pairing_apply(kem, publicParametter.g, publicParametter.gaPow[1][1], pairing);
    element_pow_zn(kem, kem, s);
    //element_printf("%B\n", kem);
    element_t C0;
    element_init_G1(C0, pairing);
    element_t temp;
    element_init_G1(temp, pairing);
    element_pow_zn(temp, publicParametter.g, s);
    element_mul(C0, temp, publicParametter.gAlpha);
    element_printf("%B\n", C0);
    element_invert(C0, C0);
    element_printf("%B\n", C0);
    element_t C1;
    element_init_G2(C1, pairing);

}