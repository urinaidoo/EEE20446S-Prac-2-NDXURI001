#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "NDXURI001 & MSSALE009"
#define YEAR "2022"

void Dec2RadixI(int d, int r) {  //function to convert decimal

    int n = ceil(log(d+1)/log(r))-1; //find the number of bits needed to make the radix-i value
    int q, ri;
    printf("\nThe radix-%d value is ",r);
    for (int i=n; i>=0; i--) {  //for loop to find each bit value
        ri = trunc(pow(r, i)); //find radix to the power i
        q = trunc(d/ri); //bit value at position i
        if (q <= 9) { printf("%d", q); }
        else { printf("%c", q+55); } //if bit value > 9: finds a char letter
        d = d-q*ri; //finds remainder decimal value for the next bit
    }
}

int main() {

    printf("*****************************\n");
    printf("%s\n",TITLE);
    printf("Written by: %s\n", AUTHOR);
    printf("Date: %s\n",YEAR);
    printf("*****************************\n");

    while (1){  //loop to run unless exited by user
        int D;
        int R;
        printf("Enter a decimal number: ");
        scanf("%d",&D);
        if (D<0) { // if decimal value less than 0, exit loop and code
                printf("EXIT");
                break;
        }
        else if (D==0) { // if decimal value is 0 run this code
            printf("The number you have entered is %d \n",D);
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d", &R);
            while (R<2 || R>16) {
                printf("Enter a radix for the converter between 2 and 16: ");
                scanf("%d", &R);
            }
            printf("The log2 of the number is undefined\n");
            int Num2=D/R;
            printf("The integer result of the number divided by %d is %d\n",R, Num2);
            printf("The remainder is %d\n", D%R);
            printf("The radix-%d value is 0\n",R); //return new radix-i value

        }
        else { // if decimal is a positive integer run this code
            printf("The number you have entered is %d \n",D);
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d", &R);
            while (R<2 || R>16) {
                printf("Enter a radix for the converter between 2 and 16: ");
                scanf("%d", &R);
            }
            printf("The radix you have entered is %d \n",R);
            double Num1 = D;
            printf("The log2 of the number is %.2lf\n", log2(Num1));
            int Num2=D/R;
            printf("The integer result of the number divided by %d is %d\n",R, Num2);
            printf("The remainder is %d", D%R);
            Dec2RadixI(D, R); //return new radix-i value
            printf("\n");
        }
    }

 return 0;
}