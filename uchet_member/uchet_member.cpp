#include <iostream>     // Подключение библиотеки для ввода/вывода (cin, cout)
#include <conio.h>      // Подключение библиотеки для _getch() (ожидание нажатия клавиши)
#include <fstream>      // Подключение библиотеки для работы с файлами (ifstream, ofstream)
#include <string>       // Подключение библиотеки для работы со строками (string)
#include <Windows.h>    // Подключение Windows API для работы с консолью (цвета, кодировка)
#include "uchet.h"      // Подключение пользовательского заголовочного файла со структурой Member и цветами

using namespace std;    // Использование стандартного пространства имён

Member* firstMember = nullptr;  // Глобальный указатель на первый элемент связного списка (изначально пустой)

// Функция авторизации пользователя
bool LOGIN_IN() {
    string login;       // Переменная для хранения введённого логина
    string password;    // Переменная для хранения введённого пароля

    while (true) {      // Бесконечный цикл до успешного входа
        system("cls");  // Очистка экрана консоли
        SetTextColor(crt::COLOR_YELLOW);    // Установка жёлтого цвета текста
        cout << "ВХОД В СИСТЕМУ\n\n";       // Вывод заголовка
        ResetColor();   // Сброс цвета текста на стандартный

        SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
        cout << "Введите логин: ";              // Запрос логина
        ResetColor();                           // Сброс цвета
        getline(cin, login);                    // Ввод строки логина

        SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
        cout << "Введите пароль: ";             // Запрос пароля
        ResetColor();                           // Сброс цвета
        getline(cin, password);                 // Ввод строки пароля

        // Проверка введённых данных с жёстко заданными учётными данными
        if (login == "admin" && password == "12345") {
            SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
            cout << "\nУспешный вход! Добро пожаловать, " << login << "." << endl;  // Сообщение об успехе
            ResetColor();                           // Сброс цвета
            _getch();                               // Ожидание нажатия любой клавиши
            return true;                            // Возврат успешного результата
        }
        else {
            SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
            cout << "\nОшибка: Неверный логин или пароль." << endl;   // Сообщение об ошибке
            cout << "Попробуйте еще раз.\n";        // Предложение повторить попытку
            ResetColor();                           // Сброс цвета
            cout << "Нажмите любую клавишу...";     // Приглашение нажать клавишу
            _getch();                               // Ожидание нажатия
        }
    }
}

// Функция добавления нового члена общества
void AddData() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_LIGHT_MAGENTA);     // Установка ярко-пурпурного цвета
    cout << "----ДОБАВИТЬ ЧЛЕНА ОБЩЕСТВА----\n\n";   // Заголовок
    ResetColor();   // Сброс цвета

    Member* member = new Member();  // Выделение памяти под нового члена (динамическая память)

    SetTextColor(crt::COLOR_MAGENTA);    // Установка пурпурного цвета
    cout << "Номер членского билета: ";  // Запрос номера билета
    ResetColor();                        // Сброс цвета
    cin >> member->ticketNumber;         // Ввод числа в поле ticketNumber
    cin.ignore();                        // Очистка буфера ввода (удаление символа новой строки)

    SetTextColor(crt::COLOR_MAGENTA);    // Установка пурпурного цвета
    cout << "Фамилия (до 15 символов): "; // Запрос фамилии
    ResetColor();                        // Сброс цвета
    getline(cin, member->lastName);      // Ввод строки фамилии
    if (member->lastName.length() > 15)  // Если длина больше 15 символов
        member->lastName = member->lastName.substr(0, 15);  // Обрезать до 15 символов

    SetTextColor(crt::COLOR_MAGENTA);    // Установка пурпурного цвета
    cout << "Имя (до 15 символов): ";    // Запрос имени
    ResetColor();                        // Сброс цвета
    getline(cin, member->firstName);     // Ввод строки имени
    if (member->firstName.length() > 15) // Если длина больше 15 символов
        member->firstName = member->firstName.substr(0, 15);  // Обрезать до 15 символов

    SetTextColor(crt::COLOR_MAGENTA);    // Установка пурпурного цвета
    cout << "Отчество (до 15 символов): "; // Запрос отчества
    ResetColor();                        // Сброс цвета
    getline(cin, member->patronymic);    // Ввод строки отчества
    if (member->patronymic.length() > 15) // Если длина больше 15 символов
        member->patronymic = member->patronymic.substr(0, 15);  // Обрезать до 15 символов

    SetTextColor(crt::COLOR_MAGENTA);    // Установка пурпурного цвета
    cout << "Дата вступления (ДД.ММ.ГГГГ): "; // Запрос даты вступления
    ResetColor();                        // Сброс цвета
    getline(cin, member->joinDate);      // Ввод строки даты

    SetTextColor(crt::COLOR_MAGENTA);    // Установка пурпурного цвета
    cout << "Общая сумма уплаченных взносов: "; // Запрос суммы взносов
    ResetColor();                        // Сброс цвета
    cin >> member->totalFees;            // Ввод вещественного числа

    member->next = firstMember;  // Новый элемент указывает на текущий первый элемент
    firstMember = member;        // Теперь новый элемент становится первым

    SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
    cout << "\nЧлен общества успешно добавлен!" << endl;   // Сообщение об успехе
    ResetColor();                           // Сброс цвета
    _getch();                               // Ожидание нажатия клавиши
}

