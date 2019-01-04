#include <stdio.h>

#include <stdlib.h>

int randomNumbers(n) //Function to generate and sum the 2 random numbers between -100 and 100 taking "n" as a parameter which will be taken as an input from command line arguement

{

int upper = 100;//upper limit for the rand() function

int lower = -100;//lower limit for the rand() function.

int i;//variable for the "for loop" iterations

if(n==0)//if there are no spawns or the user given value is zero process will be exited

return 0;

for(i=0;i<=n;i++)//for loop to print the random numbers and their sum for number of iterations i.e. spawns given by user

{

int num1 = (rand() % (upper - lower + 1)) + lower;//generating first random number between -100 and 100

printf("Random Number1 for %d iteration : %d\n",i,num1);//Printing the first random number

int num2 = (rand() % (upper - lower + 1)) + lower;//generating second random number between -100 and 100

printf("Random Number2 for %d iteration : %d\n",i,num2);//Printing second random number

printf("Sum of 2 Random Numbers for %d iteration : %d\n",i,num1+num2);//Printing sum of two random numbers

}

}

int main()//main function

{

long int n;

printf("Enter number of spawns :");

scanf("%d",&n);//taking the input from the user through command line

randomNumbers(n);//calling the function randomNumbers() by passing the user input

return 0;
}
