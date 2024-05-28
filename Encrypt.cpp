//
// Created by Trinh Tuan on 28/05/2024.
//

#include<iostream>
#include"Encrypt.h"
using namespace std;

void encrypt(pairing_t pairing, public_parametter publicParametter) {
    element_t s;
    element_init_Zr(s, pairing);
    element_random(s);
    element_t kem;
    element_init_GT(kem, pairing);
    pairing_apply(kem, publicParametter.g, publicParametter.gaPow[1][1], pairing);
    element_pow_zn(kem, kem, s);
    element_printf("%B\n", kem);


}