#include <iostream>

using namespace std;

string jednosci(char one){
    string local_result = "";
    switch (one)
    {
    case '1':
        local_result += "jeden";
        break;
    case '2':
        local_result += "dwa";
        break;
    case '3':
        local_result += "trzy";
        break;
    case '4':
        local_result += "cztery";
        break;
    case '5':
        local_result += "pięć";
        break;
    case '6':
        local_result += "sześć";
        break;
    case '7':
        local_result += "siedem";
        break;
    case '8':
        local_result += "osiem";
        break;    
    case '9':
        local_result += "dziewięć";
        break; 
    default:
        break;
    }
    return local_result;
}

string dziesiatki(char dec){
    string local_result = "";
    switch (dec)
    {
    case '2':
        local_result += "dwadzieścia ";
        break;
    case '3':
        local_result += "trzydzieści ";
        break;
    case '4':
        local_result += "czterdzieści ";
        break;
    case '5':
        local_result += "pięćdziesiąt ";
        break;
    case '6':
        local_result += "sześćdziesiąt ";
        break;
    case '7':
        local_result += "siedemdziesiąt ";
        break;
    case '8':
        local_result += "osiemdziesiąt ";
        break;    
    case '9':
        local_result += "dziewięćdziesiąt ";
        break; 
    default:
        break;
    }
    return local_result;
}

string setki(char cen){
    string local_result = "";
    switch (cen)
    {
    case '1':
        local_result += "sto ";
        break;
    case '2':
        local_result += "dwieścia ";
        break;
    case '3':
        local_result += "trzysta ";
        break;
    case '4':
        local_result += "czterysta ";
        break;
    case '5':
        local_result += "pięćset ";
        break;
    case '6':
        local_result += "sześćset ";
        break;
    case '7':
        local_result += "siedemset ";
        break;
    case '8':
        local_result += "osiemset ";
        break;    
    case '9':
        local_result += "dziewięćset ";
        break; 
    default:
        break;
    }
    return local_result;
}

int main(){
    string number;
    cin>>number;
    string result = "";
    if (number[0] == '-')
    {
        result += "minus ";
        if (number.length() == 4)
        {
            result += setki(number[1]);
            if(number[2] == '1'){
                switch (number[3])
                {
                case '1':
                    result += "jedenaście ";
                    break;
                case '2':
                    result += "dwanaście ";
                    break;
                case '3':
                    result += "trzynaście ";
                    break;
                case '4':
                    result += "czternaście ";
                    break;
                case '5':
                    result += "piętnaście ";
                    break;
                case '6':
                    result += "szesnaście ";
                    break;
                case '7':
                    result += "siedemnaście ";
                    break;
                case '8':
                    result += "osiemnaście ";
                    break;    
                case '9':
                    result += "dziewiętnaście ";
                    break; 
                default:
                    break;
                }
            }else{
                result += dziesiatki(number[2]); 
                result += jednosci(number[3]);
            }
        }else if(number.length() == 3){
            if(number[1] == '1'){
                switch (number[2])
                {
                case '1':
                    result += "jedenaście ";
                    break;
                case '2':
                    result += "dwanaście ";
                    break;
                case '3':
                    result += "trzynaście ";
                    break;
                case '4':
                    result += "czternaście ";
                    break;
                case '5':
                    result += "piętnaście ";
                    break;
                case '6':
                    result += "szesnaście ";
                    break;
                case '7':
                    result += "siedemnaście ";
                    break;
                case '8':
                    result += "osiemnaście ";
                    break;    
                case '9':
                    result += "dziewiętnaście ";
                    break; 
                default:
                    break;
                }
            }else{
                result += dziesiatki(number[1]); 
                result += jednosci(number[2]);
            }
        }else if(number.length() == 2){
            result += jednosci(number[1]);
        }
        
    }else{
        if (number.length() == 3)
        {
            result += setki(number[0]);
            if(number[1] == '1'){
                switch (number[2])
                {
                case '1':
                    result += "jedenaście ";
                    break;
                case '2':
                    result += "dwanaście ";
                    break;
                case '3':
                    result += "trzynaście ";
                    break;
                case '4':
                    result += "czternaście ";
                    break;
                case '5':
                    result += "piętnaście ";
                    break;
                case '6':
                    result += "szesnaście ";
                    break;
                case '7':
                    result += "siedemnaście ";
                    break;
                case '8':
                    result += "osiemnaście ";
                    break;    
                case '9':
                    result += "dziewiętnaście ";
                    break; 
                default:
                    break;
                }
            }else{
                result += dziesiatki(number[1]) ;
                result += jednosci(number[2]);
            }
        }else if(number.length() == 2){
            if(number[0] == '1'){
                switch (number[1])
                {
                case '1':
                    result += "jedenaście ";
                    break;
                case '2':
                    result += "dwanaście ";
                    break;
                case '3':
                    result += "trzynaście ";
                    break;
                case '4':
                    result += "czternaście ";
                    break;
                case '5':
                    result += "piętnaście ";
                    break;
                case '6':
                    result += "szesnaście ";
                    break;
                case '7':
                    result += "siedemnaście ";
                    break;
                case '8':
                    result += "osiemnaście ";
                    break;    
                case '9':
                    result += "dziewiętnaście ";
                    break; 
                default:
                    break;
                }
            }else{
                result += dziesiatki(number[0]) ;
                result += jednosci(number[1]);
            }
        }else if(number.length() == 1){
            result += jednosci(number[0]);
        }
    }
    cout<<"Liczba: "<<result; 
    
    return 0;
}