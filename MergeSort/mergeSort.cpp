/**
*   Name: Sajib Adhikary
*   ID  : CSE1901016103
*   Section: 16A3
*   Binary Search Time Complexity
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

/**
* Merges two sub arrays of arr[].
* First sub array is arr[l..m]
* Second sub array is arr[m+1..r]
* @peram long arr[]
* @peram long l
* @peram long m
* @peram long r
*/
void merge(long arr[], long l, long m, long r){
    long i, j, k;
    long n1 = m - l + 1;
    long n2 = r - m;

    // create temp arrays
    long L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first sub array
    j = 0; // Initial index of second sub array
    k = l; // Initial index of merged sub array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
* Merge Sort Function
* @peram long arr[]
* @peram long l
* @peram long r
*/
void mergeSort(long arr[], long l, long r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/**
*   Main Function Starts here
*/
int main(int argc, char ** argv)
{
    long amount,i=0,j,read;
    double finish;
    clock_t start;

    //File operation starts here
    ofstream outputFile; //creates output file stream
    outputFile.open("outputFile.txt",ios::out);

    //opens file for reading data
    ifstream is("../inputFile.txt");
    is>>read;
    amount = read; //getting 1st data from file

    cout<<"\n\t<<< Reading data from File ..... "<<amount<<endl;
    while(i<amount && is>>read){
        numbers[i++] = read;
    }
    cout<<"\t<<< Data reading complete !!!\n";
    cout<<"\t<<< Merge Sort process started,Please Wait...\n";

    start = clock(); //time initialization
    //Merge Sort function calling here..
    mergeSort(numbers,0,amount-1);
    finish = ((double)start)/clockPerSec;

    cout<<"\t<<< Sorting Complete ...!!!\n\n";
    cout<<"\t<<< Number of Data : "<<amount<<" ,Time needed for sorting :  "<<finish<<" sec\n";

    cout<<"\n\n\t<<< This informations are printed in file named 'outputMergeSort.txt' \n"<<endl;
    outputFile<<"Data = "<<amount<<" ,Time needed = "<<finish<<endl;
    outputFile<<"\n\n\t<<< Array after Merge Sort :\n";

    for(i=0; i<amount; i++){
        outputFile<<numbers[i]<<endl; //prints sorted data into the file ...
    }

	return 0;
}
