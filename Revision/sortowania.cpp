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
