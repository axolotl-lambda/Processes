// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // execl example
        // fprintf(stdout, "execl example:\n");
        // execl("/bin/ls", "ls", "-l", "-a", (char *)0);

        // execv example
        char *args[] = {"ls", "-l", "-a", NULL};
        execv("/bin/ls", args);

        // e is used to pass environment vars to child new process
    }
    else
    {
        wait(NULL);
        // printf("In parent. Finishing.");
    }

    return 0;
}
