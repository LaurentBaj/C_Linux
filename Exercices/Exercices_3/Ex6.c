#include <stdio.h>
#include <stdlib.h>


int fibbonacci(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}



int main(int argc, char *argv[]) {
   int n = atoi(argv[1]);
   int i;	
   printf("Fibbonacci of %d\n: " , n);
   for(i = 0;i<n;i++) {
      printf("%d\n ",fibbonacci(i));            
   }
}
