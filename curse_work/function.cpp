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
            cout << "������ �������� �����!";
        }
        int i = 0;
        if (i >= SIZE) {
            cout << "������ ����� �����!";
        }
        else {
            do {
                cout << "������� ������ ������(���, ������, ������): ";
                cin >> ws;
                gets_s(task[i].group.character, 50);
                cout << "������� ��������� ������: ";
                cin >> ws;
                gets_s(task[i].title, 50);
                cout << "������� ���������� ������: ";
                cin >> ws;
                cin >> task[i].priority;
                cout << "������� ��������� �������� ������: ";
                cin >> ws;
                gets_s(task[i].description, 100);
                cout << "������� ���� ���������� ������: ";
                cin >> ws;
                gets_s(task[i].date, 50);
                cout << "������� ����� ���������� ������: ";
                cin >> ws;
                gets_s(task[i].time, 50);
                cout << "������ �������� ��� ������? [1] ��, [0] ���.";
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
        // ���������� ��������� �� ����
        FILE* tdOut;

        // ��������� ���� �� ������
        fopen_s(&tdOut, filePath, "rb");
        if (!tdOut) {
            cout << "������ �������� �����!";
        }
        //�������� ������ � ��������� ������ �� �����, ����� ������� �� �� �����
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, tdOut);
            fgets(task[i].title, 50, tdOut);
            fscanf(tdOut, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, tdOut);
            fgets(task[i].date, 50, tdOut);
            fgets(task[i].time, 50, tdOut);
            cout << "\n============================" << "������ �" << i + 1 << "================================\n";
            cout << "\t�������� ������:" << task[i].group.character << "\n" <<
                     "\t�������� ������:" << task[i].title << "\n" <<
                "       ��������� ������:" << task[i].priority << "\n" <<
                "\t�������� ������:" << task[i].description << "\n" <<
                " ���� ���������� ������:" << task[i].date << "\n" <<
                "����� ���������� ������:" << task[i].time << endl;
            cout << "=====================================================================";
        }
        fclose(tdOut);
    }

    void findTaskTitle(toDoList task[], int SIZE, const char* filePath) {
        FILE* tdT;
        fopen_s(&tdT, filePath, "rb");
        char titleTask[50];
        cout << "\t\t������� �������� ��� ������ ������: ";
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
                cout << "\t\t����� ������ �����������! " << endl;
            }
            else {
                cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                cout << "\t�������� ������:" << task[i].group.character <<
                    "\n\t�������� ������:" << task[i].title <<
                    "\n       ��������� ������:" << task[i].priority <<
                    "\n\t�������� ������:" << task[i].description <<
                    "\n ���� ���������� ������:" << task[i].date <<
                    "\n����� ���������� ������:" << task[i].time << endl;
                cout << "\n=====================================================================\n";
            }
        }
        fclose(tdT);
    }


    void findTaskPriority(toDoList task[], int SIZE, const char* filePath) {
        FILE* td; //���������� ��������� �� ���� � ������� ��������� ������ �����
        fopen_s(&td, filePath, "r"); // ��������� ���� � ������ ������
        int taskPrior; // ���������� ���������� � ������� ����� ��������� ������� ��������
        cout << "\t\t������� ��������� �� 1 �� 3 ��� ������: ";
        cin >> taskPrior; // ������ ��������� ��� ������ �������� � �����
        if (!td) { // ����������� ��������� ��� ��� ���� ���������� � �����������
            cout << "Error, file 'ToDo_list.txt' not open!\n"; // � ������ ���������� ����� ���� ��� �����������, ������� ��������� �� ������
        }
        if (taskPrior > 0 && taskPrior <= 3) { // ��������� ��� ���� ������� �������� �������� � ���������� ���������
            for (int i = 0; i < SIZE; i++) { // ������� � ���� � ������ ���� ����� ���������
                fgets(task[i].group.character, 50, td); // ��� � ���� � ������� ������������ ������� �� ��������� ������ �� �����
                fgets(task[i].title, 50, td);
                fscanf(td, "%i\n ", &task[i].priority); 
                fgets(task[i].description, 100, td);
                fgets(task[i].date, 50, td);
                fgets(task[i].time, 50, td);
                if (task[i].priority == taskPrior) { // � ���� ������� �� ��������� ������ ������ � ����� �������� ������� �������� � ��� ������ �����, �� ������� ����������� (��. ���� ��� � �������)
                  
                    cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                    cout << "\t�������� ������:" << task[i].group.character <<
                        "\n\t�������� ������:" << task[i].title <<
                        "\n       ��������� ������:" << task[i].priority <<
                        "\n\t�������� ������:" << task[i].description <<
                        "\n ���� ���������� ������:" << task[i].date <<
                        "\n����� ���������� ������:" << task[i].time << endl;
                    cout << "\n=====================================================================\n";
                }
            }
        }
        else {
            cout << "����� ������ �����������, ����, �� ����� ������ ���������!" << endl;
        }
        fclose(td); // ����� �������� ����� � ������ � ��� ���������� ��� ������� �� ��������� ������ ������
    }

    void findTaskGroup(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "rb");
        char taskGroupFind[50];
        cout << "\t\t������� �������� ������ ��� (���, ������, ������): ";
        cin >> taskGroupFind;
        for (int i = 0; i < SIZE; i++) {
            fgets(task[i].group.character, 50, td);
            fgets(task[i].title, 50, td);
            fscanf(td, "%i\n ", &task[i].priority);
            fgets(task[i].description, 100, td);
            fgets(task[i].date, 50, td);
            fgets(task[i].time, 50, td);
            if (task[i].group.character == taskGroupFind) {
                cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                cout << "\t�������� ������:" << task[i].group.character <<
                    "\n�������� ������:" << task[i].title <<
                    "\n       ��������� ������:" << task[i].priority <<
                    "\n\t�������� ������:" << task[i].description <<
                    "\n ���� ���������� ������:" << task[i].date <<
                    "\n����� ���������� ������:" << task[i].time << endl;
                cout << "\n=====================================================================\n";
            }
            else {
                cout << "�� �����";
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
        // ��������� ������ �� ��� �����
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

        //���������� ��������� ������ ����� �������
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
            
            cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
            cout << "\t�������� ������:" << task[i].group.character <<
                "\n�������� ������:" << task[i].title <<
                "\n       ��������� ������:" << task[i].priority <<
                "\n\t�������� ������:" << task[i].description <<
                "\n ���� ���������� ������:" << task[i].date <<
                "\n����� ���������� ������:" << task[i].time << endl;
            cout << "\n=====================================================================\n";

        }
        fclose(tdSort);
    }

    /* ������� ���������� �����
    int rewriteFile(toDoList task[], int SIZE, const char* filePath) {
        SetConsoleCP(1251);
        FILE* tdRW;
        fopen_s(&tdRW, filePath, "a");
        if (!tdRW) {
            cout << "������ �������� �����!";
            return -1;
        }
        for (int i = 0; i < SIZE; i++) {
            fprintf(tdRW, "%s\n", task[i].title);
            fprintf(tdRW, "%i\n", task[i].priority);
            fprintf(tdRW, "%s\n", task[i].description);
            fprintf(tdRW, "%s\n", task[i].date);
            fprintf(tdRW, "%s\n", task[i].time);
            cout << "���� ������� �����������!";
        }
        SetConsoleCP(866);
        fclose(tdRW);
    }*/

    /* ������� �������� �������� �� ����� � ������� ������� ������ � ���������� ����������
    int removeListElement(toDoList task[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdOut;
        fopen_s(&tdOut, filePath, "wb");
        char task[50];
        cout << "������� ������� �������� ��� �������� �� ������ ���: ";
        cin >> task;
        int position = findTask(task, SIZE, filePath, task);
        if (!tdOut) {
            cout << "������ �������� �����!";
            return -1;
        }
        if (position == -1) {
            cout << "������ �� �������!";
        }
        SIZE--;
        cout << "������ �������.";
        rewriteFile(task, SIZE, filePath);
        fclose(tdOut);
    }*/
    /* ������� �������� �������� � ����������� ��������� ������ � ���� �������
    int removeListElement(toDoList task[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdDel;
        FILE* tdOut;
        fopen_s(&tdDel, deletedList, "w");
        fopen_s(&tdOut, filePath, "a");
        char findRemovTasks[50];
        cout << "������� �������� ������ ��� ������: ";
        cin >> findRemovTasks;
        for (int i = 0; i < 5; i++) {
            if (findRemovTasks == task[i].title) {
                fprintf(tdDel, "%s\n ", task[i].title);
                fprintf(tdDel, "%i\n ", task[i].priority);
                fprintf(tdDel, "%s\n ", task[i].description);
                fprintf(tdDel, "%s\n ", task[i].date);
                fprintf(tdDel, "%s\n ", task[i].time);
                cout << "������ ������� � �������!";
            }
            else {
                fprintf(tdOut, "%s\n ", task[i].title);
                fprintf(tdOut, "%i\n ", task[i].priority);
                fprintf(tdOut, "%s\n ", task[i].description);
                fprintf(tdOut, "%s\n ", task[i].date);
                fprintf(tdOut, "%s\n ", task[i].time);
                cout << "�������� ���� �����������!";
            }
        }
        fclose(tdDel);
        fclose(tdOut);
    }
    ���� �������
    void showBasket(toDoList task[], int SIZE, const char* deletedList) {
        FILE* tdDel;
        fopen_s(&tdDel, deletedList, "r");
        int choise;
        cout << "\n���������� ���������� �������? 1) ��     2) ���";
        cin >> choise;
        if (choise == 1) {
            for (int i = 0; i < 2; i++) {
                fgets(task[i].title, 50, tdDel);
                fscanf(tdDel, "%i\n ", task[i].priority);
                fgets(task[i].description, 50, tdDel);
                fgets(task[i].date, 50, tdDel);
                fgets(task[i].time, 50, tdDel);
                cout << "\t�������� ������:" << task[i].title <<
                    "\n       ��������� ������:" << task[i].priority <<
                    "\n\t�������� ������:" << task[i].description <<
                    "\n ���� ���������� ������:" << task[i].date <<
                    "\n����� ���������� ������:" << task[i].time << endl;
            }
        }
        fclose(tdDel);
    }*/

    void toDoListForTheDay(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char findTasksForTheDay[50];
        cout << "\t\t\t������� ���� ��� ��������� �����: ";
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
                cout << "\n============================" << "������ �" << i + 1 << "================================\n";
                cout << "\t�������� ������:" << task[i].group.character << "\n" <<
                    "�������� ������:" << task[i].title << "\n" <<
                    "       ��������� ������:" << task[i].priority << "\n" <<
                    "\t�������� ������:" << task[i].description << "\n" <<
                    " ���� ���������� ������:" << task[i].date << "\n" <<
                    "����� ���������� ������:" << task[i].time << endl;
                cout << "=====================================================================";
            }
        }
    }

    void toDoListForTheWeek(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char findTasksForTheWeek[50];
        cout << "\t\t\t������� ���� ��� ��������� �����: ";
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
                cout << "\n============================" << "������ �" << i + 1 << "================================\n";
                cout << "\t�������� ������:" << task[i].group.character << "\n" <<
                    "�������� ������:" << task[i].title << "\n" <<
                    "       ��������� ������:" << task[i].priority << "\n" <<
                    "\t�������� ������:" << task[i].description << "\n" <<
                    " ���� ���������� ������:" << task[i].date << "\n" <<
                    "����� ���������� ������:" << task[i].time << endl;
                cout << "=====================================================================";
            }
        }
    }

    void toDoListForTheMounth(toDoList task[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char findTasksForTheMounth[50];
        cout << "\t\t\t������� ���� ��� ��������� �����: ";
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
                cout << "\n============================" << "������ �" << i + 1 << "================================\n";
                cout << "\t�������� ������:" << task[i].group.character << "\n" <<
                    "�������� ������:" << task[i].title << "\n" <<
                    "       ��������� ������:" << task[i].priority << "\n" <<
                    "\t�������� ������:" << task[i].description << "\n" <<
                    " ���� ���������� ������:" << task[i].date << "\n" <<
                    "����� ���������� ������:" << task[i].time << endl;
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
            cout << "������ �������� �����!";
        }
        int i = 0;
        if (i >= SIZE) {
            cout << "������ ����� �����!";
        }
        else {
            do {
                cout << "������� �������� �����: ";
                cin >> ws;
                gets_s(song[i].titleSongs, 50);
                cout << "������� ������ �����: ";
                cin >> ws;
                gets_s(song[i].authorSongs, 50);
                cout << "������� ����� �����: ";
                cin >> ws;
                gets_s(song[i].songFile, 255);
                cout << "������� ��� ������ �����: ";
                cin >> ws;
                cin >> song[i].yearOfTheSongs;
                cout << "������ �������� ��� �����? [1] ��, [0] ���.";
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
        // ���������� ��������� �� ����
        FILE* Rsong;

        // ��������� ���� �� ������
        fopen_s(&Rsong, songFile, "r");
        if (!Rsong) {
            cout << "������ �������� �����!";
        }
        //�������� ������ � ��������� ������ �� �����, ����� ������� �� �� �����
        for (int i = 0; i < SIZE; i++) {
            fgets(song[i].titleSongs, 50, Rsong);
            fgets(song[i].authorSongs, 50, Rsong);
            fgets(song[i].songFile, 100, Rsong);
            fscanf(Rsong, "%i\n ", song[i].yearOfTheSongs);
            cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
            cout << "\t�������� �����: " << song[i].titleSongs <<
                "\n����� �����: " << song[i].authorSongs <<
                "\n       ����� �����: " << song[i].songFile <<
                "\n\t��� ������ �����: " << song[i].yearOfTheSongs << endl;
            cout << "\n=====================================================================\n";
        }
        fclose(Rsong);
    }

    void findSongAuthor(Songs song[], int SIZE, const char* songFile) {
        FILE* sf;
        fopen_s(&sf, songFile, "r");
        char title[50];

        cout << "\t\t�������� ����� ������ ������: ";
        cin >> title;
        for (int i = 0; i < SIZE; i++) {
            fgets(song[i].titleSongs, 50, sf);
            fgets(song[i].authorSongs, 50, sf);
            fgets(song[i].songFile, 100, sf);
            fscanf(sf, "%i\n ", song[i].yearOfTheSongs);
            if (strcmp(song[i].authorSongs, title) == 0) {
                cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                cout << "\t�������� �����: " << song[i].titleSongs <<
                    "\n����� �����: " << song[i].authorSongs <<
                    "\n       ����� �����: " << song[i].songFile <<
                    "\n\t��� ������ �����: " << song[i].yearOfTheSongs << endl;
                cout << "\n=====================================================================\n";
            }
        }
        fclose(sf);
    }

    void findWordInTheSong(Songs song[], int SIZE, const char* songFile) {
        FILE* sf;
        fopen_s(&sf, songFile, "r");
        char word[50];

        cout << "\t\t������� ����� � �� ������ ����� ��������� ���� �����: ";
        cin >> word;
        for (int i = 0; i < SIZE; i++) {
            fgets(song[i].titleSongs, 50, sf);
            fgets(song[i].authorSongs, 50, sf);
            fgets(song[i].songFile, 100, sf);
            fscanf(sf, "%i\n ", song[i].yearOfTheSongs);
            if (strcmp(song[i].songFile, word) == 0) {
                cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                cout << "\t�������� �����: " << song[i].titleSongs <<
                    "\n����� �����: " << song[i].authorSongs <<
                    "\n       ����� �����: " << song[i].songFile <<
                    "\n\t��� ������ �����: " << song[i].yearOfTheSongs << endl;
                cout << "\n=====================================================================\n";
            }
        }
        fclose(sf);
    }
}