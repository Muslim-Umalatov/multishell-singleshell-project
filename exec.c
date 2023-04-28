#include "main.h"
void exec(char **argv){
    char *command = NULL ,*full_command_path = NULL;
    pid_t child_pid = fork();
    if (child_pid == 0)
    {  
        command = argv[0];
        full_command_path = get_path(command);
        if(execve(full_command_path, argv,NULL)== -1){
            perror("Shell Error");
        }
        exit(0);
    }
    else if (child_pid > 0){
        waitpid(child_pid, NULL, 0);
    }else{
        perror("fork");
        exit(1);
    }
}
