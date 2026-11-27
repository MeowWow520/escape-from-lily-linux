// Created by MeowWow520 on 2026-11-26
#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <SDL3/SDL.h>
#include "GameCtx.h"



class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    void AttachGameContext(GameContext& context);

    virtual int Initialize();
    virtual int HandleEvents(SDL_Event& event);
    virtual int Render();
    virtual int Update();
    virtual int Destroy();

protected:
    GameContext& Context() const;

private:
    GameContext* m_pGameContext{nullptr};
};
#endif // OBJECT_H