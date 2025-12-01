#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f = fopen("input.txt", "r");
    int zero_count = 0;
    char letter;
    int number;
    int current_position = 50;

    while (!feof(f)) {
        fscanf(f, "%c%d\n", &letter, &number);
        printf("letter = %c; number = %d\n", letter, number);
        if (letter == 'R') {
            for (int i = 0; i < number; i++) {
                current_position++;
                if (current_position > 99) {
                    current_position = 0;
                }
                if (current_position == 0) {
                    zero_count++;
                }
            }
        } else {
            for (int i = 0; i < number; i++) {
                current_position--;
                if (current_position < 0) {
                    current_position = 99;
                }
                if (current_position == 0) {
                    zero_count++;
                }
            }
        }
    }
    printf("code : %d\n", zero_count);
    return 0;
}