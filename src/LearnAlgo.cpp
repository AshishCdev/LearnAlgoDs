//============================================================================
// Name        : LearnAlgo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printArray(int *ArrayPtr, int ArraySize){
    cout << "[ ";
    for (int i = 0; i < ArraySize; i++)
    {
        cout << ArrayPtr[i] << " ";
    }
    cout << "]" << endl;
}

int bubbleSort(int *aryAddr, int size){
    int Temp = 0;
    for (int i=0; i < (size-1);){    // No need to check if variable is the last element
        if(aryAddr[i] > aryAddr[i+1]){
            Temp = aryAddr[i];
            aryAddr[i] = aryAddr[i+1];
            aryAddr[i+1] = Temp;
            if(i>0) i--;
        }
        else{
            i++;
        }
    }
    return 0;
}

int mergeFinal(int *aryAddr, int size){
    int ansArray[size];
    int firstArrayStartIndex = 0;
    int secndArrayStartIndex = 0;
    if(size%2 == 0) secndArrayStartIndex = (size/2);
    else secndArrayStartIndex = ((size/2)+1);
    int boundry = secndArrayStartIndex;
    for (int i = 0; i < size;i++){
        if(firstArrayStartIndex >= boundry){
            ansArray[i] = aryAddr[secndArrayStartIndex];
            secndArrayStartIndex++;
        }
        else if(secndArrayStartIndex >=size){
            ansArray[i] = aryAddr[firstArrayStartIndex];
            firstArrayStartIndex++;
        }

        else if (aryAddr[firstArrayStartIndex] < aryAddr[secndArrayStartIndex]){
            ansArray[i] = aryAddr[firstArrayStartIndex];
            firstArrayStartIndex++;
        }
        else{
            ansArray[i] = aryAddr[secndArrayStartIndex];
            secndArrayStartIndex++;
        }
    }
    for (int i = 0; i < size;i++){
        aryAddr[i] = ansArray[i];
    }
    return 0;
}

void MergeSortArray(int * unsrtedArray,int size){
	if(size <= 1){
		return;
	}
	else{
		if((size%2) == 0){
			MergeSortArray(unsrtedArray, size/2);
			MergeSortArray(&unsrtedArray[size/2], size/2);
		}
		else {
			MergeSortArray(unsrtedArray, ((size/2)+1));
			MergeSortArray(&unsrtedArray[((size/2)+1)], ((size/2)));
		}
		mergeFinal(unsrtedArray, size);
	}
}

int main() {
	int unsrtedArray[10] = {245,4323,64,80,1000,1,356,523,75,977};
	MergeSortArray(unsrtedArray,(sizeof(unsrtedArray)/sizeof(int)));
	printArray(unsrtedArray, (sizeof(unsrtedArray)/sizeof(int)));
	return 0;
}
