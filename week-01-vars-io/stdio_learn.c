#include <stdio.h>

void file();

int main(int argc, int * argv[]) {

    return 0;
}

void file() {
    
    FILE * file;
    /*
     * ^ FILE is a complex data structure used as pointer to files.
     * Copying with  FILE f = * file is NOT allowed!
     * Stores:
     * 1. Posix file discriptor (number for system to find)
     * 2. Buffering state: full buffered (waits all), line-buffered (waits '\n', stdout), unbuffered (stderr)
     * 3. Remembers I/O mode and binary/text. Here I open in read 'r'
     * 4. Indicators (error and EOF bits)
     * 5. File position indicator
     * Also there is a wide/narrow character and their funtions cannot be mixed.
     */

    /*
     * stdin    -   standard input stream, reads conventional input.
     * stdout   -   standard output stream, writes conventional output.
     * stderr   -   standard error stream, writes diagnostic output. (Needs to throw immediately)
     *
     * Both stdin and stdout at program startup are fully buffered if and only if the stream can be determined
     *      to not refer to an interactive device. The stderr at the start is not fully buffered
     * In POSIX stdin and stdout are line-buffered when terminal and stderr is unbuffered.
     */

    file = fopen("example.txt", "r+");
    // fopen is a function that opens a file, takes filename and a mode.
    // Filename - may include absolute or relative filesystem path. 
    // Mode shows access to file. Read, write, append. More on https://en.cppreference.com/c/io/fopen
    // If tries to read non-existing - throughs error, other way creates a new file.
    // Also mode "b" allows in binary. No effect on POSIX, on Windows ignores '\n'
    // Extended '+' requires to be careful with streamptr
    // Mode 'x' with 'w' returns error if the file exists instead of overwriting

    if (file == NULL) {
        printf("Error: file do not exist");
        return;
    }
}
