#include <stdio.h>

int my_printf(const char *format, ...); /* Function prototype */

int main(void)
{
    my_printf("Number: %d\n", 1234);
    my_printf("Negative: %i\n", -5678);
    my_printf("Zero: %d\n", 0);
    my_printf("Multiple: %d %i %d\n", 1, -2, 3);

    return (0);
}
