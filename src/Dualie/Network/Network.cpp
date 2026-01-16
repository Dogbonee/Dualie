#include <Dualie/Network/Network.hpp>



dl::Socket::Socket()
{
    if (!SOC_buffer) {
        initSocketService();
    }
    // libctru provides BSD sockets so most code from here is standard
    clientlen = sizeof(client);

    sock = socket (AF_INET, SOCK_STREAM, IPPROTO_IP);

    if (sock < 0) {
        printf("Could not initialize socket\n");
    }

    memset (&server, 0, sizeof (server));
    memset (&client, 0, sizeof (client));

}

dl::Socket::~Socket()
{
    ::close(sock);
}

//TODO: This never gets cleaned up?
bool dl::Socket::initSocketService()
{
    SOC_buffer = (u32*)memalign(SOC_ALIGN, SOC_BUFFERSIZE);

    if(SOC_buffer == NULL) {
        printf("SOC_buffer is NULL\n");
        return false;
    }

    if ((socInit(SOC_buffer, SOC_BUFFERSIZE)) != 0) {
        printf("Failed to initialize socket service\n");
        return false;
    }
    return true;
}

void dl::Socket::bind(int port)
{
    server.sin_family = AF_INET;
    server.sin_port = htons (port);
    server.sin_addr.s_addr = gethostid();
    if ( (ret = ::bind (sock, (struct sockaddr *) &server, sizeof (server))) ) {
        ::close(sock);
        printf("Could not bind to port %d\n", port);
    }
}

void dl::Socket::listen()
{
    if ( (ret = ::listen( sock, 5)) ) {
        printf("Could not listen on socket\n");
    }
}

void dl::Socket::accept()
{
    csock = ::accept (sock, (struct sockaddr *) &client, &clientlen);
}

void dl::Socket::close()
{
    ::close (csock);
}

void dl::Socket::recv(void *temp, int len, int flags)
{
    memset (temp, 0, len);
    ret = ::recv (csock, temp, len, flags);
}

void dl::Socket::send(char *buf, int len, int flags)
{
    ::send(csock, buf, len, flags);
}

void dl::Socket::setBlocking(bool blocking)
{
    if (blocking)
    {
        fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) & ~O_NONBLOCK);
        fcntl(csock, F_SETFL, fcntl(csock, F_GETFL, 0) & ~O_NONBLOCK);
    } else
    {
        fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) | O_NONBLOCK);
        fcntl(csock, F_SETFL, fcntl(csock, F_GETFL, 0) | O_NONBLOCK);
    }
}

const char * dl::Socket::getIpAddress()
{
    return inet_ntoa(server.sin_addr);
}