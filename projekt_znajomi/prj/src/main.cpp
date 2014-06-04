/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje main() 
 *
 */
#include "../inc/Dijkstry.hh"

using namespace std;
int main(){
	srand( time( NULL ) );
	Graf tab;

	int oper=0;
	do{
		cout<<"--------------------------------------------------------\n";
		cout<<"Oto opcje programu :";
		cout<<"\n1 -> Wczytaj liste i polaczenia z dowolnego pliku\n"
		<<"2 -> Wczytaj liste i polaczenia z pliku domyslnego\n"
		<<"3 -> Wczytaj liste i polaczenia z pliku testowego \n"
		<<"4 -> Wygeneruj liste i polaczenia losowo\n"
		<<"5 -> Znajdz polaczenie losowe\n"
		<<"6 -> Znajdz dowolne polaczenie\n"
		<<"7 -> Wyswietl liste i polaczenia\n"
		<<"10 -> koniec"
		<<"\n--------------------------------------------------------\n";
		cout<<"Twoja opcja to : ";
		cin>>oper;
		if (( oper > 0 ) && ( oper < 15)){
			switch(oper){
			case 1: tab.dowolny_plik(); break;
			case 2: tab.domyslny_plik(); break;
    		case 3: tab.testowy_plik(); break;
			case 4:  {
				bool pom = false;
				int ilosc=0, gestosc=0;
				cout<<"Podaj ilosc : ";
				cin>>ilosc;
				cout<<"Podaj gestosc : ";
				cin>>gestosc;
				while (pom != true){
					tab.generuj_liste(ilosc, gestosc);
					pom = tab.czy_spojny();	}
			} break;
			case 5: tab.losowe_dijkstry() ; break;
			case 6: {
				int a=0, b=0;
				cout<<"Podaj id wierzcholka 1 :";
				cin>>a;
				cout<<"Podaj id wierzcholka 2 :";
				cin>>b;
				tab.dijkstry(a,b);
			} break;
			case 7: tab.wyswietl(); break;
			case 10: break;
			default: cerr << "\n***********nierozpoznana opcja ! Wpisz ponownie : ***********\n"; break;
			}
		}
		else cout<<"\n***********podales zly znak, sprobuj jeszcze raz !***********\n";
	}while(oper != 10);

	return 0;
}