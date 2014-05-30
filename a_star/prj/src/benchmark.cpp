/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy benchmark
 *
 */
#include "../inc/benchmark.hh"
#include <iostream>

using namespace std;

void benchmark::czas_start(){
	gettimeofday(&t1, NULL);
}
void benchmark::czas_stop(){
	gettimeofday(&t2, NULL);
}
double benchmark::ile_czasu(){
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	//cout <<"Czas operacji: " << elapsedTime << "ms.\n";	
	return elapsedTime;
}

void benchmark::algorytm(){
	string typ="A_star1";
	graf g100(50);
	graf g400(60);
	graf g900(70);
	graf g1600(100);

	double czasy[4];
	int rozmiary[4] ={2500,3600,4900,10000};
	czas_start();
	g100.A_star();
	czas_stop();
	czasy[0] = ile_czasu();
	czas_start();
	g400.A_star();
	czas_stop();
	czasy[1] = ile_czasu();
	czas_start();
	g900.A_star();
	czas_stop();
	czasy[2] = ile_czasu();
	czas_start();
	g1600.A_star();
	czas_stop();
	czasy[3] = ile_czasu();

	typ="dane/"+typ;
	ofstream plik(typ.c_str());
		for (int i = 0; i < 4; i++)
		{
			plik<<rozmiary[i]<<"		"<<czasy[i]<<endl;
		}

}
