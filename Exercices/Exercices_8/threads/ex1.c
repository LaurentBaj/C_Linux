#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void* player1(void *arg) // returns void pointer 
{
    while (1)
    {
        sleep(1.1); 
        printf("P1's turn\n"); 
    }
    return NULL; 
}

void player2() // normal func
{
    while (1)
    {
        sleep(1); 
        printf("P2's turn\n"); 
    }
}


// gcc ex1.c -lpthread -o e1
int main ()
{
    pthread_t thread;  
    pthread_create(&thread, NULL, player1, NULL); 
    player2();
}