// Функция вывода всех членов общества
void PrintData() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_YELLOW);    // Установка жёлтого цвета
    cout << "----СПИСОК ЧЛЕНОВ ОБЩЕСТВА----\n\n";   // Заголовок
    ResetColor();   // Сброс цвета

    if (firstMember == nullptr) {   // Если список пуст
        SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
        cout << "Список пуст!\n";               // Сообщение о пустоте
        ResetColor();                           // Сброс цвета
    }
    else {
        Member* current = firstMember;  // Указатель для прохода по списку, начинаем с первого
        int count = 0;                  // Счётчик элементов
        while (current != nullptr) {    // Пока не дошли до конца списка
            SetTextColor(crt::COLOR_LIGHT_GREEN);    // Установка ярко-зелёного цвета
            cout << "[" << ++count << "] ";          // Вывод порядкового номера
            ResetColor();                            // Сброс цвета
            cout << "Номер билета: " << current->ticketNumber << endl;   // Вывод номера билета
            cout << "    ФИО: " << current->lastName << " "              // Вывод ФИО
                << current->firstName << " " << current->patronymic << endl;
            cout << "    Дата вступления: " << current->joinDate << endl; // Вывод даты
            SetTextColor(crt::COLOR_LIGHT_CYAN);     // Установка ярко-голубого цвета
            cout << "    Сумма взносов: " << current->totalFees << " руб." << endl; // Вывод суммы
            ResetColor();                            // Сброс цвета
            cout << "-------------------\n";         // Разделительная линия
            current = current->next;                 // Переход к следующему элементу
        }
    }
    cout << "\nНажмите любую клавишу...";   // Приглашение нажать клавишу
    _getch();                               // Ожидание нажатия
}

// Функция поиска члена по номеру билета
void SearchByTicketNumber() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_YELLOW);    // Установка жёлтого цвета
    cout << "----ПОИСК ПО НОМЕРУ БИЛЕТА----\n\n";   // Заголовок
    ResetColor();   // Сброс цвета

    int number;     // Переменная для номера билета
    SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
    cout << "Введите номер билета: ";       // Запрос номера
    ResetColor();                           // Сброс цвета
    cin >> number;                          // Ввод числа

    Member* current = firstMember;  // Указатель для прохода по списку
    bool found = false;             // Флаг нахождения элемента

    while (current != nullptr) {    // Пока не конец списка
        if (current->ticketNumber == number) {  // Если номер совпадает
            SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
            cout << "\nНайден член общества:\n";    // Сообщение о находке
            ResetColor();                           // Сброс цвета
            cout << "Номер билета: " << current->ticketNumber << endl;  // Вывод номера
            cout << "ФИО: " << current->lastName << " "                  // Вывод ФИО
                << current->firstName << " " << current->patronymic << endl;
            cout << "Дата вступления: " << current->joinDate << endl;    // Вывод даты
            SetTextColor(crt::COLOR_LIGHT_CYAN);     // Установка ярко-голубого цвета
            cout << "Сумма взносов: " << current->totalFees << " руб.\n"; // Вывод суммы
            ResetColor();                            // Сброс цвета
            found = true;        // Устанавливаем флаг, что нашли
            break;               // Выход из цикла (нужен только первый найденный)
        }
        current = current->next; // Переход к следующему элементу
    }

    if (!found) {   // Если ничего не нашли
        SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
        cout << "\nЧлен с таким номером не найден!\n";   // Сообщение об ошибке
        ResetColor();                           // Сброс цвета
    }
    cout << "\nНажмите любую клавишу...";   // Приглашение нажать клавишу
    _getch();                               // Ожидание нажатия
}

