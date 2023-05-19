#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "header.h"
using namespace std;
namespace toDo {
    
    void appendTasks(toDoList task[], int SIZE, const char* filePath) {
        FILE* tdAppend;
        fopen_s(&tdAppend, filePath, "ab");
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
                cout << "Введите группу задачи(дом, работа, личное): ";
                cin >> ws;
                gets_s(task[i].group.character, 50);
                cout << "Введите загаловок задачи: ";
                cin >> ws;
                gets_s(task[i].title, 50);
                cout << "Введите приортитет задачи: ";
                cin >> ws;
                cin >> task[i].priority;
                cout << "Введите подробное описание задачи: ";
                cin >> ws;
                gets_s(task[i].description, 100);
                cout << "Введите дату выполнения задачи: ";
                cin >> ws;
                gets_s(task[i].date, 50);
                cout << "Введите время выполнения задачи: ";
                cin >> ws;
                gets_s(task[i].time, 50);
                cout << "Хотите добавить еще задачу? [1] Да, [0] Нет.";
                cin >> stop;
                fprintf(tdAppend, "%s\n", task[i].group.character);
                fprintf(tdAppend, "%s\n", task[i].title);
                fprintf(tdAppend, "%i\n", task[i].priority);
                fprintf(tdAppend, "%s\n", task[i].description);
                fprintf(tdAppend, "%s\n", task[i].date);
                fprintf(tdAppend, "%s\n", task[i].time);
                i++;
            } while (stop != 0);
        }
        fclose(tdAppend);
    }

    void showAllList(toDoList task[], int SIZE, const char* filePath) {
        // определяем указатель на файл
        FILE* tdOut;

        // открываем файл на чтение
        fopen_s(&tdOut, filePath, "rb");
        if (!tdOut) {
            cout << "Ошибка открытия файла!";
        }
        //проходим циклом и считываем данные из файла, потом выводим их на экран
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, tdOut);
            fgets(task[i].title, 50, tdOut);
            fscanf(tdOut, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, tdOut);
            fgets(task[i].date, 50, tdOut);
            fgets(task[i].time, 50, tdOut);
            cout << "\n============================" << "Запись №" << i + 1 << "================================\n";
            cout << "\tНазвание группы:" << task[i].group.character << "\n" <<
                     "\tНазвание задачи:" << task[i].title << "\n" <<
                "       Приоритет задачи:" << task[i].priority << "\n" <<
                "\tОписание задачи:" << task[i].description << "\n" <<
                " Дата выполнения задачи:" << task[i].date << "\n" <<
                "Время выполнения задачи:" << task[i].time << endl;
            cout << "=====================================================================";
        }
        fclose(tdOut);
    }

    void findTaskTitle(toDoList task[], int SIZE, const char* filePath) {
        FILE* tdT;
        fopen_s(&tdT, filePath, "rb");
        char titleTask[50];
        cout << "\t\tВведите название для поиска задачи: ";
        cin >> ws;
        gets_s(titleTask, 50);
        if (!tdT) {
            cout << "Error, file 'ToDo_list.txt' not open!\n";
        }
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, tdT);
            fgets(task[i].title, 50, tdT);
            fscanf(tdT, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, tdT);
            fgets(task[i].date, 50, tdT);
            fgets(task[i].time, 50, tdT);
            if (!strcmp(task[i].title, titleTask)) {
                cout << "\t\tТакая задача отсутствует! " << endl;
            }
            else {
                cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                cout << "\tНазвание группы:" << task[i].group.character <<
                    "\n\tНазвание задачи:" << task[i].title <<
                    "\n       Приоритет задачи:" << task[i].priority <<
                    "\n\tОписание задачи:" << task[i].description <<
                    "\n Дата выполнения задачи:" << task[i].date <<
                    "\nВремя выполнения задачи:" << task[i].time << endl;
                cout << "\n=====================================================================\n";
            }
        }
        fclose(tdT);
    }


    void findTaskPriority(toDoList task[], int SIZE, const char* filePath) {
        FILE* td; //Определяем указатель на файл в котором храниться список задач
        fopen_s(&td, filePath, "r"); // открываем файл в режиме чтения
        int taskPrior; // определяем переменную в которую будем считывать искомое значение
        cout << "\t\tВведите приоритет от 1 до 3 для поиска: ";
        cin >> taskPrior; // вводим переменую для поиска значения в файле
        if (!td) { // обязательно проверяем что наш файл существует и открывается
            cout << "Error, file 'ToDo_list.txt' not open!\n"; // в случае отсутствия файла либо его повреждения, выводим сообщение об ошибке
        }
        if (taskPrior > 0 && taskPrior <= 3) { // проверяем что наше искомое значение вводится в допустимом диапазоне
            for (int i = 0; i < SIZE; i++) { // заходим в цикл и читаем поля нашей структуры
                fgets(task[i].group.character, 50, td); // тут и ниже с помощью библиотечных функций мы считываем строки из файла
                fgets(task[i].title, 50, td);
                fscanf(td, "%i\n ", &task[i].priority); 
                fgets(task[i].description, 100, td);
                fgets(task[i].date, 50, td);
                fgets(task[i].time, 50, td);
                if (task[i].priority == taskPrior) { // в этом условии мы проверяем каждую строку с нашим введеном искомым значение и как только нашли, то выводим иноформацию (см. ниже код с выводом)
                  
                    cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                    cout << "\tНазвание группы:" << task[i].group.character <<
                        "\n\tНазвание задачи:" << task[i].title <<
                        "\n       Приоритет задачи:" << task[i].priority <<
                        "\n\tОписание задачи:" << task[i].description <<
                        "\n Дата выполнения задачи:" << task[i].date <<
                        "\nВремя выполнения задачи:" << task[i].time << endl;
                    cout << "\n=====================================================================\n";
                }
            }
        }
        else {
            cout << "Такая задача отсутствует, либо, не верно указан приоритет!" << endl;
        }
        fclose(td); // после открытия файла и работы с ним необходимо его закрыть во избежании утечки памяти
    }

    void findTaskGroup(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "rb");
        char taskGroupFind[50];
        cout << "\t\tВведите название группы дел (Дом, Работа, Личное): ";
        cin >> taskGroupFind;
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, td);
            fgets(task[i].title, 50, td);
            fscanf(td, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, td);
            fgets(task[i].date, 50, td);
            fgets(task[i].time, 50, td);
            if (task[i].group.character == taskGroupFind) {
                cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                cout << "\tНазвание группы:" << task[i].group.character <<
                    "\nНазвание задачи:" << task[i].title <<
                    "\n       Приоритет задачи:" << task[i].priority <<
                    "\n\tОписание задачи:" << task[i].description <<
                    "\n Дата выполнения задачи:" << task[i].date <<
                    "\nВремя выполнения задачи:" << task[i].time << endl;
                cout << "\n=====================================================================\n";
            }
            else {
                cout << "Не нашел";
            }
        }
        fclose(td);
    }

    void sortByPriority(toDoList task[], int SIZE, const char* filePath, int left, int right) {
        FILE* tdSort;
        fopen_s(&tdSort, filePath, "r");
        int i = left;
        int j = right;
        toDoList sort = task[(i + j) / 2];
        // Разбиваем массив на две части
        while (i <= j) {
            while (task[i].priority < sort.priority) {
                i++;
            }
            while (task[j].priority > sort.priority) {
                j--;
            }
            if (i <= j) {
                toDoList tmp = task[i];
                task[i] = task[j];
                task[j] = tmp;
                i++;
                j--;
            }
        }

        //рекрсивной сортируем каждую часть массива
        if (left < j) {
            sortByPriority(task, SIZE, filePath, left, j);
            
        }

        if (i < right) {
            sortByPriority(task, SIZE, filePath, i, right);
           
        }
        fgets(task[i].group.character, 50, tdSort);
        fgets(task[i].title, 50, tdSort);
        fscanf(tdSort, "%i\n ", &task[i].priority);
        fgets(task[i].description, 100, tdSort);
        fgets(task[i].date, 50, tdSort);
        fgets(task[i].time, 50, tdSort);
        for (int i = 0; i < SIZE; i++) {
            
            cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
            cout << "\tНазвание группы:" << task[i].group.character <<
                "\nНазвание задачи:" << task[i].title <<
                "\n       Приоритет задачи:" << task[i].priority <<
                "\n\tОписание задачи:" << task[i].description <<
                "\n Дата выполнения задачи:" << task[i].date <<
                "\nВремя выполнения задачи:" << task[i].time << endl;
            cout << "\n=====================================================================\n";

        }
        fclose(tdSort);
    }

    /* ФУНКЦИЯ ПЕРЕЗАПИСИ ФАЙЛА
    int rewriteFile(toDoList task[], int SIZE, const char* filePath) {
        SetConsoleCP(1251);
        FILE* tdRW;
        fopen_s(&tdRW, filePath, "a");
        if (!tdRW) {
            cout << "Ошибка открытия файла!";
            return -1;
        }
        for (int i = 0; i < SIZE; i++) {
            fprintf(tdRW, "%s\n", task[i].title);
            fprintf(tdRW, "%i\n", task[i].priority);
            fprintf(tdRW, "%s\n", task[i].description);
            fprintf(tdRW, "%s\n", task[i].date);
            fprintf(tdRW, "%s\n", task[i].time);
            cout << "Файл успешно перезаписан!";
        }
        SetConsoleCP(866);
        fclose(tdRW);
    }*/

    /* ФУНКЦИЯ УДАЛЕНИЯ ЭЛЕМЕНТА ИЗ ФАЙЛА С ВЫЗОВОМ ФУНКЦИИ ПОИСКА И ДАЛЬНЕЙШЕЙ ПЕРЕЗАПИСИ
    int removeListElement(toDoList task[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdOut;
        fopen_s(&tdOut, filePath, "wb");
        char task[50];
        cout << "Введите искомое название для удаления из списка дел: ";
        cin >> task;
        int position = findTask(task, SIZE, filePath, task);
        if (!tdOut) {
            cout << "Ошибка открытия файла!";
            return -1;
        }
        if (position == -1) {
            cout << "Запись не наидена!";
        }
        SIZE--;
        cout << "Запись удалена.";
        rewriteFile(task, SIZE, filePath);
        fclose(tdOut);
    }*/
    /* ФУНКЦИЯ УДАЛЕНИЯ ЭЛЕМЕНТА С ПЕРЕЗАПИСЬЮ УДАЛЕННОЙ ЗАПИСИ В ФАЙЛ КОРЗИНУ
    int removeListElement(toDoList task[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdDel;
        FILE* tdOut;
        fopen_s(&tdDel, deletedList, "w");
        fopen_s(&tdOut, filePath, "a");
        char findRemovTasks[50];
        cout << "Введите название задачи для поиска: ";
        cin >> findRemovTasks;
        for (int i = 0; i < 5; i++) {
            if (findRemovTasks == task[i].title) {
                fprintf(tdDel, "%s\n ", task[i].title);
                fprintf(tdDel, "%i\n ", task[i].priority);
                fprintf(tdDel, "%s\n ", task[i].description);
                fprintf(tdDel, "%s\n ", task[i].date);
                fprintf(tdDel, "%s\n ", task[i].time);
                cout << "Задача удалена в корзину!";
            }
            else {
                fprintf(tdOut, "%s\n ", task[i].title);
                fprintf(tdOut, "%i\n ", task[i].priority);
                fprintf(tdOut, "%s\n ", task[i].description);
                fprintf(tdOut, "%s\n ", task[i].date);
                fprintf(tdOut, "%s\n ", task[i].time);
                cout << "Основной файл перезаписан!";
            }
        }
        fclose(tdDel);
        fclose(tdOut);
    }
    ФАЙЛ КОРЗИНА
    void showBasket(toDoList task[], int SIZE, const char* deletedList) {
        FILE* tdDel;
        fopen_s(&tdDel, deletedList, "r");
        int choise;
        cout << "\nПосмотреть содержимое корзины? 1) Да     2) Нет";
        cin >> choise;
        if (choise == 1) {
            for (int i = 0; i < 2; i++) {
                fgets(task[i].title, 50, tdDel);
                fscanf(tdDel, "%i\n ", task[i].priority);
                fgets(task[i].description, 50, tdDel);
                fgets(task[i].date, 50, tdDel);
                fgets(task[i].time, 50, tdDel);
                cout << "\tНазвание задачи:" << task[i].title <<
                    "\n       Приоритет задачи:" << task[i].priority <<
                    "\n\tОписание задачи:" << task[i].description <<
                    "\n Дата выполнения задачи:" << task[i].date <<
                    "\nВремя выполнения задачи:" << task[i].time << endl;
            }
        }
        fclose(tdDel);
    }*/

    void toDoListForTheDay(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char findTasksForTheDay[50];
        cout << "\t\t\tВведите дату для просмотра задач: ";
        cin >> findTasksForTheDay;
        if (!td) {
            cout << "Error, file 'ToDo_list.txt' not open!\n";
        }
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, td);
            fgets(task[i].title, 50, td);
            fscanf(td, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, td);
            fgets(task[i].date, 50, td);
            fgets(task[i].time, 50, td);
            if (strcmp(task[i].date, findTasksForTheDay) == 0) {
                cout << "\n============================" << "Запись №" << i + 1 << "================================\n";
                cout << "\tНазвание группы:" << task[i].group.character << "\n" <<
                    "Название задачи:" << task[i].title << "\n" <<
                    "       Приоритет задачи:" << task[i].priority << "\n" <<
                    "\tОписание задачи:" << task[i].description << "\n" <<
                    " Дата выполнения задачи:" << task[i].date << "\n" <<
                    "Время выполнения задачи:" << task[i].time << endl;
                cout << "=====================================================================";
            }
        }
    }

    void toDoListForTheWeek(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char findTasksForTheWeek[50];
        cout << "\t\t\tВведите дату для просмотра задач: ";
        cin >> findTasksForTheWeek;
        if (!td) {
            cout << "Error, file 'ToDo_list.txt' not open!\n";
        }
        if (findTasksForTheWeek ) {

        }
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, td);
            fgets(task[i].title, 50, td);
            fscanf(td, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, td);
            fgets(task[i].date, 50, td);
            fgets(task[i].time, 50, td);
            if (strcmp(task[i].date, findTasksForTheWeek) == 0) {
                cout << "\n============================" << "Запись №" << i + 1 << "================================\n";
                cout << "\tНазвание группы:" << task[i].group.character << "\n" <<
                    "Название задачи:" << task[i].title << "\n" <<
                    "       Приоритет задачи:" << task[i].priority << "\n" <<
                    "\tОписание задачи:" << task[i].description << "\n" <<
                    " Дата выполнения задачи:" << task[i].date << "\n" <<
                    "Время выполнения задачи:" << task[i].time << endl;
                cout << "=====================================================================";
            }
        }
    }

    void toDoListForTheMounth(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char findTasksForTheMounth[50];
        cout << "\t\t\tВведите дату для просмотра задач: ";
        cin >> findTasksForTheMounth;
        if (!td) {
            cout << "Error, file 'ToDo_list.txt' not open!\n";
        }
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, td);
            fgets(task[i].title, 50, td);
            fscanf(td, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, td);
            fgets(task[i].date, 50, td);
            fgets(task[i].time, 50, td);
            if (strcmp(task[i].date, findTasksForTheMounth) == 0) {
                cout << "\n============================" << "Запись №" << i + 1 << "================================\n";
                cout << "\tНазвание группы:" << task[i].group.character << "\n" <<
                    "Название задачи:" << task[i].title << "\n" <<
                    "       Приоритет задачи:" << task[i].priority << "\n" <<
                    "\tОписание задачи:" << task[i].description << "\n" <<
                    " Дата выполнения задачи:" << task[i].date << "\n" <<
                    "Время выполнения задачи:" << task[i].time << endl;
                cout << "=====================================================================";
            }
        }
    }
}

