#include<stdio.h>
#include<string.h>
#include<netinet/in.h>

int main(){
    char ch[100];
    struct sockaddr_in client;
    int sock_desc,buf[100];

    if((sock_desc = socket(AF_INET,SOCK_STREAM,0)) >= 0){
        printf("socket created \n");
    }
    client.sin_family = AF_INET;
    client.sin_port = 3030;
    client.sin_addr.s_addr = INADDR_ANY;

    if((connect(sock_desc,(struct sockaddr*)&client,sizeof(client))) >=0){
        printf("connected \n");
    }

    FILE* ptr = fopen("test.txt","r");
    printf("text sended:\n");
    while(fgets(ch,100,ptr) != NULL){

        send(sock_desc,ch,100,0);

    }
    strcpy(ch,"#");
    send(sock_desc,ch,100,0);

    recv(sock_desc,buf,100,0);
    printf("%d",buf[0]);
    close(sock_desc);
}



