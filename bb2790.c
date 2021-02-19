#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
  while(1){
    printf("lab1>\n ");
    char s[20];
    fgets(s,20,stdin); // get the input from the user. You can use a different API if you want.
    printf("Parent Process %d\n", getpid());

     /*(the string entered by the user is a built-in command)*/ {

      if(strcmp(s,"printid\n") == 0){
        printf("the ID of the current process is %d", getpid());
      }
      else if(strcmp(s,"greet\n")== 0){
        printf("Hello\n");
      }
      else if(strcmp(s,"exit\n")== 0){
        exit(0);
      }
      //Check the string and based on it, do the corresponding tasks as stated below.
      //If the built-in command is “exit” then ends the whole process using exit(0);
      else{
        char *args[] = {s,0};
        int pid = fork();
        if( pid == 0 ){ // the created child process
          printf("Child process %d will execute the command %s\n", getpid(), s); //print process ID of the child process and the string
                                                                          //entered by the user.
          int l = strlen(s);
          s[l-1] = '\0';
          char t[25];
          strcpy(t,"/bin/");
          strcat(t,s);
          execve(t,args,NULL);// use the string entered by the user to transform the child process to the new process.
          //if execution of the child process reaches this point, it means execve failed. In that
          //case, print “Command Not Found!\n” and exits.
          printf("> Command Not Found!\n");
          exit(0);
        }
      }
    }
    //wait till the child process finishes
    pid_t wait(int *stat_loc);
  }
}
