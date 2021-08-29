#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

char *	g_path;
char *	g_buf;
int  	g_buf_size;


void putstr(char *str)
{
	while(*str)
		write(1,str++,1);
}

int ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_atoi(char *str)
{
	int 	i;
	int 	result;

	i = 0;
	result = 0;
	while (*str)
	{
		result = result*10 + (int)(*str - '0'); 
		str++;
	}
	return (result);
}


void display_err(char *file)
{
	putstr(basename(file));
	putstr(": ");
	putstr(file);
	putstr(": ");
	putstr(strerror(errno));
	putstr("\n");
	errno = 0;
}


void display_file(char *file)
{
	int	fd;
	int 	index;
	int 	tmp;

	index = 0;
	fd = open(file,O_RDONLY);
	if (fd == -1)
		display_err(file);
	else
	{
		if (g_buf_size == 0)
		{
			while(read(fd,g_buf,1))
			{
				if (errno)
				{
					display_err(file);
					return ;
				}
				index ++;
			}
		}
		else
		{
			tmp = 0;
			while (read(fd,g_buf+tmp,1))
			{
				index ++;
				tmp = index % g_buf_size;
			}
			if (index > g_buf_size)
				write(1,g_buf+tmp,g_buf_size-tmp);
			write(1,g_buf,tmp);
		
		}	
	}
	close(fd);
}

void display(int argc, char **argv)
{
	int 	i;
	int 	k;

	i = 2;
	k = 0;
	while (++i<argc)
	{
		if (k)
			putstr("\n");
		putstr("===> ");
		putstr(argv[i]);
		putstr(" <===\n");
		k = 1;
		display_file(argv[i]);
	}
	
	
		
}


int main(int argc, char **argv)
{
	g_path = argv[0];
	if (argc <  4)
		return (0);
	else
	{	
		g_buf_size = ft_atoi(argv[2]);
		g_buf = (char *)malloc(g_buf_size);
		display(argc,argv);
		free(g_buf);
	}
	return (0);
}