namespace song {

    void addSongs(Songs song[], int SIZE, const char* songFile) {
        FILE* fSong;
        fopen_s(&fSong, songFile, "w");
        int stop = 0;
        if (!fSong) {
            cout << "Ошибка открытия файла!";
        }
        int i = 0;
        if (i >= SIZE) {
            cout << "Список песен полон!";
        }
        else {
            do {
                cout << "Введите название песни: ";
                cin >> ws;
                gets_s(song[i].titleSongs, 50);
                cout << "Введите автора песни: ";
                cin >> ws;
                gets_s(song[i].authorSongs, 50);
                cout << "Введите текст песни: ";
                cin >> ws;
                gets_s(song[i].songFile, 255);
                cout << "Введите год выхода песни: ";
                cin >> ws;
                cin >> song[i].yearOfTheSongs;
                cout << "Хотите добавить еще песню? [1] Да, [0] Нет.";
                cin >> stop;
                fprintf(fSong, "%s\n", song[i].titleSongs);
                fprintf(fSong, "%s\n", song[i].authorSongs);
                fprintf(fSong, "%s\n", song[i].songFile);
                fprintf(fSong, "%i\n", song[i].yearOfTheSongs);
                i++;
            } while (stop != 0);
        }
        fclose(fSong);
    }

