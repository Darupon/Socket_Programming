#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc, char *argv[]) // 
{
	int serv_sock; // 2개의 변수선언
	int clnt_sock; // 서버와 클라이언트의 파일 디스크립트 저장

	struct sockaddr_in serv_addr; // 주소 정보 저장
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size; // 클라이언트 주소의 길이 정보

	char message[] = "Hello world!";

	if(argc! = 2)
	{
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM,0); // 최초로 소켓 생성(IPV4, 전송 방식은 TCP)
	if(serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr)); // 구조체의 멤버를  전부 0으로 초기화
	serv_addr.sin_family = AF_INET; // IPV4
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 32bit IP주소를 할당(호스트를 네트워크 형태로(근데 0으로 채움 = INADDR_ANY))
	serv_addr.sin_port = htons(atoi(argv[1])); // 

	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == 1)
		error_handling("bind() error");

	if(listen(serv_sock, 5) == -1) // 숫자 조정
		error_handling("listen() error");

	clnt_addr_size = sizeof(clnt_addr); // 클라이언트 크기
	clnt_sock = accept(serv_sock,(struct sockaddr*) &clnt_addr, &clnt_addr_size); // 서버 소켓, 주소 정보 구조체, 크기, 
	if(clnt_sock == -1)
		error_handling("accept() error");

	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
