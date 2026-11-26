// Created by meowwow520 on 2026-11-25      

#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SDL3/SDL.h>



class GameManager {
public:
    static GameManager& GetInstance() {
        static GameManager instance;
        return instance;
    }
    ~GameManager() = default;

protected:
    int Initialize();
    int Update();
    int HandleEvents(SDL_Event& event);
    int Render();
    int Destroy();

private:
    GameManager() = default;
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
};

#endif // GAMEMANAGER_H