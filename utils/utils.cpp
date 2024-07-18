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
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
void powCoefficient(element_t s1, element_t s2, pairing_t pairing, element_t kq){
    //S1 là g1, s2 là Zr
    element_t mupow, nk, k;
    element_t xpownk, gk, temp;
    element_t res;
    element_init_Zr(mupow, pairing);
    element_init_G2(xpownk, pairing);
    element_init_G2(gk, pairing);
    element_init_G2(res, pairing);
    element_init_Zr(nk, pairing);
    element_init_Zr(k, pairing);
    element_init_G2(temp, pairing);
    element_set1(temp);
    element_set0(res);

    for(int i = 0; i <= maxLevel;i++) {
        element_set_si(mupow, binomialCoefficient(maxLevel, i));
        element_set_si(nk, maxLevel - i);
        element_set_si(k, i);

        element_pow_zn(xpownk, s1, nk);
        element_pow_zn(gk, s2, k);
        element_mul(temp, xpownk, gk);
        element_add(res, res, temp);
    }
    element_set(kq, res);

}
void vietaFormular(element_t *roots, int n, element_t *saved, pairing_t pairing) {
    element_t coeff[n + 1];

    for(int i = 0; i <= n;i++) {
        element_init_Zr(coeff[i], pairing);
        element_set0(coeff[i]);
    }

    // Set highest order coefficient as 1
    element_set1(coeff[0]);


    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j > 0; j--) {
            element_t temp;
            element_init_Zr(temp, pairing);
            element_mul(temp, roots[i], coeff[j-1]);
            element_add(coeff[j], coeff[j], temp);
        }
    }


    for (int i = n; i >= 0; i--) {
        element_init_Zr(saved[i], pairing);
        element_set(saved[i], coeff[i]);
    }
}
