// Created by meowwow520 on 2026-11-25       



#include "core/GameManager.h"

int main() {
    GameManager gameManager;
    if (gameManager.Initialize() != 0) {
        return -1;
    }
    return gameManager.Running();
}