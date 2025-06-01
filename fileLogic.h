


#define TEXT_EDITOR_CPP_FILELOGIC_H

#pragma once
#include <iostream>
#include "textStorage.h"

class fileLogic{
public:
    void savetoFile(const textStorage* textStorage, const char* filename);
    void loadfromFile(textStorage* textStorage, const char* filename);
};
