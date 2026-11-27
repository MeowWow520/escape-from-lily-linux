// Created by MeowWow520 on 2026-11-27
#pragma once
#ifndef GAMECTX_H
#define GAMECTX_H

#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include <glm/fwd.hpp>



struct GameWindowCtx {
    bool isRunning{false};
    const char* title{"thereisnotitle"};
    float deltatime{0};
    Uint64 lastFrameTime{0};
    glm::vec2 logicalSize{0,0};
    glm::vec2 resizedSize{0,0};
    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};
};
struct GameManagerCtx {
    // some other ctx shared between game classes
}; 
struct GameContext {
    GameWindowCtx windowCtx;
    GameManagerCtx managerCtx;
};

class GameCtx {
public:
    GameCtx() = default;
    ~GameCtx() = default;
    GameCtx(const GameCtx&) = delete;
    GameCtx& operator=(const GameCtx&) = delete;

    GameContext& GetGameContext() { return m_GameContext; }
    const GameContext& GetGameContext() const { return m_GameContext; }

    int Initialize();
    int Destroy();

private:
    GameContext m_GameContext{};
};

#endif // GAMECTX_H