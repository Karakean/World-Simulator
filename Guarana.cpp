#include "Guarana.h"
Guarana::Guarana(int polX, int polY, Swiat* s) : Roslina(polX, polY, s) {
	this->ID = 'G';
	this->sila = 0;
}
Guarana::Guarana(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Roslina(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'G';
}
void Guarana::kolizja(Organizm* jedzacy) {
	jedzacy->cofniecie();
	zjedzenie(jedzacy, this);
	jedzacy->setSila(jedzacy->getSila() + 3);
}
void Guarana::rysowanie() {
	printf(" G ");
}