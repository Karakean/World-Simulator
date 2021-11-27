#pragma once
#include "Zwierze.h"
class Zolw :public Zwierze {
public:
	Zolw(int polX, int polY, Swiat* s);
	Zolw(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
};
