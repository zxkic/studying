#include"CGI.h"
class server
{
private:
    int sock;
public:
    server();
    void create_socket();
};
 
server::server()
{
    int sock = 0;
}
 
void server::create_socket()
{
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);
    
    sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);
 
    int ret = bind(sock,(struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);
 
    ret = listen(sock,5);
    assert(ret != -1);
 
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    socklen_t client_addrlength = sizeof(client);
    int connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
    if(connfd<0)
    {
        cout << "errno is :" << errno << endl; 
    }
    else{
        close(1);//close(STDOUT_FILENO)
        //int fd=dup2(connfd,1);
        dup(connfd);
        printf("abcd\n");//fd会将返回到客户端的socket上
        close(connfd);
    }
    close(sock);
}
 
int main()
{
    server CGI;
    CGI.create_socket();
    return 0;
}