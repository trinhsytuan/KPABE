//
// Created by Trinh Tuan on 28/05/2024.
//

#include"global_params.h"
#include"KeyGenerator.h"
#ifndef KPABE_ENCRYPT_H
#define KPABE_ENCRYPT_H

vector<element_s> encrypt(pairing_t pairing, global_parameter params, keyUser userKey, vector<vector<element_s> > attribute);
#endif //KPABE_ENCRYPT_H
