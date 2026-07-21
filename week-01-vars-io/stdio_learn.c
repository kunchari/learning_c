#include <stdio.h>

void file();

int main(int argc, int * argv[]) {

    return 0;
}

void file() {
    FILE * file = fopen("example.txt", "r");
    // ^ FILE is a complex data structure used as pointer to files.
    // Copying with  FILE f = * file is NOT allowed!
    // It keeps (including POSIX file descriptor):
    // 1. Character width
    // 2.
}
