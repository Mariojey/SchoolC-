#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(int arr[], int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void selectionSort(int arr[], int n){
  for(int i=0;i<n-1;i++){
    int min = i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

void insertionSort(int arr[], int n){
  for(int i=1;i<n;i++){
    int temp = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>temp){
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = temp;
  }
}

void merge(int arr[], int left, int middle, int right){
  int n1 = middle - left + 1;
  int n2 = right - middle;

  int leftNumbers[n1], rightNumbers[n2];
  for(int i=0;i<n1;i++){
    leftNumbers[i] = arr[left];
  }
  for(int i=0;i<n2;i++){
    rightNumbers[i] = arr[middle+1];
  }
  int i = 0, j = 0, k = left;
  while(i<n1 && j<n2){
    if(leftNumbers[i]<=rightNumbers[j]){
      arr[k] = leftNumbers[i];
    }
    else{
      arr[k] = rightNumbers[j];
    }
  }
  while(i<n1){
    arr[k++] = leftNumbers[i++];
  }
  while(j<n2){
    arr[k++] = rightNumbers[j++];
  }
}

void mergeSort(int arr[], int left, int right){
  if(left<right){
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main(int argc, char * argv[]) {

  string sortType = argv[1];
  string sourceFile = argv[2];

  fstream inputFile;
  inputFile.open(sourceFile);

  if (!inputFile.is_open()) {
    cout<<"Nie ma pliku"<<endl;
    return 1;
  }

  int countNumbers;
  inputFile>>countNumbers;

  int * tab  = new int[countNumbers];

  //To coś wczyta ignorując spacje, nie trzbea getline !
  for (int i = 0; i < countNumbers; i++) {
    inputFile>>tab[i];
  }

  inputFile.close();

  delete[] tab;

}
