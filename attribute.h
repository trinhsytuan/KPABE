//
// Created by Trinh Tuan on 27/05/2024.
//

#ifndef KPABE_ATTRIBUTE_H
#define KPABE_ATTRIBUTE_H

const char* attributesTable[] = {"Dean", "Deputy dean", "Lecture", "Computer science", "Information system", "Head of section"};

const char* dummpTable[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

int getSizeAttributesTable(){
    return sizeof(attributesTable) / sizeof(attributesTable[0]);
}

int getDummpTable() {
    return sizeof(dummpTable) / sizeof(dummpTable[0]);
}

#endif //KPABE_ATTRIBUTE_H
