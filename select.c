#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>

int main()
{
	fd_set read_fds; // fd_set 구조체변수선언
	struct timeval timeout; // 시간표시구조체
	int ret;
	// fd_set형 테이블 read_fds의 모든 비트를 0으로 초기화
	FD_ZERO(&read_fds);
	// read_fds 테이블에 0번 fd를 등록한다
	FD_SET(0, &read_fds);
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	puts("5초동안 입력을 기다립니다...");

	ret = select(1, &read_fds, NULL, NULL, &timeout);
	if(ret == -1) //실패
	{
		perror("select() failed");
		return 1;
	}
	else if(ret == 0) //timeout
	{
		puts("시간초과! 입력이 없습니다");
	}
	else
	{
		if(FD_ISSET(0, &read_fds))
		{
			char buf[1024];
			fgets(buf, sizeof(buf), stdin);
			printf("입력받은: %s\n", buf);
		}
	}
	return 0;
}
