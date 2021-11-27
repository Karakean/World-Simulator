#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Organizm.h"
#define ESC 27
#define GORA 72
#define DOL 80
#define LEWO 75
#define PRAWO 77
#define UMIEJETNOSC_SPECJALNA 120
#define ZAPIS 122
#define SZANSA_NA_ROZPRZESTRZENIANIE 25 //w procentach
#define ILE_PRZEDSTAWICIELI_GATUNKU_ZWIERZAT 3 
#define ILE_PRZEDSTAWICIELI_GATUNKU_ROSLIN 1 
class Organizm;
class Czlowiek;
class Swiat {
	bool czyRozpoczeta;
	bool tryb;
	int szerokosc;
	int wysokosc;
	Organizm*** mapa;
	std::vector <Organizm*> organizmy;
	std::vector <Organizm*> organizmyDoUsuniecia;
	Czlowiek* czlowiek;
	bool warunekPomocniczy(Organizm* o, int polX, int polY, bool czyPobratymcow);
	void sortowanieOrganizmow(std::vector <Organizm*>& org, int n);
	bool porownajInicjatywe(Organizm* org1, Organizm* org2);
	void stworzSwiat();
	void setSwiat(int szer, int wys, bool trybs);
	void szukajPustychMiejsc(int* koordynaty);
public:
	Swiat();
	Swiat(int szer, int wys);
	int getSzerokosc() const;
	int getWysokosc() const;
	bool czyCzlowiekZyje() const;
	Organizm* getOrganizm(int polX, int polY) const;
	Czlowiek* getCzlowiek() const;
	bool getTryb() const;
	void setTryb(bool t);
	void wykonajTure();
	void rysujSwiat();
	void dodajNaMape(Organizm* o, int polX, int polY);
	void dodajOrganizm(Organizm* o, int polX, int polY);
	void dodajOrganizmDoUsuniecia(Organizm* o);
	void usunZMapy(int polX, int polY);
	void usunOrganizm(Organizm* o);
	bool porownajSile(Organizm* o1, Organizm* o2) const;
	bool szukajMiejsca(Organizm* o, int* koordynaty, bool czyPobratymcow);
	void zapiszSwiat();
	void wczytajSwiat();
	~Swiat();
};
