#pragma once
#include "Zwierze.h"
class Czlowiek :public Zwierze {
	int dzialanie;
	bool wlaczonaUmiejetnosc;
	int oczekiwanie;
public:
	Czlowiek(int polX, int polY, Swiat* s);
	Czlowiek(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, bool um, int ocz, Swiat* s);
	int getOczekiwanie() const;
	bool czyWlaczonaUmiejetnosc() const;
	bool czyUciekl() const override;
	void ustawDzialanie(int code);
	void akcja() override;
	void kolizja(Organizm* o) override;
	void rysowanie() override;
};