#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int forking = fork();
    int status;
    pid_t x;
    
    if (forking == 0)
    {
        printf("Imaginate que soy el hijo %d y mi padre dizque me va a esperar mientras duermo.\n", (int)getpid());
        sleep(2);
        printf("Ya desperté.\n");
    }
    else
    {
        printf("Hola soy el padre y estoy esperando a mi hijo %d.\n", forking);
        do
        {
            x = waitpid(forking, &status, WNOHANG);
            if (x == -1)
                perror("waitpid() error");
            else if (x == 0)
            {
                printf("Un momento mi hijo está durmiendo.\n");
                sleep(2);
            }
            else
            {
                if (WIFEXITED(status))
                {
                    printf("Es todo mi hijo ya despertó.\n");
                }
            }
        } while (x == 0);
    }

    return 0;
}