#pragma once                      // Директива: гарантирует, что заголовочный файл будет подключен только один раз
#include <string>                 // Подключение библиотеки для работы со строками (string)
#include <Windows.h>              // Подключение Windows API для работы с консолью (цвета, дескрипторы)

using namespace std;              // Использование стандартного пространства имён

#ifndef UCHET_H                   // Начало инклюз-гарда: если UCHET_H не определён
#define UCHET_H                   // Определяем UCHET_H, чтобы предотвратить повторное подключение

// Пространство имён для цветов (как в joitoy.h)
namespace crt {                   // Объявление пространства имён crt (console color types)
    const int COLOR_BLACK = 0;        // Чёрный цвет (обычно для фона)
    const int COLOR_BLUE = 1;         // Синий цвет
    const int COLOR_GREEN = 2;        // Зелёный цвет
    const int COLOR_CYAN = 3;         // Голубой (циан) цвет
    const int COLOR_RED = 4;          // Красный цвет
    const int COLOR_MAGENTA = 5;      // Пурпурный (маджента) цвет
    const int COLOR_BROWN = 6;        // Коричневый/тёмно-жёлтый цвет
    const int COLOR_GRAY = 7;         // Светло-серый (стандартный цвет текста)
    const int COLOR_DARK_GRAY = 8;    // Тёмно-серый (яркий чёрный)
    const int COLOR_LIGHT_BLUE = 9;   // Ярко-синий цвет
    const int COLOR_LIGHT_GREEN = 10; // Ярко-зелёный цвет
    const int COLOR_LIGHT_CYAN = 11;  // Ярко-голубой цвет
    const int COLOR_LIGHT_RED = 12;   // Ярко-красный (розовый) цвет
    const int COLOR_LIGHT_MAGENTA = 13; // Ярко-пурпурный цвет
    const int COLOR_YELLOW = 14;      // Жёлтый цвет
    const int COLOR_WHITE = 15;       // Белый цвет
}

// Функции для работы с цветом
inline void SetTextColor(int color, int background = crt::COLOR_BLACK) {
    // Получаем дескриптор стандартного вывода (консоли)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Устанавливаем атрибуты текста: цвет текста | (цвет фона << 4)
    // Сдвиг на 4 бита потому, что цвет фона хранится в старших битах
    SetConsoleTextAttribute(hConsole, color | (background << 4));
}

inline void ResetColor() {
    // Сбрасываем цвет на стандартный: светло-серый текст на чёрном фоне
    SetTextColor(crt::COLOR_GRAY, crt::COLOR_BLACK);
}

// Структура, описывающая члена общества
struct Member {
    int ticketNumber;      // Номер членского билета (уникальный идентификатор)
    string lastName;       // Фамилия члена общества (до 15 символов)
    string firstName;      // Имя члена общества (до 15 символов)
    string patronymic;     // Отчество члена общества (до 15 символов)
    string joinDate;       // Дата вступления в общество (формат ДД.ММ.ГГГГ)
    double totalFees;      // Общая сумма уплаченных взносов (в рублях)
    Member* next;          // Указатель на следующий элемент в связном списке

    // Конструктор по умолчанию: инициализирует поля значениями по умолчанию
    Member() : ticketNumber(0), totalFees(0.0), next(nullptr) {}
};

// Объявление внешней переменной - указателя на первый элемент списка
// Определение находится в файле main.cpp
extern Member* firstMember;

#endif // UCHET_H               // Конец инклюз-гарда
