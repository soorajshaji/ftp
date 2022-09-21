#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

int main(){
    char buf[100];
    int sock_desc,sock,sum[100]={0},i=0,j=0,len;
    struct sockaddr_in server,client;


    if((sock_desc = socket(AF_INET,SOCK_STREAM,0)) >= 0){
        printf("socket created \n");
    }
    server.sin_family = AF_INET;
    server.sin_port = 3030;
    server.sin_addr.s_addr = INADDR_ANY;

    if((bind(sock_desc,(struct sockaddr*)&server,sizeof(server)))>=0){
        printf("binding success \n");
    }
    if((listen(sock_desc,5) >=0)){
        printf("listensing...\n");
    }

     len = sizeof(client);
    sock = accept(sock_desc,(struct sockaddr*)&client,&len);


    while(1){

        recv(sock,buf,sizeof(buf),0);


        if(strcmp(buf,"#")==0){
            break;
        }
        else{
            printf("%s",buf);
            for(i=0;i<strlen(buf);i++){
                if(buf[i] == ' '){
                    continue;
                }
                else{
                    j++;
                }

            }
            sum[0]= sum[0]+j-1;
            j =0;
        }

    }

    send(sock,sum,100,0);
    close(sock);
    close(sock_desc);




}
