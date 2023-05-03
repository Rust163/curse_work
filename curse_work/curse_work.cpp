#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include "header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //const int* SIZE = new int[255]{ 0 };
    int SIZE = 5;
    int left = 0;
    int right = 0;
    toDo::toDoList list[5];
    const char* filePath = "ToDo_list.txt";
    const char* deletedList = "ToDo_list_deleted.txt";

    cout << "\n************************************To Do list***************************************\n";
   
    time_t mytime = time(NULL);
    struct tm* now = localtime(&mytime);
    cout << "\t\t\t\t  Дата: " << now->tm_mday << "." << now->tm_mon + 1 << "." << now->tm_year + 1900 << endl;
    cout << "\t\t\t\t  Время: " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;

    cout << "\n---------------------------------------Menu---------------------------------------\n";

    cout << "[1] Добавить задачи.\n";
    cout << "[2] Показать полный список задач.\n";
    cout << "[3] Редактировать задачу.\n";
    cout << "[4] Поиск дел по:\n";
    cout << "[5] Сортировка списка задач по:\n";
    cout << "[6] Отображение списка дел:\n";
    int changeMenu = 0;
    cout << "Введите порядковый номер меню: ";
    cin >> changeMenu;
    switch (changeMenu) {
    case 1:
        toDo::appendTasks(list, SIZE, filePath);
        break;
    case 2:
        toDo::showAllList(list, SIZE, filePath);
        break;
    case 3:
        
        break;
    case 4:
        int searchTasks;
        cout << "Выберете пункт поиска дел по... \n\t[1]Названию, \n\t[2]Приоритету, \n\t[3]Описанию, \n\t[4]Дате и времени" << endl;
        cout << "\tВаш выбор: ";
        cin >> searchTasks;
        switch (searchTasks) {
        case 1:
            cout << "\t\tПоиск по названию." << endl;
            toDo::findTaskTitle(list, SIZE, filePath);
            break;
        case 2:
            cout << "\t\tПоиск по приоритету: " << endl;
            toDo::findTaskPriority(list, SIZE, filePath);
            break;
        case 3:
            cout << "Поиск по описанию: " << endl;

            break;
        case 4:
            cout << "Поиск по дате и времени: " << endl;

            break;
        default:
            break;
        }
        //toDo::removeListElement(list, SIZE, filePath, deletedList);
        break;
    case 5:
        int sortChange;
        cout << "\t\tСортировка задач по ...\n\t\t [1]Приоритету.\n\t\t [2]По дате и времени" << endl;
        cout << "\t\tВыберете пункт: ";
        cin >> sortChange;
        switch (sortChange) {
        case 1:
            cout << "\t\t\tВы выбрале по приоритету" << endl;
            toDo:: sortByPriority(list, SIZE, filePath, left, right);
            break;
        case 2:
            cout << "\t\t\tВы выбрале по дате и времени" << endl;

            break;
        default:
            break;
        }
    case 6:
        int dispList;
        cout << "Отображение списка дел на [1]День, [2]Неделю, [3]Месяц" << endl;
        cout << "Введите вариант выбора: ";
        cin >> dispList;
        switch (dispList) {
        case 1:
            cout << "Список дел на день: " << endl;

            break;
        case 2:
            cout << "Список дел на неделю: " << endl;

            break;
        case 3:
            cout << "Список дел на месяц: " << endl;

            break;
        default:
            break;
        }
        break;
        //toDo::showBasket(list, SIZE, deletedList);
        break;
    default:
        break;
    }
    
}
