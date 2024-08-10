// willl search in an array that some value is present or not

#include <stdio.h>

// find value function
void find(int* arr, int size, int value){
    int position = -1;
    for (int i = 0; i < size; i++){
        if (*(arr + i) == value){
            position = i;
            break;
        }
    }
    if (position == -1){
        printf("\nvalue %d not present", value);
    }
    else{
        printf("\nvalue %d is present at %d",value, position);

    }
    

}

int main(){
    //? Im not writing the user get functions or pint fuction, focus is on the searching

    int arr[10] = {2,3,6,4,6,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    find(arr, size, 56);
   
    
    return 0;
}
