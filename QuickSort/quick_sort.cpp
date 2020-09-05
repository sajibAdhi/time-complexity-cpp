/**
*   Name: Sajib Adhikary
*   ID  : CSE1901016103
*   Section: 16A3
*   Quick Sort Time Complexity
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

/**
*   Swap Two Param
*/
void swap(long* a, long* b) {
    long t = *a;
    *a = *b;
    *b = t;
}

/**
*   Paratition Function
*   @retrun j
*/
long partition (long arr[], long low, long high) {
    long pivot = arr[high];
    long i = (low - 1);

    for (long j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++;
            // Swap two Value
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
*   Quick Sort Function
*/
void quickSort(long arr[], long low, long high) {
    if (low < high) {
        //partition the array
        long pivot = partition(arr, low, high);
        //sort the sub arrays recursivly
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

/**
*
*   *MAin Function Starts Here
*
*/
int main(int argc, char ** argv){
    long amount,i,j;
    double finish;
    clock_t start;

    FILE *inputFile, *outputFile;

    //File Operation Starts Here
    inputFile = fopen("../inputFile.txt","r");
    outputFile = fopen("outputFile.txt","w");

    //Taking the amount of data's
    fscanf(inputFile,"%d",&amount);

    cout<<"\n\t<<< Reading Data Form File..... "<<endl;
    for (i=0; i<amount; i++){
        fscanf(inputFile,"%d",&numbers[i]);
    }
    cout<<"\t<<< Data Reading Complete.\n";

    cout<<"\t<<< Quick Sort process started.\n\t<<<Please Wait.....\n";

    //Start time counting
    start = clock();

    //Quick Sort function calling here..
    quickSort(numbers, 0, amount-1);

    //End time Counting
    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Quick Sort Complete.\n\n";
    cout<<"\t<<< Number of Data : "<<amount<<" Time needed for sorting is :  "<<finish<<endl;

    cout<<"\n\n\t<<< This information is recorded to file 'outFile.txt' \n"<<endl;
	fprintf(outputFile,"Data = %d , Time = %lf",amount,finish);
	fprintf(outputFile,"\n\n Sorted Data : \n\n");

    //Creating Output file
    for(long i=0; i<amount; i++){
        fprintf(outputFile,"%d\n",numbers[i]);
    }
	return 0;
}
