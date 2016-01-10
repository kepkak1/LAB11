#include "stdafx.h"
#include "wektor.h"
#include "stdafx.h"
#include <vector>
#include <cstdarg>
#include <iostream>

using namespace std;

wektor::wektor()
{
}

wektor::wektor(char* nr)
{
	cout << "Wektor nr " << nr << "\nPodaj wymiar: ";
	cin >> wymiar;
	cout << "Podaj wspolrzedne wektora:\n";
	double temp;
	for (int i = 0; i < wymiar; i++)
	{
		cin >> temp;
		w.push_back(temp);
	}
}

wektor::wektor(int wymiar)
{
	this->wymiar = wymiar;
	for (int i = 0; i < wymiar; i++) w.push_back(0.0);

}

wektor::wektor(unsigned int wymiar, ...)
{
	this->wymiar = wymiar;
	va_list argument;
	va_start(argument, wymiar);

	for (int i = 0; i < wymiar; i++)
		w.push_back(va_arg(argument, double));

	va_end(argument);
}

void wektor::wyswietl_wektor()
{
	cout << "[ ";
	for (int i = 0; i < (this->w).size(); i++)
	{
		if (i == this->w.size() - 1)	cout << w[i] << " ]";
		else							cout << w[i] << "; ";
	}
}

unsigned int wektor::zwroc_wymiar()
{
	return this->w.size();
}

void wektor::dodaj(wektor & w1, wektor & w2, wektor & w3)
{
	w3.wymiar = w1.zwroc_wymiar();
	for (int i = 0; i < w3.wymiar; i++)
	{
		w3.w[i] = w1.w[i] + w2.w[i];
	}
};

void wektor::odejmij(wektor & w1, wektor & w2, wektor & w3)
{
	w3.wymiar = w1.zwroc_wymiar();
	for (int i = 0; i < w3.wymiar; i++)
	{
		w3.w[i] = w1.w[i] - w2.w[i];
	}
};

void wektor::pomnoz(wektor & w1, wektor & w2, wektor & w3)
{
	w3.wymiar = w1.zwroc_wymiar();
	for (int i = 0; i < w3.wymiar; i++)
	{
		w3.w[i] = w1.w[i] * w2.w[i];
	}
};

double wektor::skalar(wektor & w1, wektor & w2)
{
	double skalarny = 0;
	for (int i = 0; i < w1.wymiar; i++)
	{
		skalarny += w1.w[i] * w2.w[i];
	}
	return skalarny;
};

double wektor::dlugosc_wektora()
{
	double dlugosc = 0;
	for (int i = 0; i < this->wymiar; i++)
	{
		dlugosc += this->w[i] * this->w[i];
	}
	return sqrt(dlugosc);
};

double wektor::dlugosc_wektora(wektor & w1)
{
	double dlugosc = 0;
	for (int i = 0; i < this->wymiar; i++)
	{
		dlugosc += w1.w[i] * w1.w[i];
	}
	return sqrt(dlugosc);
};

double wektor::kat(wektor & w1, wektor & w2)
{
	if (w1.wymiar != w2.wymiar || w1.wymiar != 2) return -1;
	double l1 = dlugosc_wektora(w1);
	double l2 = dlugosc_wektora(w2);
	double kat = skalar(w1, w2);
	kat /= (l1*l2);
	return acos(kat) * 180 / 3.14159265359;
}

wektor::~wektor()
{
}