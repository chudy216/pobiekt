#include <iostream>
#include "wielomian.h"

int main()
{
    wielomian w1("2.5x^2-3.7");
    w1.Pokaz();
    wielomian w2("-x^3+17.5x");
    w2.Pokaz();
    wielomian w3 = w1 + w2;
    w3.Pokaz();
}
