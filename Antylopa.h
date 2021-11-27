#pragma once
#include "Zwierze.h"
class Antylopa :public Zwierze {
public:
	Antylopa(int polX, int polY, Swiat* s);
	Antylopa(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	bool czyUciekl() const override;
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	void rysowanie() override;
};
