//
// Created by Trinh Tuan on 28/05/2024.
//

#ifndef KPABE_UTILS_H
#define KPABE_UTILS_H
bool checkPolicy(char policy, const char* policyarr[], int arrPolicySize);
int factorial(int n);
int binomialCoefficient(int n, int k);
void powCoefficient(element_t s1, element_t s2, pairing_t pairing, element_t kq);
void vietaFormular(element_t *roots, int n, element_t *saved, pairing_t pairing) ;
#endif //KPABE_UTILS_H
