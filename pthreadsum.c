#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

int sum = 0;

void *myThreadFun(void *vargp)
{
   int r;
   srand((int) (pthread_self()));
   r = rand()%200 - 100;
   sum = sum+r;
   printf("Random number %d from Thread-id %d\n",r,(int)(pthread_self()));
   return NULL;
}

int main(int argc, char **argv)
{
   int i;
   int n_process = 0;
   pthread_t tid;

   if(argc != 3)
   {
       printf("Usager ./executable -n number_of_thread_or_process\n");
       return 0;
   }

   if(strcmp(argv[1],"-n") != 0)
   {
       printf("Usager ./executable -n number_of_thread_or_process\n");
       return 0;
   }

   n_process =atoi(argv[2]);
   for( i=0;i<n_process;i++)
       pthread_create(&tid, NULL, myThreadFun, NULL);
   pthread_join(tid, NULL);
   printf("\n Total sum =%d\n",sum);
   exit(0);
}


/*
OUTPUT:
Random number 97 from Thread-id -1227478208
Random number -29 from Thread-id -1235870912
Random number -59 from Thread-id -1219085504
Random number -80 from Thread-id -1244263616
Random number -1 from Thread-id -1252656320

Total sum =-72
*/
