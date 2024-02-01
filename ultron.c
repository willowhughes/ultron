#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ultron.h"


void ultron_init(Ultron* ultron) {
    ultron->pc = 0;
    ultron->ac = 0;
    for (int i = 0; i < ULTRON_MEMORY_SIZE; i++) {
        ultron->memory[i] = 0;
    }
}

void ultron_dump(Ultron* ultron) {
    printf("PC: %d\n", ultron->pc);
    printf("AC: %d\n", ultron->ac);
    for (int i = 0; i < ULTRON_MEMORY_SIZE; i++) {
        printf("%2d %4d\n", i, ultron->memory[i]);
    }
}

int ultron_memory(Ultron* ultron, int location) {
    return ultron->memory[location];
}

int ultron_accumulator(Ultron* ultron) {
    return ultron->ac;
}

int ultron_pc(Ultron* ultron) {
    return ultron->pc;
}

void ultron_load(Ultron* ultron, int size, int* instructions) {
    for (int i = 0; i < size; i++) {
        ultron->memory[i] = instructions[i];
    }
}

int ultron_run(Ultron* ultron) {
    int instruction = 0;
    int operation = 0;
    int operand = 0;
    while (1) {
        instruction = ultron->memory[ultron->pc];
        operation = instruction / 100;
        operand = instruction % 100;
        if (ultron->pc > 31 || ultron->pc < 0) {
            return -3;
        }
        if (operand > 31 || operand < 0) {
            return -2;
        }
        switch (operation) {
            case READ:
                printf("? ");
                scanf("%d", &ultron->memory[operand]);
                break;
            case WRITE:
                printf("= %d\n", ultron->memory[operand]);
                break;
            case LOAD:
                ultron->ac = ultron->memory[operand];
                break;
            case STORE:
                ultron->memory[operand] = ultron->ac;
                break;
            case ADD:
                ultron->ac += ultron->memory[operand];
                break;
            case SUBTRACT:
                ultron->ac -= ultron->memory[operand];
                break;
            case BRANCHNEG:
                if (ultron->ac < 0) {
                    ultron->pc = operand;
                    ultron->pc--;
                }
                break;
            case HALT:
                return 0;
            default:
                return -1;
        }
    ultron->pc++;
    }
}
