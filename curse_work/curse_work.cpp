#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include "header.h"
#define TODO
//#define SONGS
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
#ifdef TODO
    //const int* SIZE = new int[255]{ 0 };
    int SIZE = 5;
    int left = 0;
    int right = 0;
    toDo::toDoList task[5];
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
        toDo::appendTasks(task, SIZE, filePath);
        break;
    case 2:
        toDo::showAllList(task, SIZE, filePath);
        break;
    case 3:
        
        break;
    case 4:
        int searchTasks;
        cout << "Выберете пункт поиска дел по... \n\t[1]Названию, \n\t[2]Приоритету, \n\t[3]Описанию, \n\t[4]Дате и времени, \n\t[5]По группе(Дом, Работа, Личное)" << endl;
        cout << "\tВаш выбор: ";
        cin >> searchTasks;
        switch (searchTasks) {
        case 1:
            cout << "\t\tПоиск по названию." << endl;
            toDo::findTaskTitle(task, SIZE, filePath);
            break;
        case 2:
            cout << "\t\tПоиск по приоритету: " << endl;
            toDo::findTaskPriority(task, SIZE, filePath);
            break;
        case 3:
            cout << "\t\tПоиск по описанию: " << endl;

            break;
        case 4:
            cout << "\t\tПоиск по дате и времени: " << endl;

            break;
        case 5:
            int taskGroup;
            cout << "\t\tПоиск по группе([1]Дом, [2]Работа, [3]Личное): " << endl;
            toDo::findTaskGroup(task, SIZE, filePath);
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
            cout << "\t\t\tВы выбрали по приоритету" << endl;
            toDo:: sortByPriority(task, SIZE, filePath, left, right);
            break;
        case 2:
            cout << "\t\t\tВы выбрале по дате и времени" << endl;

            break;
        default:
            break;
        }
    case 6:
        int dispList;
        cout << "\t\tОтображение списка дел на [1]День, [2]Неделю, [3]Месяц" << endl;
        cout << "\t\tВведите вариант выбора: ";
        cin >> dispList;
        switch (dispList) {
        case 1:
            cout << "\t\t\tСписок дел на день: " << endl;
            toDo::toDoListForTheDay(task, SIZE, filePath);
            break;
        case 2:
            cout << "\t\t\tСписок дел на неделю: " << endl;

            break;
        case 3:
            cout << "\t\t\tСписок дел на месяц: " << endl;

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

#endif // TODO
    
#ifdef SONGS
//#include "header.h"
    setlocale(LC_ALL, "rus");
    int SIZE = 5;
    song::Songs song[5];
    const char* songFile = "Songs.txt";

    cout << "\n++++++++++++++++++++++++++++++++++Сборник песен!++++++++++++++++++++++++++++++++++\n";
    cout << "\n---------------------------------------MENU---------------------------------------\n";
    cout << "[1]Добавление текста песни\n" <<
        "[2]Удаление текста песни\n" <<
        "[3]Изменение текста песни\n" <<
        "[4]Отображение текста песни на экран\n" <<
        "[5]Поиск и отображение всех песен одного автора\n" <<
        "[6]Поиск песен по слову" << endl;
    int choiseMenu;
    cout << "Вы берите пункт меню: ";
    cin >> choiseMenu;
    switch (choiseMenu) {
    case 1:
        cout << "Введите название автора, текст песни и год издания." << endl;
        song::addSongs(song, SIZE, songFile);
        break;
    case 2:
        cout << "";

        break;
    case 3:
        cout << "";

        break;
    case 4:
        cout << "";
        song::showAllSongs(song, SIZE, songFile);
        break;
    case 5:
        cout << "Поиск и отображение всех песен одного автора" << endl;
        song::findSongAuthor(song, SIZE, songFile);
        break;
    case 6:
        cout << "Поиск песен по введеному слову.";
        song::findWordInTheSong(Songs song[], int SIZE, const char* songFile);
        break;
    default:
        break;
    }
#endif // SONGS

}
