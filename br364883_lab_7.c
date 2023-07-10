#include <stdio.h>
#include <stdlib.h>

int main (){
    int array[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size = sizeof(array) / sizeof(array[0]);
    int swaps[size];
    //intialize the swaps count to zero
    for (int i = 0; i < size; i++) {
        swaps[i] = 0;
    }
    // bubble sort
      for(int i = 0; i < size - 1; i++){       
        for(int j = 0; j < size - i - 1; j++){          
            if(array[j] > array[j + 1]){               
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps[j]++;
            }
        }
    }
    //print
    printf("Index\tIndex Value\tSwaps\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\n", i, array[i], swaps[i]);
    }
    return 0;
}