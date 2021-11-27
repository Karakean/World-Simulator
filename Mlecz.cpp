#include "Mlecz.h"
Mlecz::Mlecz(int polX, int polY, Swiat* s) : Roslina(polX, polY, s) {
	this->ID = 'M';
	this->sila = 0;
}
Mlecz::Mlecz(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Roslina(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'M';
}
void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		int losowa = rand() % 100 + 1;
		if (losowa <= SZANSA_NA_ROZPRZESTRZENIANIE) {
			this->rozprzestrzenianie();
		}
	}
}
void Mlecz::rysowanie() {
	printf(" M ");
}