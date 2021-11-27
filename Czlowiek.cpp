#include "Czlowiek.h"
Czlowiek::Czlowiek(int polX, int polY, Swiat* s) : Zwierze(polX, polY, s){
	this->ID = 'C';
	this->sila = 5;
	this->inicjatywa = 4;
	this->wlaczonaUmiejetnosc = 0;
	this->oczekiwanie = 0;
	this->dzialanie = 0;
}
Czlowiek::Czlowiek(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, bool um, int ocz, Swiat* s)
	: Zwierze(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'C';
	this->wlaczonaUmiejetnosc = um;
	this->oczekiwanie = ocz;
	this->dzialanie = 0;
}
void Czlowiek::ustawDzialanie(int code) {
	this->dzialanie = code;
}
bool Czlowiek::czyWlaczonaUmiejetnosc() const {
	return wlaczonaUmiejetnosc;
}
int Czlowiek::getOczekiwanie() const {
	return oczekiwanie;
}
bool Czlowiek::czyUciekl() const {
	if (this->wlaczonaUmiejetnosc)
		return 1;
	else
		return 0;
}
void Czlowiek::akcja() {
	this->poprzedniePolozenieX = polozenieX;
	this->poprzedniePolozenieY = polozenieY;
	switch (this->dzialanie)
	{
	case GORA:
		if (polozenieY > 0)
			polozenieY--;
		else 
			printf("Dotarles do miejsca, gdzie diabel mowi dobranoc. Zawroc.\n");
		break;
	case DOL:
		if (polozenieY < swiat->getWysokosc() - 1)
			polozenieY++;
		else 
			printf("Dotarles do miejsca, gdzie diabel mowi dobranoc. Zawroc.\n");
		break;
	case LEWO:
		if (polozenieX > 0)
			polozenieX--;
		else 
			printf("Dotarles do miejsca, gdzie diabel mowi dobranoc. Zawroc.\n");
		break;
	case PRAWO:
		if (polozenieX < swiat->getSzerokosc() - 1)
			polozenieX++;
		else 
			printf("Dotarles do miejsca, gdzie diabel mowi dobranoc. Zawroc.\n");
		break;
	case UMIEJETNOSC_SPECJALNA:
		if ((!this->wlaczonaUmiejetnosc) && (this->oczekiwanie == 0)) {
			this->wlaczonaUmiejetnosc = 1;
			this->oczekiwanie = 5;
			printf("Wlaczono umiejetnosc specjalna-niesmiertelnosc.\n");
			return;
		}
		else if ((this->wlaczonaUmiejetnosc) && (this->oczekiwanie >= 0))
			printf("Tura przepadla. Umiejetnosc specjalna jest juz wlaczona. Dziala jeszcze przez %d tur.\n", this->oczekiwanie - 1);
		else
			printf("Tura przepadla. Umiejetnosc specjalna jeszcze sie nie odnowila. Pozostalo tur: %d.\n", this->oczekiwanie - 1);
		break;
	default:
		break;
	}
	if (this->oczekiwanie > 0)
		this->oczekiwanie--;
	if ((this->wlaczonaUmiejetnosc) && (this->oczekiwanie == 0)) {
		this->wlaczonaUmiejetnosc = 0;
		this->oczekiwanie = 5;
	}
}
void Czlowiek::kolizja(Organizm* atakujacy) {
 
	atakujacy->cofniecie();
	bool czyPrzesunac;
	if (swiat->porownajSile(atakujacy, this)){
		if (this->wlaczonaUmiejetnosc) {
			int koordynaty[2];
			bool rezultat = this->swiat->szukajMiejsca(this, koordynaty, 0);
			if (rezultat) {
				this->przesun(koordynaty[0], koordynaty[1]);
				atakujacy->przesun(this->getPoprzedniePolozenieX(), this->getPoprzedniePolozenieY());
			}
			printf("Czlowiek uniknal walki z silniejszym przeciwnikiem dzieki swojej umiejetnosci specjalnej.\n");
		}
		else {
		//walka, wygrywa atakujacy
		czyPrzesunac = 1;
		walka(atakujacy, this, czyPrzesunac);
		}
	}
	else if (atakujacy->czyUciekl()) {
		atakujacy->wypiszOrganizm(atakujacy->getID());
		printf(" uciekl(a) przed walka.\n");
	}
	else {
		//walka, wygrywa czlowiek
		czyPrzesunac = 0;
		walka(this, atakujacy, czyPrzesunac);
	}
}
void Czlowiek::rysowanie() {
	printf(" C ");
}