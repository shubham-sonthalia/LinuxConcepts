#include <iostream>
#include <unistd.h>


const char* msgParent = "Hello World\n";
const char* msgChild = "Welcome World\n";


void printAndExit(const char* msg){
    perror(msg);
    exit(-1);
}

int main(){
    pid_t cid = fork();
    if (cid < 0){
        printAndExit("Fork Error");
    }
    if (cid == 0){
        // child process
        int count = 0;
        while (count < 10){
            write(STDOUT_FILENO,msgChild, sizeof(msgChild));
            count ++; 
        }
        _exit(0);
    }
    else{
        //parent process
        int count2 = 0; 
        while(count2 < 5){
            write(STDOUT_FILENO, msgParent, sizeof(msgParent));
            count2 ++;
        }
        wait(NULL);
        exit(0);    
    }
}