////
//// Created by Trinh Tuan on 28/05/2024.
////
//
//#include<iostream>
//#include"Encrypt.h"
//#include"utils/utils.h"
//using namespace std;
//void encrypt(pairing_t pairing, public_parametter publicParametter, int *thuoctinh, int lengtt, int level) {
//    element_t s;
//    element_init_Zr(s, pairing);
//    element_random(s);
//    element_t kem;
//    element_init_GT(kem, pairing);
//    pairing_apply(kem, publicParametter.g, publicParametter.gaPow[1][1], pairing);
//    element_pow_zn(kem, kem, s);
//    //element_printf("%B\n", kem);
//    element_t C0;
//    element_init_G1(C0, pairing);
//    element_t temp;
//    element_init_G1(temp, pairing);
//    element_pow_zn(temp, publicParametter.g, s);
//    element_mul(C0, temp, publicParametter.gAlpha);
//    //element_printf("%B\n", C0);
//    element_invert(C0, C0);
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
//
//}