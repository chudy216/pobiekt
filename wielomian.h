#pragma once
class wielomian {
	double* wsp;
	int stopien;
	void Inicjuj(int st);
	const char* AnalizujJednomian(const char* napis);
	void Analizuj(const char* napis);
public:
	wielomian(const char* napis);
	wielomian(const wielomian& w);
	~wielomian() { delete[] wsp; }
	void Pokaz();
	wielomian& operator+=(const wielomian&);
};

wielomian operator+(const wielomian& w1, const wielomian& w2);