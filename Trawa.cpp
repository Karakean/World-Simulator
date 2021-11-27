#include "Trawa.h"
Trawa::Trawa(int polX, int polY, Swiat* s) : Roslina(polX, polY, s){
	this->ID = 'T';
	this->sila = 0;
}
Trawa::Trawa(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Roslina(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'T';
}
void Trawa::rysowanie() {
	printf(" T ");
}