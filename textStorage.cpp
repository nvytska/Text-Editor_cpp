//
// Created by Наталія Вицька on 01.06.2025.
//

#include "textStorage.h"

textStorage::textStorage(){
    count = 0;
    capacity = 100;
    lines = new char*[capacity];
    for (int i = 0; i < capacity; i++) {
        lines[i] = nullptr;
    }
}
textStorage::~textStorage(){
    for (int i = 0; i < count; i++) {
        delete[] lines[i];
    }
    delete[] lines;
}

void textStorage::appendText( char* text){
    if (count == 0){
        lines[0] = new char[strlen(text) + 1];
        strcpy(lines[0], text);
        count =1;
    } else{
        int last = count - 1;
        int oldLen = strlen(lines[last]);
        int newLen = oldLen + strlen(text);
        char* newline = new char[newLen+1];
        strcpy(newline, lines[last]);
        strcat(newline, text);
        delete[] lines[last];
        lines[last] = newline;
    }
}

void textStorage::startNewLine(){
    lines[count] = new char [1];
    lines[count][0] = '\0';
    count++;
}

void textStorage::printText() {
    for (int i = 0; i < count; i++) {
        std::cout << lines[i] << std::endl;
    }
}

void textStorage::searchSubstring(textStorage* textStorage, char* substr){
    for (int i = 0; i < textStorage->count; i++) {
        char* pos =  textStorage->lines[i];
        while ((pos = strstr(pos, substr)) != NULL){
            std::cout << "Found in line" << lines << "in position" << pos << std::endl;
            pos++;
        }
    }
}

void textStorage::insertSubstring( char* substr,int line_idx, int pos, bool replace){
    char* line = lines[line_idx];
    int len = strlen(line);
    int sublen = strlen(substr);
    char* newLine = new char[len+ sublen + 1];
    strncpy(newLine, line, pos);
    newLine[pos] = '\0';
    strcat(newLine, substr);
    if (!replace){
        strcat(newLine, line + pos);
    }


    delete[] lines[line_idx];
    lines[line_idx] = newLine;
}

void textStorage::deleteSubstring(int line_idx, int pos, int lenght){
    char* line = lines[line_idx];
    int len = strlen(line);
    char* newLine = new char[len - lenght +1];
    strncpy(newLine, line, pos);
    newLine[pos] = '\0';
    strcat(newLine, line + pos+lenght);
    delete[] lines[line_idx];
    lines[line_idx] = newLine;
}
void textStorage::getSubstring(char* dest, int line_idx, int pos, int length) {
    strncpy(dest, lines[line_idx] + pos, length);
    dest[length] = '\0';
}