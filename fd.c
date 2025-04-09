#include <stdio.h>

int main()
{	
	int fd1 = 0;
	int fd2 = 0;
	int fd3 = 0;

	fd1 = fileno(stdin);
	fd2 = fileno(stdout);
	fd3 = fileno(stderr);

	printf("file descriptor for stdin: %d\n", fd1);
	printf("file descriptor for stdout: %d\n", fd2);
	printf("file discriptor for stderr: %d\n", fd3);

	return 0;
}
