#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function supporting %c, %s, and %%
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                return (-1);
            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
