#include "Antylopa.h"
Antylopa::Antylopa(int polX, int polY, Swiat* s) : Zwierze(polX, polY, s) {
	this->ID = 'A';
	this->sila = 4;
	this->inicjatywa = 4;
}
Antylopa::Antylopa(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Zwierze(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'A';
}
bool Antylopa::czyUciekl() const {
	int losowanie = rand() % 2;
	if (losowanie == 1)
		return 1;
	else
		return 0;
}
void Antylopa::akcja() {
	this->poprzedniePolozenieX = polozenieX;
	this->poprzedniePolozenieY = polozenieY;
	bool tmp = 0;
	while (!tmp) {
		int kierunek = rand() % 4;
		switch (kierunek) {
		case 0:
			if (polozenieY > 1) {
				this->polozenieY -= 2;
				tmp++;
			}
			else if (polozenieY > 0) {
				this->polozenieY--;
				tmp++;
			}
			break;
		case 1:
			if (this->polozenieY < swiat->getWysokosc() - 2) {
				this->polozenieY += 2;
				tmp++;
			}
			else if (this->polozenieY < swiat->getWysokosc() - 1) {
				this->polozenieY++;
				tmp++;
			}
			break;
		case 2:
			if (this->polozenieX > 1) {
				this->polozenieX -= 2;
				tmp++;
			}
			else if (this->polozenieX > 0) {
				this->polozenieX--;
				tmp++;
			}
			break;
		case 3:
			if (this->polozenieX < swiat->getSzerokosc() - 2) {
				this->polozenieX += 2;
				tmp++;
			}
			else if (this->polozenieX < swiat->getSzerokosc() - 1) {
				this->polozenieX++;
				tmp++;
			}
			break;
		}
	}
}
void Antylopa::kolizja(Organizm* napierajacy) {
	napierajacy->cofniecie();
	bool czyPrzesunac;
	if (this->ID == napierajacy->getID()) {
		this->rozmnazanie(napierajacy);
		return;
	}
	int koordynaty[2];
	bool rezultat = swiat->szukajMiejsca(this, koordynaty, 0);
	if ((rezultat) && (this->czyUciekl())) {
		this->przesun(koordynaty[0], koordynaty[1]);
		napierajacy->przesun(this->getPoprzedniePolozenieX(), this->getPoprzedniePolozenieY());
		printf("Antylopa uniknela walki z przeciwnikiem.\n");
	}
	else if (swiat->porownajSile(napierajacy, this)) {
		//walka, wygrywa atakujacy
		czyPrzesunac = 1;
		walka(napierajacy, this, czyPrzesunac);
	}
	else {
		//walka, wygrywa antylopa
		czyPrzesunac = 0;
		walka(this, napierajacy, czyPrzesunac);
	}
}
void Antylopa::rysowanie() {
	printf(" A ");
}