#pragma once
#include "Roslina.h"
class Barszcz_Sosnowskiego :public Roslina {
public:
	Barszcz_Sosnowskiego(int polX, int polY, Swiat* s);
	Barszcz_Sosnowskiego(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void akcja() override;
	void kolizja(Organizm* jedzacy) override;
	void rysowanie() override;
};