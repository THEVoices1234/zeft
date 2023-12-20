cmake_minimum_required(VERSION 3.26)
project(M1BASE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M1BASE
        Ammo.h
        Character.h
        DemolitionHero.h
        Game.h
        GhostMonster.h
        GUN.h
        GUN_SUB.h
        Hero.h
        Item.h
        MedicHero.h
        Monster.h
        Object.h
        Potion.h
        TankMonster.h
        EXEC.cpp)
