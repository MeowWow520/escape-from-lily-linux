// Created by MeowWow520 on 2026-11-27

#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>



#define Logger(lvl, flags, msg) \
    if (flags) {                \
        spdlog::error(msg);     \
        return -1; }            \
    spdlog::log(lvl, msg);      \


#endif // LOGGER_H