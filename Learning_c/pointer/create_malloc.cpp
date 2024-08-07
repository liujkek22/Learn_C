#include <iostream>
#include <cstring>
#include <cstdlib>


char* return_test(void) {
    const char a[20] = "hello world!";
    char* NewChar = (char*)malloc(sizeof(char) * 20);
    if (NewChar != NULL) {
        strcpy_s(NewChar, 20, a); // Using strcpy_s
        return NewChar;
    }
    else {
        std::cout << "malloc error!" << std::endl;
        return NULL;
    }
}