/*  Roulette Number
- Rio Sulendra | 2257051026
- Kezia Natalia Wongkar | 2217051034
- Wayan Santie Arif | 2257051031 */

#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<cstdlib>
#include<curses.h>

using namespace std;

void load();
void gotoxy();

int main()
{
	
	initscr();
	printw("\n\n\t\t\t=========================================\n");
	printw("\t\t\t=-------| SELAMAT DATANG DI TeKa |------=\n");
	printw("\t\t\t=========================================\n\n");
	printw("\t\t\tTekan ENTER untuk melanjutkan...");
	getch();
	endwin();
	
	system("color A");
	load();
	cout << endl << endl << endl << endl << endl << endl << endl;
	int angka, gacha, player = 0;
	int nyepin, rival = 0;
	char name[20], nama[20];
	
	// angka = angka yang ditebak pemain
	// gacha = angka yang di acak 
	// player = berapa kali pemain ke 1 menebak
	// rival = berapa kali pemain ke 2 menebak
	
	system ("CLS");
	system("color F");
	srand(time(NULL));
	gacha = rand() % 5 + 1;
	nyepin = rand() % gacha < 6;
	
	cout<<"\n\n\t\t\tMasukkan Username\n\n";
	cout<<"\t\t\tPlayer 1 : ";
	cin.getline(nama, 20);
	cout<<"\t\t\tPlayer 2 : ";
	cin.getline(name, 20);
	system ("CLS");
	
	

	cout << "\n\n\t\t\tTebak Angka 1 sampai 5\n";
	
	do{
		player++;
		
		cout << "\n\t\t\t" << nama << " masukkan tebakan anda : ";
		cin >> angka;
		
		if(angka < gacha){
			
			cout << "\n\t\t\t\tSalah, angka terlalu kecil (Cobalah masukkan angka yang lebih besar)\n\n";
			
		}else if(angka > gacha){
			
			cout << "\n\t\t\t\tSalah, angka terlalu besar (Cobalah masukkan angka yang lebih kecil)\n\n";
			
		}
		
	}while(angka != gacha);
	
	cout << "\n\t\t\t\tSelamat " << nama <<" telah menebak sebanyak " << player << " kali.";
	sleep(3);
	system ("CLS");
	cout << "\n\n\t\t\tMohon Tunggu, selanjutnya "<< name <<" yang akan menebak.";
	sleep(5);
	system ("CLS");
	
	do{
		rival++;
		
		cout << "\n\n\t\t\t"<< name << " masukkan tebakan anda : ";
		cin >> angka;
		
		if(angka < nyepin){
			
			cout << "\n\t\t\t\tSalah, angka terlalu kecil (Cobalah masukkan angka yang lebih besar)\n\n";
			
		}else if(angka > nyepin){
			
			cout << "\n\t\t\t\tSalah, angka terlalu besar (Cobalah masukkan angka yang lebih kecil)\n\n";
			
		}
		
	}while(angka != nyepin);
	
	cout << "\n\t\t\t\tSelamat " << name <<" telah menebak sebanyak " << rival << " kali.";
	sleep(5);
	system ("CLS");
	cout << "\n\n\t\t\tPemenangnya adalah...\n\n";
	sleep(5);
	
	if(player < rival){
		cout << "\t\t\tSelamat " << nama << " telah memenangkan pertandingan.";
	}else if(rival < player){
	    cout << "\t\t\tSelamat " << name << " telah memenangkan pertandingan.";
    }else if(rival == player && player == rival){
    	cout << "\t\t\tTidak ada, " << nama << " & " << name << " memiliki skor yang sama (Seri).";
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
	gotoxy(36, 4);
	cout << "Mohon Tunggu..."<< endl;
	gotoxy(30, 6);
	for(int r =1; r<=25; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
		sleep(0.5);
	}sleep(3);
}
