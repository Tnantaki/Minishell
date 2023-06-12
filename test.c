#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    char* termtype = getenv("TERM");
    if (termtype == NULL) {
        fprintf(stderr, "TERM environment variable not set\n");
        return 1;
    }
    
    int success = tgetent(NULL, termtype);
    if (success < 0) {
        fprintf(stderr, "Failed to load termcap database\n");
        return 1;
    }
    else if (success == 0) {
        fprintf(stderr, "Terminal type '%s' not found in termcap database\n", termtype);
        return 1;
    }
    
    // Retrieve the escape sequence for changing text color
    char* setcolor = tgetstr("setaf", NULL);
    if (setcolor == NULL) {
        fprintf(stderr, "Terminal does not support changing text color\n");
        return 1;
    }
    
    // Print the color escape sequence and the prompt
    printf("%s%d%s%s\n", setcolor, 2, "Hello, world!", tgetstr("sgr0", NULL));
    
    return 0;
}