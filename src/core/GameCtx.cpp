// Created by MeowWow520 on 2026-11-27

#include "GameCtx.h"



int GameCtx::Initialize() {
    auto& w = m_GameContext.windowCtx;
    w.isRunning = false;
    w.logicalSize = glm::vec2(800, 600);
    w.title = "Escape from Lily";
    
    w.window = SDL_CreateWindow(
        w.title,
        static_cast<int>(w.logicalSize.x),
        static_cast<int>(w.logicalSize.y),
        SDL_WINDOW_RESIZABLE);
    if (!w.window) return -1;

    w.renderer = SDL_CreateRenderer(w.window, nullptr);
    SDL_SetRenderVSync(w.renderer, 1);
    if (!w.renderer) {
        SDL_DestroyWindow(w.window);
        w.window = nullptr;
        return -1;
    }

    w.lastFrameTime = SDL_GetPerformanceCounter();
    SDL_SetRenderLogicalPresentation(w.renderer, 800, 600, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    w.isRunning = true;
    return 0;
}

int GameCtx::Destroy() {
    auto& w = m_GameContext.windowCtx;
    w.isRunning = false;
    if (w.renderer) { SDL_DestroyRenderer(w.renderer); w.renderer = nullptr; }
    if (w.window)   { SDL_DestroyWindow(w.window);     w.window = nullptr; }
    return 0;
}