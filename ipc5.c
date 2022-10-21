#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){

     int fd[4]; 
     char buffer[50];
     int DNI;
     char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
     char*l;
     
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     
                close(fd[0]); // Cierra el descriptor de lectura
                printf("Introduce el número de tu DNI:");
                wait(NULL);
                read(fd[0], buffer , 50);
               
     
     }
     
     else
     
     {
                close(fd[1]); // Cierra el descriptor de lectura
                
                scanf("%i",&DNI);
                DNI %= 23;
                write(fd[1],l, 50);
                printf("\nMi letra del DNI es: %c", letra[DNI]);
                wait(NULL);
                
     }
     
     

}