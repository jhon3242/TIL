#include <fcntl.h>
#include <unistd.h>
void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void    print_file(int argc, char **argv)
{
    char    buf;
    int     i;
    int     fd;
    
    
    i = 1;
    while (i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd >0)
        {
            while (read(fd, &buf, 1) != 0)
                write(1, &buf, 1);
        }else
        {
            ft_putstr("ft_cat: ");
            ft_putstr(argv[i]);
            ft_putstr(": No such file or directory\n");
        }
        close(fd);
        i++;
    }
}

void print_stdin(void)
{
    char    buf;
    while (read(0, &buf, 1) != 0)
        write(1, &buf, 1);
}



int main(int argc ,char **argv)
{
    if (argc < 2)
        print_stdin();
    print_file(argc, argv);
    return (0);
}
