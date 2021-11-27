#pragma once
#include "Roslina.h"
class Wilcze_jagody :public Roslina {
public:
	Wilcze_jagody(int polX, int polY, Swiat* s);
	Wilcze_jagody(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void kolizja(Organizm* jedzacy) override;
	void rysowanie() override;
};