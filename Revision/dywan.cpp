#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool is_Multiple_Of_3(int num){
   bool isMultiple = true;
  if(num%3==0){
        while(num>=3){
            num = num / 3;
        }
        if(num!=1){
          isMultiple = false;
        }
    }else {
        return false;
    }
    return isMultiple;
}

void drawCarpet(vector<vector<int>>& carpet, int x, int y, int size){

  if(size == 1){ //First rule of recursion
    carpet[x][y] = 1;
    return;
  }

  int newSize = size / 3;
  for(int i=0; i<3; ++i){
      for(int j=0; j<3; ++j){
          if(i==1 && j==1) continue; //Middle of the square
          drawCarpet(carpet, x+i*newSize, y+j*newSize, newSize);
      }
  }
}

void generateCarpet(int size, const string& filePath){

  vector<vector<int>> carpet(size, vector<int>(size, 0)); //Fill 0 values

  drawCarpet(carpet, 0, 0, size);

  ofstream file(filePath);
  if(!file.is_open()){
    cout<<"Nie można otworzyć pliku: "<<filePath<<endl;
    return;
  }

  file << "P2\n";
  file << size<<" "<<size<<"\n";
  file << "1\n";

  for(int i=0; i<size; ++i){
    for(int j=0; j<size; ++j){
        cout<<carpet[i][j]<<endl;
      file << carpet[i][j]<<" ";
    }
      cout<<endl;
    file<<endl;
  }
  file.close();
}

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);
    if(is_Multiple_Of_3(size)){
        string filePath = argv[2];
        generateCarpet(size, filePath);
    }else {
        cout<<"No"<<endl;
    }
}
