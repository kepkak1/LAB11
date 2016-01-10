#include "stdafx.h"
#include <vector>
#include <cstdarg>
#include <iostream>

using namespace std;

class wektor
{
private:
	vector <double> w;
	unsigned int wymiar;

public:
	wektor();
	wektor(unsigned int, ...);
	wektor(int);
	wektor(char* nr);

	void wyswietl_wektor();
	unsigned int zwroc_wymiar();

	void dodaj(wektor &, wektor &, wektor &);
	void odejmij(wektor &, wektor &, wektor &);
	void pomnoz(wektor &, wektor &, wektor &);
	double dlugosc_wektora();
	double dlugosc_wektora(wektor &);
	double skalar(wektor & w1, wektor & w2);
	double kat(wektor &, wektor &);

	~wektor();
};

