#pragma once
#include "Swiat.h"
#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcze_jagody.h"
#include "Barszcz_Sosnowskiego.h"
Swiat::Swiat(){
	this->czyRozpoczeta = false;
}
Swiat::Swiat(int szer, int wys) {
	this->czyRozpoczeta = false;
	this->szerokosc = szer;
	this->wysokosc = wys;
	this->mapa = new Organizm** [wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		this->mapa[i] = new Organizm * [szerokosc];
	}
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			this->mapa[i][j] = nullptr;
		}
	}
	this->stworzSwiat();
}
bool Swiat::czyCzlowiekZyje() const {
	if (czlowiek == nullptr)
		return 0;
	else if (!czlowiek->getZywy())
		return 0;
	else
		return 1;
}
Czlowiek* Swiat::getCzlowiek() const {
	return czlowiek;
}
int Swiat::getSzerokosc() const {
	return szerokosc;
}
int Swiat::getWysokosc() const {
	return wysokosc;
}
Organizm* Swiat::getOrganizm(int polX, int polY) const {
	return mapa[polY][polX];
}
bool Swiat::getTryb() const {
	return tryb;
}
void Swiat::setTryb(bool t) {
	this->tryb = t;
}
void Swiat::rysujSwiat() {
	printf("Symulator Swiata. Autor: Mikolaj Nowak s184865.\n");
	for (int j = 0; j < 3*szerokosc+2; j++) {
		printf("#");
	}printf("\n");
	for (int i = 0; i < wysokosc; i++) {
		printf("#");
		for (int j = 0; j < szerokosc; j++) {
			if (mapa[i][j] == nullptr) printf(" - ");
			else mapa[i][j]->rysowanie();
		}printf("#\n");
	}
	for (int j = 0; j < 3 * szerokosc + 2; j++) {
		printf("#");
	}printf("\n");
}
void Swiat::dodajOrganizmDoUsuniecia(Organizm* o) {
	this->organizmyDoUsuniecia.push_back(o);
}
void Swiat::dodajNaMape(Organizm* o, int x, int y) {
	this->mapa[y][x] = o;
}
void Swiat::usunZMapy(int x, int y) {
	this->mapa[y][x] = nullptr;
}
void Swiat::dodajOrganizm(Organizm* o, int x, int y) {
	this->dodajNaMape(o, x, y);
	this->organizmy.push_back(o);
}
void Swiat::usunOrganizm(Organizm* o) {
	organizmy.erase(std::remove(organizmy.begin(),organizmy.end(),o),organizmy.end());
}
bool Swiat::porownajSile(Organizm* atakujacy, Organizm* broniacy) const { //zwraca 1 jezeli atakujacy organizm wygralby potyczke
	if ((atakujacy->getSila() < broniacy->getSila()) || ((atakujacy->getSila() == broniacy->getSila()) && (atakujacy->getWiek() < broniacy->getWiek())))
		return 0;
	else
		return 1;
}
bool Swiat::warunekPomocniczy(Organizm* org, int polX, int polY, bool czyPobratymcow) {
	if (czyPobratymcow) {
		if (mapa[polY][polX] == nullptr)
			return 1;
		else if (mapa[polY][polX]->getID() == org->getID())
			return 1;
		else
			return 0;
	}
	else {
		if ((mapa[polY][polX]) == nullptr)
			return 1;
		else 
			return 0;
	}
}
bool Swiat::szukajMiejsca(Organizm* o, int* koordynaty, bool czyPobratymcow) {
	int x = o->getPolozenieX();
	int y = o->getPolozenieY();
	int szer = this->getSzerokosc();
	int wys = this->getWysokosc();
	bool sprawdzone[4] = { 0 };
	int zajete = 0;
	while (1) {
		int tmp = rand() % 4;
		switch (tmp)
		{
		case 0:
			if ((y > 0) && this->warunekPomocniczy(o, x, y - 1, czyPobratymcow)) {
				koordynaty[0] = x;
				koordynaty[1] = y - 1;
				return 1;
			}
			else if (sprawdzone[0] == 0) {
				sprawdzone[0] = 1;
				zajete++;
				break;
			}
			else
				break;
		case 1:
			if ((y < wys - 1) && this->warunekPomocniczy(o, x, y + 1, czyPobratymcow)) {
				koordynaty[0] = x;
				koordynaty[1] = y + 1;
				return 1;
			}
			else if (sprawdzone[1] == 0) {
				sprawdzone[1] = 1;
				zajete++;
				break;
			}
			else
				break;
		case 2:
			if ((x > 0) && this->warunekPomocniczy(o, x - 1, y, czyPobratymcow)) {
				koordynaty[0] = x - 1;
				koordynaty[1] = y;
				return 1;
			}
			else if (sprawdzone[2] == 0) {
				sprawdzone[2] = 1;
				zajete++;
				break;
			}
			else
				break;
		case 3:
			if ((x < szer - 1) && this->warunekPomocniczy(o, x + 1, y, czyPobratymcow)) {
				koordynaty[0] = x + 1;
				koordynaty[1] = y;
				return 1;
			}
			else if (sprawdzone[3] == 0) {
				sprawdzone[3] = 1;
				zajete++;
				break;
			}
			else
				break;
		}
		if (zajete == 4)
			return 0;
	}
}
bool Swiat::porownajInicjatywe(Organizm* pierwszy, Organizm* drugi) {
	if ((pierwszy->getInicjatywa() > drugi->getInicjatywa()) || ((pierwszy->getInicjatywa() == drugi->getInicjatywa()) && (pierwszy->getWiek() > drugi->getWiek())))
		return 1;
	else
		return 0;
}
void Swiat::sortowanieOrganizmow(std::vector<Organizm*>& org, int n) {
	for (int d = n / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < n; i++)
		{
			Organizm* tmp = org[i];
			int j;
			for (j = i; j >= d && porownajInicjatywe(tmp, org[j-d]) == 1; j -= d) {
				org[j] = org[j - d];
			}
			org[j] = tmp;
		}
	}
}
void Swiat::wykonajTure() {
	this->sortowanieOrganizmow(organizmy, organizmy.size());
	for (int i = 0; i < organizmy.size(); i++) {
		if (((organizmy[i]->getWiek()>0)&&(organizmy[i]->getZywy()==1))||(!this->czyRozpoczeta)) {
			int poprzednieX = organizmy[i]->getPolozenieX();
			int poprzednieY = organizmy[i]->getPolozenieY();
			organizmy[i]->akcja();
			int aktualneX = organizmy[i]->getPolozenieX();
			int aktualneY = organizmy[i]->getPolozenieY();
			if (mapa[aktualneY][aktualneX] == nullptr) {
				mapa[aktualneY][aktualneX] = organizmy[i];
				mapa[poprzednieY][poprzednieX] = nullptr;
			}
			else if ((poprzednieX == aktualneX) && (poprzednieY == aktualneY)) {
				continue;
			}
			else {
				Organizm* napierany = nullptr;
				napierany = mapa[aktualneY][aktualneX];
				napierany->kolizja(organizmy[i]);
			}
		}
	}
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getZywy() == 0) {
			usunOrganizm(organizmy[i]);
			--i;
		}
	}
	for (int i = 0; i < organizmy.size(); i++)
		organizmy[i]->setWiek(organizmy[i]->getWiek() + 1);
	this->czyRozpoczeta = true;
}
void Swiat::zapiszSwiat() {
	FILE* plik = fopen("pliktekstowy.txt", "w");
	fprintf(plik, "%d %d %d %d\n", this->szerokosc, this->wysokosc, this->organizmy.size(), (int)this->tryb);
	for (int i = 0; i < this->wysokosc; i++) {
		for (int j = 0; j < this->szerokosc; j++) {
			if (this->mapa[i][j] != nullptr) {
				char ID = this->mapa[i][j]->getID();
				int x = j;
				int y = i;
				int px = this->mapa[i][j]->getPoprzedniePolozenieX();
				int py = this->mapa[i][j]->getPoprzedniePolozenieY();
				int sil = this->mapa[i][j]->getSila();
				int ini = this->mapa[i][j]->getInicjatywa();
				int w = this->mapa[i][j]->getWiek();
				if (this->mapa[i][j]->getID() == 'C') {
					bool u = czlowiek->czyWlaczonaUmiejetnosc();
					int o = czlowiek->getOczekiwanie();
					fprintf(plik, "C %d %d %d %d %d %d %d %d %d\n", x, y, px, py, sil, ini, w, u, o);
				}
				else
					fprintf(plik, "%c %d %d %d %d %d %d %d\n", ID, x, y, px, py, sil, ini, w);
			}
		}
	}
	fclose(plik);
}
void Swiat::szukajPustychMiejsc(int* koordynaty) {
	int x = 42 * rand() % this->szerokosc;
	int y = 1337 * rand() % this->wysokosc;
	while (this->mapa[y][x] != nullptr) {
		x = 42 * rand() % this->szerokosc;
		y = 1337 * rand() % this->wysokosc;
	}
	koordynaty[0] = x;
	koordynaty[1] = y;
}
void Swiat::stworzSwiat() {
	this->czlowiek = new Czlowiek (this->szerokosc / 2, this->wysokosc / 2, this);
	int koordynaty[2];
	for (int i = 0; i < ILE_PRZEDSTAWICIELI_GATUNKU_ZWIERZAT; i++) {
		this->szukajPustychMiejsc(koordynaty);
		Wilk* w = new Wilk(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Owca* o = new Owca(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Lis* l = new Lis(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Zolw* z = new Zolw(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Antylopa* a = new Antylopa(koordynaty[0], koordynaty[1], this);
	}
	for (int i = 0; i < ILE_PRZEDSTAWICIELI_GATUNKU_ROSLIN; i++) {
		this->szukajPustychMiejsc(koordynaty);
		Trawa* t = new Trawa(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Mlecz* m = new Mlecz(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Guarana* g = new Guarana(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Wilcze_jagody* j = new Wilcze_jagody(koordynaty[0], koordynaty[1], this);
		this->szukajPustychMiejsc(koordynaty);
		Barszcz_Sosnowskiego* b = new Barszcz_Sosnowskiego(koordynaty[0], koordynaty[1], this);
	}
}
void Swiat::setSwiat(int szer, int wys, bool trybSymulacji) {
	this->szerokosc = szer;
	this->wysokosc = wys;
	this->tryb = trybSymulacji;
	this->mapa = new Organizm** [wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		this->mapa[i] = new Organizm* [szerokosc];
	}
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			this->mapa[i][j] = nullptr;
		}
	}
}
void Swiat::wczytajSwiat() {
	FILE* plik = fopen("pliktekstowy.txt", "r");
	int szerokosc, wysokosc, liczbaOrganizmow, trybSymulacji;
	fscanf_s(plik, "%d %d %d %d\n", &szerokosc, &wysokosc, &liczbaOrganizmow, &trybSymulacji);
	this->setSwiat(szerokosc, wysokosc, (bool)trybSymulacji);
	for(int i = 0; i<liczbaOrganizmow; i++) {
		char znak;
		int x, y, px, py, sil, ini, w, o, u;
		fscanf_s(plik, "%c ", &znak);
		if (znak == 'C')
			fscanf_s(plik, "%d %d %d %d %d %d %d %d %d\n", &x, &y, &px, &py, &sil, &ini, &w, &u, &o);
		else 
			fscanf_s(plik, "%d %d %d %d %d %d %d\n", &x, &y, &px, &py, &sil, &ini, &w);
		Organizm* org = nullptr;
		switch (znak)
		{
		case 'A':
			org = new Antylopa(x,y,px,py,sil,ini,w,this);
			break;
		case 'B':
			org = new Barszcz_Sosnowskiego(x, y, px, py, sil, ini, w, this);
			break;
		case 'C':
			this->czlowiek = new Czlowiek(x, y, px, py, sil, ini, w, (bool)u, o, this);
			break;
		case 'G':
			org = new Guarana(x, y, px, py, sil, ini, w, this);
			break;
		case 'J':
			org = new Wilcze_jagody(x, y, px, py, sil, ini, w, this);
			break;
		case 'L':
			org = new Lis(x, y, px, py, sil, ini, w, this);
			break;
		case 'M':
			org = new Mlecz(x, y, px, py, sil, ini, w, this);
			break;
		case 'O':
			org = new Owca(x, y, px, py, sil, ini, w, this);
			break;
		case 'T':
			org = new Trawa(x, y, px, py, sil, ini, w, this);
			break;
		case 'W':
			org = new Wilk(x, y, px, py, sil, ini, w, this);
			break;
		case 'Z':
			org = new Zolw(x, y, px, py, sil, ini, w, this);
			break;
		}
	}
	fclose(plik);
}
Swiat::~Swiat(){
	for (int i = 0; i < wysokosc; i++)
		delete [] mapa[i];
	delete [] mapa;
	organizmyDoUsuniecia.clear();
	organizmy.clear();
}