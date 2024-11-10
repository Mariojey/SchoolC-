#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>

std::wstring zmienNaWstring(const std::string& tekst) {
    try {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(tekst);
    } catch (const std::range_error& e) {
        std::cerr << "Błąd konwersji: " << e.what() << std::endl;
        return L"";
    }
}

std::string zmienNaMaleLitery(const std::string& tekst) {
    std::wstring wtekst = zmienNaWstring(tekst);
    for (auto& wc : wtekst) {
        if ((wc >= L'A' && wc <= L'Z') || (wc >= L'À' && wc <= L'Ý')) {
            wc = wc + 32;
        } else {
            switch (wc) {
                case L'Ą': wc = L'ą'; break;
                case L'Ę': wc = L'ę'; break;
                case L'Ć': wc = L'ć'; break;
                case L'Ż': wc = L'ż'; break;
                case L'Ź': wc = L'ź'; break;
                case L'Ś': wc = L'ś'; break;
                case L'Ó': wc = L'ó'; break;
                case L'Ł': wc = L'ł'; break;
                case L'Ń': wc = L'ń'; break;
                default: break;
            }
        }
    }
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wtekst);
}

std::string zmienNaDuzeLitery(const std::string& tekst) {
    std::wstring wtekst = zmienNaWstring(tekst);
    for (auto& wc : wtekst) {
        if ((wc >= L'a' && wc <= L'z') || (wc >= L'à' && wc <= L'ý')) {
            wc = wc - 32;
        } else {
            switch (wc) {
                case L'ą': wc = L'Ą'; break;
                case L'ę': wc = L'Ę'; break;
                case L'ć': wc = L'Ć'; break;
                case L'ż': wc = L'Ż'; break;
                case L'ź': wc = L'Ź'; break;
                case L'ś': wc = L'Ś'; break;
                case L'ó': wc = L'Ó'; break;
                case L'ł': wc = L'Ł'; break;
                case L'ń': wc = L'Ń'; break;
                default: break;
            }
        }
    }
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wtekst);
}

std::string zmienPierwszaLitereNaDuze(const std::string& tekst) {
    std::wstring wtekst = zmienNaWstring(tekst);
    bool nowyWyraz = true;
    for (auto& wc : wtekst) {
        if (wc == L' ' || wc == L'\t' || wc == L'\n') {
            nowyWyraz = true;
        } else if (nowyWyraz) {
            if ((wc >= L'a' && wc <= L'z') || (wc >= L'à' && wc <= L'ý')) {
                wc = wc - 32;
            } else {
                switch (wc) {
                    case L'ą': wc = L'Ą'; break;
                    case L'ę': wc = L'Ę'; break;
                    case L'ć': wc = L'Ć'; break;
                    case L'ż': wc = L'Ż'; break;
                    case L'ź': wc = L'Ź'; break;
                    case L'ś': wc = L'Ś'; break;
                    case L'ó': wc = L'Ó'; break;
                    case L'ł': wc = L'Ł'; break;
                    case L'ń': wc = L'Ń'; break;
                    default: break;
                }
            }
            nowyWyraz = false;
        } else {
            nowyWyraz = false;
        }
    }
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wtekst);
}

int main() {
    std::string tekst;
    std::cout << "Wprowadź tekst: ";
    std::getline(std::cin, tekst);

    int wybor;
    std::cout << "Wybierz opcję (1 - małe litery, 2 - duże litery, 3 - pierwsza litera duża): ";
    std::cin >> wybor;

    std::string wynik;

    switch (wybor) {
        case 1:
            wynik = zmienNaMaleLitery(tekst);
            break;
        case 2:
            wynik = zmienNaDuzeLitery(tekst);
            break;
        case 3:
            wynik = zmienPierwszaLitereNaDuze(tekst);
            break;
        default:
            std::cout << "Nieprawidłowy wybór." << std::endl;
            return 1;
    }

    std::cout << "Wynik: " << wynik << std::endl;

    return 0;
}
