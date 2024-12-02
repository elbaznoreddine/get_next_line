#include "get_next_line.h"

void	f()
{
	system("leaks a.out");
}
int main()
{
	int fd = open("txt.txt", O_RDWR | O_CREAT, 0777);
	char *str;

	//printf("%s", get_next_line(fd));
	while ((str  = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	atexit(f);
}