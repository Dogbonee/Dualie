#ifndef DUALIE_SOCKET_HPP
#define DUALIE_SOCKET_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <3ds.h>

#define SOC_ALIGN       0x1000
#define SOC_BUFFERSIZE  0x100000

static u32 *SOC_buffer = NULL;

namespace dl {

    class Socket {

        int ret;
        s32 sock = -1, csock = -1;
        u32	clientlen;
        struct sockaddr_in client;
        struct sockaddr_in server;

        bool initSocketService();

    public:
        Socket();
        ~Socket();
        void bind(int port);
        void listen();
        void accept();
        void close();
        void recv(void* temp, int len, int flags);
        void send(char* buf, int len, int flags);
        void setBlocking(bool blocking);
        const char* getIpAddress();

    };

}

#endif //SOCKET_HPP