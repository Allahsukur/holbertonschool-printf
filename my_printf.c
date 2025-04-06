#include <stdarg.h>
#include <unistd.h>

void print_int(int n) {
    char buffer[10];
    int i = 0;
    int j;

    /* Handle negative numbers */
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }

    /* Handle zero */
    if (n == 0) {
        write(1, "0", 1);
        return;
    }

    /* Convert integer to string in reverse order */
    while (n > 0) {
        buffer[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }

    /* Print the digits in correct order */
    for (j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
    }
}

int my_printf(const char *format, ...) {
    va_list args;
    int i;
    int num;

    va_start(args, format);
    i = 0;

    while (format[i]) {
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
            num = va_arg(args, int);
            print_int(num);
            i++; /* Skip the specifier character */
        } else {
            write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return 0;
}
