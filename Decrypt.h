//
// Created by Trinh Tuan on 01/07/2024.
//
#include<pbc.h>
#include"global_params.h"
#include"KeyGenerator.h"
#ifndef KPABE_DECRYPT_H
#define KPABE_DECRYPT_H
void decrypt(pairing_t pairing, global_parameter params, element_t C1, element_t C2, keyUser keyUser, int level);
#endif //KPABE_DECRYPT_Hx
