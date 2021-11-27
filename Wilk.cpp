#include "Wilk.h"
Wilk::Wilk(int polX, int polY, Swiat* s) : Zwierze(polX, polY, s) {
	this->ID = 'W';
	this->sila = 9;
	this->inicjatywa = 5;
}
Wilk::Wilk(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Zwierze(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'W';
}
void Wilk::rysowanie() {
	printf(" W ");
}