// Функция поиска членов по фамилии
void SearchByLastName() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_YELLOW);    // Установка жёлтого цвета
    cout << "=== ПОИСК ПО ФАМИЛИИ ===\n\n";    // Заголовок
    ResetColor();   // Сброс цвета

    string lastName;    // Переменная для искомой фамилии
    SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
    cout << "Введите фамилию: ";            // Запрос фамилии
    ResetColor();                           // Сброс цвета
    cin >> lastName;                        // Ввод строки

    Member* current = firstMember;  // Указатель для прохода по списку
    bool found = false;             // Флаг нахождения элементов
    int count = 0;                  // Счётчик найденных

    while (current != nullptr) {    // Пока не конец списка
        if (current->lastName == lastName) {   // Если фамилия совпадает
            SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
            cout << "\n[" << ++count << "] ";       // Вывод порядкового номера
            ResetColor();                           // Сброс цвета
            cout << "Номер билета: " << current->ticketNumber << endl;  // Вывод номера
            cout << "    ФИО: " << current->lastName << " "              // Вывод ФИО
                << current->firstName << " " << current->patronymic << endl;
            cout << "    Дата вступления: " << current->joinDate << endl;    // Вывод даты
            SetTextColor(crt::COLOR_LIGHT_CYAN);     // Установка ярко-голубого цвета
            cout << "    Сумма взносов: " << current->totalFees << " руб.\n"; // Вывод суммы
            ResetColor();                            // Сброс цвета
            found = true;        // Устанавливаем флаг, что нашли хотя бы одного
        }
        current = current->next; // Переход к следующему элементу
    }

    if (!found) {   // Если ничего не нашли
        SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
        cout << "\nЧлены с такой фамилией не найдены!\n";   // Сообщение об ошибке
        ResetColor();                           // Сброс цвета
    }
    cout << "\nНажмите любую клавишу...";   // Приглашение нажать клавишу
    _getch();                               // Ожидание нажатия
}

// Функция поиска членов по дате вступления
void SearchByJoinDate() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_YELLOW);    // Установка жёлтого цвета
    cout << "----ПОИСК ПО ДАТЕ ВСТУПЛЕНИЯ----\n\n";   // Заголовок
    ResetColor();   // Сброс цвета

    string date;    // Переменная для искомой даты
    SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
    cout << "Введите дату (ДД.ММ.ГГГГ): ";  // Запрос даты
    ResetColor();                           // Сброс цвета
    cin >> date;                            // Ввод строки

    Member* current = firstMember;  // Указатель для прохода по списку
    bool found = false;             // Флаг нахождения элементов
    int count = 0;                  // Счётчик найденных

    while (current != nullptr) {    // Пока не конец списка
        if (current->joinDate == date) {   // Если дата совпадает
            SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
            cout << "\n[" << ++count << "] ";       // Вывод порядкового номера
            ResetColor();                           // Сброс цвета
            cout << "Номер билета: " << current->ticketNumber << endl;  // Вывод номера
            cout << "    ФИО: " << current->lastName << " "              // Вывод ФИО
                << current->firstName << " " << current->patronymic << endl;
            cout << "    Дата вступления: " << current->joinDate << endl;    // Вывод даты
            SetTextColor(crt::COLOR_LIGHT_CYAN);     // Установка ярко-голубого цвета
            cout << "    Сумма взносов: " << current->totalFees << " руб.\n"; // Вывод суммы
            ResetColor();                            // Сброс цвета
            found = true;        // Устанавливаем флаг, что нашли хотя бы одного
        }
        current = current->next; // Переход к следующему элементу
    }

    if (!found) {   // Если ничего не нашли
        SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
        cout << "\nЧлены с такой датой вступления не найдены!\n";   // Сообщение об ошибке
        ResetColor();                           // Сброс цвета
    }
    cout << "\nНажмите любую клавишу...";   // Приглашение нажать клавишу
    _getch();                               // Ожидание нажатия
}

