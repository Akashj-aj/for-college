#include <stdio.h> 
int getSumOfSquares(int num) 
{ 
int sum = 0;  
while (num > 0)  
{ 
int digit = num % 10;  
sum += digit * digit; num /= 10;  
}  
return sum; 
} 
int isHappy(int num) 
{ 
int slow = num, fast = num;  
do  
{  
slow = getSumOfSquares(slow); 
fast = getSumOfSquares(getSumOfSquares(fast)); 
} while (slow != fast); 
return (slow == 1); 
} 
int main()  
{ 
int num;  
printf("Enter a positive integer: "); 
scanf("%d", &num);  
if (isHappy(num)) 
{  
printf("%d is a happy number.\n", num); 
} 
else 
{ 
printf("%d is not a happy number.\n", num);  
} 
return 0; 
} 