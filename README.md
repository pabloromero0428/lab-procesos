# PRÁCTICA 1 - PROCESOS #

## Juan Pablo Romero Laverde - Cristian Andres Marin ##

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
  > El valor de esta variable es igual X = 100
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
  >Cuando el valor x cambia es indiferente para padre e hijo, debido a que la función fork() crea una copia exacta del padre en el hijo en el momento que es llamado, y se despues se continúan como procesos totalmente independientes.
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
  >Si, ambos pueden acceder al file descriptor dada la misma razón de la pregunta anterior ("la función fork() crea una copia exacta del padre en el hijo en el momento que se llama, y despues se continúan como procesos totalmente independientes").
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
  >Cuando se hace un fork() el proceso hijo hereda una copia del file descriptor. El kernel agenda los procesos de manera independiente, por ende, puede llegar a tener líneas del archivo escritas de manera intercalada por el padre y sus procesos hijos.
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
>Se podría asegurar que el proceso hijo imprima en primer lugar si al realizar un llamado al fork() se usa un sleep() en el  proceso padre, haciendo que este imprima su mensaje algún tiempo después, sin la necesidad de llamar al wait().
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
> Pensamos que existen gracias a que son una necesidad. La ejecucion de nuevos programas no siempre puede ser igual (La parametrizacion para la ejecucion del nuevo proceso puede cambiar), el S.O debe tener una interfaz limpia y esta es la forma como lo hace (exponiendo mas llamados al sistema).
5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. 
* ¿Cuál es el valor de retorno de la función ```wait()```?.
>El valor de retorno de la funcion wait() es pid del hijo.
* ¿Qué pasa si usted usa la función ```wait``` en el hijo?
>Si se usa la funcion wait en el hijo se retorna -1, y esto sucede porque el proceso hijo no tiene ningún proceso secundario.
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?
> ```waitpid()``` Podría ser útil cuando se tienen varios procesos hijos corriendo y se desea esperar unicamente a un hijo en especial.
7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
> NO se muestra nada en la consola ya que se cerro la salida estandar para ese proceso.
8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```

## 3. Entregable ##

Los entregables para esta practica incluiran:
1. Codigo de los ejercicos propuestos.
2. Solución a las preguntas planteadas. apoyar la explicación con graficas donde lo vea necesario.
