#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void* player1(void * arg) 
{
    for (int i = 0; i < 8; i++)
    {
        sleep(1); 
        printf("P1's turn\n"); 
    }
    return NULL; 
}

void player2() 
{
    for (int i = 0; i < 3; i++)
    {
        sleep(2); 
        printf("P2's turn\n"); 
    }
}


int main ()
{
    pthread_t thread;  
    pthread_create(&thread, NULL, player1, NULL); 
    player2();

    // Without _join the main thread will finish
    // before player1 is done looping
    pthread_join(thread, NULL); 
}