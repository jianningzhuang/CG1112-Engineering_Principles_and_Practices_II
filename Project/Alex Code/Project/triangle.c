#include <stdio.h>
int main() {
   int i, space, rows, k = 0;
   printf("Enter N = ");
   scanf("%d", &rows);
   for (i = 1; i <= rows - 1; i++){
	   for (int j = 1, k = 2*rows; j < k; j++){
		   if (j == rows-i+1 || j == rows+i-1){
			   printf("*");
		   } else if (j >= rows-i+2 && j <= rows+i-2){
			   printf("#");
		   } else {
			   printf(" ");
		   }
	   }
	   printf("\n");
   }
   for (int a = 0; a < 2*rows-1; a++){
	   printf("*");
   }
   printf("\n");
   return 0;
}
