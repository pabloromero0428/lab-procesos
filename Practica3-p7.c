#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid == 0 )
    { /* hijo */
        printf("Soy el hijo, mi pid es %d\n", getpid());
				close(STDOUT_FILENO);
        printf("Nunca me mostrare");
    }
    return 0;
}
