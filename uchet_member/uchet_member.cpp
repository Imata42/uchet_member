#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include "uchet.h"

using namespace std;

Member* firstMember = nullptr;

bool LOGIN_IN() {
    string login;
    string password;

    while (true) {
        system("cls");
        SetTextColor(crt::COLOR_YELLOW);
        cout << "ВХОД В СИСТЕМУ\n\n";
        ResetColor();

        SetTextColor(crt::COLOR_LIGHT_CYAN);
        cout << "Введите логин: ";
        ResetColor();
        getline(cin, login);

        SetTextColor(crt::COLOR_LIGHT_CYAN);
        cout << "Введите пароль: ";
        ResetColor();
        getline(cin, password);

        if (login == "admin" && password == "12345") {
            SetTextColor(crt::COLOR_LIGHT_GREEN);
            cout << "\nУспешный вход! Добро пожаловать, " << login << "." << endl;
            ResetColor();
            _getch();
            return true;
        }
        else {
            SetTextColor(crt::COLOR_LIGHT_RED);
            cout << "\nОшибка: Неверный логин или пароль." << endl;
            cout << "Попробуйте еще раз.\n";
            ResetColor();
            cout << "Нажмите любую клавишу...";
            _getch();
        }
    }
}

void AddData() {
    system("cls");
    SetTextColor(crt::COLOR_LIGHT_MAGENTA);
    cout << "----ДОБАВИТЬ ЧЛЕНА ОБЩЕСТВА----\n\n";
    ResetColor();

    Member* member = new Member();

    SetTextColor(crt::COLOR_MAGENTA);
    cout << "Номер членского билета: ";
    ResetColor();
    cin >> member->ticketNumber;
    cin.ignore();

    SetTextColor(crt::COLOR_MAGENTA);
    cout << "Фамилия (до 15 символов): ";
    ResetColor();
    getline(cin, member->lastName);
    if (member->lastName.length() > 15) member->lastName = member->lastName.substr(0, 15);

    SetTextColor(crt::COLOR_MAGENTA);
    cout << "Имя (до 15 символов): ";
    ResetColor();
    getline(cin, member->firstName);
    if (member->firstName.length() > 15) member->firstName = member->firstName.substr(0, 15);

    SetTextColor(crt::COLOR_MAGENTA);
    cout << "Отчество (до 15 символов): ";
    ResetColor();
    getline(cin, member->patronymic);
    if (member->patronymic.length() > 15) member->patronymic = member->patronymic.substr(0, 15);

    SetTextColor(crt::COLOR_MAGENTA);
    cout << "Дата вступления (ДД.ММ.ГГГГ): ";
    ResetColor();
    getline(cin, member->joinDate);

    SetTextColor(crt::COLOR_MAGENTA);
    cout << "Общая сумма уплаченных взносов: ";
    ResetColor();
    cin >> member->totalFees;

    member->next = firstMember;
    firstMember = member;

    SetTextColor(crt::COLOR_LIGHT_GREEN);
    cout << "\nЧлен общества успешно добавлен!" << endl;
    ResetColor();
    _getch();
}

void PrintData() {
    system("cls");
    SetTextColor(crt::COLOR_YELLOW);
    cout << "----СПИСОК ЧЛЕНОВ ОБЩЕСТВА----\n\n";
    ResetColor();

    if (firstMember == nullptr) {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "Список пуст!\n";
        ResetColor();
    }
    else {
        Member* current = firstMember;
        int count = 0;
        while (current != nullptr) {
            SetTextColor(crt::COLOR_LIGHT_GREEN);
            cout << "[" << ++count << "] ";
            ResetColor();
            cout << "Номер билета: " << current->ticketNumber << endl;
            cout << "    ФИО: " << current->lastName << " "
                << current->firstName << " " << current->patronymic << endl;
            cout << "    Дата вступления: " << current->joinDate << endl;
            SetTextColor(crt::COLOR_LIGHT_CYAN);
            cout << "    Сумма взносов: " << current->totalFees << " руб." << endl;
            ResetColor();
            cout << "-------------------\n";
            current = current->next;
        }
    }
    cout << "\nНажмите любую клавишу...";
    _getch();
}

