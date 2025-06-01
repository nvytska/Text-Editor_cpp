#include "textStorage.h"
#include "fileLogic.h"
#include "Editor.h"
#include <iostream>
#include <string>


void printHelp(){
    printf("HELP DOCUMENTATION\n");
    printf("help    Shows help message\n");
    printf("1       Append text to the end\n");
    printf("2       Start the new line\n");
    printf("3       Enter file name for saving\n");
    printf("4       Enter file name for loading\n");
    printf("5       Print the current text to console\n");
    printf("6       Insert the text by line and symbol index\n");
    printf("7       Search text\n");
    printf("8       Delete text in line and position\n");
    printf("9       Undo\n");
    printf("10      Redo\n");
    printf("11      Cut command\n");
    printf("12      Paste command\n");
    printf("13      Copy command\n");
    printf("14      Insert with replacement\n") ;
};

int main() {
    Editor editor;
    editor.storage.startNewLine();
    char command[100];
    std::cout << "WELCOME TO THE TEXT EDITOR\n";
    fileLogic* logic = new fileLogic;
    while (true) {
        std::cout << "\nEnter the command\n> ";
        std::fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "help") == 0) {
            printHelp();
        } else if (strcmp(command, "1") == 0) {
            char *text = new char[100000];
            std::cout << "Enter text: ";
            fgets(text, sizeof(text), stdin);
            text[strcspn(text, "\n")] = '\0';
            editor.appendText(text);
        } else if (strcmp(command, "2") == 0) {
            editor.storage.startNewLine();
            std::cout << "New line started\n";
        } else if (strcmp(command, "3") == 0) {
            char filename[100];
            std::cout << "Enter file name for saving: ";
            std::fgets(filename, 100, stdin);
            filename[strcspn(filename, "\n")] = '\0';
            logic->savetoFile(&editor.storage, filename);
        } else if (strcmp(command, "4") == 0) {
            char filename[100];
            printf("Enter file name for loading: ");
            fgets(filename, 100, stdin);
            filename[strcspn(filename, "\n")] = '\0';
            logic->loadfromFile(&editor.storage, filename);
        } else if (strcmp(command, "5") == 0) {
            editor.print();
        } else if (strcmp(command, "6") == 0) {
            int line, pos;
            char substr[1000];
            printf("Enter line index: ");
            scanf("%d", &line);
            printf("Enter position: ");
            scanf("%d", &pos);
            getchar();
            printf("Enter substring: ");
            fgets(substr, 1000, stdin);
            substr[strcspn(substr, "\n")] = '\0';
            editor.insertText(substr, line, pos, false);
        } else if (strcmp(command, "7") == 0) {
            char substr[1000];
            printf("Enter substring: ");
            fgets(substr, 1000, stdin);
            substr[strcspn(substr, "\n")] = '\0';
            editor.storage.searchSubstring(&editor.storage, substr);
        } else if (strcmp(command, "8") == 0){
            int line, pos, length;
            std::cout << "Enter line index: ";
            std::cin >> line;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cout << "Enter length to delete: ";
            std::cin >> length;
            std::cin.ignore();
            editor.deleteText(line, pos, length);
        } else if (strcmp(command, "9") == 0) {
            editor.undo();
            std::cout << "Undo completed.\n";
        } else if (strcmp(command, "10") == 0) {
            editor.redo();
            std::cout << "Redo completed.\n";
        } else if (strcmp(command, "11")==0){
            int line, pos, length;
            std::cout << "Enter line index: ";
            std::cin >> line;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cout << "Enter length to delete: ";
            std::cin >> length;
            std::cin.ignore();
            editor.cutText(line, pos, length);
        } else if (strcmp(command,"12")==0){
            int line, pos;
            std::cout << "Enter line index: ";
            std::cin >> line;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cin.ignore();
            editor.pasteText(line, pos);
        } else if (strcmp(command, "13")==0){
            int line, pos, length;
            std::cout << "Enter line index: ";
            std::cin >> line;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cout << "Enter length to delete: ";
            std::cin >> length;
            std::cin.ignore();
            editor.copyText(line, pos, length);
        } else if (strcmp(command, "14")==0){
            int line, pos;
            char substr[1000];
            printf("Enter line index: ");
            scanf("%d", &line);
            printf("Enter position: ");
            scanf("%d", &pos);
            getchar();
            printf("Enter substring: ");
            fgets(substr, 1000, stdin);
            substr[strcspn(substr, "\n")] = '\0';
            editor.insertText(substr, line, pos, true);
        }
        else {
            std::cout << "Unknown command. Type 'help' for the list of commands.\n";        }
    }
    delete logic;
    return 0;
}
