//#include <jwt-cpp/jwt.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "pthread.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <unistd.h>

using namespace std;
using namespace rapidjson;



int icount = 0;

bool SendMsg(string& strHandleMsg) {
	
	icount++;
	Document d;
	Document::AllocatorType &allocate = d.GetAllocator();
	d.SetObject();
	Value strValue;
	Value objInt;
	objInt.SetInt(icount);
	d.AddMember("message", objInt, allocate);
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);
	stringstream ss;
	ss << "W" << buffer.GetString() << "QUIT";
	strHandleMsg =ss.str();
	return true;
}


int main(int argc, const char * argv[])
{
	struct sockaddr_in server_addr;
	//server_addr.sin_len = sizeof(struct sockaddr_in);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(11334);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(server_addr.sin_zero), 8);

	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		perror("socket error");
		return 1;
	}
	char recv_msg[1024];
	char reply_msg[1024];

	if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == 0) {
		//connect 成功之后，其实系统将你创建的socket绑定到一个系统分配的端口上，且其为全相关，包含服务器端的信息，可以用来和服务器端进行通信。
		while (1) {
			

			std::string strMsg = "";
			SendMsg(strMsg);
			memcpy(reply_msg, strMsg.c_str(), strMsg.length());
			if (send(server_socket, reply_msg, 1024, 0) == -1) {
				perror("send error");
			}
			if (icount > 1) {
				close(server_socket);
				break;
			}
		}

	}

	// insert code here...
	printf("Hello, World!\n");
	return 0;
}