#include "Barszcz_Sosnowskiego.h"
#include "Zwierze.h"
Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(int polX, int polY, Swiat* s) : Roslina(polX, polY, s) {
	this->ID = 'B';
	this->sila = 10;
}
Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Roslina(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'B';
}
void Barszcz_Sosnowskiego::akcja() {
	int losowa = rand() % 100 + 1;
	if (losowa <= SZANSA_NA_ROZPRZESTRZENIANIE) {
		this->rozprzestrzenianie();
	}
	int x = this->getPolozenieX();
	int y = this->getPolozenieY();
	Organizm* org[4] = { nullptr };
	if (x < swiat->getSzerokosc() - 1) {
		org[0] = swiat->getOrganizm(x + 1, y);
	}
	if (x > 0) {
		org[1] = swiat->getOrganizm(x - 1, y);
	}
	if (y < swiat->getWysokosc() - 1) {
		org[2] = swiat->getOrganizm(x, y + 1);
	}
	if (y > 0) {
		org[3] = swiat->getOrganizm(x, y - 1);
	}
	for (int i = 0; i < 4; i++) {
		bool czyZwierze;
		if ((dynamic_cast<Zwierze*>(org[i])) != nullptr)
			czyZwierze = true;
		else
			czyZwierze = false;
		if ((org[i] != nullptr)&&czyZwierze) {
			org[i]->zabij();
			swiat->usunZMapy(org[i]->getPolozenieX(), org[i]->getPolozenieY());
			org[i]->wypiszOrganizm(org[i]->getID());
			printf(" umarl(a) przez zblizenie sie do barszczu Sosnowskiego.\n");
		}
	}
}
void Barszcz_Sosnowskiego::kolizja(Organizm* jedzacy) {
	jedzacy->cofniecie();
	zjedzenie(jedzacy, this);
	jedzacy->wypiszOrganizm(jedzacy->getID());
	printf(" umarl(a) po zjedzeniu barszczu Sosnowskiego.\n");
	jedzacy->zabij();
	swiat->usunZMapy(jedzacy->getPolozenieX(), jedzacy->getPolozenieY());
}
void Barszcz_Sosnowskiego::rysowanie() {
	printf(" B ");
}