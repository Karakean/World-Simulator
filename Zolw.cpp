#include "Zolw.h"
Zolw::Zolw(int polX, int polY, Swiat* s) : Zwierze(polX, polY, s) {
	this->ID = 'Z';
	this->sila = 2;
	this->inicjatywa = 1;
}
Zolw::Zolw(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Zwierze(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'Z';
}
void Zolw::akcja() {
	this->poprzedniePolozenieX = polozenieX;
	this->poprzedniePolozenieY = polozenieY;
	int czyRuszyc = rand() % 4;
	if (czyRuszyc == 3) {
		bool tmp = 0;
		while (!tmp) {
			int kierunek = rand() % 4;
			switch (kierunek) {
			case 0:
				if (polozenieY > 0) {
					polozenieY--;
					tmp++;
				}
				break;
			case 1:
				if (polozenieY < swiat->getWysokosc() - 1) {
					polozenieY++;
					tmp++;
				}
				break;
			case 2:
				if (polozenieX > 0) {
					polozenieX--;
					tmp++;
				}
				break;
			case 3:
				if (polozenieX < swiat->getSzerokosc() - 1) {
					polozenieX++;
					tmp++;
				}
				break;
			}
		}
	}
}
void Zolw::kolizja(Organizm* napierajacy) {
	napierajacy->cofniecie();
	bool czyPrzesunac;
	if (this->ID == napierajacy->getID()) {
		this->rozmnazanie(napierajacy);
	}
	else if ((swiat->porownajSile(napierajacy, this)) && (napierajacy->getSila() >= 5)) {
		//walka, wygrywa napierajacy
		czyPrzesunac = 1;
		walka(napierajacy, this, czyPrzesunac);
	}
	else if ((swiat->porownajSile(napierajacy, this)) && (napierajacy->getSila() < 5)) {
		//atak odparty
		printf("Zolw odparl atak napastnika.\n");
	}
	else if (!swiat->porownajSile(napierajacy, this)) {
		if (napierajacy->czyUciekl()) {
			napierajacy->wypiszOrganizm(napierajacy->getID());
			printf(" uciekl przed walka.\n");
		}
		else {
			//walka, wygrywa napierany
			czyPrzesunac = 0;
			walka(this, napierajacy, czyPrzesunac);
		}
	}
}
void Zolw::rysowanie() {
	printf(" Z ");
}