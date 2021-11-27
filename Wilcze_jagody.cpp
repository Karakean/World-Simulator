#include "Wilcze_jagody.h"
Wilcze_jagody::Wilcze_jagody(int polX, int polY, Swiat* s) : Roslina(polX, polY, s) {
	this->ID = 'J';
	this->sila = 99;
}
Wilcze_jagody::Wilcze_jagody(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Roslina(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'J';
}
void Wilcze_jagody::kolizja(Organizm* jedzacy) {
	jedzacy->cofniecie();
	zjedzenie(jedzacy, this);
	jedzacy->wypiszOrganizm(jedzacy->getID());
	printf(" umarl(a) po zjedzeniu wilczych jagod.\n");
	jedzacy->zabij();
	swiat->usunZMapy(jedzacy->getPolozenieX(), jedzacy->getPolozenieY());
}
void Wilcze_jagody::rysowanie() {
	printf(" J ");
}