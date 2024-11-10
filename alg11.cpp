#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    string filePath = argv[1];
    for (int i = 2; i < argc; i++)
        {
                ifstream includedFile(filePath);

                string line;
                string schema = argv[i];
                cout<<"Linie zawierające słowo "<<"\""<<schema<<"\":"<<endl;
                while (getline(includedFile, line))
                {
                    if(line.length() >= schema.length()){
                        for (int j = 0; j < line.length()-schema.length()-1; j++)
                        {
                            string textElement = line.substr(j, schema.length());
                            if(textElement == schema){
                                cout<<line<<endl;
                                break;
                            }

                        }
                    }
                }
            
            includedFile.close();
        }
    
    return 0;

}
