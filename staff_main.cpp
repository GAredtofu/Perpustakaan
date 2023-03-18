#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "databuku.h"

using namespace std;

//variabel 
char jawab;
int opsi_akun,opsi_databuku,opsi_beranda;
string password,nama,nama_belakang;
int nim;
string judul,penulis,jenis_buku;
int tahun_terbit;
int nomor_buku (10);

//deklarasi void
void login();
    void beranda();
        void verifikasi_peminjaman();
            void menu_buku();
                void tambah_buku();
                    void edit_buku();
                        void data_buku();
                            void hapus_buku();

int main()
{
    inputlogin: 
    cout << "==================================================" << endl;
    cout << "    PERPUSTAKAAN SMKN 1 BOYOLANGU (staff only)    " << endl;
    cout << "==================================================" << endl;
    cout << "SILAHKAN MEMILIH OPSI!!                " << endl;
    cout << "1.Login                                " << endl;
    cout << "2.Create account                       " << endl;
    cout << "3.Guest                                " << endl;
    cout << "==================================================" << endl;
    cout << "INPUT OPSI : "; cin  >> opsi_akun;

    if (opsi_akun == 1)
    {
        system("cls");
        login();
    }
    else if (opsi_akun == 2)
    {
        system("cls");
        ifstream file("akun_staff.txt");
        cout << "==================================================" << endl;
        cout << "         PERPUSTAKAAN SMKN 1 BOYOLANGU            " << endl;
        cout << "==================================================" << endl;
        cout << "Input nama depan   : "; cin >> nama;
        cout << "input nama belakang: "; cin >> nama_belakang;
        cout << "input NIM          : "; cin >> nim;
        cout << "buat password      : "; cin >> password;
        cout << "==================================================" << endl;

        ofstream reg("akun_staff.txt", ios::app);
        reg << nama << ' ' << nama_belakang << ' ' << nim << ' ' << password << ' ' << endl;
    }
    else if (opsi_akun == 3)
    {
        data_buku();
    }
    else 
    {
        cout << "maaf menu yang anda pilih tidak ada!" << endl;
        cout << "silahkan ulangi lagi program ini!!" << endl;
        goto inputlogin;
    }
    

    beranda();

    // sistem back
    cout << "==================================================" << endl;
    cout << "apakah kamu ingin melakukan layanan ini lagi ?";
    cout << "(Y / T)" << endl;
    cin >> jawab;
    cout << "==================================================" << endl;
    if (jawab == 'y' || jawab == 'Y')
    {
        beranda();
    }
    else if (jawab == 't' || jawab == 'T')
    {
        cout << "TERIMAKASIH TELAH MENGGUNAKAN LAYANAN INI!!" << endl;
    }
    else
    {
        system("cls");
    pertanyaan2:
        cout << "maaf opsi salah! ulangi lagi (Y/T) ? ; " << endl;
        if (jawab == 'y' || jawab == 'Y')
        {
           beranda();
        }
        else if (jawab == 't' || jawab == 'T')
        {
            cout << "terimakasih telah menggunakan layanan ini " << endl;
        }
        else
        {
            goto pertanyaan2;
        }
    }
    return 0;
}



//PROGRAM LOGIN 
void login ()
{
    string n,pswd,nb,nm;
    string line;
    string username,pw;
    int count = 0;

    perulangan_login:
    system ("cls");
    cout << "login" << endl;
    cout << "masukkan username : "; cin >> username;
    cout << "masukkan password : "; cin >> pw;

    ifstream file("akun_staff.txt");
    while(getline(file, line))
    {
        stringstream ss(line);
        ss >> n >> nb >> nim >> pswd;

        if (n == username && pswd == pw)
        {
            count = 1;
            break;
        }
    }

    file.close();

    if (count == 1)
    {
        system("cls");
        beranda();
    }
    else 
    {
        cout << "MASUKKAN USERNAME/PASSWORD DENGAN BENAR!" << endl;
        goto perulangan_login;
    }
}

