#include "wielomian.h"
#include <stdlib.h>

Wielomian::Wielomian(const char* napis) {
    Analizuj(napis);
}
char* BezSpacji(char* napis) {
    int i = 1;
    char* p = napis;
    while (*p) 
        if (*p++ != ' ') i++;
    char* ret = new char[i];
    i = 0;
    while (napis) {
        if (*napis != ' ')
            ret[i++] = *napis;
        napis++;
    }
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
void Wielomian::Inicjuj(int st) {
    stopien = st;
    delete[] wsp;
    wsp = new double[st + 1];
    for (int i = 0; i <= st; i++)
        wsp[i] = 0;
}
char* AnalizujJednomian(char* napis) {
    double wspolczynnik;
    bool znak = true;
    if (*napis == '-') {

    }
    if (*napis == 'x')
        wspolczynnik = 1;
    else
        wspolczynnik = strtod(napis, &napis);

}
void Wielomian::Analizuj(const char* napis) {
    char* bezspacji = BezSpacji((char*)napis);
    int stopien = Stopien(napis);
    Inicjuj(stopien);
    while (*bezspacji)
        bezspacji = AnalizujJednomian(bezspacji);
    delete[] bezspacji;
}