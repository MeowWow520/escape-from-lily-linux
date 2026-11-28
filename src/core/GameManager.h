// Created by meowwow520 on 2026-11-25      

#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <spdlog/spdlog.h>
#include "Object.h"



class GameManager : public Object {
public:
    GameManager() = default;
    ~GameManager() = default;
    
    int Running();

    int Initialize() override;
    int HandleEvents(SDL_Event& event) override;
    int Update() override;
    int Render() override;
    int Destroy() override;

protected:

private:
    GameCtx m_GameCtx;
};

#endif // GAMEMANAGER_H