    void showAllSongs(Songs song[], int SIZE, const char* songFile) {
        // определяем указатель на файл
        FILE* Rsong;

        // открываем файл на чтение
        fopen_s(&Rsong, songFile, "r");
        if (!Rsong) {
            cout << "Ошибка открытия файла!";
        }
        //проходим циклом и считываем данные из файла, потом выводим их на экран
        for (int i = 0; i < SIZE; i++) {
            fgets(song[i].titleSongs, 50, Rsong);
            fgets(song[i].authorSongs, 50, Rsong);
            fgets(song[i].songFile, 100, Rsong);
            fscanf(Rsong, "%i\n ", song[i].yearOfTheSongs);
            cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
            cout << "\tНазвание песни: " << song[i].titleSongs <<
                "\nАвтор песни: " << song[i].authorSongs <<
                "\n       Текст песни: " << song[i].songFile <<
                "\n\tГод выхода песни: " << song[i].yearOfTheSongs << endl;
            cout << "\n=====================================================================\n";
        }
        fclose(Rsong);
    }

    void findSongAuthor(Songs song[], int SIZE, const char* songFile) {
        FILE* sf;
        fopen_s(&sf, songFile, "r");
        char title[50];

        cout << "\t\tВыберете пункт поиска задачи: ";
        cin >> title;
        for (int i = 0; i < SIZE; i++) {
            fgets(song[i].titleSongs, 50, sf);
            fgets(song[i].authorSongs, 50, sf);
            fgets(song[i].songFile, 100, sf);
            fscanf(sf, "%i\n ", song[i].yearOfTheSongs);
            if (strcmp(song[i].authorSongs, title) == 0) {
                cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                cout << "\tНазвание песни: " << song[i].titleSongs <<
                    "\nАвтор песни: " << song[i].authorSongs <<
                    "\n       Текст песни: " << song[i].songFile <<
                    "\n\tГод выхода песни: " << song[i].yearOfTheSongs << endl;
                cout << "\n=====================================================================\n";
            }
        }
        fclose(sf);
    }

    void findWordInTheSong(Songs song[], int SIZE, const char* songFile) {
        FILE* sf;
        fopen_s(&sf, songFile, "r");
        char word[50];

        cout << "\t\tВведите слово и мы найдем песни содежащие ваше слово: ";
        cin >> word;
        for (int i = 0; i < SIZE; i++) {
            fgets(song[i].titleSongs, 50, sf);
            fgets(song[i].authorSongs, 50, sf);
            fgets(song[i].songFile, 100, sf);
            fscanf(sf, "%i\n ", song[i].yearOfTheSongs);
            if (strcmp(song[i].songFile, word) == 0) {
                cout << "\n===================================" << "Запись №" << i + 1 << "=======================================\n";
                cout << "\tНазвание песни: " << song[i].titleSongs <<
                    "\nАвтор песни: " << song[i].authorSongs <<
                    "\n       Текст песни: " << song[i].songFile <<
                    "\n\tГод выхода песни: " << song[i].yearOfTheSongs << endl;
                cout << "\n=====================================================================\n";
            }
        }
        fclose(sf);
    }
}