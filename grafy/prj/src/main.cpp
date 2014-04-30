#include "../inc/graf.hh"

using namespace std;

int main(){
	int w;
	cout<<"Witaj w programie, na poczatek :\n";
	cout<<"Podaj liczbe wierzchołków  : ";
	cin >> w;         // Czytamy liczbę wierzchołków i krawędzi

  	graf g(w);
 	int oper=0;
	
	do{
		cout<<"Oto nastepujace opcje programu :\n";
		cout<<"\n1 -> ustaw_polaczenia\n"
		<<"2 -> dodaj wierzcholek\n"
		<<"3 -> usun wiercholek \n"
		<<"4 -> dodaj krawedz\n"
		<<"5 -> usun krawedz\n"
		<<"6 -> pokaz sasiadow wierzcholka\n"
		<<"7 -> pokaz wszystko\n"
		<<"8 -> ile wierzcholkow\n"
		<<"9 -> pokaz wierzcholki\n"
		<<"10 -> koniec\n"
		<<"Twoja opcja to : ";
		cin>>oper;
		if (( oper > 0 ) && ( oper < 11)){
			switch(oper){
			case 1: g.ustaw_polaczenia(); break;
			case 2: g.dodaj_wierzcholek(); break;
    		case 3: g.usuwanie_wierzcholka(); break;
			case 4: g.dodawanie_krawedzi(); break;
			case 5: g.usuwanie_krawedzi(); break;
			case 6: g.sasiedztwo(); break;
			case 7: g.wyswietl_wszystko(); break;
			case 8: g.ilosc_wierzcholkow(); break;
			case 9: g.wyswietl_wierzcholki(); break;
			case 10: break;
			default: cerr << "\n***********nierozpoznana opcja ! Wpisz ponownie : ***********\n"; break;
			}
		}
		else cout<<"\n***********podales zly znak, sprobuj jeszcze raz !***********\n";
	}while(oper != 10);
  return 0;
} 