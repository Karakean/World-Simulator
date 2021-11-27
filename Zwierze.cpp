#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
Zwierze::Zwierze(int polX, int polY, Swiat* s) : Organizm(polX, polY, s){}
Zwierze::Zwierze(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s) 
	: Organizm(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s){}
void Zwierze::akcja() {
	this->poprzedniePolozenieX = polozenieX;
	this->poprzedniePolozenieY = polozenieY;
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
void Zwierze::rozmnazanie(Organizm* kolidujacy) {
	if ((this->wiek >= 3) && (kolidujacy->getWiek() >= 3)) {
		int koordynaty[2];
		bool rezultat = swiat->szukajMiejsca(this, koordynaty, 0);
		if (rezultat) {
			Organizm* o;
			switch (this->ID)
			{
			case 'O':
				o = new Owca(koordynaty[0], koordynaty[1], swiat);
				break;
			case 'W':
				o = new Wilk(koordynaty[0], koordynaty[1], swiat);
				break;
			case 'L':
				o = new Lis(koordynaty[0], koordynaty[1], swiat);
				break;
			case 'Z':
				o = new Zolw(koordynaty[0], koordynaty[1], swiat);
				break;
			case 'A':
				o = new Antylopa(koordynaty[0], koordynaty[1], swiat);
				break;
			}
			this->wypiszOrganizm(this->getID());
			printf(" sie rozmnozyl(a).\n");
		}
		//else printf("Nieudana proba rozmnozenia, brak miejsca.\n");
	}
	//else printf("Nieudana proba rozmnozenia, przynajmniej jedno ze zwierzat jest zbyt mlode.\n");
}
void Zwierze::walka(Organizm* wygrany, Organizm* przegrany, bool czyPrzesunac) {
	int x = przegrany->getPolozenieX();
	int y = przegrany->getPolozenieY();
	przegrany->zabij();
	swiat->usunZMapy(x, y);
	if (czyPrzesunac) {
		wygrany->przesun(x, y);
	}
	wygrany->wypiszOrganizm(wygrany->getID());
	printf(" zabija ");
	przegrany->wypiszOrganizm(przegrany->getID());
	printf("\n");
}
void Zwierze::kolizja(Organizm* napierajacy) {
	napierajacy->cofniecie();
	bool czyPrzesunac;
	if (this->ID == napierajacy->getID()) {
		this->rozmnazanie(napierajacy);
	}
	else if (swiat->porownajSile(napierajacy, this)) {
		//walka, wygrywa napierajacy
		czyPrzesunac = 1;
		walka(napierajacy, this, czyPrzesunac);
	}
	else if (!swiat->porownajSile(napierajacy, this)) {
		if (napierajacy->czyUciekl()) {
			napierajacy->wypiszOrganizm(napierajacy->getID());
			printf(" uciekl(a) przed walka.\n");
		}
		else {
			//walka, wygrywa napierany
			czyPrzesunac = 0;
			walka(this, napierajacy, czyPrzesunac);
		}
	}
}