#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "header.h"
using namespace std;
namespace toDo {
    void appendTasks(toDoList list[], int SIZE, const char* filePath) {
        FILE* tdAppend;
        fopen_s(&tdAppend, filePath, "a");
        int stop = 0;
        if (!tdAppend) {
            cout << "Ошибка открытия файла!";
        }
        int i = 0;
        if (i >= SIZE) {
            cout << "Список задач полон!";
        }
        else {
            do {
                cout << "Введите загаловок задачи: ";
                cin >> ws;
                gets_s(list[i].title, 50);
                cout << "Введите приортитет задачи: ";
                cin >> ws;
                cin >> list[i].priority;
                cout << "Введите подробное описание задачи: ";
                cin >> ws;
                gets_s(list[i].description, 100);
                cout << "Введите дату выполнения задачи: ";
                cin >> ws;
                gets_s(list[i].date, 50);
                cout << "Введите время выполнения задачи: ";
                cin >> ws;
                gets_s(list[i].time, 50);
                cout << "Хотите добавить еще задачу? [1] Да, [0] Нет.";
                cin >> stop;
                fprintf(tdAppend, "%s\n", list[i].title);
                fprintf(tdAppend, "%i\n", list[i].priority);
                fprintf(tdAppend, "%s\n", list[i].description);
                fprintf(tdAppend, "%s\n", list[i].date);
                fprintf(tdAppend, "%s\n", list[i].time);
                i++;
            } while (stop != 0);
        }
        fclose(tdAppend);
    }
    
    void showAllList(toDoList list[], int SIZE, const char* filePath) {
        // определяем указатель на файл
        FILE* tdOut;

        // открываем файл на чтение
        fopen_s(&tdOut, filePath, "r");
        if (!tdOut) {
            cout << "Ошибка открытия файла!";
        }
        //проходим циклом и считываем данные из файла, потом выводим их на экран
        for (int i = 0; i < SIZE; i++) {
            fgets(list[i].title, 50, tdOut);
            fscanf(tdOut, "%i\n ", &list[i].priority);
            fgets(list[i].description, 100, tdOut);
            fgets(list[i].date, 50, tdOut);
            fgets(list[i].time, 50, tdOut);
            cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
            cout << "\tНазвание задачи:" << list[i].title <<
                "\n       Приоритет задачи:" << list[i].priority <<
                "\n\tОписание задачи:" << list[i].description <<
                "\n Дата выполнения задачи:" << list[i].date <<
                "\nВремя выполнения задачи:" << list[i].time << endl;
            cout << "\n=====================================================================\n";
        }
        fclose(tdOut);
    }

    void findTaskTitle(toDoList list[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char task[50];
        cout << "\t\tВведите название задачи для поиска: ";
        cin >> task;
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (_strcmpi(list[i].title, task) == 0) {
                /*fgets(list[i].title, 50, td);
                fscanf(td, "%i\n ", &list[i].priority);
                fgets(list[i].description, 100, td);
                fgets(list[i].date, 50, td);
                fgets(list[i].time, 50, td);
                cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                cout << "\tНазвание задачи:" << list[i].title <<
                    "\n       Приоритет задачи:" << list[i].priority <<
                    "\n\tОписание задачи:" << list[i].description <<
                    "\n Дата выполнения задачи:" << list[i].date <<
                    "\nВремя выполнения задачи:" << list[i].time << endl;
                cout << "\n=====================================================================\n";*/
                cout << "Нашел";
                count++;
            }
            else {
                cout << "Не нашел";
            }
        }
        fclose(td);
    }

    void findTaskPriority(toDoList list[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        int taskPrior;
        cout << "\t\tВведите приоритет от 1 до 3 для поиска: ";
        cin >> taskPrior;
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (list[i].priority == taskPrior) {
                /*fgets(list[i].title, 50, td);
                fscanf(td, "%i\n ", &list[i].priority);
                fgets(list[i].description, 100, td);
                fgets(list[i].date, 50, td);
                fgets(list[i].time, 50, td);
                cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                cout << "\tНазвание задачи:" << list[i].title <<
                    "\n       Приоритет задачи:" << list[i].priority <<
                    "\n\tОписание задачи:" << list[i].description <<
                    "\n Дата выполнения задачи:" << list[i].date <<
                    "\nВремя выполнения задачи:" << list[i].time << endl;
                cout << "\n=====================================================================\n";*/
                cout << "Нашел";
                count++;
            }
            else {
                cout << "Не нашел";
            }
        }
        fclose(td);
    }

