#include <iostream>
using namespace std;

string toLowerCase(string text) {
    string newText = "";
    for (int i = 0; i < text.length(); i++) {
        int num = static_cast<int>(text[i]);
        if (num == 32) {
            newText += " ";
        } else if (num >= 65 && num <= 90) {
            char rep_num = static_cast<char>(num + 32);
            newText += rep_num;
        } else if (num >= 97 && num <= 122) {
            char rep_num = static_cast<char>(num);
            newText += rep_num;
        } else {
            switch (text[i]) {
                case 'Ą': newText += 'ą'; break;
                case 'Ę': newText += 'ę'; break;
                case 'Ć': newText += 'ć'; break;
                case 'Ż': newText += 'ż'; break;
                case 'Ź': newText += 'ź'; break;
                case 'Ś': newText += 'ś'; break;
                case 'Ó': newText += 'ó'; break;
                case 'Ł': newText += 'ł'; break;
                case 'Ń': newText += 'ń'; break;
                default: newText += text[i]; break;
            }
        }
    }
    return newText;
}

string toUpperCase(string text) {
    string newText = "";
    for (int i = 0; i < text.length(); i++) {
        int num = static_cast<int>(text[i]);
        if (num == 32) {
            newText += " ";
        } else if (num >= 65 && num <= 90) {
            char rep_num = static_cast<char>(num);
            newText += rep_num;
        } else if (num >= 97 && num <= 122) {
            char rep_num = static_cast<char>(num - 32);
            newText += rep_num;
        } else {
            switch (text[i]) {
                case 'ą': newText += 'Ą'; break;
                case 'ę': newText += 'Ę'; break;
                case 'ć': newText += 'Ć'; break;
                case 'ż': newText += 'Ż'; break;
                case 'ź': newText += 'Ź'; break;
                case 'ś': newText += 'Ś'; break;
                case 'ó': newText += 'Ó'; break;
                case 'ł': newText += 'Ł'; break;
                case 'ń': newText += 'Ń'; break;
                default: newText += text[i]; break;
            }
        }
    }
    return newText;
}

string capitalize(string text) {
    int first = static_cast<int>(text[0]);
    string newText = "";
    if (first != 32) {
        if (first >= 65 && first <= 90) {
            char rep_num = static_cast<char>(first);
            newText += rep_num;
        } else if (first >= 97 && first <= 122) {
            char rep_num = static_cast<char>(first - 32);
            newText += rep_num;
        } else {
            switch (text[0]) {
                case 'ą': newText += 'Ą'; break;
                case 'ę': newText += 'Ę'; break;
                case 'ć': newText += 'Ć'; break;
                case 'ż': newText += 'Ż'; break;
                case 'ź': newText += 'Ź'; break;
                case 'ś': newText += 'Ś'; break;
                case 'ó': newText += 'Ó'; break;
                case 'ł': newText += 'Ł'; break;
                case 'ń': newText += 'Ń'; break;
                default: newText += text[0]; break;
            }
        }
    }
    for (int i = 1; i < text.length(); i++) {
        int num = static_cast<int>(text[i]);
        int num_before = static_cast<int>(text[i - 1]);
        if (num_before == 32 && num != 32) {
            if (num >= 65 && num <= 90) {
                char rep_num = static_cast<char>(num);
                newText += rep_num;
            } else if (num >= 97 && num <= 122) {
                char rep_num = static_cast<char>(num - 32);
                newText += rep_num;
            } else {
                switch (text[i]) {
                    case 'ą': newText += 'Ą'; break;
                    case 'ę': newText += 'Ę'; break;
                    case 'ć': newText += 'Ć'; break;
                    case 'ż': newText += 'Ż'; break;
                    case 'ź': newText += 'Ź'; break;
                    case 'ś': newText += 'Ś'; break;
                    case 'ó': newText += 'Ó'; break;
                    case 'ł': newText += 'Ł'; break;
                    case 'ń': newText += 'Ń'; break;
                    default: newText += text[i]; break;
                }
            }
        } else {
            if (num == 32) {
                newText += " ";
            } else if (num >= 65 && num <= 90) {
                char rep_num = static_cast<char>(num);
                newText += rep_num;
            } else if (num >= 97 && num <= 122) {
                char rep_num = static_cast<char>(num);
                newText += rep_num;
            } else {
                string one_char = "";
                one_char += text[i]
                switch (one_char) {
                    case "Ą": newText += 'ą'; break;
                    case "Ę": newText += 'ę'; break;
                    case "Ć": newText += 'ć'; break;
                    case "Ż": newText += 'ż'; break;
                    case "Ź": newText += 'ź'; break;
                    case "Ś": newText += 'ś'; break;
                    case "Ó": newText += 'ó'; break;
                    case "Ł": newText += 'ł'; break;
                    case "Ń": newText += 'ń'; break;
                    default: newText += text[i]; break;
                }
            }
        }
    }
    return newText;
}

int main() {
    string text;
    getline(cin, text);
    cout << "Tekst: " << text << endl;
    int wybor;
    cout << "Konwersja: " << endl;
    cout << "1. małe" << endl;
    cout << "2. WIELKIE" << endl;
    cout << "3. Tytułowe" << endl;
    cin >> wybor;
    cout << "Wybór: " << wybor << endl;
    switch (wybor) {
        case 1:
            cout << toLowerCase(text) << endl;
            break;
        case 2:
            cout << toUpperCase(text) << endl;
            break;
        case 3:
            cout << capitalize(text) << endl;
            break;
        default:
            break;
    }
    return 0;
}
