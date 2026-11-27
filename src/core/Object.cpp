// Created by MeowWow520 on 2026-11-27

#include "Object.h"



void Object::AttachGameContext(GameContext& context) {
    m_pGameContext = &context;
}

GameContext& Object::Context() const {
    SDL_assert(m_pGameContext != nullptr);
    return *m_pGameContext;
}

int Object::Initialize() { return 0; }
int Object::HandleEvents(SDL_Event& event) { 
    (void)event;
    return 0;
}
int Object::Render() { return 0; }
int Object::Update() { return 0; }
int Object::Destroy() { return 0; }