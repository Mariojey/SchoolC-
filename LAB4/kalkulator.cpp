#include <iostream>
#include <iomanip>

using  namespace std;

float dodaj(float a, float b){
    return a+b;
}
float odejmij(float a, float b){
    return a-b;
}
float pomnoz(float a, float b){
    return a*b;
}
float podziel(float a, float b){
    if(b==0){
        cout<<"Nie można dzielić przez 0"<<endl;
}
    return a/b;
}
int main(){
	string  text;
	cout<<"Działanie: ";
	getline(cin, text);
	int a = 0,b= 0 ;
	char operatorr;
	string textA ="",textB="";
	int i =0;
	while(text[i]!='/' && text[i]!='*'){
        // cout<<"Element: "<<text[i]<<endl;
		if(static_cast<int>(text[i])== 32){
            operatorr = text[i+1];
            i++;
            i++;
            break;
            // textA += text[i];
        }else{
            textA += text[i];
        }
        i++;
	}
    if(text[i] == '/' || text[i] == '*'){
        operatorr = text[i];
    }
	i++;
	while(i<text.length()){
		if(static_cast<int>(text[i])!= 32){
            textB += text[i];
        }
        i++;
	}
        // cout<<textA<<" end of A "<<operatorr<<" start of b "<<textB<<endl;
    if(textA[0] == '-'){
        a = stof(textA.substr(1,textA.length()));
        b = stof(textB);
        a = a * (-1.0);
    }else if(textB[0] == '-'){
        a = stof(textA);
        b = stof(textB.substr(1,textA.length()));
        b = b * (-1.0);
    }else{
        a = stof(textA);
        b = stof(textB);
    }
    // cout<<a<<" "<<operatorr<<" "<<b<<endl;
    if(textB == "" || (operatorr != '+' && operatorr != '-' && operatorr != '*' && operatorr != '/')){
        cout<<"Nieprawidłowe działanie"<<endl;
    }else{
        switch(operatorr) {
            case '+': cout<<fixed<<setprecision(6)<<"Wynik: "<<dodaj(a,b); break;
            case '-': cout<<fixed<<setprecision(6)<<"Wynik: "<<odejmij(a,b); break;
            case '*': cout<<fixed<<setprecision(6)<<"Wynik: "<<pomnoz(a,b); break;
            case '/': cout<<fixed<<setprecision(6)<<"Wynik: "<<podziel(a,b); break;
            default: cout<<"Nieprawidłowe działanie "; break;
            
        }
        }
    
	return 0;
    }
