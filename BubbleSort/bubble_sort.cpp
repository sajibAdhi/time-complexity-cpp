/**
*   Name: Sajib Adhikary
*   ID  : CSE1901016103
*   Section: 16A3
*   Bubble Sort Time Complexity
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

/**
*   Swap Two Parameters
*/
void swap(long* a, long* b) {
    long t = *a;
    *a = *b;
    *b = t;
}

/**
*   Bubble Sort Function
*
*/
void bubbleSort(long arr[], long high)
{
    int k, p;
    for(k=1; k<high; k++){
        for(p=0; p<high-k; p++){
            if(arr[p]>arr[p+1]){
                swap(&arr[p], &arr[p+1]);

            }
        }
    }
}

/**
*
*   *MAin Function Starts Here
*
*/
int main()
{
    long amount,i,j,save;
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

    //Start Time counting
    start = clock();

    bubbleSort(numbers, amount);

   //End time Counting
    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Bubble Sort Complete.\n\n";
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
