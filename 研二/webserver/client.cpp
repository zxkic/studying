#include"CGI.h"
class client{
private:
    int sock;
public:
    client();
    void create_client();
};
 
client::client()
{
    int sock = 0;
}
 
void client::create_client()
{
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family=AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);
    
    sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);
 
    if((connect(sock,(struct sockaddr*)&address, sizeof(address))) != -1)
    {
        char buf[30];
        cout << "connect successful!\n";
        if(recv(sock,buf,sizeof(buf),0) > 0)//测试socket接收缓存上是否接收到"abcd"
        {
            cout << buf << endl;
        }
        else{
            perror("recv");
        }
    }
    else{
        perror("connect");
    }
    close(sock);
}
 
int main()
{
    client CGI;
    CGI.create_client();
    return 0;
}