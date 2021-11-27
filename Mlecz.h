#pragma once
#include "Roslina.h"
class Mlecz :public Roslina {
public:
	Mlecz(int polX, int polY, Swiat* s);
	Mlecz(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void akcja() override;
	void rysowanie() override;
};
