#pragma once

namespace toDo {
    struct toDoList {
        char title[50];
        int priority;
        char description[100];
        char date[50];
        char time[50];
    };

    void addList(toDoList list[], int SIZE, const char* filePath);
    void showAllList(toDoList list[], int SIZE, const char* filePath);
    void appendTasks(toDoList list[], int SIZE, const char* filePath);
    void findTaskTitle(toDoList list[], int SIZE, const char* filePath);
    void findTaskPriority(toDoList list[], int SIZE, const char* filePath);
    void sortByPriority(toDoList list[], int SIZE, const char* filePath, int left, int right);
    //int rewriteFile(toDoList list[], int SIZE, const char* filePath);
    //int removeListElement(toDoList list[], int SIZE, const char* filePath, const char* deletedList);
    //void showBasket(toDoList list[], int SIZE, const char* deletedList);
}

namespace song {
    struct Songs {
        char titleSongs[50];
        char authorSongs[50];
        char textSongs[100];
        const char* songFile1 = "Songs1.txt";
        const char* songFile2 = "Songs2.txt";
        const char* songFile3 = "Songs3.txt";
        const char* songFile4 = "Songs4.txt";
        const char* songFile5 = "Songs5.txt";
        int  yearOfTheSongs;
    };

    void addSongs(Songs song[], int SIZE, const char* songFile);
    void showAllSongs(Songs song[], int SIZE, const char* songFile);
    void findSongAuthor(Songs song[], int SIZE, const char* songFile);
}