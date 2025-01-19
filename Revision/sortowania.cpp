#include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

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

int partition(int arr[], int left, int right){
  int pivot = arr[right];
  int i = left, j = right;
  while(i<j){
    if(arr[i]<=pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i], arr[right]);
  return i;
}

void quickSort(int arr[], int left, int right){
  if(left<right){
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
  }
}

void heapify(int arr[], int n, int i){

  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l<n && arr[l] > arr[largest]){
    largest = l;
  }

  if(r<n && arr[r] > arr[largest]){
    largest = r;
  }

  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }

}

void heapSort(int arr[], int n){
  for(int i=n/2-1; i>=0; i--){
    heapify(arr,n,i);
  }
  for(int i = n-1; i>0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int sum(int arr[], int n){
  int sum = 0;
  for(int i = 0; i <n; i++){
    sum += arr[i];
  }
  return sum;
}

int sumABS(int arr[], int n){
  int sum = 0;
  for(int i = 0; i < n-1; i++){
    sum += abs(arr[i+1]-arr[i]);
  }
  return sum;
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

  int sum_before = sum(tab, countNumbers);
  int abs_before = sumABS(tab, countNumbers);

  auto start = high_resolution_clock::now();

  if(sortType == "babelkowe"){
    bubbleSort(tab, countNumbers);
  }else if(sortType == "wstawianie"){
    insertionSort(tab, countNumbers);
  }else if(sortType == "wybieranie"){
    selectionSort(tab, countNumbers);
  }else if(sortType == "scalanie"){
    mergeSort(tab, 0, countNumbers-1);
  }else if(sortType == "stogowe"){
    heapSort(tab, countNumbers);
  }else if(sortType == "szybkie"){
    quickSort(tab, 0, countNumbers-1);
  }else {
    cout<<"Nie ma takiego sortowania"<<endl;
    delete [] tab;
    return 1;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  int sum_after = sum(tab, countNumbers);
  int abs_after = sumABS(tab, countNumbers);



  delete[] tab;

  cout<<"Przed sortowaniem:"<<endl;
  cout<<"SL: "<<sum_before<<endl;
  cout<<"SWBR: "<<abs_before<<endl;
  cout<<"Po sortowaniu:"<<endl;
  cout<<"SL: "<<sum_after<<endl;
  cout<<"SWBR: "<<abs_after<<endl;
  cout<<"Czas: "<<duration.count()<<" ms. "<<<<endl;

  return 0;
}
