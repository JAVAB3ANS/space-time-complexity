# include <stdio.h>
# define lowEnd 2
# define highEnd 7

/*Returns the number of integers in the array that are greater than number x*/

int number_of_greater_than(int target, int arr_size[], int arr_num) {
    int i, greater_number;
    for (i = 0; i < arr_num; i++) {
        if (arr_size[i] > target) {
            greater_number++;
        }
    }
    
    return greater_number;
}

int main() {  
    int arr_size[highEnd] = {1, 2, 3, 4, 5, 6, 7};
    int variable = number_of_greater_than(lowEnd, arr_size, highEnd);
    printf("There are %d total numbers greater than %d.", variable, lowEnd);
    
    return 0;
}

//prints There are 5 total numbers greater than 2.