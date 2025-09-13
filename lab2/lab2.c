#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//function to print the array
void printArr(int* s){
    int i;
    for (i=0;i<26;i+=1){
        printf("%d ",s[i]);
    }
    printf("\n");
}

//function to swap elements in an array
void swap(int*A, int i, int j){
    int k = A[i];
    int l = A[j];
    A[i] = l;
    A[j] = k;
}

//function to shuffle an array
void shuffleArray(int* A,int n){
    int i;
    int j;
    for (i=n-1;i>0;i=i-1){
        j = rand()%i;
        swap(A,i,j);
    }
}

//function to rotate an array A of size n by rot places
void rotateArray(int*A, int n, int rot){
     if (rot < 0) {
        rot = (rot % n + n) % n;  
    } else {
        rot = rot % n;
    }
    int* buf = (int*)malloc(rot*sizeof(int));
    int i;
    for (i=0;i<rot;i+=1){
        buf[i] = A[i];
    };
    for (i=rot;i<n;i+=1){
        A[i-rot] = A[i];
    }
    for (i=0;i<rot;i+=1){
        memcpy(&A[n-rot],buf,rot*sizeof(int));
        //A[n-rot+1]=buf[i]
    }

}

//function to calculate the frequency table of a given file
int statsAttack(FILE* ptr,FILE* wPtr, char fileName[],char outName[]){
    //initialising variables
    char c;
    int n = 27;
    int* a;
    int i;
    int v;

    //allocating memory for the array for size 27 ( 26 letters + extra character)
    a = (int*) malloc(n*sizeof(int));

    //initiallizing the array with zeros
    for (i=0;i<27;i++){
        a[i] = 0;
    }

    //opening the file to be read using readmode and pointing the file to it
    ptr = fopen(fileName,"r");
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
    wPtr = fopen(outName,"w");

    //printing the array and writting the array into the file using the fprintf functions
    for (i=0;i<n;i=i+1){
        //printf("%d\n",a[i]);
        fprintf(wPtr,"%d\n",a[i]);
    }

    //closing the filepointer
    fclose(wPtr);
    //freeing up the allocated memory - good practice
    free(a);
    return 0;
}

//function to decrypt a file by rotating the letters by k
int decrpt(FILE* enFile, FILE* deFile, int k){
    int d[26];
    int i;
    char c;
    for (i=0;i<26;i+=1){
        d[i] = i;
    };
    rotateArray(d,26,k);

    enFile = fopen("encrptedFile.txt","r");

    //creating the file to be written in write mode
    deFile = fopen("decryptedFile.txt","w");

    if (enFile == NULL){
        return 1;
    } while (( c = fgetc(enFile)) != EOF){

        if (c>= 'a' && c <= 'z')
        {
            c = 'a'+ d[c - 'a'];
            fprintf(deFile,"%c",c);
        }
    }
    //closing the file
    fclose(enFile);
    fclose(deFile);
    return 0;
}

//function to encrypt a file by rotating the letter by k
int encrpt(FILE* ogFile, FILE* newFile,int k){
    int s[26];
    int i;
    char c;

    for (i=0;i<26;i+=1){
        s[i] = i;
    };
    //printArr(s);
    rotateArray(s,26,k);
    //printArr(s);
    
    ogFile = fopen("readfile.txt","r");
    //creating the file to be written in write mode
    newFile = fopen("encrptedFile.txt","w");

    if (ogFile == NULL){
        return 1;
    } while (( c = fgetc(ogFile)) != EOF){

        if (c>= 'a' && c <= 'z')
        {
            c = 'a'+ s[c - 'a'];
            //printf("%c",c);
            fprintf(newFile,"%c",c);
            //printf("\n");
        }
    }
    fclose(ogFile);
    fclose(newFile);
    return 0;
}

int final(FILE*ogFile,FILE*freqOut){
    int c;
    int d;
    ogFile = fopen("freq.txt","r");
    freqOut = fopen("output.txt","r");
    int flag = 2;

    if (ogFile == NULL || freqOut == NULL){
        return 1;
    } while (fscanf(ogFile, "%d", &c) == 1 && fscanf(freqOut, "%d", &d) == 1){
        if (c != d){
            flag = 1; // mismatch found
            break;
        }

    }
    return flag;
}


int main(){
    FILE* ptr;
    FILE* wPtr;
    //encrypting the file
    srand(time(NULL));
    int k = rand() % 27;
    printf("k: %d\n",k);
    encrpt(ptr,wPtr,k);

    //frequency table generating
    statsAttack(ptr,wPtr,"readfile.txt","freq.txt");

    for (int i = 0; i<27; i+=1){
        //decrypting the file
        decrpt(ptr,wPtr,-i);
        statsAttack(ptr,wPtr,"decryptedFile.txt","output.txt");
        //printf("Trying shift: %d\n",i);
        if (final(ptr,wPtr) == 2){
            printf("\nThe file is encrypted by a Shift of %d\n",i);
            break;
        } 
    }
    
    return 0;
}