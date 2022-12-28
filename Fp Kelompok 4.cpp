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
    string nama, alamat, no_hp;
    long long int no_rek;
	int saldo;
};

void delay (void){
	int delay = 1;
	while (delay < 10000000){
		delay++;
	}
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

rekening nasabah[30] =
{ {"Rafani Bardatus Salsabilah","Jalan Gebang Kidul No 50", "0856254637", 653527328, 5000000},
{"Talitha Aurora Nadenggan Siregar","Jalan Medokan Ayu J-90", "0873625280", 217932803, 7000000},
{"Ahmad Hauzan Abid Romadhon","Jalan Rungkut Raya Blok AA-44", "0832426291", 245378300, 15000000},
{"Dzulfikar Al Ghozali","Jalan Gunung Anyar Indah No 33", "08334561789", 998478939, 12000000},
{"Zain Muzadid Zamzani","Jalan Raya Pandugo Perum C-77", "08456387929", 898737748, 6000000} };
int jum = 5;

void inputdata()
{
	system ("cls");
    char loop;
	gotoxy(67,1);
	cout << "+--------------------------+";
	gotoxy(67,2);
	cout << "|Masukkan Data Nasabah Baru|";
	gotoxy(67,3);
	cout << "+--------------------------+";


	do {
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
		cout << " Saldo \t\t\t: ";
		cin >> nasabah[jum].saldo;
		cout << " ---------------------------------------------------- " << endl;
		cout << "\n Data Berhasil Terinput ! " << endl;

		cout << endl;
		cout << " Apakah Anda Ingin Menambahkan Data Lagi (Y/N) ?  ";
		cin >> loop;
		cout << endl;
		jum++;
	}while (loop == 'Y' || loop == 'y');
}

void tampildata(){
	system("cls");

	gotoxy(67,1);
	cout << "+----------------------------+";
	gotoxy(67,2);
	cout << "|Data Nasabah Bank Cinta Kaya|";
	gotoxy(67,3);
	cout << "+----------------------------+";

	cout << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	cout << "|                Nama                |                Alamat                |          No. HP          |          No. Rekening          |          Saldo         |" << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	for(int j = 0; j < jum; j++)
	{
		cout << "| " << setiosflags(ios::left) << setw(35) << nasabah[j].nama << "|";
		cout << " " << setiosflags(ios::left) << setw(37) << nasabah[j].alamat << "|";
		cout << " " << setiosflags(ios::left) << setw(25) << nasabah[j].no_hp << "|";
		cout << " " << setiosflags(ios::left) << setw(31) << nasabah[j].no_rek << "|";
		cout << " " << setiosflags(ios::left) << setw(23) << nasabah[j].saldo << "|"<< endl;
	}
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
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
	swap(nasabah[terkecil].alamat, nasabah[i].alamat);

	int temp = nasabah[i].saldo;
	nasabah[i].saldo = nasabah[terkecil].saldo;
	nasabah[terkecil].saldo = temp;

	long long int temp1 = nasabah[i].no_rek;
	nasabah[i].no_rek = nasabah[terkecil].no_rek;
	nasabah[terkecil].no_rek = temp1;
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

				int temp = nasabah[j].saldo;
				nasabah[j].saldo = nasabah[j-1].saldo;
				nasabah[j-1].saldo = temp;
            }else
            {
                break;
            }
        }
    }
}

void InsertionSortAsc()
{
    for (int i=1; i<jum; i++)
    {
        for (int j=i; j>0; j--)
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

				int temp = nasabah[j].saldo;
				nasabah[j].saldo = nasabah[j-1].saldo;
				nasabah[j-1].saldo = temp;
            }else
            {
                break;
            }
        }

    }
}


void SortingNo_Rek(){
	int pilih;
	gotoxy(42,9);
	cout << "Sorting Berdasarkan No Rekening";
	gotoxy(42,10);
	cout << "1. Ascending";
	gotoxy(42,11);
	cout <<"2. Descending";
	gotoxy(42,12);
	cout << "Pilih :";
	cin >> pilih;
	if (pilih == 1)
	{
		InsertionSortAsc();
	}else
	{
		InsertionSortDesc();
	}
}

