//#include <jwt-cpp/jwt.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include "pthread.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

struct sPbuff {
	char* pBuff = nullptr;
	int length = 0;
}SPBUFF;

bool HandleMsg(string strHandleMsg) {
	std::cout << "strHandleMsg:" << strHandleMsg << "\n";
	Document d;
	d.Parse(strHandleMsg.c_str());
	Value& s = d["message"];
	std::cout << "msg:" << s.GetInt() << "\n";
	return true;
}


int main() {

	//const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	//rapidjson::Document d;
	//d.Parse(json);

	//// 2. Modify it by DOM.
	//Value& s = d["stars"];
	//s.SetInt(s.GetInt() + 1);

	//// 3. Stringify the DOM
	//StringBuffer buffer;
	//Writer<StringBuffer> writer(buffer);
	//d.Accept(writer);

	//// Output {"project":"rapidjson","stars":11}
	//std::cout << buffer.GetString() << std::endl;

	struct sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;//Address families AF_INET互联网地址簇
	server_addr.sin_port = htons(11334);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(server_addr.sin_zero), 8);

	//创建socket
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);//SOCK_STREAM 有连接
	if (server_socket == -1) {
		perror("socket error");
		return 1;
	}

	//绑定socket：将创建的socket绑定到本地的IP地址和端口，此socket是半相关的，只是负责侦听客户端的连接请求，并不能用于和客户端通信
	int bind_result = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (bind_result == -1) {
		perror("bind error");
		return 1;
	}

	//listen侦听 第一个参数是套接字，第二个参数为等待接受的连接的队列的大小，在connect请求过来的时候,完成三次握手后先将连接放到这个队列中，直到被accept处理。如果这个队列满了，且有新的连接的时候，对方可能会收到出错信息。
	if (listen(server_socket, 5) == -1) {
		perror("listen error");
		return 1;
	}

	struct sockaddr_in client_address;
	socklen_t address_len;   //可能需要先给一个长度
	int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_len);
	//返回的client_socket为一个全相关的socket，其中包含client的地址和端口信息，通过client_socket可以和客户端进行通信。
	if (client_socket == -1) {
		perror("accept error");
		return -1;
	}

	char recv_msg[1024];
	char reply_msg[1024];

	string strMsg = "";
	while (1) {
		bzero(recv_msg, 1024);

		long byte_num = recv(client_socket, recv_msg, 1024, 0);
		if (byte_num = 0) {
			std::cout << "client exit" << "\n";
			break;
		}
	//	printf("recv:%s",recv_msg)
	//	memcpy(sbuff.pBuff + sbuff.length + 1, recv_msg, byte_num);
		
		strMsg.append(recv_msg);

		if (strMsg.find_first_of("W{") != std::string::npos) {
			int iStart = strMsg.find_first_of("W{");
			int iEnd = strMsg.find_first_of("}QUIT");
			if (iEnd > iStart && iEnd != std::string::npos) {
				std::string strHandleMsg = strMsg.substr(iStart + 1, iEnd - iStart);
				HandleMsg(strHandleMsg);
				strMsg = strMsg.substr(iEnd + 5);
			}
		}

	}
	std::cout << "proc exit" << "\n";
	return 0;

}
