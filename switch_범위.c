#include <stdio.h>
int main(void) {
    int input=2;
    switch(input) {
        default:
            printf("hello\n");
            break;
        case 0 ... 5:
            printf("이욜\n");
            break;
        case 6 ... 10:
            printf("과연 \n");
            break;
        }
    return 0;
}