//PROGRAM BERANDA
void beranda ()
{
    cout << "|=======================================|" << endl;
    cout << "                 beranda                 " << endl;
    cout << "|=======================================|" << endl;
    cout << "1.verifikasi peminjaman  " << endl;
    cout << "2.menu buku              " << endl;
    cout << "0.keluar                 " << endl;
   cout << "|=======================================|" << endl;
    cout << "pilih menu : "; cin >> opsi_beranda;

    if (opsi_beranda == 1)
    {
        verifikasi_peminjaman();
    }
    else if (opsi_beranda == 2)
    {
        menu_buku();
    }
    else if (opsi_beranda == 0)
    {
        cout <<" terimakasih telah menggunakan program ini "<< endl;
        return;
    }
    else
    {
        beranda();
        cout << "maaf menu tidak ada" << endl;
        system("cls");
    }
}

//VOID PROGRAM VERIFIKASI PEMINJAMAN
void verifikasi_peminjaman()
{
     //variabel
    int count = 0; //
    int ks,tgl,wa,thn,verifn,tgla,blna,verifcode;
    string n, ns,js, bln,pw,mp;
    string siswa,password_siswa;
    string line;

    system("cls");
    cout << "|=======================================|" << endl;
    cout << "           VERIFIKASI PEMINJAMAN         " << endl;
    cout << "|=======================================|" << endl;
    cout << "|masukkan nama depan    : "; cin  >> siswa;
    cout << "|masukkan kode verifikasi anda : "; cin >> verifcode;
    cout << "|=======================================|" << endl;
    ifstream myfile("struk.txt"); //untuk membuka file struk.txt
    //myfile berfungsi membaca file teks yang diinputkan
        while (getline(myfile, line)) {  //line berfungsi untuk menyimpan setiap baris pada file yang akan dibaca 
            stringstream ss(line);
            ss >> verifn >>  n >> ns >> pw >> ks >> js >> mp >> tgla >> blna >> wa >> tgl >> bln >> thn;
            if ( verifn == verifcode  && n == siswa ) {
                count = 1;
                break;
            }
        }

        myfile.close(); // untuk menutup struk.txt

        if (count == 1)                                  
        {
            system("cls");
            cout << "<<<<LOGIN BERHASIL>>>>" << endl;
            cout << "halo" << n << ", struk anda : "<< endl;
            cout << "|==============================================================================|" << endl;
            cout << "|                            STRUK PEMINJAMAN                                  |" << endl;
            cout << "|==============================================================================|" << endl;
            cout << "| nama peminjaman                 : " << n << "-" << ns                    << "|" << endl;
            cout << "| kelas                           : " << ks << "-" << js                   << "|" << endl;
            cout << "| judul buku                      : " << mp                               << "|" << endl;
            cout << "| pengambilan pada                : " << tgla<<"-"<<blna<<"-"<<thn<< "|" << endl;
            cout << "| waktu pengambilan pada          : " << wa << endl;
            cout << "|==============================================================================|"<< endl;
            cout << "| pengembalian pada               : " << tgl << "-" << bln << "-" << thn   << "|" << endl;
            cout << "| verification                    : " << verifn                            << "|" << endl;
            cout << "| =============================================================================|" << endl;
            system("pause"); //untuk menjeda program dan akan muncul "press any key to continue...."
            system("cls");
            beranda();
        }
        else
        {
            cout << "<LOGIN ERROR>\n";
            cout << "Tolong Masukkan Nama Siswa/Username/kode verifikasi Yang Benar\n";
            cin.get();
            cin.get();
            system("pause");
            verifikasi_peminjaman();
        }
}

//PROGRAM MENU BUKU
void menu_buku ()
{
    char pertanyaan1;

    system("cls");
    cout << "======================================" << endl;
    cout << "               MENU BUKU              " << endl;
    cout << "======================================" << endl;
    cout << "1. Tambah Buku " << endl;
    cout << "2. Edit Buku " << endl;
    cout << "3. hapus Buku " << endl;
    cout << "4. lihat data buku" << endl;
    cout << "0.kembali ke beranda" << endl;
    cout << "======================================" << endl;
    cout << "opsi : "; cin >> opsi_databuku;
      
      if (opsi_databuku == 1)
      {
        tambah_buku();
      }
      else if (opsi_databuku == 2)
      {
        edit_buku();
      }
      else if (opsi_databuku == 3)
      {
        hapus_buku();
      }
      else if(opsi_databuku == 4)
      {
        data_buku();
      }
      else if (opsi_databuku == 0)
      {
        beranda();
      }
      else
      {
        pertanyaan_perulangan1:
        cout << "OPSI YANG ANDA PILIH SALAH!" << endl;
        cout << "apakah anda ingin mengulangi lagi (y/t) ? : ";
        cin  >> pertanyaan1;

        if (pertanyaan1 == 'Y' || pertanyaan1 == 'y')
        {
            menu_buku();
            system("cls");
        }
        else if (pertanyaan1 == 't' || pertanyaan1 == 'T')
        {
            beranda();
        }
        else 
        {
            goto pertanyaan_perulangan1;
            system("cls");
        }
      }
}

