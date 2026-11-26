// Created by meowwow520 on 2026-11-25       

#pragma once
#ifndef BASEENTITY_H
#define BASEENTITY_H

#include "Object.h"
#include "EntityPrama.h"


class BaseEntity : public Object {
protected:
    std::string m_strEntityName{"Default Entity Name"};
    EntityPrama m_EntityPrama{};

public:
    BaseEntity();
    ~BaseEntity();
};
#endif // BASEENTITY_H