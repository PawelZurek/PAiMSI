#include <iostream>
#include <string>
#include "../inc/tab_hash.hh"

int main(){
	int oper=0;
	tab_hash tab(100);
	cout<<"Witaj w programie, oto nastepujace opcje:\n";
	do{
	cout<<"\n1 -> dodaj element\n"
		<<"2 -> usun wybrany element\n"
		<<"3 -> wyswietl wybrany element \n"
		<<"4 -> sprawdz czy sa jakies elementy\n"
		<<"5 -> podaj ilosc elementow\n"
		<<"6 -> pokaz elementy\n"
		<<"7 -> wypelnij elementami z pliku\n"
		<<"8 -> koniec\n"
		<<"Twoja opcja to : ";
		cin>>oper;
		if (( oper > 0 ) && ( oper < 9)){
			switch(oper){
			case 1: tab.zaczynamy(); break;
			case 2: tab.usun(); break;
    		case 3: tab.znajdz(); break;
			case 4: tab.pusta(); break;
			case 5: tab.size(); break;
			case 6: tab.wyswietl(); break;
			case 7: tab.wypelnij("test.txt"); break;
			case 8: break;
			default: cerr << "\n***********nierozpoznana opcja ! Wpisz ponownie : ***********\n"; break;
			}
		}
		else cout<<"\n***********podales zly znak, sprobuj jeszcze raz !***********\n";
	}while(oper != 8);

		return 0;
}