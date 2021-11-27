#pragma once
#include "Roslina.h"
class Guarana :public Roslina {
public:
	Guarana(int polX, int polY, Swiat* s);
	Guarana(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void kolizja(Organizm* jedzacy) override;
	void rysowanie() override;
};
