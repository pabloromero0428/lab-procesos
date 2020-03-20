// C program to illustrate 
// open system call 
#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
extern int errno; 
int main() 
{	 
	// if file does not have in directory 
	// then file foo.txt is created. 
	int fd = open("Programa.txt", O_RDONLY | O_CREAT);
    int programer = 0;
    char *c;
    int forking = fork();
	
	printf("fd = %d/n", fd); 
	
	if (fd ==-1) 
	{ 
		// print which type of error have in a code 
		printf("Error Number % d\n", errno); 
		
		// print program detail "Success or failure" 
		perror("Program");				 
	} 

    if (forking == 0)
    {
        char a[] = "Soy el hijo\n\0";
        programer = write(fd, a, strlen(a));
        c = "Fin del hijo\n\0";
    }
    else
    {
        // wait(NULL);
        char b[] = "Soy el padre\n\0";
        programer = write(fd, b, strlen(b));
        // wait(NULL);
        c = "Fin del padre\n\0";
    }
    programer = write(fd, c, strlen(c));
    printf("Fin del programa. (File descriptor %d)\n", x);
	return 0; 
} 
