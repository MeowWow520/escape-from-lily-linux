// Created by meowwow520 on 2026-11-25       

#include "core/Logger.h"
#include "core/GameManager.h"



int main() {
    spdlog::set_level(spdlog::level::info);
    
    GameManager gameManager;
    Logger(spdlog::level::info, gameManager.Initialize(), "GameManager Initialize()");
    return gameManager.Running();
}