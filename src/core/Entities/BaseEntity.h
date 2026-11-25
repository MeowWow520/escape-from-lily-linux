// Created By MeowWow520 in 202611252324
#pragma once
#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "Object.h"



class BaseEntity : public Object {
protected:
    std::string m_strEntityName{"Default Entity Name"};

public:
    BaseEntity();
    ~BaseEntity();
};
#endif // BASEENTITY_H