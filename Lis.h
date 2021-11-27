#pragma once
#include "Zwierze.h"
class Lis :public Zwierze {
public:
	Lis(int polX, int polY, Swiat* s);
	Lis(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	bool potencjalnePole(Organizm* o1, Organizm* o2, int* sprawdzone,int i, int* niedozwolone);
	void akcja() override;
	void rysowanie() override;
};