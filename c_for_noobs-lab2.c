#include <stdio.h>
#include <string.h>

//Amount of people waitlist can hold
#define SIZE 5

//Instructions shown on startup
#define INSTRUCTIONS "Commands:\ndd - Adds player to waitlist\n[l]ist - List waitlist\n[n]ext - Get next person from waitlist\n[q]uit - Quits program\n"

//Number to increment as waitlist grows 
int counter = 0;

//Waitlist controller arrays
char names[SIZE][20];
char symptoms[SIZE][20];

/*
MAIN FUNCTION:
Starts the program, command handler, and waitlist full checker here.
@param {void}
@return {int}
*/

int main() {
    printf("Starting waitlist program...");
    //initialize arrays
    int k;
    for (k = 0; k < SIZE; k++) {
        strcpy(names[k], "");
        strcpy(symptoms[k], "");
    }
    //provide a list of commands for the user to use and reference
    printf(INSTRUCTIONS);
    //start a loop for command handler
    while (1 == 1) {
        //ask for command and direct user to specific functions
        char option;
        scanf("%c", &option);
        switch(option) {
            case 'q':
                printf("Exiting waitlist program...\n");
                exit(0);
                break;
            case 'a':
                //if waitlist is full, prompt the user
                if (SIZE == counter) {
                    printf("The waitlist is full! Maximum of %d people reached.\n", SIZE);
                }
                //if it is not full , allow user to insert name /symptom
                else {
                    insert();
                }
                break;
            case 'l':
                print();
                break;
            case 'n':
                next();
                break;
            }
        }
        return 0;
    } //end of main function

/*
INSERT FUNCTION:
Adds the <name> and <symptom> to the end of the list
@param {void}
@return {void}
*/

void insert() {
    //define variables
    char name[20];
    char symptom[20];
    //prompt for name
    printf("Welcome! What is your name?\n");
    scanf("%s", &name);
    //check if name is greater than character max length
    if (strlen(name) > 20) {
        printf("Your name must be less than 20 characters!Try the 'a' command again!");
        return;
    } else {
        //check if name is already in use   
        if (isRepeat(name) == 1) {
            //if name is in use, tell them and have them pick again
            printf("That name is already in use! Please try the 'a' command again!");
            return;
        } else {
            //if name is NOT in use, ask for their symptom(s)
            printf("Hey there %s! Please describe your symptoms!\n", name);
            scanf("%s", &symptoms);
            //check if name and symptom length is too long 
            if (strlen(symptom) > 20) {
                printf("Your symptom and name must be less than 20 characters! Please try the 'a' command again!");
                return;
            } else {
                //confirmation that they have joined the waitlist with provided waitlist number
                printf("You are #%d in the waitlist! Please wait for your turn\n", counter + 1);
                
                //add user to the waitlist
                strcpy(names[counter]);
                strcpy(symptom[counter]);
                //increment the waitlist counter
                counter++;
            }
        }
    }
} //end of insert function

/*
PRINT FUNCTION
prints out the entire waitlist
@param {void}
@return {void}
*/

void print() {
    //if counter is zero, it means nobody is on the waitlist
    if (counter == 0) {
        return printf("The waitlist is currently empty!\n");
    } else {
        int i;
        //print out the current waitlist using a for loop to iterate through the array
        printf("+======[Waitlist Max Size: %d ]======+\n", SIZE);
        printf("[#] | Name -> Symptom\n");
        //use counter as upper limit to stop after array is full
        for (i = 0; i < counter; i++) {
            printf("#%d | %s -> %s\n", i + 1, names[i], symptoms[i]);
        }

        printf("+==========================+\n");

    }
} //end of print function

/*
NEXT FUNCTION
Moves users up in the waitlist and provides who the next patient is
@param {void}
@return {void}
*/

void next() {
    //if counter is zero, it means nobody is on the waitlist
    if (counter == 0) {
        printf("The waitlist is empty!\n");
    } else {
        //first person in line is at index 0 
        printf("\n\nThe next person from the waitlist is %sn\n", names[0]);
        int i;
        //shifts every time the name/symptom is in the waitlist up one
        for (i = 0 ; i < SIZE - 1; i++) {
            strcpy(names[i], names[i + 1]);
            strcpy(names[i + 1], "");
            strcpy(symptoms[i], symptoms[i + 1]);
            strcpy(symptoms[i + 1], "");
        }
        //decrement the counter to keep next() position in sync
        counter--;
        print();
    }
}//end of next function

/*
isRepeat function
helper function to check if a name already exists in waitlist
@param { char string } the name to test
@return { int } 1 if is duplicate, 0 if not duplicate
*/