// Функция удаления члена по номеру билета
void DeleteData() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_YELLOW);    // Установка жёлтого цвета
    cout << "----УДАЛЕНИЕ ЧЛЕНА ОБЩЕСТВА----\n\n";   // Заголовок
    ResetColor();   // Сброс цвета

    int number;     // Переменная для номера билета
    SetTextColor(crt::COLOR_LIGHT_RED);  // Установка ярко-красного цвета
    cout << "Введите номер билета для удаления: ";   // Запрос номера
    ResetColor();                        // Сброс цвета
    cin >> number;                       // Ввод числа

    if (firstMember == nullptr) {        // Если список пуст
        SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
        cout << "Список пуст!\n";               // Сообщение об ошибке
        ResetColor();                           // Сброс цвета
        _getch();                               // Ожидание нажатия
        return;                                 // Выход из функции
    }

    // Удаление первого элемента списка
    if (firstMember->ticketNumber == number) {
        Member* temp = firstMember;      // Запоминаем указатель на удаляемый элемент
        firstMember = firstMember->next; // Перенаправляем начало списка на следующий элемент
        delete temp;                     // Освобождаем память удаляемого элемента
        SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
        cout << "\nЧлен успешно удален!\n";     // Сообщение об успехе
        ResetColor();                           // Сброс цвета
        _getch();                               // Ожидание нажатия
        return;                                 // Выход из функции
    }

    // Поиск элемента для удаления (не первого)
    Member* current = firstMember;      // Начинаем с первого элемента
    while (current->next != nullptr && current->next->ticketNumber != number) {
        current = current->next;        // Переход к следующему элементу
    }

    if (current->next != nullptr) {     // Если нашли элемент для удаления
        Member* temp = current->next;   // Запоминаем указатель на удаляемый элемент
        current->next = current->next->next;  // Перенаправляем указатель, пропуская удаляемый
        delete temp;                    // Освобождаем память удаляемого элемента
        SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
        cout << "\nЧлен успешно удален!\n";     // Сообщение об успехе
        ResetColor();                           // Сброс цвета
    }
    else {                              // Если не нашли элемент с таким номером
        SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
        cout << "\nЧлен с таким номером не найден!\n";   // Сообщение об ошибке
        ResetColor();                           // Сброс цвета
    }
    _getch();   // Ожидание нажатия клавиши
}

// Функция сохранения данных в файл
bool SaveData() {
    ofstream file("members.txt");   // Открываем файл для записи
    if (!file.is_open()) return false;  // Если не удалось открыть - возвращаем false

    Member* current = firstMember;  // Указатель для прохода по списку
    while (current != nullptr) {    // Пока не конец списка
        // Записываем данные в файл, разделяя поля символом '|'
        file << current->ticketNumber << "|"
            << current->lastName << "|"
            << current->firstName << "|"
            << current->patronymic << "|"
            << current->joinDate << "|"
            << current->totalFees << "\n";
        current = current->next;    // Переход к следующему элементу
    }
    file.close();   // Закрываем файл
    return true;    // Возвращаем успешный результат
}

// Функция загрузки данных из файла
bool LoadData() {
    ifstream file("members.txt");   // Открываем файл для чтения
    if (!file.is_open()) {          // Если файл не существует
        return true;                // Возвращаем true (это нормально для первого запуска)
    }

    // Очищаем текущий список перед загрузкой новых данных
    while (firstMember != nullptr) {
        Member* temp = firstMember;     // Запоминаем указатель на удаляемый элемент
        firstMember = firstMember->next; // Переходим к следующему элементу
        delete temp;                    // Освобождаем память
    }

    string line;    // Переменная для хранения строки из файла
    while (getline(file, line)) {   // Читаем файл построчно
        if (line.empty()) continue; // Пропускаем пустые строки

        Member* member = new Member();  // Выделяем память под нового члена

        size_t pos = 0;         // Текущая позиция в строке
        string token;           // Переменная для хранения очередного поля

        // Лямбда-функция для получения следующего поля из строки (разделитель '|')
        auto getNextField = [&]() {
            size_t delimiterPos = line.find('|', pos);  // Ищем разделитель
            if (delimiterPos == string::npos) {         // Если разделитель не найден
                token = line.substr(pos);               // Берём всё до конца строки
                pos = line.length();                    // Устанавливаем позицию в конец
            }
            else {
                token = line.substr(pos, delimiterPos - pos); // Берём часть до разделителя
                pos = delimiterPos + 1;                       // Перемещаем позицию за разделитель
            }
            return token;   // Возвращаем полученное поле
        };

        try {   // Пытаемся преобразовать строки в нужные типы данных
            member->ticketNumber = stoi(getNextField());   // Номер билета (int)
            member->lastName = getNextField();             // Фамилия (string)
            member->firstName = getNextField();            // Имя (string)
            member->patronymic = getNextField();           // Отчество (string)
            member->joinDate = getNextField();             // Дата вступления (string)
            member->totalFees = stod(getNextField());      // Сумма взносов (double)

            member->next = firstMember;    // Новый элемент указывает на текущий первый
            firstMember = member;          // Новый элемент становится первым
        }
        catch (...) {   // Если произошла ошибка при преобразовании
            delete member;  // Удаляем некорректный элемент
            continue;       // Пропускаем эту строку и продолжаем чтение
        }
    }
    file.close();   // Закрываем файл
    return true;    // Возвращаем успешный результат
}

