#include "Owca.h"
Owca::Owca(int polX, int polY, Swiat* s) : Zwierze(polX, polY, s){
	this->ID = 'O';
	this->inicjatywa = 4;
	this->sila = 4;
}
Owca::Owca(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Zwierze(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'O';
}
void Owca::rysowanie() {
	printf(" O ");
}