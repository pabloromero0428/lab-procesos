#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100
#define LECTURA 0
#define ESCRITURA 1


int main(int argc, char *argv[])
{
	int tuberiaIz[2], tuberiaDer[2];
	printf("\n\n");
	pipe(tuberiaIz);
    
	pid_t pidPrimerHijo = fork();
    if (pidPrimerHijo == 0 )
    {
		//Primer Hijo
		close(tuberiaIz[LECTURA]);
        printf("PRIMER HIJO: Mi pid es %d\n\n", getpid());
		char *msg = "Hola hemano.";
		printf("PRIMER HIJO: El mensaje que mandare es (%s)\n\n", msg);
		write(tuberiaIz[ESCRITURA], msg, strlen(msg));
		close(tuberiaIz[ESCRITURA]);
    }else if(pidPrimerHijo > 0){
		//Padre
		close(tuberiaIz[ESCRITURA]);
		pipe(tuberiaDer);

		pid_t pidSegundoHijo = fork();
		if (pidSegundoHijo == 0 )
		{
			//Segundo hijo
			close(tuberiaDer[ESCRITURA]);
		    printf("SEGUNDO HIJO: Mi pid es %d\n\n", getpid());
			char msg [SIZE];
			read(tuberiaDer[LECTURA], msg, SIZE);
			printf("SEGUNDO HIJO: El mensaje que me llego es (%s)\n\n", msg);

			close(tuberiaDer[LECTURA]);
		}else if(pidSegundoHijo > 0){
			//Padre
			close(tuberiaDer[LECTURA]);
			char msg [SIZE];
			read(tuberiaIz[LECTURA], msg, SIZE);
			write(tuberiaDer[ESCRITURA], msg, strlen(msg));
			close(tuberiaDer[ESCRITURA]);
		}else{
			printf("Error al crear el segundo hijo\n\n");
		}
		close(tuberiaIz[LECTURA]);
	}else{
		printf("Error al crear el primer hijo\n\n");
	}
	sleep(1000);
    return 0;
}
