#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void* player1(void * arg) 
{
    int *iptr = (int*)malloc(sizeof(int)); 
    *iptr = 5; 
    for (int i = 0; i < 8; i++)
    {
        sleep(1); 
        printf("P1's turn! %d %d\n", i, *iptr);
        (*iptr)++; 
    }
    return iptr; 
}

void player2() 
{
    for (int i = 0; i < 3; i++)
    {
        sleep(2); 
        printf("P2's turn!\n"); 
    }
}


int main ()
{
    pthread_t thread;  
    int *result; 

    pthread_create(&thread, NULL, player1, NULL); 
    player2();

    /*
       - Wait for thread to finish
       - Return address (ptr) and put into another pointer (*result)
    */
    pthread_join(thread, (void*)&result); 
    printf("Thread's done: *result=%d\n", *result); 
}