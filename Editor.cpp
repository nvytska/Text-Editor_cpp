//
// Created by Наталія Вицька on 01.06.2025.
//

#include <iostream>
#include <cstring>
#include <stack>
#include "textStorage.h"
#include "Editor.h"

    void Editor::appendText( char* text) {
        int line;
        int pos;
        if (storage.count == 0) {
            line = 0;
            pos = 0;
        } else {
            line = storage.count - 1;
            pos = strlen(storage.lines[line]);
        }
        storage.appendText(text);
        Action act = { APPEND, line, pos, strdup(text), false };
        undoStack.push(act);
        clearRedo();
    }
    void Editor::insertText( char* text, int line, int pos, bool replace) {
        storage.insertSubstring(text, line, pos, replace);
        Action act = { INSERT, line, pos, strdup(text), replace };
        undoStack.push(act);
        clearRedo();
    }

    void Editor::deleteText(int line, int pos, int length) {
        char* deleted = new char[length + 1];
        storage.getSubstring(deleted, line, pos, length);
        storage.deleteSubstring(line, pos, length);
        Action act = { DELETE, line, pos, deleted, false };
        undoStack.push(act);
        clearRedo();
    }
    void Editor::undo() {
        if (undoStack.empty()) return;
        Action act = undoStack.top(); undoStack.pop();
        switch (act.type) {
            case APPEND:
            case INSERT:
                storage.deleteSubstring(act.line, act.pos, strlen(act.text));
                break;
            case DELETE:
                storage.insertSubstring(act.text, act.line, act.pos, false);
                break;
        }
        redoStack.push(act);
    }

    void Editor::redo() {
        if (redoStack.empty()) return;
        Action act = redoStack.top(); redoStack.pop();
        switch (act.type) {
            case APPEND:
            case INSERT:
                storage.insertSubstring(act.text, act.line, act.pos, act.replace);
                break;
            case DELETE:
                storage.deleteSubstring(act.line, act.pos, strlen(act.text));
                break;
        }
        undoStack.push(act);
    }

    void Editor::print() {
        storage.printText();
    }
void Editor::clearRedo() {
    while (!redoStack.empty()) {
        free(redoStack.top().text);
        redoStack.pop();
    }

}
void Editor::copyText(int line, int pos, int length) {
    if (clipboard) free(clipboard);
    clipboard = new char[length + 1];
    storage.getSubstring(clipboard, line, pos, length);
}

void Editor::cutText(int line, int pos, int length) {
    copyText(line, pos, length);
    deleteText(line, pos, length);
}

void Editor::pasteText(int line, int pos) {
    if (clipboard) {
        insertText(clipboard, line, pos, false);
    }
}





