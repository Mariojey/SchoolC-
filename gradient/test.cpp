#include <iostream>
#include <fstream>

using namespace std;

void generate_gradient(int width, int heigth, const string& destination, const string& filename){
    ofstream file(filename);
    if(!file.is_open()){
        cout<<"Nie można otworzyć pliku do zapisu."<<endl;
    }

    file << "P2\n";
    file << width <<" "<<heigth<<"\n";
    file << "255\n";

    int value = 0;
    for(int y = 0; y<heigth; y++){
        for (int x = 0; x < width; x++)
        {
            // int value = static_cast<int>((static_cast<float>(255-x)/(width - 1)) * 255);
            // file << value << " ";
            if (destination.length() == 1)
            {
                switch (destination[0])
                {
                case 'N':
                    value = static_cast<int>((static_cast<float>(255-y)/(heigth - 1)) * 255);
                    file << value << " ";
                    break;
                case 'W':
                    value = static_cast<int>((static_cast<float>(255-x)/(width - 1)) * 255);
                    file << value << " ";
                    break;
                case 'E':
                    value = static_cast<int>((static_cast<float>(x)/(width - 1)) * 255);
                    file << value << " ";
                    break;
                case 'S':
                    value = static_cast<int>((static_cast<float>(y)/(heigth - 1)) * 255);
                    file << value << " ";
                    break;
                
                default:
                    break;
                }
            }else if(destination.length() == 2){
                switch (destination[0])
                {
                case 'N':
                    switch (destination[1])
                        {
                        case 'N':
                            value = static_cast<int>((static_cast<float>(255-y)/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        case 'W':
                            value = static_cast<int>((static_cast<float>(255-((y-1)+(x-1)))/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        case 'E':
                            value = static_cast<int>((static_cast<float>((x-y))/(heigth - 1)) * 255);
                            file << value << " ";                            
                            break;
                        case 'S':
                             value = static_cast<int>((static_cast<float>(255-y)/(heigth - 1)) * 255);
                            file << value << " ";                           
                        
                        default:
                            break;
                        }
                    break;
                case 'W':
                    switch (destination[1])
                        {
                        case 'N':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";        
                            break;
                        case 'W':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";                           
                            break;
                        case 'E':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";                            
                            break;
                        case 'S':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        
                        default:
                            break;
                        }                    
                    break;
                case 'E':
                    switch (destination[1])
                        {
                        case 'N':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";        
                            break;
                        case 'W':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";                           
                            break;
                        case 'E':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";                            
                            break;
                        case 'S':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " "; 
                            break;
                        default:
                            break;
                        }                    
                    break;
                case 'S':
                    switch (destination[1])
                        {
                        case 'N':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        case 'W':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        case 'E':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        case 'S':
                            value = static_cast<int>((static_cast<float>(255-(y-1)+(x-1))/(heigth - 1)) * 255);
                            file << value << " ";
                            break;
                        default:
                            break;
                        }                    
                
                default:
                    break;
                }
            }
            
        }
        
    };
            file.close();
}

int main(){
    int width,height;
    string destination;
    string filename;
    cin>>width;
    cin>>height;
    cin>>destination;
    cin>>filename;
    generate_gradient(width, height, destination, filename);
    return 0;
}