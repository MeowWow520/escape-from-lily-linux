// Created by meowwow520 on 2026-11-25       
#pragma once
#ifndef ENTITYPRAMA_H
#define ENTITYPRAMA_H

#include <string>
#include <cmath>
#include <glm/glm.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_blendmode.h>
#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float4.hpp>



struct RenderPrama {
    bool IsTextureDirty{false};
    bool IsVisible{false};
    bool IsMirror{false};
    float Rotation{0.0f}; // Define in 360
    // Hitbox .xy = box center, .wh = box wigth and height
    SDL_FRect Hitbox{0.0f,0.0f,0.0f,0.0f};
    glm::vec2 OriginalSize{0.0f,0.0f};
    // Scale .xy = scale center, .wh = scale level in diff
    glm::vec4 Scale{1.0f,1.0f,0.5f,0.5f};
    SDL_Texture* SDLTexture{nullptr};
    SDL_Color SDLColor{0x00,0x00,0x00,0x00};
    SDL_BlendMode SDLBlendMode{SDL_BLENDMODE_BLEND};
    std::string TexturePath{"./assets"};
};

struct EntityGame {
    float Health{0.0f};
    float CurrentSpeed{0.0f};
    glm::vec2 Direction{0.0f,0.0f};
    glm::vec4 Position{0.0f,0.0f,0.0f,0.0f};
    std::string Name{"thereisnoname"};
};

struct EntityPrama {
    RenderPrama Renders{};
    EntityGame Games{};
};

#endif // ENTITYPRAMA_H