#include <stdarg.h>
#include <unistd.h>

void print_int(int n)
{
    char buffer[10];
    int i;
    int j;
    int num;

    i = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num == 0)
    {
        write(1, "0", 1);
        return;
    }

    while (num > 0)
    {
        buffer[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
    }
}

int my_printf(const char *format, ...)
{
    va_list args;
    int i;
    int num;

    va_start(args, format);
    i = 0;

    while (format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
            num = va_arg(args, int);
            print_int(num);
            i++; /* skip the format character */
        }
        else
        {
            write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return (0);
}
