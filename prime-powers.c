//Prime powers.c - Change  PCOUNT and POWER and this program will find the first PCOUNT primes, and then prints sequence of all the powers up to POWER for each
// example, with POWER 3, PCOUNT 2, We get output {2,4,8,3,9,27} which is the first 3 powers of the first 2 primes (2 and 3)

//This program is meant to (partially) produce sequence A246655 in the OEIS

#include <stdio.h>
#include <stdbool.h>

#define PCOUNT 10
#define POWER 5
//function headers
bool isPrime(int n);
void findPrimes(int n, int arr[]);
int power(int n,int p);
void fillPArr(int n, int pow, int arr[], int pArr[]);
void printArr (int arr[],int size); //print array elements
void arraySwap(int arr[],int indx1, int indx2);
void insertionSort(int arr[],int size);

int main(){
    int size = POWER*PCOUNT;

    int array[PCOUNT];
    findPrimes(PCOUNT,array);

    int pArray[size];
    fillPArr(PCOUNT,POWER,array,pArray);

    insertionSort(pArray,size);
    printArr(pArray, size);
}

int power(int n,int p){ //this is incorrect but should work becose we only using positive integers 1 or greater. won't work for p < 1 
    if(p == 1)
        return n;
    return n * power(n,p-1);
}
void fillPArr(int n, int pow, int arr[], int pArr[]){
    int pos = 0;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=pow;j++){
            pArr[pos] = power(arr[i],j);
            pos++;
        }
    }
}

void findPrimes(int n, int arr[]){
    int count = 0;
    int i = 2;
    while(count<n){
        if(isPrime(i)){
            arr[count] = i;
            count++;
        }
        i++;
    }
}
bool isPrime(int n){
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
void printArr (int arr[],int size){
    for(int i = 0; i<size; ++i){
        (i < size-1) ? printf("%d,",arr[i]):printf("%d\n",arr[i]);
    }
}
void arraySwap(int arr[],int indx1, int indx2){// swap values of indx1 and indx2
    int temp = arr[indx1];
    arr[indx1] = arr[indx2];
    arr[indx2] = temp;
}
void insertionSort(int arr[],int size){ //we find and insert the minimum element and repeat to get sorted array
    int key,j;
    for(int i = 1;i<size;i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){	
            arr[j+1] = arr[j];				
            j--;							
        }
        arr[j+1] = key;					
    }
}
