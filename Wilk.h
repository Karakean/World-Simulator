#pragma once
#include "Zwierze.h"
class Wilk :public Zwierze {
public:
	Wilk(int polX, int polY, Swiat* s);
	Wilk(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	void rysowanie() override;
};