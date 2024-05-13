cmake_minimum_required(VERSION 3.28)
project(MBSearch C)

set(CMAKE_C_STANDARD 23)

add_executable(MBSearcg_ main.c
        commands.h
        boolean.h
        commands.c
        avl.h
        avl.c
        MarketBasket.h
        MarketBasket.c
        associativeArr.h
        associativeArr.c
)
