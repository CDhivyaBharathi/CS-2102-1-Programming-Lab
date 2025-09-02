#include <stdio.h>
#include <stdlib.h>

int main(){
    //file pointers
    FILE* ptr;
    FILE* wPtr;

    //initialising variables
    char c;
    int n = 27;
    int* a;
    int i;
    int v;

    //allocating memory for the array for size 27 ( 26 letters + extra character)
    a = (int*) malloc(n*sizeof(int));

    //initiallizing the array with zeros
    for (i=0;i<0;i++){
        a[i] = 0;
    }

    //opening the file to be read using readmode and pointing the file to it
    ptr = fopen("readfile.txt","r");
    if (ptr == NULL){
        return 1;
    } while (( c = fgetc(ptr)) != EOF){

        //subtracting the value of the read character and the value of 'a' (assume 0) so that even in repetition the same index gets updated
        v = c - 'a';

        //checking if its a valid character
        if (v >= 0 && v < 26){
            a[v] = a[v] + 1;
        } else {
            a[n-1] = a[n-1] + 1; //any other characters (even capital characters) will be stored in the last position in the array
        }
    }
    //closing the file
    fclose(ptr);


    //creating the file to be written in write mode
    wPtr = fopen("writefile.txt","w");

    //printing the array and writting the array into the file using the fprintf functions
    for (i=0;i<n;i=i+1){
        printf("%d\n",a[i]);

        fprintf(wPtr,"%d\n",a[i]);
    }

    //closing the filepointer
    fclose(wPtr);

    //freeing up the allocated memory - good practice
    free(a);
}