    void sortByPriority(toDoList list[], int SIZE, const char* filePath, int left, int right) {
        FILE* tdSort;
        fopen_s(&tdSort, filePath, "r");
        int i = left;
        int j = right;
        toDoList sort = list[(i + j) / 2];
        // Разбиваем массив на две части
        while (i <= j) {
            while (list[i].priority < sort.priority) {
                i++;
            }
            while (list[j].priority > sort.priority) {
                j--;
            }
            if (i <= j) {
                toDoList tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
                i++;
                j--;
            }
        }

        //рекрсивной сортируем каждую часть массива
        if (left < j) {
            sortByPriority(list, SIZE, filePath, left, j);
            
        }

        if (i < right) {
            sortByPriority(list, SIZE, filePath, i, right);
           
        }
        for (int i = 0; i < SIZE; i++) {
            fgets(list[i].title, 50, tdSort);
            fscanf(tdSort, "%i\n ", &list[i].priority);
            fgets(list[i].description, 100, tdSort);
            fgets(list[i].date, 50, tdSort);
            fgets(list[i].time, 50, tdSort);
            cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
            cout << "\tНазвание задачи:" << list[i].title <<
                "\n       Приоритет задачи:" << list[i].priority <<
                "\n\tОписание задачи:" << list[i].description <<
                "\n Дата выполнения задачи:" << list[i].date <<
                "\nВремя выполнения задачи:" << list[i].time << endl;
            cout << "\n=====================================================================\n";

            fclose(tdSort);
        }
        
    }

    /* ФУНКЦИЯ ПЕРЕЗАПИСИ ФАЙЛА
    int rewriteFile(toDoList list[], int SIZE, const char* filePath) {
        SetConsoleCP(1251);
        FILE* tdRW;
        fopen_s(&tdRW, filePath, "a");
        if (!tdRW) {
            cout << "Ошибка открытия файла!";
            return -1;
        }
        for (int i = 0; i < SIZE; i++) {
            fprintf(tdRW, "%s\n", list[i].title);
            fprintf(tdRW, "%i\n", list[i].priority);
            fprintf(tdRW, "%s\n", list[i].description);
            fprintf(tdRW, "%s\n", list[i].date);
            fprintf(tdRW, "%s\n", list[i].time);
            cout << "Файл успешно перезаписан!";
        }
        SetConsoleCP(866);
        fclose(tdRW);
    }*/

    /* ФУНКЦИЯ УДАЛЕНИЯ ЭЛЕМЕНТА ИЗ ФАЙЛА С ВЫЗОВОМ ФУНКЦИИ ПОИСКА И ДАЛЬНЕЙШЕЙ ПЕРЕЗАПИСИ
    int removeListElement(toDoList list[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdOut;
        fopen_s(&tdOut, filePath, "wb");
        char task[50];
        cout << "Введите искомое название для удаления из списка дел: ";
        cin >> task;
        int position = findTask(list, SIZE, filePath, task);
        if (!tdOut) {
            cout << "Ошибка открытия файла!";
            return -1;
        }
        if (position == -1) {
            cout << "Запись не наидена!";
        }
        SIZE--;
        cout << "Запись удалена.";
        rewriteFile(list, SIZE, filePath);
        fclose(tdOut);
    }*/
    /* ФУНКЦИЯ УДАЛЕНИЯ ЭЛЕМЕНТА С ПЕРЕЗАПИСЬЮ УДАЛЕННОЙ ЗАПИСИ В ФАЙЛ КОРЗИНУ
    int removeListElement(toDoList list[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdDel;
        FILE* tdOut;
        fopen_s(&tdDel, deletedList, "w");
        fopen_s(&tdOut, filePath, "a");
        char findRemovTasks[50];
        cout << "Введите название задачи для поиска: ";
        cin >> findRemovTasks;
        for (int i = 0; i < 5; i++) {
            if (findRemovTasks == list[i].title) {
                fprintf(tdDel, "%s\n ", list[i].title);
                fprintf(tdDel, "%i\n ", list[i].priority);
                fprintf(tdDel, "%s\n ", list[i].description);
                fprintf(tdDel, "%s\n ", list[i].date);
                fprintf(tdDel, "%s\n ", list[i].time);
                cout << "Задача удалена в корзину!";
            }
            else {
                fprintf(tdOut, "%s\n ", list[i].title);
                fprintf(tdOut, "%i\n ", list[i].priority);
                fprintf(tdOut, "%s\n ", list[i].description);
                fprintf(tdOut, "%s\n ", list[i].date);
                fprintf(tdOut, "%s\n ", list[i].time);
                cout << "Основной файл перезаписан!";
            }
        }
        fclose(tdDel);
        fclose(tdOut);
    }
    ФАЙЛ КОРЗИНА
    void showBasket(toDoList list[], int SIZE, const char* deletedList) {
        FILE* tdDel;
        fopen_s(&tdDel, deletedList, "r");
        int choise;
        cout << "\nПосмотреть содержимое корзины? 1) Да     2) Нет";
        cin >> choise;
        if (choise == 1) {
            for (int i = 0; i < 2; i++) {
                fgets(list[i].title, 50, tdDel);
                fscanf(tdDel, "%i\n ", list[i].priority);
                fgets(list[i].description, 50, tdDel);
                fgets(list[i].date, 50, tdDel);
                fgets(list[i].time, 50, tdDel);
                cout << "\tНазвание задачи:" << list[i].title <<
                    "\n       Приоритет задачи:" << list[i].priority <<
                    "\n\tОписание задачи:" << list[i].description <<
                    "\n Дата выполнения задачи:" << list[i].date <<
                    "\nВремя выполнения задачи:" << list[i].time << endl;
            }
        }
        fclose(tdDel);
    }*/

    void displayingTheList(toDoList list[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        time_t current_time = time(NULL);
        struct tm* current_tm = localtime(&current_time);
        for (int i = 0; i < SIZE; i++) {
            if (list[i].date) {

            }
        }
    }
}
