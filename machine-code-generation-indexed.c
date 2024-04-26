#include <stdio.h>
#include <stdint.h>

void generate_machine_code()
{
    uint32_t array[10] = {0};
    uint32_t index = 3;

    array[index] = 42;

    printf("Machine code for indexed assignment statement:\n");
    printf("lw $t0, %lu($zero)\n", index * sizeof(uint32_t));
    printf("li $t1, 42\n");
    printf("la $t2, array\n");
    printf("sw $t1, 0($t2, $t0)\n");
}

int main()
{
    generate_machine_code();
    return 0;
}