int isRepeat(char name[20]) {
    int i;
    //initialize at 0
    int val = 0;
    //loop through array
    for (i = 0; i < SIZE; i++) {
        //detect if name is equal
        if (strcmp(name, names[i]) == 0) {
            //set to one if name is equal 
            val = 1;
        } 
    }
       return val;
=======
#include <stdio.h>
#include <string.h>

//Amount of people waitlist can hold
#define SIZE 5

//Instructions shown on startup
#define INSTRUCTIONS "Commands:\ndd - Adds player to waitlist\n[l]ist - List waitlist\n[n]ext - Get next person from waitlist\n[q]uit - Quits program\n"

//Number to increment as waitlist grows 
int counter = 0;

//Waitlist controller arrays
char names[SIZE][20];
char symptoms[SIZE][20];

/*
MAIN FUNCTION:
Starts the program, command handler, and waitlist full checker here.
@param {void}
@return {int}
*/

int main() {
    printf("Starting waitlist program...");
    //initialize arrays
    int k;
    for (k = 0; k < SIZE; k++) {
        strcpy(names[k], "");
        strcpy(symptoms[k], "");
    }
    //provide a list of commands for the user to use and reference
    printf(INSTRUCTIONS);
    //start a loop for command handler
    while (1 == 1) {
        //ask for command and direct user to specific functions
        char option;
        scanf("%c", &option);
        switch(option) {
            case 'q':
                printf("Exiting waitlist program...\n");
                exit(0);
                break;
            case 'a':
                //if waitlist is full, prompt the user
                if (SIZE == counter) {
                    printf("The waitlist is full! Maximum of %d people reached.\n", SIZE);
                }
                //if it is not full , allow user to insert name /symptom
                else {
                    insert();
                }
                break;
            case 'l':
                print();
                break;
            case 'n':
                next();
                break;
            }
        }
        return 0;
    } //end of main function

/*
INSERT FUNCTION:
Adds the <name> and <symptom> to the end of the list
@param {void}
@return {void}
*/

void insert() {
    //define variables
    char name[20];
    char symptom[20];
    //prompt for name
    printf("Welcome! What is your name?\n");
    scanf("%s", &name);
    //check if name is greater than character max length
    if (strlen(name) > 20) {
        printf("Your name must be less than 20 characters!Try the 'a' command again!");
        return;
    } else {
        //check if name is already in use   
        if (isRepeat(name) == 1) {
            //if name is in use, tell them and have them pick again
            printf("That name is already in use! Please try the 'a' command again!");
            return;
        } else {
            //if name is NOT in use, ask for their symptom(s)
            printf("Hey there %s! Please describe your symptoms!\n", name);
            scanf("%s", &symptoms);
            //check if name and symptom length is too long 
            if (strlen(symptom) > 20) {
                printf("Your symptom and name must be less than 20 characters! Please try the 'a' command again!");
                return;
            } else {
                //confirmation that they have joined the waitlist with provided waitlist number
                printf("You are #%d in the waitlist! Please wait for your turn\n", counter + 1);
                
                //add user to the waitlist
                strcpy(names[counter]);
                strcpy(symptom[counter]);
                //increment the waitlist counter
                counter++;
            }
        }
    }
} //end of insert function

/*
PRINT FUNCTION
prints out the entire waitlist
@param {void}
@return {void}
*/

void print() {
    //if counter is zero, it means nobody is on the waitlist
    if (counter == 0) {
        return printf("The waitlist is currently empty!\n");
    } else {
        int i;
        //print out the current waitlist using a for loop to iterate through the array
        printf("+======[Waitlist Max Size: %d ]======+\n", SIZE);
        printf("[#] | Name -> Symptom\n");
        //use counter as upper limit to stop after array is full
        for (i = 0; i < counter; i++) {
            printf("#%d | %s -> %s\n", i + 1, names[i], symptoms[i]);
        }

        printf("+==========================+\n");

    }
} //end of print function

/*
NEXT FUNCTION
Moves users up in the waitlist and provides who the next patient is
@param {void}
@return {void}
*/

void next() {
    //if counter is zero, it means nobody is on the waitlist
    if (counter == 0) {
        printf("The waitlist is empty!\n");
    } else {
        //first person in line is at index 0 
        printf("\n\nThe next person from the waitlist is %sn\n", names[0]);
        int i;
        //shifts every time the name/symptom is in the waitlist up one
        for (i = 0 ; i < SIZE - 1; i++) {
            strcpy(names[i], names[i + 1]);
            strcpy(names[i + 1], "");
            strcpy(symptoms[i], symptoms[i + 1]);
            strcpy(symptoms[i + 1], "");
        }
        //decrement the counter to keep next() position in sync
        counter--;
        print();
    }
}//end of next function

/*
isRepeat function
helper function to check if a name already exists in waitlist
@param { char string } the name to test
@return { int } 1 if is duplicate, 0 if not duplicate
*/

int isRepeat(char name[20]) {
    int i;
    //initialize at 0
    int val = 0;
    //loop through array
    for (i = 0; i < SIZE; i++) {
        //detect if name is equal
        if (strcmp(name, names[i]) == 0) {
            //set to one if name is equal 
            val = 1;
        } 
    }
       return val;
} //end of isRepeat function
