// Created by 12414 on 2023/1/6.
//

#ifndef SOCKET_TEST_SOCKET_HPP
#define SOCKET_TEST_SOCKET_HPP

#include "iostream"
#include"unistd.h"
#include "arpa/inet.h"
#include "cstring"
#include "thread"

#include "queue"
#include "mutex"
using namespace std;

#define PORT  8989
#define IP " 172.24.147.211"
#define Error(error) cout<<"[ "<<__LINE__<<" ]  "<<error<<" failed "<<endl;





//客户端
int CreateClient();

//用于working函数的参数传递
struct ParameterTransfer
{
    int client;
    sockaddr_in addr;
};

//子线程的工作函数
int working(void *arg);

//服务端
class ServerClass
{
public:
    //函数区
    //创建服务端
    ServerClass();
    //多并发的实现
    void Manager();
    friend int working();
private:
    int server_fd;
    queue<ParameterTransfer> ClientIfo;//用于存放client的信息

};


#endif //SOCKET_TEST_SOCKET_HPP
