// Created By MeowWow520 in 202611252313
#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <SDL3/SDL.h>
#include <glm/glm.hpp>


class Object {
protected:
    std::string m_strObjectName{"Default Object Name"};
    glm::vec2 m_v2WorldPosition{0.0f, 0.0f};
    glm::vec2 m_v2ScreenPosition{0.0f, 0.0f};

public:
    Object();
    ~Object();

    virtual void Initialize();
    virtual void Update();
    virtual void HandleEvents(SDL_Event& event);
    virtual void Render();
    virtual void Destroy();
};

#endif // OBJECT_H