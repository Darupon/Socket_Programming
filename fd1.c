#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
	int fd;

	fd = open("a.txt", O_CREAT | O_RDONLY);
	if(fd < 0)
	{
		perror("Could not open a.txt");
		exit(1);
	}
	else
	{
		printf("Successfully open");
		printf("file discriptor: %d\n", fd);
	}

	close(fd); // 열어줬던 파일 닫아줘야함
}
