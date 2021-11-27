#pragma once
#include "Organizm.h"
#include "Swiat.h"
class Roslina :public Organizm {
public:
	Roslina(int polX, int polY, Swiat* s);
	Roslina(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void rozprzestrzenianie();
	virtual bool czyTrujaca() const;
	virtual void zjedzenie(Organizm* o1, Organizm* o2);
	virtual void akcja() override;
	virtual void kolizja(Organizm* o) override;
	virtual void rysowanie() = 0;
};