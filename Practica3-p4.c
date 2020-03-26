#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	printf("\n\n");
	pid_t pidProcesoHijo = fork();
    if (pidProcesoHijo == 0 )
    {
		//Primer Hijo
		execl("/bin/ls", "/bin/ls", "-l", ".", NULL);
    }else if(pidProcesoHijo > 0){
		//Padre
		
	}else{
		printf("Error al crear el primer hijo\n\n");
	}
	sleep(1000);
    return 0;
}
