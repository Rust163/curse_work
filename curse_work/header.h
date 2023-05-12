#pragma once

namespace toDo {
    struct GroupTask {
        char character[50];
    };

    struct toDoList {
        GroupTask group;
        char title[50];
        int priority;
        char description[100];
        char date[50];
        char time[50];
    };

    //void addList(toDoList list[], int SIZE, const char* filePath);
    void showAllList(toDoList list[], int SIZE, const char* filePath);
    void appendTasks(toDoList list[], int SIZE, const char* filePath);
    void findTaskTitle(toDoList list[], int SIZE, const char* filePath);
    void findTaskPriority(toDoList list[], int SIZE, const char* filePath);
    void findTaskGroup(toDoList list[], int SIZE, const char* filePath);
    void sortByPriority(toDoList list[], int SIZE, const char* filePath, int left, int right);
    //int rewriteFile(toDoList list[], int SIZE, const char* filePath);
    //int removeListElement(toDoList list[], int SIZE, const char* filePath, const char* deletedList);
    //void showBasket(toDoList list[], int SIZE, const char* deletedList);
}

namespace song {
    struct Songs {
        char titleSongs[50]{0};
        char authorSongs[50]{0};
        char songFile[255]{0};
        int  yearOfTheSongs{0};
    };

    void addSongs(Songs song[], int SIZE, const char* songFile);
    void showAllSongs(Songs song[], int SIZE, const char* songFile);
    void findSongAuthor(Songs song[], int SIZE, const char* songFile);
}