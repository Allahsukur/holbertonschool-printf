#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == '%' && (*(ptr + 1) == 'c' || *(ptr + 1) == 's' || *(ptr + 1) == '%')) {
            ptr++;  // Move past '%' to check the specifier
            if (*ptr == 'c') {
                char c = va_arg(args, int);  // 'c' expects an int, not a char
                write(1, &c, 1);
                count++;
            } else if (*ptr == 's') {
                char *str = va_arg(args, char*);
                for (int i = 0; str[i] != '\0'; i++) {
                    write(1, &str[i], 1);
                    count++;
                }
            } else if (*ptr == '%') {
                write(1, "%", 1);
                count++;
            }
        } else {
            write(1, ptr, 1);  // Regular character
            count++;
        }
    }

    va_end(args);
    return count;
}
