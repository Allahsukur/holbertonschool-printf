#include <stdarg.h>
#include <unistd.h>

void print_int(int n) {
    if (n < 0) {
        write(1, "-", 1);  /* Print minus sign for negative numbers */
        n = -n;  /* Make n positive */
    }

    char buffer[10];
    int i = 0;

    /* Convert integer to string (reversed) */
    if (n == 0) {
        write(1, "0", 1);
        return;
    }

    while (n > 0) {
        buffer[i++] = (n % 10) + '0';  /* Get the last digit and convert to ASCII */
        n = n / 10;
    }

    /* Reverse the string and print it */
    int j;
    for (j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
    }
}

/* Example of how your printf function might look: */
int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int i = 0;
    while (format[i]) {
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
            int num = va_arg(args, int);
            print_int(num);
            i++;  /* Skip the %d or %i */
        } else {
            write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return 0;
}
