#include <stdio.h>
#include <pthread.h>

 

void* threadfunction(void* arg)
{
    printf("hello from the thread\n ");
    return NULL;
}

int main()
{
pthread_t  thread ;

  if(pthread_create(&thread,NULL, threadfunction,NULL)!=0)
{
   perror ("failed to create thread\n ");
   return 1;
}
 printf("main thread is running\n ");

if(pthread_join(thread,NULL)!=0)
  {
perror ("failed to join thread ");
   return 1;
}

printf("main thread executed successfully happy\n ");
return 0;
}

