// Created by meowwow520 on 2026-11-25       

#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <SDL3/SDL.h>



class Object {

public:
    Object();
    ~Object();

    virtual int Initialize();
    virtual int Update();
    virtual int HandleEvents(SDL_Event& event);
    virtual int Render();
    virtual int Destroy();
};

#endif // OBJECT_H