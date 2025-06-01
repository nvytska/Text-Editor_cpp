//
// Created by Наталія Вицька on 01.06.2025.
//

#ifndef TEXT_EDITOR_CPP_EDITOR_H
#define TEXT_EDITOR_CPP_EDITOR_H
#include <iostream>
#include <cstring>
#include <stack>
#include "textStorage.h"


enum ActionType { APPEND, INSERT, DELETE };

struct Action {
    ActionType type;
    int line;
    int pos;
    char* text;
    bool replace;
};

class Editor {
public:
    textStorage storage;
    std::stack<Action> undoStack;
    std::stack<Action> redoStack;
    char* clipboard = nullptr;

    void appendText(char *text);

    void insertText(char *text, int line, int pos, bool replace = false);

    void deleteText(int line, int pos, int length);
    void print();
    void undo();
    void redo();
    void clearRedo();

    void copyText(int line, int pos, int length);
    void cutText(int line, int pos, int length);
    void pasteText(int line, int pos);
};



#endif //TEXT_EDITOR_CPP_EDITOR_H
