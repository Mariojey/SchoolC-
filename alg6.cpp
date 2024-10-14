//MANDAT
#include <iostream>

using namespace std;

int main(){
    int value;
    cin>>value;
    cout<<"Prędkość: "<<value<<endl;
    // switch (value > 0){    
    // case true:
    //     switch (value<=10)
    //     {
    //     case true:
    //         cout<<"Mandat wynosi 50 PLN"<<endl;
    //         break;
    //     case false:
    //         switch (value <= 20)
    //         {
    //         case true:
    //             cout<<"Mandat wynosi 100 PLN"<<endl;
    //             break;
    //         case false:
    //             switch (value < 30)
    //             {
    //             case true:
    //                 switch (value)
    //                 {
    //                 case 21:
    //                     cout<<"Mandat wynosi 110 PLN"<<endl;
    //                     break;
    //                 case 22:
    //                     cout<<"Mandat wynosi 120 PLN"<<endl;
    //                     break;
    //                 case 23:
    //                     cout<<"Mandat wynosi 140 PLN"<<endl;
    //                     break;
    //                 case 24:
    //                     cout<<"Mandat wynosi 150 PLN"<<endl;
    //                     break;
    //                 case 25:
    //                     cout<<"Mandat wynosi 150 PLN"<<endl;
    //                     break;
    //                 case 26:
    //                     cout<<"Mandat wynosi 145 PLN"<<endl;
    //                     break;
    //                 case 27:
    //                     cout<<"Mandat wynosi 140 PLN"<<endl;
    //                     break;
    //                 case 28:
    //                     cout<<"Mandat wynosi 150 PLN"<<endl;
    //                     break;
    //                 case 29:
    //                     cout<<"Mandat wynosi 140 PLN"<<endl;
    //                     break;
    //                 default:
    //                     break;
    //                 }
    //                 break;
    //             case false:
    //                 cout<<"Mandat wynosi 200 PLN"<<endl;
    //                 break;
    //             default:
    //                 break;
    //             }           
    //         default:
    //             break;
    //         }
    //     default:
    //         break;
    //     }
    //     break;
    // case false:
    //     cout<<"Prędkość nie może być ujemna"<<endl;
    // default:
    //     break;
    // }
    if (value >= 0)
    {
        switch (value)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            cout<<"Mandat wynosi 50 PLN"<<endl;
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            cout<<"Mandat wynosi 100 PLN"<<endl;
            break;
        case 21:
            cout<<"Mandat wynosi 110 PLN"<<endl;
            break;
        case 22:
            cout<<"Mandat wynosi 120 PLN"<<endl;
            break;
        case 23:
            cout<<"Mandat wynosi 140 PLN"<<endl;
            break;
        case 24:
            cout<<"Mandat wynosi 150 PLN"<<endl;
            break;
        case 25:
            cout<<"Mandat wynosi 150 PLN"<<endl;
            break;
        case 26:
            cout<<"Mandat wynosi 145 PLN"<<endl;
            break;
        case 27:
            cout<<"Mandat wynosi 140 PLN"<<endl;
            break;
        case 28:
            cout<<"Mandat wynosi 150 PLN"<<endl;
            break;
        case 29:
            cout<<"Mandat wynosi 140 PLN"<<endl;
            break;
        default:
        cout<<"Mandat wynosi 200 PLN"<<endl;
            break;
        }
    }else{
        cout<<"Prędkość nie może być ujemna"<<endl;
    }
    
    return 0;
}