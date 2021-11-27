#pragma once
#include "Roslina.h"
class Trawa :public Roslina {
public:
	Trawa(int polX, int polY, Swiat* s);
	Trawa(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void rysowanie() override;
};