// Функция вывода справки
void PrintHelp() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
    cout << "----СПРАВКА----\n\n";          // Заголовок
    ResetColor();                           // Сброс цвета
    cout << "1. Добавить члена общества\n";
    cout << "2. Показать всех членов\n";
    cout << "3. Поиск по номеру билета\n";
    cout << "4. Поиск по фамилии\n";
    cout << "5. Поиск по дате вступления\n";
    cout << "6. Удалить по номеру билета\n";
    cout << "7. Сохранить в файл\n";
    cout << "8. Выход (автосохранение)\n\n";
    _getch();   // Ожидание нажатия клавиши
}

// Функция отображения главного меню и получения выбора пользователя
char MainMenu() {
    system("cls");  // Очистка экрана
    SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
    cout << "УЧЕТ ЧЛЕНОВ ОБЩЕСТВА ОХОТНИКОВ-РЫБОЛОВОВ\n\n";   // Название программы
    ResetColor();                           // Сброс цвета
    SetTextColor(crt::COLOR_GREEN);         // Установка зелёного цвета
    cout << "====================================\n";   // Разделительная линия
    ResetColor();                           // Сброс цвета
    SetTextColor(crt::COLOR_LIGHT_CYAN);    // Установка ярко-голубого цвета
    cout << "1. Добавить члена\n";
    cout << "2. Показать всех членов\n";
    cout << "3. Поиск по номеру билета\n";
    cout << "4. Поиск по фамилии\n";
    cout << "5. Поиск по дате вступления\n";
    cout << "6. Удалить по номеру билета\n";
    cout << "7. Сохранить\n";
    cout << "8. Выход\n\n";
    ResetColor();                           // Сброс цвета
    cout << "Выбор: ";                      // Приглашение к вводу

    char choice = _getch();     // Считывание символа без нажатия Enter
    cout << choice << "\n";     // Вывод выбранного символа на экран

    if (choice < '1' || choice > '8') {     // Если выбран неверный пункт
        SetTextColor(crt::COLOR_LIGHT_RED); // Установка ярко-красного цвета
        cout << "Неверный выбор!\n";        // Сообщение об ошибке
        ResetColor();                       // Сброс цвета
        _getch();                           // Ожидание нажатия
        return '0';                         // Возврат нулевого символа
    }
    return choice;  // Возврат выбранного пункта
}

// Функция обработки событий (главный цикл программы)
void HandleEvents() {
    char choice = 0;    // Переменная для хранения выбора пользователя
    while (choice != '8') {         // Цикл до выбора пункта "Выход"
        choice = MainMenu();        // Показываем меню и получаем выбор
        switch (choice) {           // Обработка выбора
        case '1': AddData(); break;                 // Добавление
        case '2': PrintData(); break;               // Вывод всех
        case '3': SearchByTicketNumber(); break;    // Поиск по номеру
        case '4': SearchByLastName(); break;        // Поиск по фамилии
        case '5': SearchByJoinDate(); break;        // Поиск по дате
        case '6': DeleteData(); break;              // Удаление
        case '7':   // Сохранение
            if (SaveData()) {                       // Если сохранение успешно
                SetTextColor(crt::COLOR_LIGHT_GREEN);   // Установка ярко-зелёного цвета
                cout << "\nДанные сохранены!\n";        // Сообщение об успехе
                ResetColor();                           // Сброс цвета
            }
            else {
                SetTextColor(crt::COLOR_LIGHT_RED);     // Установка ярко-красного цвета
                cout << "\nОшибка сохранения!\n";       // Сообщение об ошибке
                ResetColor();                           // Сброс цвета
            }
            _getch();   // Ожидание нажатия клавиши
            break;
        case '8': break;    // Выход из цикла
        case '0': break;    // Обработка неверного выбора
        }
    }
}

// Главная функция программы
int main() {
    SetConsoleOutputCP(1251);   // Установка кодировки вывода для Windows (кириллица)
    SetConsoleCP(1251);         // Установка кодировки ввода для Windows (кириллица)

    if (!LOGIN_IN()) {  // Если авторизация не пройдена
        return 0;       // Завершаем программу
    }

    LoadData();         // Загружаем данные из файла
    HandleEvents();     // Запускаем главный цикл обработки
    SaveData();         // Сохраняем данные перед выходом

    // Очистка динамической памяти (освобождение всех элементов списка)
    while (firstMember != nullptr) {
        Member* temp = firstMember;     // Запоминаем указатель на удаляемый элемент
        firstMember = firstMember->next; // Переходим к следующему элементу
        delete temp;                    // Освобождаем память
    }

    return 0;   // Успешное завершение программы
}
