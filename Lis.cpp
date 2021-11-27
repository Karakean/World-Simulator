#include "Lis.h"
Lis::Lis(int polX, int polY, Swiat* s) : Zwierze(polX, polY, s) {
	this->ID = 'L';
	this->sila = 3;
	this->inicjatywa = 7;
}
Lis::Lis(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s)
	: Zwierze(polX, polY, poprzPolX, poprzPolY, sil, ini, w, s) {
	this->ID = 'L';
}
bool Lis::potencjalnePole(Organizm* lis, Organizm* potencjalnyPrzeciwnik, int* sprawdzone, int i, int* niedozwolone) {
	if ((potencjalnyPrzeciwnik != nullptr) && (swiat->porownajSile(lis, potencjalnyPrzeciwnik))) {
		lis->setPolozenieX(potencjalnyPrzeciwnik->getPolozenieX());
		lis->setPolozenieY(potencjalnyPrzeciwnik->getPolozenieY());
		return 1;
	}
	else if (sprawdzone[i] == 0) {
		sprawdzone[i] = 1;
		(*niedozwolone)++;
	}
	return 0;
}
void Lis::akcja() {
	this->poprzedniePolozenieX = this->polozenieX;
	this->poprzedniePolozenieY = this->polozenieY;
	int koordynaty[2];
	bool rezultat=swiat->szukajMiejsca(this, koordynaty, 1);
	if (rezultat) {
		this->setPolozenieX(koordynaty[0]);
		this->setPolozenieY(koordynaty[1]);
	}
	else {
		int x = this->getPolozenieX();
		int y = this->getPolozenieY();
		Organizm* org[4] = { nullptr };
		if (x < swiat->getSzerokosc() - 1) {
			org[0] = swiat->getOrganizm(x + 1, y);
		}
		if (x > 0) {
			org[1] = swiat->getOrganizm(x - 1, y);
		}
		if (y < swiat->getWysokosc() - 1) {
			org[2] = swiat->getOrganizm(x, y + 1);
		}
		if (y > 0) {
			org[3] = swiat->getOrganizm(x, y - 1);
		}
		int sprawdzone[4] = { 0 };
		int niedozwolone=0;
		while (1) {
			int tmp = rand() % 4;
			switch (tmp)
			{
			case 0:
				if (potencjalnePole(this, org[0], sprawdzone, 0, &niedozwolone))
					return;
				else
					break;
			case 1:
				if (potencjalnePole(this, org[1], sprawdzone, 1, &niedozwolone))
					return;
				else
					break;
			case 2:
				if (potencjalnePole(this, org[2], sprawdzone, 2, &niedozwolone))
					return;
				else
					break;
			case 3:
				if (potencjalnePole(this, org[3], sprawdzone, 3, &niedozwolone))
					return;
				else
					break;
			}
			if (niedozwolone == 4)
				return;
		}
	}
}
void Lis::rysowanie() {
	printf(" L ");
}