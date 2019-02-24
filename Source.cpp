#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<math.h>

int strOpcja;
int znaczek;

enum gracz { kolko = 0, krzyzyk = 1 };

gracz him1;// = (gracz)(rand() % 2);
gracz him2;// = (gracz)abs((int)(him1)-1);
using namespace std;
int plansza[3][3] =
{
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 }
};

int sprawdzaj_plansze()
{
	
	int i, j, s=0;
	for (i = 0; i < 3; i++)
	{
			if (plansza[0][i] * plansza[1][i] * plansza[2][i] == 8) return 2;
			if (plansza[i][0] * plansza[i][1] * plansza[i][2] == 8) return 2;
			if (plansza[0][i] * plansza[1][i] * plansza[2][i] == 1) return 1;
			if (plansza[i][0] * plansza[i][1] * plansza[i][2] == 1) return 1;
	}
	if (plansza[0][0] * plansza[1][1] * plansza[2][2]==8) return 2;
	if (plansza[0][2] * plansza[1][1] * plansza[2][0]==8) return 2;
	if (plansza[0][0] * plansza[1][1] * plansza[2][2]==1) return 1;
	if (plansza[0][2] * plansza[1][1] * plansza[2][0]==1) return 1;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			s += plansza[i][j];
	}
	if (s >= 13) return 3;
	else return 0;
}

void rysuj_plansze()
	{
		int i, j;
		
		system("cls");
		for (i = 0; i < 3; i++)
		{
			printf("\n |");
			for (j = 0; j < 3; j++)
			{

				if (plansza[i][j] == 0) printf(" |");
				if (plansza[i][j] == 1) printf("O|");
				if (plansza[i][j] == 2) printf("X|");
			}
		}
	}

gracz zamiana(gracz him)
{
	return (gracz)abs((int)(him)-1);
}

void ruch(gracz him)
{
		
	int pole;
	do{
		printf("\n \n POLE: ");
		scanf_s("%d", &pole);
	} while (pole < 1 || pole>9);
	if (him == kolko){
		
		switch (pole)
		{
		
		case 1: if (plansza[0][0] == 0) plansza[0][0]++; 
				else ruch(him); break;
		case 2: if (plansza[0][1] == 0) plansza[0][1]++;
				else ruch(him); break;
		case 3: if (plansza[0][2] == 0) plansza[0][2]++;
				else ruch(him); break;
		case 4: if (plansza[1][0] == 0) plansza[1][0]++;
				else ruch(him); break;
		case 5: if (plansza[1][1] == 0) plansza[1][1]++;
				else ruch(him); break;
		case 6: if (plansza[1][2] == 0) plansza[1][2]++;
				else ruch(him); break;
		case 7: if (plansza[2][0] == 0) plansza[2][0]++;
				else ruch(him); break;
		case 8: if (plansza[2][1] == 0) plansza[2][1]++;
				else ruch(him); break;
		case 9: if (plansza[2][2] == 0) plansza[2][2]++;
				else ruch(him); break;
			
		};
	}
	if (him == krzyzyk)
	{
		switch (pole)
		{
		case 1: if (plansza[0][0] == 0) plansza[0][0] = plansza[0][0]+2;
				else ruch(him); break;
		case 2: if (plansza[0][1] == 0) plansza[0][1]= plansza[0][1] + 2;
				else ruch(him); break;
		case 3: if (plansza[0][2] == 0) plansza[0][2] = plansza[0][2] + 2;
				else ruch(him); break;
		case 4: if (plansza[1][0] == 0) plansza[1][0] = plansza[1][0] + 2;
				else ruch(him); break;
		case 5: if (plansza[1][1] == 0) plansza[1][1] = plansza[1][1] + 2;
				else ruch(him); break;
		case 6: if (plansza[1][2] == 0) plansza[1][2] = plansza[1][2] + 2;
				else ruch(him); break;
		case 7: if (plansza[2][0] == 0) plansza[2][0] = plansza[2][0] + 2;
				else ruch(him); break;
		case 8: if (plansza[2][1] == 0) plansza[2][1] = plansza[2][1] + 2;
				else ruch(him); break;
		case 9: if (plansza[2][2] == 0) plansza[2][2] = plansza[2][2] + 2;
				else ruch(him); break;
		
		};
	}
}

void AI_ruch(gracz him)
{
	int pole;
	srand(time(NULL));
	
	bool prawda = true;
	do{
		pole = rand() % 9 + 1;
		prawda = true;
		if (him == kolko){

			switch (pole)
			{

			case 1: if (plansza[0][0] == 0) plansza[0][0]++;
					else prawda=false; break;
			case 2: if (plansza[0][1] == 0) plansza[0][1]++;
					else prawda = false; break;
			case 3: if (plansza[0][2] == 0) plansza[0][2]++;
					else prawda=false; break;
			case 4: if (plansza[1][0] == 0) plansza[1][0]++;
					else prawda=false; break;
			case 5: if (plansza[1][1] == 0) plansza[1][1]++;
					else prawda=false; break;
			case 6: if (plansza[1][2] == 0) plansza[1][2]++;
					else prawda=false; break;
			case 7: if (plansza[2][0] == 0) plansza[2][0]++;
					else prawda=false; break;
			case 8: if (plansza[2][1] == 0) plansza[2][1]++;
					else prawda=false; break;
			case 9: if (plansza[2][2] == 0) plansza[2][2]++;
					else prawda=false; break;

			};
		}
		if (him == krzyzyk)
		{
			switch (pole)
			{
			case 1: if (plansza[0][0] == 0) plansza[0][0] = plansza[0][0] + 2;
					else prawda=false; break;
			case 2: if (plansza[0][1] == 0) plansza[0][1] = plansza[0][1] + 2;
					else prawda=false; break;
			case 3: if (plansza[0][2] == 0) plansza[0][2] = plansza[0][2] + 2;
					else prawda=false; break;
			case 4: if (plansza[1][0] == 0) plansza[1][0] = plansza[1][0] + 2;
					else prawda=false; break;
			case 5: if (plansza[1][1] == 0) plansza[1][1] = plansza[1][1] + 2;
					else prawda=false; break;
			case 6: if (plansza[1][2] == 0) plansza[1][2] = plansza[1][2] + 2;
					else prawda=false; break;
			case 7: if (plansza[2][0] == 0) plansza[2][0] = plansza[2][0] + 2;
					else prawda=false; break;
			case 8: if (plansza[2][1] == 0) plansza[2][1] = plansza[2][1] + 2;
					else prawda=false; break;
			case 9: if (plansza[2][2] == 0) plansza[2][2] = plansza[2][2] + 2;
					else prawda = false; break;

			};
		}
	} while (prawda==false);
}

