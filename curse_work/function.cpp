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
            cout << "������ �������� �����!";
        }
        int i = 0;
        if (i >= SIZE) {
            cout << "������ ����� �����!";
        }
        else {
            do {
                cout << "������� ��������� ������: ";
                cin >> ws;
                gets_s(list[i].title, 50);
                cout << "������� ���������� ������: ";
                cin >> ws;
                cin >> list[i].priority;
                cout << "������� ��������� �������� ������: ";
                cin >> ws;
                gets_s(list[i].description, 100);
                cout << "������� ���� ���������� ������: ";
                cin >> ws;
                gets_s(list[i].date, 50);
                cout << "������� ����� ���������� ������: ";
                cin >> ws;
                gets_s(list[i].time, 50);
                cout << "������ �������� ��� ������? [1] ��, [0] ���.";
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
        // ���������� ��������� �� ����
        FILE* tdOut;

        // ��������� ���� �� ������
        fopen_s(&tdOut, filePath, "r");
        if (!tdOut) {
            cout << "������ �������� �����!";
        }
        //�������� ������ � ��������� ������ �� �����, ����� ������� �� �� �����
        for (int i = 0; i < SIZE; i++) {
            fgets(list[i].title, 50, tdOut);
            fscanf(tdOut, "%i\n ", &list[i].priority);
            fgets(list[i].description, 100, tdOut);
            fgets(list[i].date, 50, tdOut);
            fgets(list[i].time, 50, tdOut);
            cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
            cout << "\t�������� ������:" << list[i].title <<
                "\n       ��������� ������:" << list[i].priority <<
                "\n\t�������� ������:" << list[i].description <<
                "\n ���� ���������� ������:" << list[i].date <<
                "\n����� ���������� ������:" << list[i].time << endl;
            cout << "\n=====================================================================\n";
        }
        fclose(tdOut);
    }

    void findTaskTitle(toDoList list[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        char task[50];
        cout << "\t\t������� �������� ������ ��� ������: ";
        cin >> task;
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (_strcmpi(list[i].title, task) == 0) {
                /*fgets(list[i].title, 50, td);
                fscanf(td, "%i\n ", &list[i].priority);
                fgets(list[i].description, 100, td);
                fgets(list[i].date, 50, td);
                fgets(list[i].time, 50, td);
                cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                cout << "\t�������� ������:" << list[i].title <<
                    "\n       ��������� ������:" << list[i].priority <<
                    "\n\t�������� ������:" << list[i].description <<
                    "\n ���� ���������� ������:" << list[i].date <<
                    "\n����� ���������� ������:" << list[i].time << endl;
                cout << "\n=====================================================================\n";*/
                cout << "�����";
                count++;
            }
            else {
                cout << "�� �����";
            }
        }
        fclose(td);
    }

    void findTaskPriority(toDoList list[], int SIZE, const char* filePath) {
        FILE* td;
        fopen_s(&td, filePath, "r");
        int taskPrior;
        cout << "\t\t������� ��������� �� 1 �� 3 ��� ������: ";
        cin >> taskPrior;
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (list[i].priority == taskPrior) {
                /*fgets(list[i].title, 50, td);
                fscanf(td, "%i\n ", &list[i].priority);
                fgets(list[i].description, 100, td);
                fgets(list[i].date, 50, td);
                fgets(list[i].time, 50, td);
                cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
                cout << "\t�������� ������:" << list[i].title <<
                    "\n       ��������� ������:" << list[i].priority <<
                    "\n\t�������� ������:" << list[i].description <<
                    "\n ���� ���������� ������:" << list[i].date <<
                    "\n����� ���������� ������:" << list[i].time << endl;
                cout << "\n=====================================================================\n";*/
                cout << "�����";
                count++;
            }
            else {
                cout << "�� �����";
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
        // ��������� ������ �� ��� �����
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

        //���������� ��������� ������ ����� �������
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
            cout << "\n===================================" << "������ �" << i + 1 << "=======================================\n";
            cout << "\t�������� ������:" << list[i].title <<
                "\n       ��������� ������:" << list[i].priority <<
                "\n\t�������� ������:" << list[i].description <<
                "\n ���� ���������� ������:" << list[i].date <<
                "\n����� ���������� ������:" << list[i].time << endl;
            cout << "\n=====================================================================\n";

            fclose(tdSort);
        }
        
    }

    /* ������� ���������� �����
    int rewriteFile(toDoList list[], int SIZE, const char* filePath) {
        SetConsoleCP(1251);
        FILE* tdRW;
        fopen_s(&tdRW, filePath, "a");
        if (!tdRW) {
            cout << "������ �������� �����!";
            return -1;
        }
        for (int i = 0; i < SIZE; i++) {
            fprintf(tdRW, "%s\n", list[i].title);
            fprintf(tdRW, "%i\n", list[i].priority);
            fprintf(tdRW, "%s\n", list[i].description);
            fprintf(tdRW, "%s\n", list[i].date);
            fprintf(tdRW, "%s\n", list[i].time);
            cout << "���� ������� �����������!";
        }
        SetConsoleCP(866);
        fclose(tdRW);
    }*/

    /* ������� �������� �������� �� ����� � ������� ������� ������ � ���������� ����������
    int removeListElement(toDoList list[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdOut;
        fopen_s(&tdOut, filePath, "wb");
        char task[50];
        cout << "������� ������� �������� ��� �������� �� ������ ���: ";
        cin >> task;
        int position = findTask(list, SIZE, filePath, task);
        if (!tdOut) {
            cout << "������ �������� �����!";
            return -1;
        }
        if (position == -1) {
            cout << "������ �� �������!";
        }
        SIZE--;
        cout << "������ �������.";
        rewriteFile(list, SIZE, filePath);
        fclose(tdOut);
    }*/
    /* ������� �������� �������� � ����������� ��������� ������ � ���� �������
    int removeListElement(toDoList list[], int SIZE, const char* filePath, const char* deletedList) {
        FILE* tdDel;
        FILE* tdOut;
        fopen_s(&tdDel, deletedList, "w");
        fopen_s(&tdOut, filePath, "a");
        char findRemovTasks[50];
        cout << "������� �������� ������ ��� ������: ";
        cin >> findRemovTasks;
        for (int i = 0; i < 5; i++) {
            if (findRemovTasks == list[i].title) {
                fprintf(tdDel, "%s\n ", list[i].title);
                fprintf(tdDel, "%i\n ", list[i].priority);
                fprintf(tdDel, "%s\n ", list[i].description);
                fprintf(tdDel, "%s\n ", list[i].date);
                fprintf(tdDel, "%s\n ", list[i].time);
                cout << "������ ������� � �������!";
            }
            else {
                fprintf(tdOut, "%s\n ", list[i].title);
                fprintf(tdOut, "%i\n ", list[i].priority);
                fprintf(tdOut, "%s\n ", list[i].description);
                fprintf(tdOut, "%s\n ", list[i].date);
                fprintf(tdOut, "%s\n ", list[i].time);
                cout << "�������� ���� �����������!";
            }
        }
        fclose(tdDel);
        fclose(tdOut);
    }
    ���� �������
    void showBasket(toDoList list[], int SIZE, const char* deletedList) {
        FILE* tdDel;
        fopen_s(&tdDel, deletedList, "r");
        int choise;
        cout << "\n���������� ���������� �������? 1) ��     2) ���";
        cin >> choise;
        if (choise == 1) {
            for (int i = 0; i < 2; i++) {
                fgets(list[i].title, 50, tdDel);
                fscanf(tdDel, "%i\n ", list[i].priority);
                fgets(list[i].description, 50, tdDel);
                fgets(list[i].date, 50, tdDel);
                fgets(list[i].time, 50, tdDel);
                cout << "\t�������� ������:" << list[i].title <<
                    "\n       ��������� ������:" << list[i].priority <<
                    "\n\t�������� ������:" << list[i].description <<
                    "\n ���� ���������� ������:" << list[i].date <<
                    "\n����� ���������� ������:" << list[i].time << endl;
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
