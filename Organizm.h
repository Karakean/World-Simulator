#pragma once
#include "Swiat.h"
class Swiat;
class Organizm {
protected:
	int sila;
	int inicjatywa;
	int wiek;
	int polozenieX;
	int polozenieY;
	int poprzedniePolozenieX;
	int poprzedniePolozenieY;
	char ID;
	bool zywy;
	Swiat* swiat;
public:
	Organizm(int polX, int polY, Swiat* s);
	Organizm(int polX, int polY, int poprzPolX, int poprzPolY, int sil, int ini, int w, Swiat* s);
	int getPolozenieX() const;
	int getPolozenieY() const;
	int getPoprzedniePolozenieX() const;
	int getPoprzedniePolozenieY() const;
	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	bool getZywy() const;
	char getID() const;
	virtual void setPolozenieX(int x);
	virtual void setPolozenieY(int y);
	void setWiek(int w);
	void setSila(int s);
	virtual bool czyUciekl() const;
	void zabij();
	void przesun(int noweX, int noweY);
	void cofniecie();
	void wypiszOrganizm(char identyfikator);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* atakujacy) = 0;
	virtual void rysowanie() = 0;
};
