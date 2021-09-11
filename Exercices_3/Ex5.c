#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	/*	
	Create random number 
	srand(time(NULL));
	int a = rand() % 100;
	printf("%d", a)*/;
	
	
   srand(time(NULL)); 
   int a = rand()%20;
   if(a == 1){
      printf("%d is 1\n", a);}
   else if(a%2 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%3 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%5 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%7 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%11 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%13 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%17 == 0){
      printf("%d is not a prime\n", a);}
   else if(a%19 == 0){
      printf("%d is not a prime\n", a);}
   else{
      printf("%d is a prime\n", a);
   }

   return(0);
}


