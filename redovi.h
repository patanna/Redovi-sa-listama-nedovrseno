class Red {
public:
	Red() { prvi = nullptr; }; //podrazumevani
	Red(int b) { prvi = new clan(b); };
	Red(const Red& prvii); //kopirajuci konstruktor
	Red(Red&& prvii) { prvi = prvii.prvi; prvii.prvi = nullptr; } //ne mora al ajde i premestajuci (kraci je pa neka ga ovde ceo)
	~Red() { brisi(); };
	void ispis() const;
	void popuni(int b);
	void uzmi();
	int duzina ();  //necu ovo pozivati u switchu, poenta iskoristiti u friend function
 	void brisi();
	void kopiraj();
private:
	struct clan {
		int broj;
		clan* sled;
		clan(int b, clan* sl = nullptr)
		{
			broj = b; sled = sl;
		}

	};
	clan* prvi;
};
class Niz {
public:
	Niz() { niz = nullptr; int n = 0; }; //podrazumevani
	Niz(int duz) { niz = new int[n = duz]; };  //kopirajuci
	~Niz() { delete[] niz; };
	void napraviniz(int n);
private:
	int *niz; int n;

};
