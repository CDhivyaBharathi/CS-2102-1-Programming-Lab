#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* ptr;
    FILE* wPtr;
    char c;
    int n = 27;
    int* a;
    int i;
    int v;

    a = (int*) malloc(n*sizeof(int));

    for (i=0;i<0;i++){
        a[i] = 0;
    }

    ptr = fopen("readfile.txt","r");
    if (ptr == NULL){
        return 1;
    } while (( c = fgetc(ptr)) != EOF){
        v = c - 'a';
        if (v >= 0 && v < 26){
            a[v] = a[v] + 1;
        } else {
            a[n-1] = a[n-1] + 1;
        }
    }
    fclose(ptr);


    wPtr = fopen("writefile.txt","w");
    for (i=0;i<n;i=i+1){
        printf("%d\n",a[i]);

        fprintf(wPtr,"%d\n",a[i]);
    }
    fclose(wPtr);
    free(a);
}