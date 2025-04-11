#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
	int fd = 0;
	char buf[20];
	ssize_t read_sz; // 입출력함수에서 성공여부를 확인하기 위해 사용
	
	fd = open("hello.txt", O_RDONLY);

	if(fd < 0)
	{
		perror("could not open");
		exit(1);
	}

	read_sz = read(fd, buf, sizeof(buf));

	if(read_sz < 0)
	{
		perror("failed to read from file");
		exit(1);
	}
	printf("Read from file: %s\n", buf);

	close(fd);
}
