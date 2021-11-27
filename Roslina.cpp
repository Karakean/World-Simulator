#include "Roslina.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcze_jagody.h"
#include "Barszcz_Sosnowskiego.h"
Roslina::Roslina(int polX, int polY, Swiat* s) : Organizm(polX, polY, s){
	this->inicjatywa = 0;
}
Roslina::Roslina(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Organizm(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {}
bool Roslina::czyTrujaca() const {
	return 0;
}
void Roslina::rozprzestrzenianie() {
	int koordynaty[2];
	bool result = swiat->szukajMiejsca(this, koordynaty, 0);
	if (result) {
		Organizm* org;
		switch (this->getID())
		{
		case 'T':
			org = new Trawa(koordynaty[0], koordynaty[1], swiat);
			break;
		case 'M':
			org = new Mlecz(koordynaty[0], koordynaty[1], swiat);
			break;
		case 'G':
			org = new Guarana(koordynaty[0], koordynaty[1], swiat);
			break;
		case 'J':
			org = new Wilcze_jagody(koordynaty[0], koordynaty[1], swiat);
			break;
		case 'B':
			org = new Barszcz_Sosnowskiego(koordynaty[0], koordynaty[1], swiat);
			break;
		}
		this->wypiszOrganizm(this->getID());
		printf(" sie rozprzestrzenia.\n");
	}
}
void Roslina::zjedzenie(Organizm* jedzacy, Organizm* zjedzony) {
	int x = zjedzony->getPolozenieX();
	int y = zjedzony->getPolozenieY();
	zjedzony->zabij();
	swiat->usunZMapy(x, y);
	jedzacy->przesun(x, y);
	jedzacy->wypiszOrganizm(jedzacy->getID());
	printf(" zjadl(a) ");
	zjedzony->wypiszOrganizm(zjedzony->getID());
	printf("\n");
}
void Roslina::akcja() {
	int losowa = rand() % 100 + 1;
	if (losowa <= SZANSA_NA_ROZPRZESTRZENIANIE) {
		this->rozprzestrzenianie();
	}
}
void Roslina::kolizja(Organizm* napierajacy) {
	napierajacy->cofniecie();
	zjedzenie(napierajacy, this);
}