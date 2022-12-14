/*  Roulette Number
- Rio Sulendra | 2257051026
- Kezia Natalia Wongkar | 2217051034
- Wayan Santie Arif | 2257051031 */

#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <curses.h>

using namespace std;

void header()
{
	cout << "\n=========================================\n";
	cout << "=---------| Teka (Tebak Angka) |--------=\n";
	cout << "=========================================\n";
 }
 
 void peraturan()
 {
 	system("CLS");
 	cout << "\n==================================================================================================\n";
	cout << "=                                                                                                =\n";
	cout << "=                                  PETUNJUK PERMAINAN                                            =\n";
	cout << "=                                                                                                =\n";
	cout << "==================================================================================================\n";
	cout << "=                                                                                                =\n";
	cout << "=  1. Pemain di perbolehkan menebak sampai tebakan pemain benar.                                 =\n";
	cout << "=  2. Pemain yang memiliki tebakan yang salah terbanyak maka dia akan kalah.                     =\n";
	cout << "=  3. Pemain yang memiliki tebakan paling sedikit maka dia yang memenangkan pertandingan.        =\n";
	cout << "=  4. Pemain dapat menebak angka secara bebas dari 1 sampai 5.                                   =\n";
	cout << "=                                                                                                =\n";
	cout << "==================================================================================================\n\n";
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
	system("color A");
	char a = 219;
	gotoxy(13, 2);
	cout << "Mohon Tunggu...\n"<< endl;
	gotoxy(7, 4);
	for(int r =1; r<=25; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
		Sleep(1);
	}sleep(1.5);
	system ("CLS");
	system("color F");
}

int main()
{
	initscr();
	printw("\n=========================================\n");
	printw("=-------| SELAMAT DATANG DI TeKa |------=\n");
	printw("=========================================\n\n");
	printw("Tekan ENTER untuk melanjutkan...");
	getch();
	endwin();
	
	load();
	
	int angka, gacha, player = 0;
	int nyepin, rival = 0;
	char name[20], nama[20], repeat;
	
	srand(time(NULL));
	gacha = rand() % 5 + 1;
	nyepin = rand() % gacha < 6;
	
	header();
	cout<<"\nMasukkan Username\n\n";
	cout<<"Player 1 : ";
	cin.getline(nama, 20);
	cout<<"Player 2 : ";
	cin.getline(name, 20);
	system ("CLS");
	
	do
	{
		peraturan ();
		do{
			player++;
		
			cout << "\n" << nama << " masukkan tebakan anda : ";
			cin >> angka;
		
			if(angka < gacha){
			
				cout << "\n\tSalah, angka terlalu kecil (Cobalah masukkan angka yang lebih besar)\n\n";
			
			}else if(angka > gacha){
			
				cout << "\n\tSalah, angka terlalu besar (Cobalah masukkan angka yang lebih kecil)\n\n";
			
			}
		
		}while(angka != gacha);
	
		cout << "\n\tSelamat " << nama <<" telah menebak sebanyak " << player << " kali.";
		sleep(1);
		system ("CLS");
		
		load();
	
		peraturan ();
		do{
			rival++;
		
			cout << "\n"<< name << " masukkan tebakan anda : ";
			cin >> angka;
		
			if(angka < nyepin){
			
				cout << "\n\tSalah, angka terlalu kecil (Cobalah masukkan angka yang lebih besar)\n\n";
			
			}else if(angka > nyepin){
			
				cout << "\n\tSalah, angka terlalu besar (Cobalah masukkan angka yang lebih kecil)\n\n";
			
			}
		
		}while(angka != nyepin);
	
		cout << "\n\tSelamat " << name <<" telah menebak sebanyak " << rival << " kali.";
		sleep(1);
		system ("CLS");
		
		header();
		cout << "\nPemenangnya adalah...\n\n";
		sleep(3);
	
		if(player < rival){
			cout << "Selamat " << nama << " telah memenangkan pertandingan.\n\n";
		}else if(rival < player){
		    cout << "Selamat " << name << " telah memenangkan pertandingan.\n\n";
   		}else if(rival == player && player == rival){
  		  	cout << "Tidak ada, " << nama << " & " << name << " memiliki skor yang sama (Seri).\n\n";
		}
		
		cout<<"Apakah Anda ingin bermain lagi ( y / n ) : ";
		cin>>repeat;
		if(repeat == 'y'){
			player = 0;
			rival = 0;
		}
		system("CLS");
	}while(repeat!='n');
	cout << "\n========================================\n";
	cout << "=----------| Enjoy Your Game |---------=\n";
	cout << "========================================\n";

	
}
