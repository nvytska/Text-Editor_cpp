//
// Created by Наталія Вицька on 01.06.2025.
//


#define TEXT_EDITOR_CPP_TEXTSTORAGE_H


#pragma once
#include <iostream>

class textStorage{

public:
    char** lines;
    int count;
    int capacity;


    textStorage();
    ~textStorage();
    void appendText( char* text);
    void startNewLine();
    void printText();
    void searchSubstring(textStorage* textStorage, char* substr);
    void insertSubstring( char* substr,int line_idx, int pos, bool replace);
    void deleteSubstring(int line_idx, int pos, int lenght);
    void getSubstring(char* dest, int line_idx, int pos, int length);

};