void gra( gracz him)
{
	
		rysuj_plansze();
		if (him == kolko) printf("\n \n kolej gracza: kolko");
		if (him == krzyzyk) printf("\n \n kolej gracza: krzyzyk");
		ruch(him);
		rysuj_plansze();
		
}

int menu(char strOpcja)
{
    
	printf("\n KOLKO I KRZYZYK - ultimate fighters \n");
	printf("\n 1.Jeden gracz");
	printf("\n 2.Dwoch graczy");
	printf("\n \n Q.Wyjscie");
	printf("\n \n OPCJA: ");
	scanf_s("%c", strOpcja);
	if (strOpcja == 'a' ) return 1;
	if (strOpcja == 'b') return 2;
	if (strOpcja == 'c') return 3;

}

void main()
{
	
	
	printf("\n KOLKO I KRZYZYK  \n");
	printf("\n 1.Jeden gracz");
	printf("\n 2.Dwoch graczy");
	printf("\n \n 3.Wyjscie");
	printf("\n \n OPCJA: ");
	std::cin >> strOpcja;
	


	switch (strOpcja){
		//singleplayer
	case 1:
	{
		system("cls");
		
		srand(time(NULL));
		gracz losowanie = (gracz)(rand() % 2);

		printf("\n Wybierz jakim znaczkiem chcesz byc: ");
		printf("\n \n 1. Kolko");
		printf("\n 2. Krzyzyk");
		printf(" \n \n znaczek:");
		std::cin >> znaczek;
		if (znaczek == 1) him1 = kolko;
		if (znaczek == 2) him1 = krzyzyk;
		him2 = (gracz)abs((int)(him1)-1);
		system("cls");
		printf("\n Za chwile rozpocznie sie losowanie gracza!\n\n ");
		system("\n Pause");


		if (losowanie == him1)
		{
			do{

				gra(him1);
				sprawdzaj_plansze();
				if (sprawdzaj_plansze() >= 1) break;
				//gra(him2);
				rysuj_plansze();
				if (him2 == kolko) printf("\n \n kolej gracza: kolko");
				if (him2 == krzyzyk) printf("\n \n kolej gracza: krzyzyk");
				AI_ruch(him2);
				rysuj_plansze();
				//
				sprawdzaj_plansze();
			} while (sprawdzaj_plansze() < 1);
		}

		if (losowanie == him2)

		{
			{
				do{
					//gra him2
					rysuj_plansze();
					if (him2 == kolko) printf("\n \n kolej gracza: kolko");
					if (him2 == krzyzyk) printf("\n \n kolej gracza: krzyzyk");
					AI_ruch(him2);
					rysuj_plansze();
					//
					sprawdzaj_plansze();
					if (sprawdzaj_plansze() >= 1) break;
					gra(him1);
					sprawdzaj_plansze();
				} while (sprawdzaj_plansze() < 1);
			} 

			
			if (sprawdzaj_plansze() == 1) printf("\n \n Wygralo kolko!");
			if (sprawdzaj_plansze() == 2) printf("\n \n Wygral krzyzyk!");

			if (sprawdzaj_plansze() == 3) printf("\n \n Mamy remis! ");
 
		}
	}break;
	//multiplayer
	case 2:
	{
		srand(time(NULL));
		him1 = (gracz)(rand() % 2);
		him2 = (gracz)abs((int)(him1)-1);
		printf("\n Ustalcie z przeciwnikiem kto jest jakim znaczkiem");
		printf("\n Numery (1-9) na klaw. sa kolejnymi polami...");
		printf("\n Za chwile rozpocznie sie losowanie gracza!\n\n ");
		system("\n Pause");
		if (him1 == kolko) printf("Zaczyna kolko");
		if (him1 == krzyzyk) printf("Zaczyna krzyzyk");

		_getch();

		do{

			gra(him1);
			sprawdzaj_plansze();
			if (sprawdzaj_plansze() >= 1) break;
			gra(him2);
			sprawdzaj_plansze();
		} while (sprawdzaj_plansze() < 1);

		if (sprawdzaj_plansze() == 1) printf("\n \n Wygralo kolko!");
		if (sprawdzaj_plansze() == 2) printf("\n \n Wygral krzyzyk!");
		if (sprawdzaj_plansze() == 3) printf("\n \n Mamy remis! ");

		_getch(); 
	}break;
	case 3: printf("koniec!");
	};
		_getch();
	
}