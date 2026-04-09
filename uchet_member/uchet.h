#pragma once
#include <string>
#include <Windows.h>

using namespace std;

#ifndef UCHET_H
#define UCHET_H

// Пространство имён для цветов (как в joitoy.h)
namespace crt {
    const int COLOR_BLACK = 0;
    const int COLOR_BLUE = 1;
    const int COLOR_GREEN = 2;
    const int COLOR_CYAN = 3;
    const int COLOR_RED = 4;
    const int COLOR_MAGENTA = 5;
    const int COLOR_BROWN = 6;
    const int COLOR_GRAY = 7;
    const int COLOR_DARK_GRAY = 8;
    const int COLOR_LIGHT_BLUE = 9;
    const int COLOR_LIGHT_GREEN = 10;
    const int COLOR_LIGHT_CYAN = 11;
    const int COLOR_LIGHT_RED = 12;
    const int COLOR_LIGHT_MAGENTA = 13;
    const int COLOR_YELLOW = 14;
    const int COLOR_WHITE = 15;
}

// Функции для работы с цветом
inline void SetTextColor(int color, int background = crt::COLOR_BLACK) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color | (background << 4));
}

inline void ResetColor() {
    SetTextColor(crt::COLOR_GRAY, crt::COLOR_BLACK);
}

struct Member {
    int ticketNumber;
    string lastName;
    string firstName;
    string patronymic;
    string joinDate;
    double totalFees;
    Member* next;

    Member() : ticketNumber(0), totalFees(0.0), next(nullptr) {}
};

extern Member* firstMember;

#endif#pragma once
