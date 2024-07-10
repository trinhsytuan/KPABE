//
// Created by Trinh Tuan on 10/7/24.
//
#include"attribute.h"

vector<vector<std::string> > generateAttributes() {
    vector<vector<string> > attributes;

    vector<string> att1 = {"Computer science", "Trieu Son District"};
    vector<string> att2 = {"Mathematics", "Thanh Hoa Province"};
    vector<string> att3 = {"Deputy", "Male"};
    vector<string>att4= {"Att4", "4"};
    vector<string> att5 = {"Att5", "5"};
    vector<string>att6 = {"Att6", "v6"};

    attributes.push_back(att1);
    attributes.push_back(att2);
    attributes.push_back(att3);
    attributes.push_back(att4);
    attributes.push_back(att5);
    attributes.push_back(att6);


    return attributes;
}