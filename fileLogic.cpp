
#include <iostream>
#include <fstream>
#include "textStorage.h"
#include "fileLogic.h"

void fileLogic::savetoFile(const textStorage* textStorage, const char* filename){
    std::ofstream file(filename);
    for (int i = 0; i < textStorage->count; i++){
        file << textStorage->lines[i] << std::endl;
    }
    file.close();
}
void fileLogic::loadfromFile(textStorage* textStorage, const char* filename) {
    std::ifstream file(filename);
    char buffer[1000];
    while (file.getline(buffer, sizeof(buffer), '\n')) {
        textStorage->startNewLine();
        textStorage->appendText(buffer);
    }
    file.close();
}