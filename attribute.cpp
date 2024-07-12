//
// Created by Trinh Tuan on 10/7/24.
//
#include"attribute.h"

vector<vector<element_s>> generateAttributes(global_parameter params) {
    vector<vector<element_s>> attributes;

    vector<element_s> att1 = {params.U[1], params.U[0]};
    vector<element_s> att2 = {params.U[0], params.U[2]};


    // Add the generated attribute to the attributes vector
    attributes.push_back(att1);
    attributes.push_back(att2);


    return attributes;
}

