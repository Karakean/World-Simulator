#include "Organizm.h"
Organizm::Organizm(int polX, int polY, Swiat* s) {
	this->polozenieX = polX;
	this->polozenieY = polY;
	this->poprzedniePolozenieX = polX;
	this->poprzedniePolozenieY = polY;
	this->swiat = s;
	this->wiek = 0;
	this->zywy = 1;
	swiat->dodajOrganizm(this, polozenieX, polozenieY);
}
Organizm::Organizm(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w,Swiat* s) {
	this->polozenieX = polX;
	this->polozenieY = polY;
	this->poprzedniePolozenieX = poprzPolX;
	this->poprzedniePolozenieY = poprzPolY;
	this->sila = sil;
	this->inicjatywa = ini;
	this->wiek = w;
	this->swiat = s;
	this->zywy = 1;
	swiat->dodajOrganizm(this, polX, polY);
}
int Organizm::getPolozenieX() const {
	return polozenieX;
}
int Organizm::getPolozenieY() const {
	return polozenieY;
}
int Organizm::getPoprzedniePolozenieX() const {
	return poprzedniePolozenieX;
}
int Organizm::getPoprzedniePolozenieY() const {
	return poprzedniePolozenieY;
}
int Organizm::getSila() const {
	return sila;
}
int Organizm::getInicjatywa() const {
	return inicjatywa;
}
int Organizm::getWiek() const {
	return wiek;
}
char Organizm::getID() const {
	return ID;
}
bool Organizm::getZywy() const {
	return zywy;
}
bool Organizm::czyUciekl() const {
	return 0;
}
void Organizm::zabij() {
	this->zywy = 0;
}
void Organizm::przesun( int noweX, int noweY) {
	this->setPolozenieX(noweX);
	this->setPolozenieY(noweY);
	swiat->usunZMapy(this->poprzedniePolozenieX, this->poprzedniePolozenieY);
	swiat->dodajNaMape(this, this->polozenieX, this->polozenieY);
}
void Organizm::setPolozenieX(int x) {
	this->poprzedniePolozenieX = polozenieX;
	this->polozenieX = x;
}
void Organizm::setPolozenieY(int y) {
	this->poprzedniePolozenieY = polozenieY;
	this->polozenieY = y;
}
void Organizm::cofniecie() {
	this->polozenieX = poprzedniePolozenieX;
	this->polozenieY = poprzedniePolozenieY;
}
void Organizm::setWiek(int w) {
	this->wiek = w;
}
void Organizm::setSila(int s) {
	this->sila = s;
}
void Organizm::wypiszOrganizm(char identyfikator) {
	switch (identyfikator) {
	case 'A':
		printf("Antylopa");
		break;
	case 'B':
		printf("Barszcz Sosnowskiego");
		break;
	case 'C':
		printf("Czlowiek");
		break;
	case 'G':
		printf("Guarana");
		break;
	case 'J':
		printf("Wilcze jagody");
		break;
	case 'L':
		printf("Lis");
		break;
	case 'M':
		printf("Mlecz");
		break;
	case 'O':
		printf("Owca");
		break;
	case 'T':
		printf("Trawa");
		break;
	case 'W':
		printf("Wilk");
		break;
	case 'Z':
		printf("Zolw");
		break;
	}
}