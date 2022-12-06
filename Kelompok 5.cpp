#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<cstdlib>
#include<ncurses.h>

using namespace std;

void load();
void gotoxy();

int main()
{
	
	initscr();
	printw("Tekan Enter Untuk Lanjutkan");
	getch();
	endwin();
	
	system("color A");
	load();
	cout << endl << endl << endl << endl << endl << endl << endl;
	int angka, gacha, player = 0;
	int nyepin, rival = 0;
	
	// angka = angka yang ditebak pemain
	// gacha = angka yang di acak 
	// player = berapa kali pemain ke 1 menebak
	// rival = berapa kali pemain ke 2 menebak
	
	srand(time(NULL));
	gacha = rand() % 5 + 1;
	system ("CLS");
	srand(time(NULL));
	nyepin = rand() % gacha < 6;
	
	cout <<"-----------------------------------\n";
	cout << "\t Roulette Number \n";
	cout << "- Rio Sulendra | 2257051026\n";
	cout << "- Kezia Natalia Wongkar | 2217051034\n";
	cout << "- Wayan Santie Arif | 2257051031\n";
	cout <<"-----------------------------------\n";
	cout << " Masukan Angka Yang Ingin ditebak 1-5 \n";
	
	do{
		player++;
		
		cout << " Player 1 Masukan Angka : ";
		cin >> angka;
		
		if(angka < gacha){
			
			cout << "\n\t Salah,Angka terlalu kecil; \n\n";
			
		}else if(angka > gacha){
			
			cout << "\n\t Salah,Angka terlalu besar \n\n";
			
		}
		
	}while(angka != gacha);
	
	cout << "\n\t Benar,anda telah menebak sebanyak " << player << " kali";
	sleep(3);
	system ("CLS");
	cout << "\nMohon Tunggu, Giliran Player 2";
	sleep(5);
	system ("CLS");
	
	do{
		rival++;
		
		cout << " Player 2 Masukan Angka : ";
		cin >> angka;
		
		if(angka < nyepin){
			
			cout << "\n\t Salah,Angka terlalu kecil; \n\n";
			
		}else if(angka > nyepin){
			
			cout << "\n\t Salah,Angka terlalu besar \n\n";
			
		}
		
	}while(angka != nyepin);
	
	cout << "\n\t Benar,anda telah menebak sebanyak " << rival << " kali";
	sleep(5);
	system ("CLS");
	cout << "Pemenangnya adalah : ";
	sleep(5);
	
	if(player < rival){
		cout << "Player 1 Menang";
	}else if(rival < player){
	    cout << "Player 2 Menang";
    }else if(rival == player && player == rival){
    	cout << "Tidak ada (Seri)";
	}
}

void gotoxy(int x, int y)
{
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}
void load()
{
	char a = 219;
	gotoxy(36, 14);
	cout << "Mohon Tunggu..."<< endl;
	gotoxy(30,16);
	for(int r =1; r<=25; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
		sleep(0.5);
	}sleep(3);
}
