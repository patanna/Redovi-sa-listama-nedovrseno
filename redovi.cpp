#include "Redovi.h"
#include<iostream>
using namespace std;


Red::Red(const Red& prvii) //kopirajuci konstruktor
{
	prvi = nullptr;
	for (clan *tekuci = prvii.prvi, *posl = nullptr; tekuci; tekuci = tekuci->sled) {
		clan* novi = new clan(tekuci->broj);
		if (!prvi) prvi = novi; else posl->sled = novi;
		posl = novi;
	}
}

void Red::brisi()
{
	while (prvi) {
		clan* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}

void Red::kopiraj()
{
	for (clan* tek = prvi; tek; tek = tek->sled) {
		for (int i = 0; i < duzina(); i++)
			niz[i] = tek->broj;
	}
}

void Red::ispis() const
{
	if (prvi == nullptr) { cout << "Red je prazan" << endl; }
	for (clan* tekuci = prvi; tekuci; tekuci = tekuci->sled)
		cout << tekuci->broj << ' ';
}

void Red::popuni(int b)
{

	clan* novi = new clan(b);
	if (!prvi) prvi = novi;
	else {
		clan* tek = prvi;
		while (tek->sled) tek = tek->sled;
		tek->sled = novi;
	}
}

void Red::uzmi()
{
	clan* stari = prvi;
	cout << stari->broj;
	prvi = prvi->sled;
	delete stari;

}

int Red::duzina() 
{
	int duz = 0;
	for (clan* tek = prvi; tek; tek = tek->sled)
		duz++;
	return duz;
}




void Niz::napraviniz(int n)
{
	Red prviii;
	niz = new int[prviii.duzina()];
}
