#pragma once
#include "Zwierze.h"
class Owca :public Zwierze {
public:
	Owca(int polX, int polY, Swiat* s);
	Owca(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void rysowanie() override;
};
