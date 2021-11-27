#pragma once
#include "Organizm.h"
#include "Swiat.h"
class Zwierze :public Organizm {
public:
	Zwierze(int polX, int polY, Swiat* s);
	Zwierze(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void akcja() override;
	void kolizja(Organizm* o) override;
	void rozmnazanie(Organizm* o);
	void walka(Organizm* o1, Organizm* o2, bool czyPrzesunac);
	virtual void rysowanie() = 0;
};