void SortingNama(){
	int pilih;
	gotoxy(42,9);
	cout << "Sorting Berdasarkan Nama Dengan Metode Selection Sort";
	gotoxy(42,10);
	cout << "1. Ascending";
	gotoxy(42,11);
	cout <<"2. Descending";
	gotoxy(42,12);
	cout << "Pilih :";
	cin >> pilih;
	if (pilih == 1)
	{
		SelectionSortAsc();
	}else
	{
		SelectionSortDesc();
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
	SelectionSortAsc();
	string cari;
	fflush(stdin);
	gotoxy(42,9);
	cout << "Masukkan Nama yang Dicari : "; getline(cin, cari);

	int hasil;
	hasil = JumpSearch(cari);
	if (jum==0)
	{
		gotoxy(42,11);
		cout << "+------------+";
		gotoxy(42,12);
		cout << "|Data Kosong |";
		gotoxy(42,13);
		cout << "+------------+";
	}else
	{
		if (hasil == -1)
		{
		gotoxy(42,11);
		cout << "+---------------------+";
		gotoxy(42,12);
		cout << "|Data Tidak Ditemukan |";
		gotoxy(42,13);
		cout << "+---------------------+";
		}else
		{
	system("cls");
	gotoxy(67,1);
	cout << "+----------------------------+";
	gotoxy(67,2);
	cout << "|Data Nasabah Bank Cinta Kaya|";
	gotoxy(67,3);
	cout << "+----------------------------+";

	cout << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	cout << "|                Nama                |                Alamat                |          No. HP          |          No. Rekening          |          Saldo         |" << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
			cout << "| " << setiosflags(ios::left) << setw(35) << nasabah[hasil].nama << "|";
			cout << " " << setiosflags(ios::left) << setw(37) << nasabah[hasil].alamat << "|";
			cout << " " << setiosflags(ios::left) << setw(25) << nasabah[hasil].no_hp << "|";
			cout << " " << setiosflags(ios::left) << setw(31) << nasabah[hasil].no_rek << "|";
			cout << " " << setiosflags(ios::left) << setw(23) << nasabah[hasil].saldo << "|"<< endl;
			cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
		}
		getch();
	}
}

void SukuBunga(){
	SelectionSortAsc();
	string cari;
	fflush(stdin);
	int pilih, hasil, untung;
	char pil;
	gotoxy(42,9);
	cout << "Bunga Deposito Berjangka";
	gotoxy(42,10);
	cout << "Masukkan Nama Nasabah : "; getline(cin, cari);

	hasil = JumpSearch(cari);
	if (hasil == -1)
	{
		gotoxy(42,12);
		cout << "+---------------------+";
		gotoxy(42,13);
		cout << "|Data Tidak Ditemukan |";
		gotoxy(42,14);
		cout << "+---------------------+";
		getch();
	}else
	{
		gotoxy(42,12);
		cout << "1. 6 Bulan";
		gotoxy(42,13);
		cout << "2. 1 Tahun";
		gotoxy(42,14);
		cout << "3. 1 Tahun dan 6 Bulan";
		gotoxy(42,15);
		cout << "4. 2 Tahun";
		gotoxy(42,16);
		cout << "Pilih Jangka Waktu Deposito : "; cin >> pilih;

		if (pilih == 1)
		{
			untung = (nasabah[hasil].saldo * 0.05 * 182) / 365;
		} else if (pilih == 2)
		{
			untung = (nasabah[hasil].saldo * 0.05 * 365) / 365;
		} else if (pilih == 3)
		{
			untung = (nasabah[hasil].saldo * 0.05 * 547) / 365;
		} else if (pilih == 4)
		{
			untung = (nasabah[hasil].saldo * 0.05 * 730) / 365;
		}
		gotoxy(42,18);
		cout << "Dengan Bunga 5% Saldo Awal akan Menjadi Rp " << nasabah[hasil].saldo + untung;
		gotoxy(42,20);
		cout << "Apakah Deposito Dilakukan (Y/N) : "; cin >> pil;
		fflush(stdin);
		if (pil == 'y' || pil == 'Y')
		{
			nasabah[hasil].saldo = nasabah[hasil].saldo + untung;
		}
	}
}

void print(){
	system("cls");
	gotoxy(67,1);
	cout << "+----------------------------+";
	gotoxy(67,2);
	cout << "|Data Nasabah Bank Cinta Kaya|";
	gotoxy(67,3);
	cout << "+----------------------------+";

	cout << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	cout << "|                Nama                |                Alamat                |          No. HP          |          No. Rekening          |          Saldo         |" << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	for(int j = 0; j < jum; j++)
	{
		cout << "| " << setiosflags(ios::left) << setw(35) << nasabah[j].nama << "|";
		cout << " " << setiosflags(ios::left) << setw(37) << nasabah[j].alamat << "|";
		cout << " " << setiosflags(ios::left) << setw(25) << nasabah[j].no_hp << "|";
		cout << " " << setiosflags(ios::left) << setw(31) << nasabah[j].no_rek << "|";
		cout << " " << setiosflags(ios::left) << setw(23) << nasabah[j].saldo << "|"<< endl;
	}
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	getch();
}

int BinarySearch(){
	int kiri = 0;
	int kanan = jum-1;
	int tengah;

	while (kiri <= kanan)
    {
        tengah = (kiri+kanan)/2;
        if (kunci == nasabah[tengah].no_rek)
        {
            return tengah;
        }else if (kunci > nasabah[tengah].no_rek)
        {
            kiri = tengah+1;
        }else
        {
            kanan = tengah-1;
        }
    }
	return -1;
}

void SearchNo_Rek()
{

    SelectionSortAsc();
    if (jum == 0)
    {
    	gotoxy(42,16);
		cout << "+--------------------+";
		gotoxy(42,17);
		cout << "|Data Belum Tersedia |";
		gotoxy(42,18);
		cout << "+--------------------+";
    }else
    {
    	gotoxy(42,9);
		cout << "No Rekening yang Anda cari : ";cin>>kunci;
		int hasil = BinarySearch();
		if (hasil == -1)
		{
    	gotoxy(42,16);
		cout << "+---------------------+";
		gotoxy(42,17);
		cout << "|Data Tidak Ditemukan |";//baru
		gotoxy(42,18);
		cout << "+---------------------+";
		}else{
	system("cls");
	gotoxy(67,1);
	cout << "+----------------------------+";
	gotoxy(67,2);
	cout << "|Data Nasabah Bank Cinta Kaya|";
	gotoxy(67,3);
	cout << "+----------------------------+";

	cout << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
	cout << "|                Nama                |                Alamat                |          No. HP          |          No. Rekening          |          Saldo         |" << endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
			cout << "| " << setiosflags(ios::left) << setw(35) << nasabah[hasil].nama << "|";
			cout << " " << setiosflags(ios::left) << setw(37) << nasabah[hasil].alamat << "|";
			cout << " " << setiosflags(ios::left) << setw(25) << nasabah[hasil].no_hp << "|";
			cout << " " << setiosflags(ios::left) << setw(31) << nasabah[hasil].no_rek << "|";
			cout << " " << setiosflags(ios::left) << setw(23) << nasabah[hasil].saldo << "|"<< endl;
	cout << "+------------------------------------+--------------------------------------+--------------------------+--------------------------------+------------------------+" << endl;
		}
    }
	getch();
}

void HapusNama(){
    SelectionSortAsc();

	string cari;
	fflush(stdin);
	gotoxy(42,15);
	cout << "Masukkan Nama yang Dicari : "; getline(cin, cari);
	int posisi = JumpSearch(cari);
	if (posisi == -1)
	{
		gotoxy(42,16);
		cout << "+--------------------+";
		gotoxy(42,17);
		cout << "|Data Tidak Ditemukan|";
		gotoxy(42,18);
		cout << "+--------------------+";
	}else{
		for(int i=posisi; i<jum; i++){
			nasabah[i] = nasabah[i+1];
		}
		jum--;
		gotoxy(42,16);
		cout << "+---------------------+";
		gotoxy(42,17);
		cout << "|Data Berhasil Dihapus|";
		gotoxy(42,18);
		cout << "+---------------------+";
	}
	getch();
}

void HapusRek(){
    SelectionSortAsc();
	gotoxy(42,15);
	cout << "No Rekening yang Akan Dihapus : ";cin>>kunci;
	int posisi = BinarySearch();
	if (posisi == -1)
	{
		gotoxy(42,16);
		cout << "+--------------------+";
		gotoxy(42,17);
		cout << "|Data Tidak Ditemukan|";
		gotoxy(42,18);
		cout << "+--------------------+";
	}else{
		for(int i=posisi; i<jum; i++){
			nasabah[i] = nasabah[i+1];
		}
		jum--;
		gotoxy(42,16);
		cout << "+---------------------+";
		gotoxy(42,17);
		cout << "|Data Berhasil Dihapus|";
		gotoxy(42,18);
		cout << "+---------------------+";
	}
	getch();
}

void hapusdata(){
	if (jum == 0)
	{
		cout << "Data belum tersedia" << endl;
	}else{
		int pilih;
		gotoxy(42,10);
		cout << "Hapus Data Berdasarkan Nama atau No Rekening";
		gotoxy(42,11);
		cout << "1. Hapus Berdasarkan Nama";
		gotoxy(42,12);
		cout << "2. Hapus Berdasarkan No Rekening";
		gotoxy(42,13);
		cout << "Pilih :";
		cin >> pilih;
		if (pilih == 1)
		{
			HapusNama();
		}else
		{
			HapusRek();
		}
	}
}

int main(){
	menu :
	system("cls");
	cout << "                         +------------------------------------+                     " << endl;
	cout << " -------------------------<<|SISTEM INFORMASI BANK CINTA KAYA|>>-------------------------" << endl;
	cout << "                         +------------------------------------+                     " << endl;
	cout << "\t\t\t+--------------------------------------+" << endl;
	cout << "\t\t\t|PEMROGRAMAN LANJUT KELOMPOK 4 :       |" << endl;
	cout << "\t\t\t+--------------------------------------+" << endl;
	cout << "\t\t\t|DZULFIKAR AL GHOZALI (21081010160)    |" << endl;
	cout << "\t\t\t|TALITHA AURORA N.S. (21081010170)     |" << endl;
	cout << "\t\t\t|RAFANI BARDATUS S. (21081010172)      |" << endl;
	cout << "\t\t\t|ZAIN MUZADID ZAMZAMI (21081010174)    |" << endl;
	cout << "\t\t\t|AHMAD HAUZAN ABID R. (21081010185)    |" << endl;
	cout << "\t\t\t+--------------------------------------+" << endl;

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
		getch();
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
		cout << "7. Hitung Bunga";
		gotoxy(3,14);
		cout << "8. Hapus Data Nasabah";
		gotoxy(3,15);
		cout << "9. Selesai / Logout";

		string pilihan;
		gotoxy(42,7);
		cout << "Masukkan Pilihan Anda : ";
		cin >> pilihan;

if(pilihan == "1"){
			tampildata();
			getch();
			goto choice;
		}else if(pilihan == "2"){
			inputdata();
        	goto choice;
		}else if(pilihan == "3"){
			SortingNama();
			print();
			goto choice;
		}else if(pilihan == "4"){
			SortingNo_Rek();
			print();
			goto choice;
		}else if(pilihan == "5"){
			SearchNama();
			goto choice;
		}else if(pilihan == "6"){
			SearchNo_Rek();
			goto choice;
		}else if(pilihan == "7"){
			SukuBunga();
			goto choice;
		}else if(pilihan == "8"){
			hapusdata();
			goto choice;
		}else if(pilihan == "9"){
			system("cls");
			gotoxy(40,10);
			printf("---THANKS AND HAVE A NICE DAY---");
			gotoxy(40,11);
            printf("-----------KELOMPOK 4-----------\n");
		}else{
			gotoxy(42,9);
        	printf ("Pilihan Anda Tidak Tersedia\n");
        	gotoxy(42,10);
        	printf ("Silakan Pilih Menu yang Tersedia\n");
        	getch();
        	goto choice;
		}

}
