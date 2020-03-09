#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid;
    int x = 200;
 
    if ( (pid=fork()) == 0 )
    { /* hijo */
        printf("Soy el hijo (%d, hijo de %d, valor de x %d)\n", getpid(),
        getppid(),x);
        x += 300; 
    }
    else if((pid=fork()) < 0){
        printf("El fork ha fallado");
    }
    else
    { /* padre */
        printf("Soy el padre (%d, hijo de %d, valor de x %d)\n", getpid(),
        getppid(),x);
        x += 800;
    }

    printf("El valor final de x en mi proceso %d es %d \n", getpid(), x);
 
    return 0;
}