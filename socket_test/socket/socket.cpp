//
// Created by 12414 on 2023/1/6.
//

#include "socket.hpp"

//创建主线程
ServerClass::ServerClass()
{

    //创建socket
    server_fd= socket(AF_INET,SOCK_STREAM,0);
    if (server_fd == -1) {
        Error("socket");
        exit(-1);
    }

    //初始化addr
    sockaddr_in addr;
    addr.sin_addr.s_addr=INADDR_ANY;  // 走动绑定IP地址
    addr.sin_port= htons(PORT);
    addr.sin_family=AF_INET;


    //bind
    int ret=bind(server_fd,(sockaddr*)&addr,sizeof(addr));
    if (ret == -1) {
        Error("bind");
        close(server_fd);
        exit(-1);
    }

    //打开端口复用功能
    int option=1;
    if(setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,(const char*)(& option),sizeof(option)))
    {
        Error("setsockopt");
        close(server_fd);
        exit(-1);
    }

    //监听
    ret=listen(server_fd,10);
    if (ret == -1) {
        Error("listen");
        close(server_fd);
        exit(-1);
    }


}

void ServerClass::Manager()
{
    cout<<"wait connection........"<<endl;
    ParameterTransfer tem;
    int addr_len=sizeof(tem.addr);
    while(1)
    {
        tem.client=accept(server_fd, (sockaddr*) &tem.addr, (socklen_t *)(&addr_len));
        if(tem.client ==-1)
        {
            Error("accept");
            break;
        }

        ClientIfo.push(tem);
        thread tid(working,&ClientIfo.front());
        ClientIfo.pop();
        tid.detach();
    }
    close(server_fd);
}

int working(void *arg)
{
    ParameterTransfer* client_inf=(ParameterTransfer*)arg;
    char ip[32]={0};
    cout<<"be connected successfully!    "<<endl<<
        "IP："<<inet_ntop(AF_INET,&client_inf->addr.sin_addr.s_addr,ip,sizeof(ip))<<endl<<
        "PORT："<<ntohs(client_inf->addr.sin_port)<<endl;
    char Recv[BUFSIZ]={0};
    char Send[BUFSIZ]={0};
    cout<<"communication mode"<<endl;
    while(1)
    {
        cout << "receive messages:";
        if (recv(client_inf->client, Recv, BUFSIZ, 0) < 1) {
            Error("recv");
            break;
        }
        cout << Recv << endl;
        memset(Recv, 0, BUFSIZ);
        cout << "send messages：";
        cin.getline(Send, BUFSIZ);
        int len = send(client_inf->client, Send, BUFSIZ, 0);
        if (len < 0) {
            Error("send");
            break;
        } else if (len == 0) {
            cout << "exit communication" << endl;
            break;
        }
        memset(Send, 0, BUFSIZ);

    }
        close(client_inf->client);
}


int CreateClient()
{
    //创建socket
    int fd= socket(AF_INET,SOCK_STREAM,0);
    if (fd == -1) {
        Error("socket");
        return -1;
    }

    //初始化addr
    sockaddr_in addr;
    inet_pton(AF_INET,IP,&addr.sin_addr.s_addr);
    addr.sin_port= htons(PORT);
    addr.sin_family=AF_INET;

    //connect
    int ret= connect(fd,(sockaddr*)&addr,sizeof(addr));
    if(ret == -1)
    {
        Error("connect");
        close(fd);
        return -1;
    }

    return fd;
}
