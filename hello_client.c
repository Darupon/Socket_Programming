#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_addr; // 서버의 주소를 저장할 구조체
	char message[30];
	int str_len; // 문자열 길이 저장할 변수

	if(argc!=3)
	{
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	// 소켓 생성
	sock = socket(PF_INET, SOCK_STREAM, 0); // IPV4, TCP / 소켓 생성
	if(sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr)); // 서버 주소 0으로 초기화
	serv_addr.sin_family = AF_INET; //IPV4 주소
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // 32비트 주소
	serv_addr.sin_port = htons(atoi(argv[2])); // 문자열로 저장한 포트번호를 정수 형태로 변화 host -> network byte

	// 연결 요청
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) // 소켓, 서버의 주소
		error_handling("connect() error!");

	str_len = read(sock, message, sizeof(message)-1);
	if(str_len == -1)
		error_handling("read() error!");

	printf("Message from server: %s \n", message);
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
