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
