#include "wielomian.h"
#include <stdlib.h>
#include <iostream>

wielomian::wielomian(const char* napis) {
    wsp = 0;
    Analizuj(napis);
}
char* BezSpacji(const char* napis) {
    int i = 1;
    const char* p = napis;
    while (*p) 
        if (*p++ != ' ') i++;
    char* ret = new char[i];
    i = 0;
    while (*napis) {
        if (*napis != ' ')
            ret[i++] = *napis;
        napis++;
    }
    ret[i] = 0;
    return ret;
}
int Stopien(const char* w) {
    int akt = 0, max = 0;
    while (*w) {
        if (*w++ == 'x') {
            akt = 1;
            if (*w == '^') {
                char* p;
                akt = strtol(++w,&p,10);
                w = p;
            }
            if (akt > max) {
                max = akt;
            }
        }
    }
    return max;
}
void wielomian::Inicjuj(int st) {
    stopien = st;
    delete[] wsp;
    wsp = new double[st + 1];
    for (int i = 0; i <= st; i++)
        wsp[i] = 0;
}
const char* wielomian::AnalizujJednomian(const char* napis) {
    double wspolczynnik;
    int znak = 1;
    int wykladnik = 0;
    char* koniec{};
    if (*napis == '+')
        napis++;
    if (*napis == '-')
        znak = -1;
    if (*napis == 'x')
        wspolczynnik = 1;
    else {
        wspolczynnik = strtod(napis, &koniec);
        napis = koniec;
    }
    std::cout << *napis;
    if (*napis == 'x') {
        int akt = 1;
        if (*napis == '^') {
            akt = strtol(++napis, &koniec, 10);
            napis = koniec;
        }
    }
    wsp[wykladnik] += znak*wspolczynnik;
    return napis;

}
void wielomian::Analizuj(const char* napis) {
    const char* bezspacji = BezSpacji(napis);
    napis = bezspacji;
    int stopien = Stopien(napis);
    int i = 0;
    Inicjuj(stopien);
    while (*napis)
        napis = AnalizujJednomian(napis);
    delete[] bezspacji;
}

void wielomian::Pokaz() {
    for (int i = stopien; i >= 0; i--) {
        if (i > 1) {
            if(wsp[i]!='1')
                std::cout << std::showpos << wsp[i];
            std::cout << 'x';
            if (i > 2)
                std::cout << '^' << i;
        }
        else
            std::cout << std::showpos << wsp[i];
    }
}
wielomian& operator+=(const wielomian&) {

}
wielomian operator+(const wielomian& w1, const wielomian& w2) {

}