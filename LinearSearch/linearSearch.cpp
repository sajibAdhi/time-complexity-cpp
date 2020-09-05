/**
*   Name: Sajib Adhikary
*   ID  : CSE1901016103
*   Section: 16A3
*   Linear Search Time Complexity
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define clockPerSec 1000
using namespace std;
long numbers[400000];

/**
*   Main Function Start's Here
*/
int main(int argc, char ** argv)
{
    long amount,i,j,value,ptr,counter=0;
    double finish;
    clock_t start;

    //File operation starts here
    FILE *inputFile, *outputFile;

    inputFile = fopen("../inputfile.txt","r");
    outputFile = fopen("outputfile.txt","w");
    fscanf(inputFile,"%d",&amount);

    cout<<"\n\t<<< Reading data from File ..... "<<endl;
    for (i=0; i<amount; i++){
        fscanf(inputFile,"%d",&numbers[i]);
    }
    cout<<"\t<<< Data reading complete !!!\n\n";
    cout<<"Please enter a value for search :";
    cin>>value;

    cout<<"\n\t<<< Linear Search process started,Please Wait...\n";
    fprintf(outputFile,"\t<<<: Linear Search Time Complexity :>>>\n\nValue entered for search : %ld \n\n",value);

    start = clock(); //time initialization
            //Linear Search algorithm starts here.......
    for(ptr=0; ptr<amount; ptr++){
        if(numbers[ptr] == value){
            fprintf(outputFile,"Position of data = %ld : %ld\n",ptr,value); //prints the array index where data is founded
            counter++;
        }
    }
    finish = ((double)start)/clockPerSec; //Desired time

    cout<<"\t<<< Search Complete ...!!!\n\n";
    cout<<"\t<<< Total number of Data :"<<amount<<endl<<endl;

    if(counter>0){
        cout<<"\t<<< Number of Data found: "<<counter<<" ,Time needed for searching :  "<<finish<<" sec\n";
        fprintf(outputFile,"Data found = %d times, Search Time = %lf sec",counter,finish);
    }
    else {
            fprintf(outputFile,"Data isn't Founded ! Try another Number.......\n");
            cout<<"Data isn't Founded ! Try another Number.......\n";
            cout<<"Time needed for searching :  "<<finish<<"sec\n";
    }
    cout<<"\n\n\t<<< This informations are printed to file named 'outputLinearSearch.txt' \n"<<endl;

	return 0;
}
