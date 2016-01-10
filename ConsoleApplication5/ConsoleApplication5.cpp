// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "wektor.h"
using namespace std;

int main()
{

	wektor w1("1"), w2("2");

	if (w1.zwroc_wymiar() != w2.zwroc_wymiar()) cout << "BLAD! Wektory musza miec taki sam wymiar...\n";
	else
	{
		wektor w3(w1.zwroc_wymiar());
		w3.dodaj(w1, w2, w3);
		cout << "\nWynik dodawania: ";
		w3.wyswietl_wektor();

		w3.odejmij(w1, w2, w3);
		cout << "\nWynik odejmowania:";
		w3.wyswietl_wektor();

		w3.pomnoz(w1, w2, w3);
		cout << "\nWynik mnozenia: ";
		w3.wyswietl_wektor();

		cout << "\nKat pomiedzy wektorami: ";
		cout << w3.kat(w1, w2) << endl;
	}
	system("PAUSE");
	return 0;
}

