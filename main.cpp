#include "Swiat.h"
#include "Czlowiek.h"
int main() {
	srand(time(NULL));
	int N = 0, M = 0;
	Swiat* swiat = nullptr;
	bool poprawny = false;
	int trybBezCzlowieka = -1;
	while (!poprawny) {
		printf("Witaj w symulatorze wirtualnego swiata.\nN-Nowa gra\nP-Wczytaj stan gry z pliku\nESC-Wyjscie z gry\nAutor: Mikolaj Nowak s184865\n");
		char wybor = _getch();
		if ((wybor == 110) || (wybor == 78)) { //n lub N
			printf("Podaj szerokosc planszy: ");
			scanf_s("%d", &N);
			while (N < 5) {
				printf("Nieprawidlowa szerokosc planszy. Minimalna szerokosc wynosi 5.\nPodaj szerokosc planszy: ");
				scanf_s("%d", &N);
			}
			printf("Podaj wysokosc planszy: ");
			scanf_s("%d", &M);
			while (M < 5) {
				printf("Nieprawidlowa wysokosc planszy. Minimalna wysokosc wynosi 5.\nPodaj wysokosc planszy: ");
				scanf_s("%d", &N);
			}
			printf("Czy symulacja ma trwac dalej po smierci czlowieka? Wpisz 1 jesli tak, 0 jesli nie.\n");
			scanf_s("%d", &trybBezCzlowieka);
			while ((trybBezCzlowieka != 0) && (trybBezCzlowieka != 1)) {
				printf("Nieprawidlowy wybor. Wpisz 1 jezeli symulacja ma trwac po smierci czlowieka, 0 jesli nie.\n");
				scanf_s("%d", &trybBezCzlowieka);
			}
			swiat = new Swiat(N, M);
			swiat->setTryb((bool)trybBezCzlowieka);
			system("cls");
			poprawny = true;
		}
		else if ((wybor == 112) || (wybor == 80)) { //p lub P
			swiat = new Swiat();
			swiat->wczytajSwiat();
			system("cls");
			printf("Wczytano stan gry z pliku.\n");
			poprawny = true;
		}
		else if (wybor == ESC)
			return 0;
		else
			printf("\nBlad, prosze wybrac opcje z menu.\n\n");
	}
	Czlowiek* c = swiat->getCzlowiek();
	swiat->rysujSwiat();
	if(swiat->czyCzlowiekZyje())
		printf("Z - zapisz stan gry\nX - uzycie umiejetnosc specjalnej czlowieka\n\n");
	else
		printf("Z - zapisz stan gry\nT - nowa tura\n\n");
	int input = NULL;
	while (swiat->czyCzlowiekZyje()) {
		input = _getch();
		if (input == 0 || input == 224) {
			int kierunek = _getch();
			c->ustawDzialanie(kierunek);
		}
		else if ((input == UMIEJETNOSC_SPECJALNA) || (input == 88)) { //x lub X
			c->ustawDzialanie(UMIEJETNOSC_SPECJALNA);
		}
		else if ((input == ZAPIS) || (input == 90)) { //z lub Z
			swiat->zapiszSwiat();
			printf("Zapisano stan gry do pliku.\n");
		}
		else if (input == ESC) {
			return 0;
		}
		else {
			c->ustawDzialanie(0);
			printf("Wcisnieto zly klawisz, ruch przepadl.\n");
		}
		if (input != ZAPIS) {
			swiat->wykonajTure();
			swiat->rysujSwiat();
			if(swiat->czyCzlowiekZyje())
				printf("Z - zapisz stan gry\nX - uzycie umiejetnosc specjalnej czlowieka\n\n");
			else if (swiat->getTryb())
				printf("Z - zapisz stan gry\nT - nowa tura\n\n");
		}
	}
	while ((swiat->getTryb())&&(input != ESC)) {
		input = _getch();
		if ((input == 116) || (input == 84)) { //t lub T
			swiat->wykonajTure();
			swiat->rysujSwiat();
			printf("Z - zapisz stan gry\nT - nowa tura\n\n");
		}
		else if ((input == ZAPIS) || (input == 90)) { //z lub Z
			swiat->zapiszSwiat();
			printf("Zapisano stan gry do pliku.\n");
		}
	}
	delete swiat;
	return 0;
}