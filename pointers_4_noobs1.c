<<<<<<< HEAD
#include<stdio.h>

int main() {
    // variables usually take up 4 bytes in memory

    /*
    HYPOTHETICAL!

    variable x 's address: 225
    variable p 's address: 215
    variable q 's address: 205
    variable r 's address: 230
    */

    int x = 5; //memory will be allocated for x = 5

    int *p; //pointer's stored in 4 bytes
    p = &x; // p points to x

    // p is pointing to integer and not character, which is why it works
    //pointer is a data reference where you could modify values

    *p = 6; 
    int **q;
    q = &p; //now q can store the address and not value of pi

    int*** r = &q;

    printf("%d\n", *p); //6 = value of p stored at that address 
    printf("%d\n", *q); // 225 = address of x
    printf("%d\n", *(*q)); // 6 = value of p
    printf("%d\n", *(*r)); // 225 = address of x
    printf("%d\n", *(*(*r))); // 6 = value of p
    ***r = 10;
    printf("x = %d\n", x);
    **q = *p + 2;
    printf("x = %d\n", x);

}
=======
#include<stdio.h>

int main() {
    // variables usually take up 4 bytes in memory

    /*
    HYPOTHETICAL!

    variable x 's address: 225
    variable p 's address: 215
    variable q 's address: 205
    variable r 's address: 230
    */

    int x = 5; //memory will be allocated for x = 5

    int *p; //pointer's stored in 4 bytes
    p = &x; // p points to x

    // p is pointing to integer and not character, which is why it works
    //pointer is a data reference where you could modify values

    *p = 6; 
    int **q;
    q = &p; //now q can store the address and not value of pi

    int*** r = &q;

    printf("%d\n", *p); //6 = value of p stored at that address 
    printf("%d\n", *q); // 225 = address of x
    printf("%d\n", *(*q)); // 6 = value of p
    printf("%d\n", *(*r)); // 225 = address of x
    printf("%d\n", *(*(*r))); // 6 = value of p
    ***r = 10;
    printf("x = %d\n", x);
    **q = *p + 2;
    printf("x = %d\n", x);

}
>>>>>>> a1f0e4f928b8b36dff7eee61d39c3b63cd2ced71