//PROGRAM UNTUK MENAMBAH DATA BUKU
void tambah_buku()
{
    system("cls");
    cout << "==================================================" << endl;
    cout << "                   TAMBAH BUKU                    " << endl;
    cout << "==================================================" << endl;
    cout << "Judul buku          : "; cin >> judul;
    cout << "Nama pengarang      : "; cin >> penulis;
    cout << "tahun terbit        : "; cin >> tahun_terbit;
    cout << "jenis buku          : "; cin >> jenis_buku;
    cout << "masukkan nomor buku : "; cin >> nomor_buku;
    cout << "==================================================" << endl;
    
    ofstream reg("database_buku.txt",ios::app);
    reg << judul << ' ' << penulis << ' ' << tahun_terbit << ' ' <<jenis_buku << ' ' << nomor_buku << endl;

    cout << "DATA BERHASIL DITAMBAHKAN!!" << endl;
    system("pause");
    beranda();
}

void edit_buku ()
{
    string line;
    string find;
    string judul_baru,penulis_baru,tahun_terbit_baru,nomor_buku_baru,jenis_buku_baru;

    fstream myfile("database_buku.txt");

    system("cls");
    cout << "EDIT DATA BUKU" << endl;
    cout << "masukkan judul buku yang akan diedit : ";
    cin  >> find;

    while(getline(myfile, line))
    {
        stringstream ss(line);
        ss >> judul >> penulis >> tahun_terbit >> nomor_buku;

        if (judul == find)
        {
            cout << "masukkan judul : ";
            cin  >> judul_baru;
            cout << "masukkan nama penulis : ";
            cin  >> penulis_baru;
            cout << "masukkan tahun terbit : ";
            cin >> tahun_terbit_baru;
            cout << "masukkan jenis buku : ";
            cin  >> jenis_buku_baru;
            cout << "masukkan kode buku : ";
            cin  >> nomor_buku_baru;
            ofstream reg("database_buku.txt", ios::app);
            reg << judul_baru << ' ' << penulis_baru << ' ' << tahun_terbit_baru << ' ' << nomor_buku_baru;
        } 
    }
    myfile.close();
    system("pause");
    beranda();
}

//program untuk menampilkan data buku
void data_buku()
{
    string judul, pengarang, tahun_terbit;
    string line;
    ifstream myfile("database_buku.txt");
    
    system("cls");
    cout << "|====================================================================================================================|" << endl;
    cout << "|       JUDUL        |       NAMA PENGARANG      |        TAHUN TERBIT      |       JENIS BUKU     |    NOMOR BUKU   |" << endl;
    cout << "|====================================================================================================================|" << endl;
    while (getline(myfile , line)) {
         stringstream ss(line);
        ss >> judul >> pengarang >> tahun_terbit >> jenis_buku >> nomor_buku;
         cout << "|" << setw (20) << left <<judul 
         << "|" << setw (27) << left << pengarang 
         << "|" << setw (26) << left << tahun_terbit  
         << "|" << setw (22) << left << jenis_buku 
         << "|" << setw (17) << left << nomor_buku 
         << "|" << endl;
        }
    cout << "|====================================================================================================================|" << endl;

    myfile.close(); //berfungsi untuk menutup file

    cout << "JIKA MENEKAN SEMUA TOMBOL MAKA PROGRAM AKAN KEMBALI KE HALAMAN AWAL!!" << endl;
    system("pause");
    beranda();
}

//DELETE DATA BUKU
void hapus_buku()
{
    string filename = "database_buku.txt";
    ifstream input_file(filename);
    ofstream output_file("temp.txt");

    int line_number = 2; // the line number you want to delete

    string line;
    int count = 0;
    while (getline(input_file, line)) {
        count++;
        if (count != line_number) {
            output_file << line << endl;
        }
    }

    input_file.close();
    output_file.close();

    remove(filename.c_str()); // delete the original file
    rename("temp.txt", filename.c_str()); // rename the temp file to the original file name
}
