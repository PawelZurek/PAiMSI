/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy benchmark
 *
 */
#include "../inc/benchmark.hh"
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
	double depth[8], breth[8];
	for (int i = 0; i < 7; ++i)
	{
		depth[i]=0;
		breth[i]=0;
	}
	int wielkosci [] = {100,250,500,750,1000,1500,2000};
	graf g100(100);
	g100.losuj_polaczenia(100);
	graf g250(250);
	g250.losuj_polaczenia(100);
	graf g500(500);
	g500.losuj_polaczenia(100);
	graf g750(750);
	g750.losuj_polaczenia(100);
	graf g1000(1000);
	g1000.losuj_polaczenia(100);
	graf g1500(1500);
	g1500.losuj_polaczenia(100);*
	string typ="dane/test.txt";
	ofstream plik(typ.c_str());
	for (int i = 0; i < 7; ++i){
		graf g(wielkosci[i]);
	g.losuj_polaczenia(25);
	czas_start();
	g.dfs(1);
	czas_stop();
	cout<<endl<<ile_czasu()<<endl;
	plik<<ile_czasu()<<endl;
}
    

	/*
	//nie wiem czemu ale lepiej dziala
	czas_start();
	g2000.dfs(1);
	czas_stop();
	//depth dla 100....
	czas_start();
	g100.dfs(1);
	czas_stop();
	depth[0]=ile_czasu();
	depth[7]=depth[7]+depth[0];

	czas_start();
	g250.dfs(1);
	czas_stop();
	depth[1]=ile_czasu();
	depth[7]=depth[7]+depth[1];

	czas_start();
	g500.dfs(1);
	czas_stop();
	depth[2]=ile_czasu();
	depth[7]=depth[7]+depth[2];

	czas_start();
	g750.dfs(1);
	czas_stop();
	depth[3]=ile_czasu();
	depth[7]=depth[7]+depth[3];

	czas_start();
	g1000.dfs(1);
	czas_stop();
	depth[4]=ile_czasu();
	depth[7]=depth[7]+depth[4];
	
	czas_start();
	g1500.dfs(1);
	czas_stop();
	depth[5]=ile_czasu();
	depth[7]=depth[7]+depth[5];

	czas_start();
	g2000.dfs(1);
	czas_stop();
	depth[6]=ile_czasu();
	depth[7]=depth[7]+depth[6];

	//breadth !!!! dla 100,...
	czas_start();
	g100.bfs(1);
	czas_stop();
	breth[0] = ile_czasu();
	breth[7]=breth[7]+breth[0];

	czas_start();
	g250.bfs(1);
	czas_stop();
	breth[1] = ile_czasu();
	breth[7]=breth[7]+breth[1];

	czas_start();
	g500.bfs(1);
	czas_stop();
	breth[2] = ile_czasu();
	breth[7]=breth[7]+breth[2];

	czas_start();
	g750.bfs(1);
	czas_stop();
	breth[3] = ile_czasu();
	breth[7]=breth[7]+breth[3];

	czas_start();
	g1000.bfs(1);
	czas_stop();
	breth[4] = ile_czasu();
	breth[7]=breth[7]+breth[4];

	czas_start();
	g1500.bfs(1);
	czas_stop();
	breth[5] = ile_czasu();
	breth[7]=breth[7]+breth[5];

	czas_start();
	g2000.bfs(1);
	czas_stop();
	breth[6] = ile_czasu();
	breth[7]=breth[7]+breth[6];


	wyswietl_wszystko(depth,breth, wielkosci);

	stworz_plik("breth100",breth, wielkosci);
	stworz_plik("depth100",depth, wielkosci);

}
*/

void benchmark::wyswietl_wszystko(double *d, double *b, int *s){
	for (int i = 0; i < 7; i++){
	cout<<"\nCzas przeszukania grafu w glab dla "<<s[i]<<" wierzcholkow : ";
	cout<<d[i]<<" ms "<<endl;
	cout<<"\nCzas przeszukania grafu w szerz dla "<<s[i]<<" wierzcholkow : ";
	cout<<b[i]<<" ms "<<endl;
	}
	
	cout<<"\nCalkowity Czas przeszukania grafu w glab : ";
	cout<<d[7]<<" ms "<<endl;
	cout<<"\nCalkowity Czas przeszukania grafu w szerz : ";
	cout<<b[7]<<" ms "<<endl;

	cout<<"\nCalkowity czas wykonywania to : "<<czas<<" ms "<<endl;
} 

void benchmark::stworz_plik(string typ, double *dane, int *s){
	typ="dane/"+typ;
	ofstream plik(typ.c_str());
	if (size>0){		
		for (int i = 0; i < 7; i++)
		{
			plik<<s[i]<<"		"<<dane[i]<<endl;
		}
	}
}
