#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int b, int c) {
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

int main (){
    int array[10] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size = 9;
    int count = 0;
      for(int i = 0; i < size - 1; i++){       

        for(int j = 0; j < size - i - 1; j++){          

            if(array[j] > array[j + 1]){               
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                count++;
            }
        }
    }

    for(int i = 0; i <size; i++){
        printf("%d\n",array[i]);
    }
    printf("Count: %d", count);
}