#include <Windows.h> //system
#include <iostream>
#include <iomanip>
#include <stdio.h> //printf
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;

struct rekening{
    string nama, no_hp, alamat;
    int no_rek;
};

rekening nasabah[30];
int jum = 0;

void inputdata()
{
	system ("cls");
    char loop;
	cout << " \t\tData Nasabah Bank " << endl;
	cout << " ==================================================== " << endl;
	do 
	{
		system ("cls");
		cout << " Data Nasabah ke-" << jum + 1 << endl;
		cout << " Nama \t\t\t: "; 
		getline (cin >> ws, nasabah[jum].nama);
		cout << " Alamat \t\t: "; 
		getline (cin >> ws, nasabah[jum].alamat);
		cout << " No. HP \t\t: "; 
		getline (cin >> ws, nasabah[jum].no_hp);
		cout << " No. Rekening \t\t: "; 
		cin >> nasabah[jum].no_rek;
		cout << " ---------------------------------------------------- " << endl;
		
		cout << endl;
		cout << "=========================================================================================================================================" << endl;
		cout << "|                Nama                |                Alamat                |          No. HP          |          No. Rekening          | " << endl;
		cout << "=========================================================================================================================================" << endl;
		for(int j = 0; j <= jum; j++)
		{
			cout << "| " << setiosflags(ios::left) << setw(35) << nasabah[j].nama << "|"; 
			cout << " " << setiosflags(ios::left) << setw(37) << nasabah[j].alamat << "|"; 
			cout << " " << setiosflags(ios::left) << setw(25) << nasabah[j].no_hp << "|"; 
			cout << " " << setiosflags(ios::left) << setw(31) << nasabah[j].no_rek << "|"<< endl;
		}
		
		cout << endl;
		cout << " Apakah Anda Ingin Menambahkan Data (Y/N) ?  ";
		cin >> loop;
		cout << endl;
		jum++;	
	}while (loop == 'Y' || loop == 'y');
}

