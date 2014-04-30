#include <iostream>
#include <string>
#include "../inc/stos_tablica.hh"

int main(){
	int oper=0;
	stos_tablica tab;
	cout<<"Witaj w programie, oto nastepujace opcje:\n";
	do{
	cout<<"\n1 -> dodaj element z kluczem\n"
		<<"2 -> usun element z kluczem\n"
		<<"3 -> wyswietl element z kluczem\n"
		<<"4 -> sprawdz czy sa jakies elementy\n"
		<<"5 -> podaj ilosc elementow\n"
		<<"6 -> pokaz elementy\n"
		<<"8 -> koniec\n"
		<<"Twoja opcja to : ";
		cin>>oper;
		if (( oper > 0 ) && ( oper < 9)){
			switch(oper){
			case 1: tab.dodaj_element(); break;
			case 2: tab.usun(); break;
    		case 3: tab.pobierz(); break;
			case 4: tab.isEmpty(); break;
			case 5: tab.size(); break;
			case 6: tab.pokaz_elementy(); break;
			case 8: break;
			default: cerr << "\n***********nierozpoznana opcja ! Wpisz ponownie : ***********\n"; break;
			}
		}
		else cout<<"\n***********podales zly znak, sprobuj jeszcze raz !***********\n";
	}while(oper != 8);

		return 0;
}