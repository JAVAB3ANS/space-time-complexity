#include<stdio.h>

int main() {
    //Introduction to Pointers in C:

    int a; //how much memory allocated depends on data type and compiler

    //number  = 4 bytes
    // float = 4  bytes
    // character = 1 byte 

    char c;

    a = 5;

    a++; //modifies [a = 5] at that time in time

    //pointers = variables that store address of another variable
 
    int *p; // prints 5 --> put asterick to define pointer
    p = &a; // p now has address of a and points to it --> get address of it 

    a = 5; // has address of 204 and value of 5
    printf("%d\n", p); // 204
    printf("%d\n", &a); // 204 because [p = &a]
    printf("%d\n", &p); // 64 which is the address of p

    printf("%d\n", *p); // gives value of starting location it points to => deferencing 

    *p = 8; //value at p now modified to 8
    printf("%d\n", a); // 8 

    // p -> address
    // *p -> value at address

}