void SearchByTicketNumber() {
    system("cls");
    SetTextColor(crt::COLOR_YELLOW);
    cout << "----ПОИСК ПО НОМЕРУ БИЛЕТА----\n\n";
    ResetColor();

    int number;
    SetTextColor(crt::COLOR_LIGHT_CYAN);
    cout << "Введите номер билета: ";
    ResetColor();
    cin >> number;

    Member* current = firstMember;
    bool found = false;

    while (current != nullptr) {
        if (current->ticketNumber == number) {
            SetTextColor(crt::COLOR_LIGHT_GREEN);
            cout << "\nНайден член общества:\n";
            ResetColor();
            cout << "Номер билета: " << current->ticketNumber << endl;
            cout << "ФИО: " << current->lastName << " "
                << current->firstName << " " << current->patronymic << endl;
            cout << "Дата вступления: " << current->joinDate << endl;
            SetTextColor(crt::COLOR_LIGHT_CYAN);
            cout << "Сумма взносов: " << current->totalFees << " руб.\n";
            ResetColor();
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "\nЧлен с таким номером не найден!\n";
        ResetColor();
    }
    cout << "\nНажмите любую клавишу...";
    _getch();
}

void SearchByLastName() {
    system("cls");
    SetTextColor(crt::COLOR_YELLOW);
    cout << "=== ПОИСК ПО ФАМИЛИИ ===\n\n";
    ResetColor();

    string lastName;
    SetTextColor(crt::COLOR_LIGHT_CYAN);
    cout << "Введите фамилию: ";
    ResetColor();
    cin >> lastName;

    Member* current = firstMember;
    bool found = false;
    int count = 0;

    while (current != nullptr) {
        if (current->lastName == lastName) {
            SetTextColor(crt::COLOR_LIGHT_GREEN);
            cout << "\n[" << ++count << "] ";
            ResetColor();
            cout << "Номер билета: " << current->ticketNumber << endl;
            cout << "    ФИО: " << current->lastName << " "
                << current->firstName << " " << current->patronymic << endl;
            cout << "    Дата вступления: " << current->joinDate << endl;
            SetTextColor(crt::COLOR_LIGHT_CYAN);
            cout << "    Сумма взносов: " << current->totalFees << " руб.\n";
            ResetColor();
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "\nЧлены с такой фамилией не найдены!\n";
        ResetColor();
    }
    cout << "\nНажмите любую клавишу...";
    _getch();
}

void SearchByJoinDate() {
    system("cls");
    SetTextColor(crt::COLOR_YELLOW);
    cout << "----ПОИСК ПО ДАТЕ ВСТУПЛЕНИЯ----\n\n";
    ResetColor();

    string date;
    SetTextColor(crt::COLOR_LIGHT_CYAN);
    cout << "Введите дату (ДД.ММ.ГГГГ): ";
    ResetColor();
    cin >> date;

    Member* current = firstMember;
    bool found = false;
    int count = 0;

    while (current != nullptr) {
        if (current->joinDate == date) {
            SetTextColor(crt::COLOR_LIGHT_GREEN);
            cout << "\n[" << ++count << "] ";
            ResetColor();
            cout << "Номер билета: " << current->ticketNumber << endl;
            cout << "    ФИО: " << current->lastName << " "
                << current->firstName << " " << current->patronymic << endl;
            cout << "    Дата вступления: " << current->joinDate << endl;
            SetTextColor(crt::COLOR_LIGHT_CYAN);
            cout << "    Сумма взносов: " << current->totalFees << " руб.\n";
            ResetColor();
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "\nЧлены с такой датой вступления не найдены!\n";
        ResetColor();
    }
    cout << "\nНажмите любую клавишу...";
    _getch();
}

void DeleteData() {
    system("cls");
    SetTextColor(crt::COLOR_YELLOW);
    cout << "----УДАЛЕНИЕ ЧЛЕНА ОБЩЕСТВА----\n\n";
    ResetColor();

    int number;
    SetTextColor(crt::COLOR_LIGHT_RED);
    cout << "Введите номер билета для удаления: ";
    ResetColor();
    cin >> number;

    if (firstMember == nullptr) {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "Список пуст!\n";
        ResetColor();
        _getch();
        return;
    }

    if (firstMember->ticketNumber == number) {
        Member* temp = firstMember;
        firstMember = firstMember->next;
        delete temp;
        SetTextColor(crt::COLOR_LIGHT_GREEN);
        cout << "\nЧлен успешно удален!\n";
        ResetColor();
        _getch();
        return;
    }

    Member* current = firstMember;
    while (current->next != nullptr && current->next->ticketNumber != number) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Member* temp = current->next;
        current->next = current->next->next;
        delete temp;
        SetTextColor(crt::COLOR_LIGHT_GREEN);
        cout << "\nЧлен успешно удален!\n";
        ResetColor();
    }
    else {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "\nЧлен с таким номером не найден!\n";
        ResetColor();
    }
    _getch();
}

bool SaveData() {
    ofstream file("members.txt");
    if (!file.is_open()) return false;

    Member* current = firstMember;
    while (current != nullptr) {
        file << current->ticketNumber << "|"
            << current->lastName << "|"
            << current->firstName << "|"
            << current->patronymic << "|"
            << current->joinDate << "|"
            << current->totalFees << "\n";
        current = current->next;
    }
    file.close();
    return true;
}

bool LoadData() {
    ifstream file("members.txt");
    if (!file.is_open()) {
        return true;
    }

    while (firstMember != nullptr) {
        Member* temp = firstMember;
        firstMember = firstMember->next;
        delete temp;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        Member* member = new Member();

        size_t pos = 0;
        string token;

        auto getNextField = [&]() {
            size_t delimiterPos = line.find('|', pos);
            if (delimiterPos == string::npos) {
                token = line.substr(pos);
                pos = line.length();
            }
            else {
                token = line.substr(pos, delimiterPos - pos);
                pos = delimiterPos + 1;
            }
            return token;
            };

        try {
            member->ticketNumber = stoi(getNextField());
            member->lastName = getNextField();
            member->firstName = getNextField();
            member->patronymic = getNextField();
            member->joinDate = getNextField();
            member->totalFees = stod(getNextField());

            member->next = firstMember;
            firstMember = member;
        }
        catch (...) {
            delete member;
            continue;
        }
    }
    file.close();
    return true;
}

void PrintHelp() {
    system("cls");
    SetTextColor(crt::COLOR_LIGHT_CYAN);
    cout << "----СПРАВКА----\n\n";
    ResetColor();
    cout << "1. Добавить члена общества\n";
    cout << "2. Показать всех членов\n";
    cout << "3. Поиск по номеру билета\n";
    cout << "4. Поиск по фамилии\n";
    cout << "5. Поиск по дате вступления\n";
    cout << "6. Удалить по номеру билета\n";
    cout << "7. Сохранить в файл\n";
    cout << "8. Выход (автосохранение)\n\n";
    _getch();
}

char MainMenu() {
    system("cls");
    SetTextColor(crt::COLOR_LIGHT_GREEN);
    cout << "УЧЕТ ЧЛЕНОВ ОБЩЕСТВА ОХОТНИКОВ-РЫБОЛОВОВ\n\n";
    ResetColor();
    SetTextColor(crt::COLOR_GREEN);
    cout << "====================================\n";
    ResetColor();
    SetTextColor(crt::COLOR_LIGHT_CYAN);
    cout << "1. Добавить члена\n";
    cout << "2. Показать всех членов\n";
    cout << "3. Поиск по номеру билета\n";
    cout << "4. Поиск по фамилии\n";
    cout << "5. Поиск по дате вступления\n";
    cout << "6. Удалить по номеру билета\n";
    cout << "7. Сохранить\n";
    cout << "8. Выход\n\n";
    ResetColor();
    cout << "Выбор: ";

    char choice = _getch();
    cout << choice << "\n";

    if (choice < '1' || choice > '8') {
        SetTextColor(crt::COLOR_LIGHT_RED);
        cout << "Неверный выбор!\n";
        ResetColor();
        _getch();
        return '0';
    }
    return choice;
}

void HandleEvents() {
    char choice = 0;
    while (choice != '8') {
        choice = MainMenu();
        switch (choice) {
        case '1': AddData(); break;
        case '2': PrintData(); break;
        case '3': SearchByTicketNumber(); break;
        case '4': SearchByLastName(); break;
        case '5': SearchByJoinDate(); break;
        case '6': DeleteData(); break;
        case '7':
            if (SaveData()) {
                SetTextColor(crt::COLOR_LIGHT_GREEN);
                cout << "\nДанные сохранены!\n";
                ResetColor();
            }
            else {
                SetTextColor(crt::COLOR_LIGHT_RED);
                cout << "\nОшибка сохранения!\n";
                ResetColor();
            }
            _getch();
            break;
        case '8': break;
        case '0': break;
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    if (!LOGIN_IN()) {
        return 0;
    }

    LoadData();
    HandleEvents();
    SaveData();

    while (firstMember != nullptr) {
        Member* temp = firstMember;
        firstMember = firstMember->next;
        delete temp;
    }

    return 0;
}