void delay (void){
	int delay = 1;
	while (delay < 1000000){
		delay++;
	}
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void loadingScreen (string nama){
	system("cls");
    printf("\e[?25l");

    //Set ASCII to print special character.
    //Code page 437
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;

	for (int i = 1; i <= 100; i++){
		gotoxy(40,10);
		cout << "L O A D I N G . . . ." << i << "%";
		delay();
	}
	cout << endl;

	gotoxy(40,11);
    for(int i = 0; i < 25; i++)
    cout << (char)bar1;
    cout <<"\r";
    gotoxy(40,11);
    for(int i = 0; i < 25; i++){
        cout << (char)bar2;
        Sleep(150);
    }
    gotoxy(40,13);
    cout<<"Selamat Datang " << nama << endl;
    gotoxy(40,14);
    cout << "Have A Nice Day !" << endl;
    getch();
}

int login(string data[], int akhir, string cari)
{
	int awal, tengah, b_flag = 0;
	awal = 0;
	while (b_flag == 0 && awal<=akhir)
    {
        tengah = (awal + akhir)/2;
        if(data[tengah] == cari)
        {
            b_flag = 1;
            return tengah;
        }
        else if(data[tengah]<cari){
            awal = tengah + 1;
        }else{
            akhir = tengah -1;
        }
    }
   return -1;
}

void tukar(int i, int terkecil){
	swap(nasabah[terkecil].nama, nasabah[i].nama);
	swap(nasabah[terkecil].no_hp, nasabah[i].no_hp);
	swap(nasabah[terkecil].no_rek, nasabah[i].no_rek);

	int temp = nasabah[i].no_rek;
	nasabah[i].no_rek = nasabah[terkecil].no_rek;
	nasabah[terkecil].no_rek = temp;
}

void SelectionSortAsc(){
	int terkecil = 0;
    for(int i=0; i<jum; i++){
        terkecil=i;
        for(int j=0; j<jum-1; j++){
            if(nasabah[terkecil].nama < nasabah[j].nama){
                terkecil = j;
            }
			tukar(i, terkecil);
        }
    }
}

void SelectionSortDesc(){
	int terkecil = 0;
    for(int i=0; i<jum; i++){
        terkecil=i;
        for(int j=0; j<jum-1; j++){
            if(nasabah[terkecil].nama > nasabah[j].nama){
                terkecil = j;
            }
			tukar(i, terkecil);
        }
    }
}

void SortingNama(){
	system("cls");
	int pilih;
	cout << "\t\tSorting Berdasarkan Nama Dengan Metode Selection Sort\n\n";
	cout << "\n1. Ascending\n2. Descending\nPilih :";
	cin >> pilih;
	if (pilih == 1)
	{
		SelectionSortAsc();
	}else
	{
		SelectionSortDesc();
	}
}

string temp2,temp3,temp4;
long long int temp1,kunci;

void InsertionSortDesc()
{
    for (int i=1; i<jum; i++)
            {
                for (int j=i; j>0; j--)
                {
                    if (nasabah[j].no_rek>nasabah[j-1].no_rek)
                    {
                        temp1=nasabah[j].no_rek;
                        nasabah[j].no_rek=nasabah[j-1].no_rek;
                        nasabah[j-1].no_rek=temp1;

                        temp2=nasabah[j].nama;
                        nasabah[j].nama=nasabah[j-1].nama;
                        nasabah[j-1].nama=temp2;

                        temp3=nasabah[j].no_hp;
                        nasabah[j].no_hp=nasabah[j-1].no_hp;
                        nasabah[j-1].no_hp=temp3;

                        temp4=nasabah[j].alamat;
                        nasabah[j].alamat=nasabah[j-1].alamat;
                        nasabah[j-1].alamat=temp4;
                    }else
                    {
                        break;
                    }
                }

            }
}

void BubbleSortAsc()
{
    for (int i=0; i<jum; i++)
            {
                for (int j=1; j<jum; j++)
                {
                    if (nasabah[j].no_rek<nasabah[j-1].no_rek)
                    {
                        temp1=nasabah[j].no_rek;
                        nasabah[j].no_rek=nasabah[j-1].no_rek;
                        nasabah[j-1].no_rek=temp1;

                        temp2=nasabah[j].nama;
                        nasabah[j].nama=nasabah[j-1].nama;
                        nasabah[j-1].nama=temp2;

                        temp3=nasabah[j].no_hp;
                        nasabah[j].no_hp=nasabah[j-1].no_hp;
                        nasabah[j-1].no_hp=temp3;

                        temp4=nasabah[j].alamat;
                        nasabah[j].alamat=nasabah[j-1].alamat;
                        nasabah[j-1].alamat=temp4;
                    }
                }

            }
}

void SortingNo_Rek(){
	system("cls");
	int pilih;
	cout << "\t\tSorting Berdasarkan No Rekening \n\n";
	cout << "\n1. Ascending\n2. Descending\nPilih :";
	cin >> pilih;
	if (pilih == 1)
	{
		BubbleSortAsc();
	}else
	{
		InsertionSortDesc();
	}
}

int JumpSearch(string cari){
	int ukuran = jum - 1;
	int kiri = 0;
	int kanan = sqrt(ukuran);

	while (nasabah[kanan].nama <= cari && kanan < ukuran)
	{
		kiri = kanan;
		kanan += sqrt(ukuran);

		if(kanan > ukuran-1){
			kanan = ukuran;
		}
	}

	for (int i = kiri; i < kanan; i++)
	{
		if (nasabah[i].nama == cari)
		{
			return i;
		}
	}
	return -1;
}

void SearchNama(){
	system("cls");
	SelectionSortAsc();
	string cari;
	fflush(stdin);
	cout << "Masukkan Nama yang Dicari : "; getline(cin, cari);

	int hasil;
	hasil = JumpSearch(cari);
	if (jum==0)
	{
		cout << "\n\nData Kosong\n\n";
	}else
	{
		if (hasil == -1)
		{
			cout << "\n\nData Tidak Ditemukan\n\n";
		}else
		{
			system("cls");
			cout << endl;
			cout << "=========================================================================================================================================" << endl;
			cout << "|                Nama                |                Alamat                |          No. HP          |          No. Rekening          | " << endl;
			cout << "=========================================================================================================================================" << endl;
			cout << "| " << setiosflags(ios::left) << setw(35) << nasabah[hasil].nama << "|"; 
			cout << " " << setiosflags(ios::left) << setw(37) << nasabah[hasil].alamat << "|"; 
			cout << " " << setiosflags(ios::left) << setw(25) << nasabah[hasil].no_hp << "|"; 
			cout << " " << setiosflags(ios::left) << setw(31) << nasabah[hasil].no_rek << "|"<< endl;
		}	
		system ("pause");
	}
}

int kiri = 0;
int kanan = jum-1;
int tengah;
void searchNo_Rek()
{
    system("cls");
    if (nasabah[0].no_rek == NULL )
    {
        cout << "Data belum tersedia" << endl;
    }else
    {
        SelectionSortAsc();

        cout << "==============================================================" << endl;
        cout << "|     Nama     |     No HP     |    Alamat    |    No Rek    |" << endl;
        cout << "==============================================================" << endl;
        while (kiri <= kanan)
        {
            tengah = (kiri+kanan)/2;
            if (kunci == nasabah[tengah].no_rek)
            {
                cout <<"|"<<setw(14)<<nasabah[tengah].nama;
                cout <<"|"<<setw(15)<<nasabah[tengah].no_hp;
                cout <<"|"<<setw(15)<<nasabah[tengah].alamat;
                cout <<"|"<<setw(15)<<nasabah[tengah].no_rek<<"|";
                cout << endl;

                break;

            }else if (kunci > nasabah[tengah].no_rek)
            {
                kiri = tengah+1;
            }else
            {
                kanan = tengah-1;
            }
        }
    }

}

int main(){
	menu :
	system("cls");
	cout << "                   +--------------------------------+                     " << endl;
	cout << "-----------------<<|SISTEM INFORMASI BANK CINTA KAYA|>>-------------------" << endl;
	cout << "                   +--------------------------------+                     " << endl;
	cout << "+----------------------------------------+" << endl;
	cout << "|PEMROGRAMAN LANJUT KELOMPOK 4 :         |" << endl;
	cout << "+----------------------------------------+" << endl;
	cout << "|DZULFIKAR AL GHOZALI (21081010160)      |" << endl;
	cout << "|TALITHA AURORA N.S. (21081010170)       |" << endl;
	cout << "|RAFANI BADRATUS SALSABILA (21081010172) |" << endl;
	cout << "|ZAIN MUZADID ZAMZAMI (21081010174)      |" << endl;
	cout << "|AHMAD HAUZAN ABID R. (21081010185)      |" << endl;
	cout << "+----------------------------------------+" << endl;

	string npm[5];
	npm[0]= "21081010160";
	npm[1]= "21081010170";
	npm[2]= "21081010172";
	npm[3]= "21081010174";
	npm[4]= "21081010185";

	string nama[5];
	nama[0]= "DZULFIKAR" ;
	nama[1]= "TALITHA" ;
	nama[2]= "RAFANI" ;
	nama[3]= "ZAIN" ;
	nama[4]= "ABID" ;

	int  p;
	string c;
	cout << "Silakan Login Terlebih Dahulu" << endl;
	cout << "Masukkan NPM : ";
	cin >> c;
	p = login(npm, 5, c);
	if (p == -1){
		cout << "+--------------------------------------------+" << endl;
		cout << "|Login Gagal! NPM Anda Salah/ Tidak Tersedia |" << endl;
		cout << "+--------------------------------------------+" << endl;
		cout << "SILAKAN COBA LAGI" << endl;
		system("Pause");
		goto menu;
	}else{
		string akun = nama[p];
		loadingScreen(akun);
	}
	choice :
	system("cls");

	//bingkai menu
	for(int i = 2; i < 100; i++){
		gotoxy(i,1);	cout << "-";
		gotoxy(i,5);	cout << "-";
		gotoxy(i,26);	cout << "-";
		gotoxy(i,30);	cout << "-";

	}

	for(int i = 2; i <= 30; i++){
		gotoxy(1,i);	cout << "|";
		gotoxy(100,i);	cout << "|";
	}

	for(int i = 5; i <= 26; i++){
		gotoxy(40,i);	cout << "|";

	}
		gotoxy(1,1);	cout << "+";
		gotoxy(1,5);	cout << "+";
		gotoxy(1,26);	cout << "+";
		gotoxy(1,30);	cout << "+";
		gotoxy(100,1);	cout << "+";
		gotoxy(100,5);	cout << "+";
		gotoxy(100,26);	cout << "+";
		gotoxy(100,30);	cout << "+";
		gotoxy(40,5); 	cout << "+";
		gotoxy(40,26); 	cout << "+";

		//Teks
		gotoxy(33,3);
		cout << "SISTEM INFORMASI BANK CINTA KAYA";
		gotoxy(31,28);
		cout << "PEMROGRAMAN LANJUT E081 KELOMPOK 4";

		//Main Menu
		gotoxy(3,7);
		cout << "1. Cek Data Nasabah";
		gotoxy(3,8);
		cout << "2. Tambah Data Nasabah";
		gotoxy(3,9);
		cout << "3. Sorting Berdasarkan Nama";
		gotoxy(3,10);
		cout << "4. Sorting Berdasarkan No Rekening";
		gotoxy(3,11);
		cout << "5. Searching Berdasarkan Nama";
		gotoxy(3,12);
		cout << "6. Searching Berdasarkan No Rekening";
		gotoxy(3,13);
		cout << "7. Selesai / Logout";

		int pilihan;
		gotoxy(42,7);
		cout << "Masukkan Pilihan Anda : ";
		cin >> pilihan;

		if(pilihan > 0 && pilihan < 8){
		switch(pilihan){
			case 1 :
			break;

			case 2 :
			inputdata();
        	goto choice;
			break;

			case 3 :
			SortingNama();
			goto choice;
			break;

			case 4 :
			SortingNo_Rek();
			break;

			case 5 :
			SearchNama();
			goto choice;
			break;

			case 6 :
			searchNo_Rek();
			break;

			case 7 :
			system("cls");
			gotoxy(40,10);
			printf("---THANKS AND HAVE A NICE DAY---");
			gotoxy(40,11);
            printf("-----------KELOMPOK 4-----------\n");
            getch();
		}
		}else {
			gotoxy(42,9);
        	printf ("Pilihan Anda Tidak Tersedia\n");
        	gotoxy(42,10);
        	printf ("Silakan Pilih Menu yang Tersedia\n");
        	getch();
        	goto choice;
    	}



	getch();
}
