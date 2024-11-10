#include <iostream>
#include <string>

// Funkcja zmieniająca wszystkie litery na małe
std::string zamienNaMaleLitery(const std::string& tekst) {
    std::string wynik;
    for (size_t i = 0; i < tekst.size(); ++i) {
        unsigned char ch = tekst[i];
        // Spacja
        if (ch == 32) {
            wynik += ch;
        }
        // Wielkie litery angielskiego alfabetu
        else if (ch >= 65 && ch <= 90) {
            wynik += static_cast<unsigned char>(ch + 32);
        }
        // Wielkie litery polskiego alfabetu (UTF-8)
        else if (ch == 0xC4 && i + 1 < tekst.size() && tekst[i + 1] >= 0x84 && tekst[i + 1] <= 0xB9) {
            wynik += static_cast<unsigned char>(ch);
            wynik += static_cast<unsigned char>(tekst[++i] + 32);
        }
        else if (ch == 0xC5 && i + 1 < tekst.size() && tekst[i + 1] >= 0x81 && tekst[i + 1] <= 0xBA) {
            wynik += static_cast<unsigned char>(ch);
            wynik += static_cast<unsigned char>(tekst[++i] + 32);
        }
        else {
            wynik += ch;
        }
    }
    return wynik;
}

// Funkcja zmieniająca wszystkie litery na duże
std::string zamienNaDuzeLitery(const std::string& tekst) {
    std::string wynik;
    for (size_t i = 0; i < tekst.size(); ++i) {
        unsigned char ch = tekst[i];
        // Spacja
        if (ch == 32) {
            wynik += ch;
        }
        // Małe litery angielskiego alfabetu
        else if (ch >= 97 && ch <= 122) {
            wynik += static_cast<unsigned char>(ch - 32);
        }
        // Małe litery polskiego alfabetu (UTF-8)
        else if (ch == 0xC4 && i + 1 < tekst.size() && tekst[i + 1] >= 0x85 && tekst[i + 1] <= 0xBC) {
            wynik += static_cast<unsigned char>(ch);
            wynik += static_cast<unsigned char>(tekst[++i] - 32);
        }
        else if (ch == 0xC5 && i + 1 < tekst.size() && tekst[i + 1] >= 0x82 && tekst[i + 1] <= 0xBB) {
            wynik += static_cast<unsigned char>(ch);
            wynik += static_cast<unsigned char>(tekst[++i] - 32);
        }
        else {
            wynik += ch;
        }
    }
    return wynik;
}

int main() {
    // Pobranie tekstu od użytkownika
    std::string tekst;
    std::cout << "Wprowadź tekst: ";
    std::getline(std::cin, tekst);

    // Zamiana na małe litery
    std::string maleLitery = zamienNaMaleLitery(tekst);
    std::cout << "Tekst z małymi literami: " << maleLitery << std::endl;

    // Zamiana na duże litery
    std::string duzeLitery = zamienNaDuzeLitery(tekst);
    std::cout << "Tekst z dużymi literami: " << duzeLitery << std::endl;

    return 0;
}
