#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int forking = fork();
    if (forking < 0)
    {
        printf("El fork ha fallado carajo\n");
    }
    else if (forking == 0)
    {
        printf("Hello\n");
    }
    else
    {
        sleep(1);
        printf("Goodbye\n");
    }

    return 0;
}