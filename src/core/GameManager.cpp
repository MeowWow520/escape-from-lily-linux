// Created by meowwow520 on 2026-11-26       



#include "GameManager.h"

int GameManager::Initialize() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }
    if (m_GameCtx.Initialize() != 0) {
        SDL_Quit();
        return -1;
    }
    AttachGameContext(m_GameCtx.GetGameContext());
    return 0;
}

int GameManager::Running() {
    SDL_Event event;
    while (Context().windowCtx.isRunning) {
        auto &ctx = Context().windowCtx;
        Uint64 currentFrameTime = SDL_GetPerformanceCounter();

        ctx.deltatime = static_cast<float>(currentFrameTime - ctx.lastFrameTime) / SDL_GetPerformanceFrequency();
        ctx.deltatime = std::min(ctx.deltatime, 0.1f);
        ctx.lastFrameTime = currentFrameTime;
        while (SDL_PollEvent(&event)) {
            HandleEvents(event);
        }
        Update();
        Render();
    }
    Destroy();
    return 0;
}

int GameManager::HandleEvents(SDL_Event& event) {
    if (event.type == SDL_EVENT_QUIT) {
        Context().windowCtx.isRunning = false;
    }
    return 0;
}

int GameManager::Update() {
    return 0;
}
int GameManager::Render() {
    SDL_Renderer* renderer = Context().windowCtx.renderer;
    if (renderer == nullptr) {
        return -1;
    }
    SDL_SetRenderDrawColor(renderer, 0x1A, 0x1A, 0x2E, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return 0;
}
int GameManager::Destroy() {
    m_GameCtx.Destroy();
    SDL_Quit();
    return 0;
}