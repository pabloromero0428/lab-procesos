#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int forking = fork();
    int t;

    if (forking == 0)
    {
        t = wait(NULL);
        printf("Soy el hijo, y la funcion wait retorna %d\n", t);
    }
    else
    {
        t = wait(NULL);
        printf("Soy el padre, el PID de mi hijito es %d y la función wait() que esta instanciada retorna %d\n", forking, t);
    }

    return 0;
}