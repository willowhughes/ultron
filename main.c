#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ultron.h"

// count.u
// for dr tan: do i need to leave the branch as checking for negative
// or can i change to check positive
// and what to study for on exam


int main(int argc, char** argv) {
    Ultron my_ultron;
    ultron_init(&my_ultron);
    FILE *file;
    int instructions[32];
    int num_of_instructions = 32;
    int line = 0;
    int option = 0;
    int i_flag = 0;
    int f_flag = 0;

    for (int i = 0; i < 32; i++) {
        instructions[i] = 0;
    }

    while ((option = getopt(argc, argv, "if")) != -1) {
        if (option == 'i') {
            if (f_flag) {
                fprintf(stderr, "Error: Cannot use both -i and -f options.\n");
                return 1;
            }
            i_flag = 1;
        } else if (option == 'f') {
            if (i_flag) {
                fprintf(stderr, "Error: Cannot use both -i and -f options.\n");
                return 1;
            }
            f_flag = 1;
        } else {
            fprintf(stderr, "Usage: %s -f <value>\n", argv[0]);
            return 1;
        }
    }

    if (i_flag) {
        if (argv[2] != NULL) {
            num_of_instructions = atoi(argv[2]);
        }
        for (int i = 0; i < num_of_instructions; i++) {
                if (num_of_instructions > 32) {
                    printf("too many lines (less than 33)\n");
                    return 1;
                }
                scanf("%d", &line);
                instructions[i] = line;
        }
    } else if (f_flag) {
        char file_name[30];
        if (argv[2] == NULL) {
                scanf("%s", file_name);
                printf("%s", file_name);
        } else {
            snprintf(file_name, sizeof(file_name), "%s", argv[2]);
        }

        num_of_instructions = 0;
        file = fopen(file_name, "r");
        if (file == NULL) {
            printf("Error opening the file\n");
            return 1;
        }
        while (fscanf(file, "%d", &line) != EOF) {
            if (num_of_instructions >= 32) {
                printf("too many lines in file\n");
                return 1;
            }
            instructions[num_of_instructions] = line;
            num_of_instructions++;
        }
        for (int i = 0; i < 32; i++) {
            printf("%d\n", instructions[i]);
        }
        fclose(file);
    } else {
        printf("need a flag (-i or -f)\n");
        return 1;
    }

    ultron_load(&my_ultron, num_of_instructions, instructions);
    printf("Result: %d\n", ultron_run(&my_ultron));
    ultron_dump(&my_ultron);
    return 0;
}
