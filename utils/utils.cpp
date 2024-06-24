//
// Created by Trinh Tuan on 27/05/2024.
//

#include<pbc.h>
#include<iostream>
using namespace std;
const int maxLevel = 5;
bool checkPolicy(char policy, const char* policyarr[], int arrPolicySize) {
    return true;
}
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int kq = 1;
        for(int i = 1;i<=n;i++) kq *= i;
    }
}

long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
element_t* powCoefficient(element_t s1, element_t s2, pairing_t pairing){
    element_t mupow, nk, k;
    element_t xpownk, gk, temp;
    element_t *res = (element_t *)malloc(sizeof(element_t));
    if (res == NULL) {
        return NULL;
    }
    element_init_G1(mupow, pairing);
    element_init_G1(xpownk, pairing);
    element_init_G1(gk, pairing);
    element_init_G1(*res, pairing);
    element_init_G1(nk, pairing);
    element_init_G1(k, pairing);
    element_init_G1(temp, pairing);
    element_set1(temp);
    element_set0(*res);
    for(int i = 0; i <= maxLevel;i++) {
        element_set_si(mupow, binomialCoefficient(maxLevel, i));
        element_set_si(nk, maxLevel - i);
        element_set_si(k, i);
        element_pow_zn(xpownk, s1, nk);
        element_pow_zn(gk, s2, k);
        element_mul(temp, xpownk, gk);
        element_add(*res, *res, temp);
    }
    return res;
}