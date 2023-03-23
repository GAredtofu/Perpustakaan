#include <iostream> //untuk menggunakan cin cout dll
#include <fstream>  //input database
#include <string>   //aktivasi string
#include <ctime>    //input real time
#include <sstream>  //input 
#include "databuku.h" //untuk menyambungkan file databuku.h

using namespace std;

//PUSAT VARIABEL 
string nama, nama_belakang, pengembalian, jurusan;
string *pinjam_buku;
string a;

//program waktu dan tanggal
time_t detik = time(0);
string waktu = ctime(&detik);

time_t now = time(0);
tm*ltm= localtime(&now);

int bulan = 1 + ltm -> tm_mon;
int tahun = 1900 + ltm -> tm_year;
int tanggal;

//variabel char int dan float 
int menu, jawabpinjam, opsikelas, opsibuku, utama, menumapel, jawabpeminjaman, kategori,menulogin;
int kelas, pilihkelas, jumlah_buku, pilihbuku, buku_p,tipe_novel,tanggal_pengembalian,bulan_pengembalian,opsiakun;
char jawab, jawab_struk, jawab_qbuku, jawab_about, pertanyaan_pengulangan;
char password[15];
float waktu_ambil;

//DEKLARASI VOID
void databuku();
void beranda();
void tipebuku();
void bukupelajaran();
void novel();
void bukupengetahuan();
void struk();
void login();
void login_struk();



int main()
{
    inputlogin: 
    cout << "=======================================" << endl;
    cout << "PERPUSTAKAAN SMKN 1 BOYOLANGU " << endl;
    cout << "=======================================" << endl;
    cout << "SILAHKAN MEMILIH OPSI!!                " << endl;
    cout << "1.Login                                " << endl;
    cout << "2.Create account                       " << endl;
    cout << "=======================================" << endl;
    cout << "INPUT OPSI : " << endl;
    cin  >> opsiakun;
    if (opsiakun == 1 )
    {
        login();
    }
    else if (opsiakun == 2)
    {
    system("cls");
    system("color 2"); //untuk mengganti warna teks
    cout << "=======================================" << endl;
    cout << "PERPUSTAKAAN SMKN 1 BOYOLANGU " << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan nama depan    : "; cin >> nama;
    cout << "masukkan nama belakang : "; cin >> nama_belakang;
    cout << "Masukkan kelas         : "; cin >> kelas;
    cout << "masukkan jurusan       : "; cin >> jurusan;
    cout << "buat password          : "; cin >> password;
    cout << "=======================================" << endl;

    ofstream reg("akun.txt");
    reg << nama << ' ' << nama_belakang << ' ' << kelas << ' ' << jurusan << ' ' << password << endl;

    }
    else 
    {
        cout << "MAAF OPSI SALAH!!" << endl;
        goto inputlogin;
    }


    beranda();


    // sistem back
    cout << "apakah kamu ingin melakukan layanan ini lagi ?";
    cout << "(Y / T)" << endl;
    cin >> jawab;
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

void login()
{
    int count = 0;
    string line;
    string n,nb,c,j,pw;
    string s,ps;
    cout << "==================================" << endl;
    cout << "              LOGIN               " << endl;
    cout << "==================================" << endl;
    cout << "masukkan nama depan : "; cin >> s;
    cout << "masukkan password   : "; cin >> ps;
    cout << "==================================" << endl;

     fstream file("akun.txt");
    while(getline(file, line))
    {
        stringstream ss(line);
        ss >>  n >> nb >> c >> j >> pw;
        if (n == s && ps == pw)
        {
            count = 1;
            break;
        }
    }
    file.close();

    if(count == 1)
    {
        system("cls");
        cout << "LOGIN BERHASIL!" << endl;
        beranda();
    }
    else 
    {
       
        cout << "LOGIN ERROR" << endl;
        cout << "TOLONG MASUKKAN NAMA DAN USERNAME YANG BENAR" << endl;
        system("pause");
        system("cls");
        login();
    }

}


// BERANDA ATAU HALAMAN UTAMA
void beranda()
{
    system("cls");
    cout << "|=======================================|" << endl;
    cout << "|               PERPUSTAKAAN            |" << endl;
    cout << "|=======================================|" << endl;
    cout << "|HALLO SELAMAT DATANG                   |" << endl;
    cout << "|ada yang bisa kami bantu?              |" << endl;
    cout << "|=======================================|" << endl;
    cout << "|apa yang ingin anda lakukan :          |" << endl;
    cout << "|1.peminjaman buku                      |" << endl;
    cout << "|2.Struk peminjaman                     |" << endl;
    cout << "|0.Keluar                               |" << endl;
    cout << "|=======================================|" << endl;
    cout << "input menu : ";
    cin >> menu;
    if (menu == 1)
    {
        tipebuku();
    }
    else if (menu == 2)
    {
        system("cls");
        login_struk();
    }
    else if (menu == 0)
    {
        cout << "Terimakasih telah mencoba layanan kami" << endl;
    }
    else
    {
        cout << "maaf menu yang anda input tidak ada" << endl;
        cout << "apakah kamu ingin melakukan layanan ini lagi ?";
        cout << "(Y / T)" << endl;
        cin >> jawab;
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
            system("cls");
        pertanyaan:
            cout << "maaf opsi salah! ulangi lagi (Y/T) ? : " << endl;
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
                goto pertanyaan;
            }
        }
    }
}

// PEMILIHAN TIPE BUKU!!
void tipebuku()
{
    system("cls");
    cout << "|======================================|" << endl;
    cout << "|               TIPE BUKU              |" << endl;
    cout << "|======================================|" << endl;
    cout << "|1.buku pelajaran                      |" << endl;
    cout << "|2.buku pengetahuan                    |" << endl;
    cout << "|3.Novel                               |" << endl;
    cout << "|4.lainya                              |" << endl;
    cout << "|0.Beranda                             |" << endl;
    cout << "|======================================|" << endl;
    cout << "pilih tipe buku : ";
    cin >> pilihbuku;
    if (pilihbuku == 1)
    {
        bukupelajaran();
    }
    else if (pilihbuku == 2)
    {
        bukupengetahuan();
    }
    else if (pilihbuku == 3)
    {
        novel();
    }
    else if (pilihbuku == 0)
    {
        beranda();
    }
    else
    {
        cout << "maaf menu yang anda pilih tidak ada" << endl;
    }
}

// BERISI TENTANG BUKU PELAJARAN PER-ANGKATAN
void bukupelajaran()
{
    system("cls");
    cout << "|====================================|" << endl;
    cout << "|          PILIH KELAS               |" << endl;
    cout << "|====================================|" << endl;
    cout << "|1.kelas 10                          |" << endl;
    cout << "|2.kelas 11                          |" << endl;
    cout << "|3.kelas 12                          |" << endl;
    cout << "|0.keluar                            |" << endl;
    cout << "|====================================|" << endl;
    cout << "pilih kelas : " << endl;
    cin >> pilihkelas;
    cout << "|====================================|" << endl;

    // kelas 10
    if (pilihkelas == 1)
    {
        system("cls");
        cout << "====================================" << endl;
        cout << "pilih buku pelajaran kelas 10 : " << endl;
        cout << "1.Bahasa indonesia " << endl;
        cout << "2.Bahasa inggris   " << endl;
        cout << "3.Pkn " << endl;
        cout << "====================================" << endl;
        cout << "pilh Mata pelajaran : ";
        cin >> menumapel;
        cout << "====================================" << endl;

        switch (menumapel)
        {
        // BUKU BAHASA INDONESIA
        case 1:
        databuku1:
            pinjam_buku = BindoA;
            for (int i = 0; i <= 3; i++)
            {
                cout << BindoA[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan1:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku1;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan1;
                }
            }
            break;

        // BUKU BAHASA INGGRIS
        case 2:
        databuku2:
            pinjam_buku = BinggrisA;
            for (int i = 0; i <= 3; i++)
            {
                cout << BinggrisA[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan2:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku2;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan2;
                }
            }
            break;

        // BUKU PKN
        case 3:
        databuku3:
            pinjam_buku = PKNA;
            for (int i = 0; i <= 3; i++)
            {
                cout << PKNA[i] << endl;
            }
           cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan3:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku3;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan3;
                }
            }
            break;
        }
    }
    // kelas 11
    else if (pilihkelas == 2)
    {
        system("cls");
        cout << "|====================================|" << endl;
        cout << "|   pilih buku pelajaran kelas 11 :  |" << endl;
        cout << "|====================================|" << endl;
        cout << "|1.Bahasa indonesia                  |" << endl;
        cout << "|2.Bahasa inggris                    |" << endl;
        cout << "|3.Pkn                               |" << endl;
        cout << "|====================================|" << endl;
        cout << "pilh Mata pelajaran : ";
        cin >> menumapel;
        cout << "|====================================|" << endl;

        switch (menumapel)
        {
        // BUKU BAHASA INDONESIA
        case 1:
        system("cls");
        databuku4:
            pinjam_buku = BindoB;
            for (int i = 0; i <= 3; i++)
            {
                cout << BindoB[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan4:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku4;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan4;
                }
            }
            break;

        // BUKU BAHASA INGGRIS
        case 2:
        system("cls");
        databuku5:
            pinjam_buku = BinggrisB;
            for (int i = 0; i <= 3; i++)
            {
                cout << BinggrisB[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan5:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku5;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan5;
                }
            }
            break;

        // BUKU PKN
        case 3:
         system("cls");
        databuku6:
            pinjam_buku = PKNB;
            for (int i = 0; i <= 3; i++)
            {
                cout << PKNB[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan6:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku6;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan6;
                }
            }
            break;
        }
    }
    else if (pilihkelas == 3) // KELAS 12
    {
        system("cls");
        cout << "|====================================|" << endl;
        cout << "|   pilih buku pelajaran kelas 12 :  |" << endl;
        cout << "|====================================|" << endl;
        cout << "|1.Bahasa indonesia                  |" << endl;
        cout << "|2.Bahasa inggris                    |" << endl;
        cout << "|3.Pkn                               |" << endl;
        cout << "|====================================|" << endl;
        cout << "pilh Mata pelajaran : ";
        cin >> menumapel;
        cout << "|====================================|" << endl;

        switch (menumapel)
        {
        // BUKU BAHASA INDONESIA
        case 1:
        databuku7:
            pinjam_buku = BindoC;
            for (int i = 0; i <= 3; i++)
            {
                cout << BindoC[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan7:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku7;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan7;
                }
            }
            break;

        // BUKU BAHASA INGGRIS
        case 2:
        databuku8:
            pinjam_buku = BinggrisC;
            for (int i = 0; i <= 3; i++)
            {
                cout << BinggrisC[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                bukupelajaran();
            }
            else
            {
            pertanyaan8:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku8;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan8;
                }
            }
            break;

        // BUKU PKN
        case 3:
        databuku9:
            pinjam_buku = PKNC;
            for (int i = 0; i <= 3; i++)
            {
                cout << PKNC[i] << endl;
            }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
            cout << "cetak struk (y/t) ? " << endl;
            cin >> jawab_struk;
            if (jawab_struk == 'Y' || jawab_struk == 'y')
            {
                struk();
            }
            else if (jawab_struk == 'T' || jawab_struk == 't')
            {
                beranda();
            }
            else
            {
            pertanyaan9:
                cout << "maaf menu yang anda input tidak ada!" << endl;
                cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
                cin >> pertanyaan_pengulangan;
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
                {
                    goto databuku9;
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else
                {
                    goto pertanyaan9;
                }
            }
            break;
        }
    }
    else if (pilihkelas == 0)
    {
        beranda();
    }
    else
    {
    pertanyaan10:
        cout << "maaf menu yang anda pilih tidak ada!" << endl;
        cout << "apakah ingin mengulangi program ini lagi (y/t) ?";
        cin >> pertanyaan_pengulangan;
        if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
        {
           bukupelajaran();
        }
        else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
        {
            beranda();
        }
        else
        {
            goto pertanyaan10;
        }
    }
}

//PROGRAM PEMINJMANAN BUKU PENGETAHUAN
void bukupengetahuan()
{
    system("cls");
        cout << "|====================================|" << endl;
        cout << "|        pilih buku pengetahuan      |" << endl;
        cout << "|====================================|" << endl;
        cout << "|1.buku python                       |" << endl;
        cout << "|2.buku c++                          |" << endl;
        cout << "|3.buku java                         |" << endl;
        cout << "|0.Keluar                            |" << endl;
        cout << "|====================================|" << endl;
        cout << "pilh Mata pelajaran : ";
        cin >> buku_p;
        cout << "|====================================|" << endl;
    if (buku_p == 1)
    {
    data_pengetahuan1:
        pinjam_buku = bukupython;
        for (int i = 0; i < 3; i++)
        {
            cout << bukupython[i] << endl;
        }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
        cout << "cetak struk (y/t) ? " << endl;
        cin >> jawab_struk;
        if (jawab_struk == 'Y' || jawab_struk == 'y')
        {
            struk();
        }
        else if (jawab_struk == 'T' || jawab_struk == 't')
        {
            bukupengetahuan();
        }
        else
        {
        pertanyaan_bp1:
            cout << "maaf menu yang anda input tidak ada!" << endl;
            cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
            cin >> pertanyaan_pengulangan;
            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                goto data_pengetahuan1;
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();  
            }
            else
            {
                goto pertanyaan_bp1;
            }
        }
    }
    else if (buku_p == 2)
    {
    data_pengetahuan2:
        pinjam_buku = bukucpp;
        for (int i = 0; i < 3; i++)
        {
            cout << bukucpp[i] << endl;
        }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
        cout << "cetak struk (y/t) ? " << endl;
        cin >> jawab_struk;
        if (jawab_struk == 'Y' || jawab_struk == 'y')
        {
            struk();
        }
        else if (jawab_struk == 'T' || jawab_struk == 't')
        {
            bukupengetahuan();
        }
        else
        {
        pertanyaan_bp2:
            cout << "maaf menu yang anda input tidak ada!" << endl;
            cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
            cin >> pertanyaan_pengulangan;
            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                goto data_pengetahuan2;
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
               beranda();
            }
            else
            {
                goto pertanyaan_bp2;
            }
        }
    }

    else if (buku_p == 3)
    {
    data_pengetahuan3:
        pinjam_buku = bukujava;
        for (int i = 0; i < 3; i++)
        {
            cout << bukujava[i] << endl;
        }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
        cout << "cetak struk (y/t) ? " << endl;
        cin >> jawab_struk;
        if (jawab_struk == 'Y' || jawab_struk == 'y')
        {
            struk();
        }
        else if (jawab_struk == 'T' || jawab_struk == 't')
        {
            bukupengetahuan();
        }
        else
        {
        pertanyaan_bp3:
            cout << "maaf menu yang anda input tidak ada!" << endl;
            cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
            cin >> pertanyaan_pengulangan;
            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                goto data_pengetahuan3;
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();
            }
            else
            {
                goto pertanyaan_bp3;
            }
        }
    }
    else if (buku_p == 0)
    {
        beranda();
    }
    else
    {
        pertanyaan_bp:
        cout << "MAAF MENU YANG ANDA PILIH TIDAK ADA!" << endl;
        cout << "APAKAH INGIN MENGULANGI PROGRAM INI LAGI? (Y/T)? : ";
        cin >> pertanyaan_pengulangan;
        if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
        {
            bukupengetahuan();
        }
        else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
        {
            beranda();
        }
        else
        {
            goto pertanyaan_bp;
        }
    }
}

void novel()
{
system("cls");
    cout << "=======================================" << endl;
    cout << "                 NOVEL                 " << endl;
    cout << "=======================================" << endl;
    cout << "1.Awal terjadinya ngawi" << endl;
    cout << "2.Sang Roger sumatera  " << endl;
    cout << "3.dilan 1990           " << endl;
    cout << "0.kembali              " << endl;
    cout << "=======================================" << endl;
    cout << "pilih tipe novel : ";
    cin >> tipe_novel;

    if (tipe_novel == 1)
    {
    datanovel1:
        pinjam_buku = terjadinya_ngawi;
        for (int i = 0; i < 3; i++)
        {

            cout << terjadinya_ngawi[i] << endl;
        }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
        cout << "cetak struk (y/t) ? " << endl;
        cin >> jawab_struk;
        if (jawab_struk == 'Y' || jawab_struk == 'y')
        {
            struk();
        }
        else if (jawab_struk == 'T' || jawab_struk == 't')
        {
            novel();
        }
        else
        {
        pertanyaannovel1:
            cout << "maaf menu yang anda input tidak ada!" << endl;
            cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
            cin >> pertanyaan_pengulangan;
            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                goto datanovel1;
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();
            }
            else
            {
                goto pertanyaannovel1;
            }
        }
    }
    else if (tipe_novel == 2)
    {
    datanovel2:
        pinjam_buku = sang_rogersumatra;
        for (int i = 0; i < 3; i++)
        {
            cout << sang_rogersumatra[i] << endl;
        }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
        cout << "cetak struk (y/t) ? " << endl;
        cin >> jawab_struk;
        if (jawab_struk == 'Y' || jawab_struk == 'y')
        {
            struk();
        }
        else if (jawab_struk == 'T' || jawab_struk == 't')
        {
             novel();
        }
        else
        {
        pertanyaannovel2:
            cout << "maaf menu yang anda input tidak ada!" << endl;
            cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
            cin >> pertanyaan_pengulangan;
            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                goto datanovel2;
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();
            }
            else
            {
                goto pertanyaannovel2;
            }
        }
    }
    else if (tipe_novel == 3)
    {
    datanovel3:
        pinjam_buku = dilan_1990;
        for (int i = 0; i < 3; i++)
        {
            cout << dilan_1990[i] << endl;
        }
            cout << "===============================================================" << endl;
            cout << "nama peminjam : " << nama << endl;
            cout << "kelas         : " << kelas << endl;
            cout << "===============================================================" << endl;
            cout << "                     Tanggal pengambilan pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal;
            cout << "bulan                           : " << bulan << endl; 
            cout << "tahun                           : " << tahun << endl;
            cout << "diambil pada jam                : "; cin >> waktu_ambil;
            cout << "===============================================================" << endl;
            cout << "                    Tanggal pengembalian pada                  " << endl;
            cout << "===============================================================" << endl;
            cout << "tanggal                         : "; cin >> tanggal_pengembalian;
            cout << "bulan                           : "; cin >> bulan_pengembalian;
            cout << "tahun                           : " << tahun << endl;
            cout << "===============================================================" << endl;
        cout << "cetak struk (y/t) ? " << endl;
        cin >> jawab_struk;
        if (jawab_struk == 'Y' || jawab_struk == 'y')
        {
            struk();
        }
        else if (jawab_struk == 'T' || jawab_struk == 't')
        {
            novel();
        }
        else
        {
        pertanyaannovel3:
            cout << "maaf menu yang anda input tidak ada!" << endl;
            cout << "apakah anda ingin mengulangi program ini (Y/T)? : ";
            cin >> pertanyaan_pengulangan;
            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                goto datanovel3;
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();
            }
            else
            {
                goto pertanyaannovel3;
            }
        }
    }
    else if (tipe_novel == 0)
    {
        beranda();
    }
    else
    {
        pertanyaan_novel:
        cout << "MAAF MENU YANG ANDA PILIH TIDAK ADA!" << endl;
        cout << "APAKAH INGIN MENGULANGI PROGRAM INI LAGI? (Y/T)? : ";
        cin >> pertanyaan_pengulangan;
        if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
        {
            novel();
        }
        else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
        {
            beranda();
        }
        else
        {
            goto pertanyaan_novel;
        }
    }
}

void struk() // digunakan untuk mencetak struk
{
    system("cls");
    cout << "|==============================================================================|" << endl;
    cout << "|                            STRUK PEMINJAMAN                                  |" << endl;
    cout << "|==============================================================================|" << endl;
    cout << "|" << waktu                                                                     << endl;   
    cout << "| nama peminjaman                 : " << nama << "-" << nama_belakang      << "|" << endl;
    cout << "| kelas                           : " << kelas << "-" << jurusan           << "|" << endl;
    cout << "|==============================================================================|" << endl;
    cout << "| judul buku                      :" << *pinjam_buku<< "|" << endl;
    cout << "| pengambilan pada                : " << tanggal<<"-"<<bulan<<"-"<< tahun  << "|" << endl;
    cout << "| waktu pengambilan               : " << waktu_ambil << endl;
    cout << "|==============================================================================|" << endl;
    cout << "| pengembalian pada               : "<<tanggal_pengembalian<<"-"<<bulan_pengembalian<<"-"<<tahun<< "|" << endl;
    cout << "| kode verifikasi anda            : ";
    ifstream file("verifnum.txt");
    file >> a;
    cout << "| " << a                                                                   << "|" << endl;
    cout << "| =============================================================================|" << endl;
    ofstream reg("struk.txt",ios::app); //ios::app dapat menambahkan data tanpa menghapus data sebelumnya yang sudah ada
    reg << a << ' ' << nama <<' '<< nama_belakang << ' '<< password << ' ' << kelas <<' '<< jurusan << ' ' << *pinjam_buku << ' ' << tanggal << ' ' <<
    bulan<< ' ' << ' ' << waktu_ambil << ' ' <<  tanggal_pengembalian << ' ' <<   bulan_pengembalian << ' ' << tahun << ' ' << endl;
    //program diatas menunjukkan data dari struk dimasukkan ke dalam "struk.txt". fungsi dari << ' ' << adalah untuk memberikan spasi dalam file "struk.txt"
}

//login untuk mencari struk dari buku yang anda pinjam.
void login_struk()
{
    //variabel
    int count = 0; //
    int ks,tgl,wa,thn,verifn,tgla,blna;
    string n, ns,js, bln,pw,mp;
    string siswa,password_siswa;
    string line;

    system("cls");
    cout << "|=======================================|" << endl;
    cout << "|                  LOGIN                |" << endl;
    cout << "|=======================================|" << endl;
    cout << "|masukkan nama depan    : "; cin  >> siswa;
    cout << "|masukkan password anda : "; cin  >> password_siswa;
    cout << "|=======================================|" << endl;
    ifstream myfile("struk.txt"); //untuk membuka file struk.txt
    //myfile berfungsi membaca file teks yang diinputkan
        while (getline(myfile, line)) {  //line berfungsi untuk menyimpan setiap baris pada file yang akan dibaca 
            stringstream ss(line);
            ss >> verifn >> n >> ns >> pw >> ks >> js >> mp >> tgla >> blna >> wa >> tgl >> bln >> thn;
            if (n == siswa && pw == password_siswa) {
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
            cout << "| verification                    : " << verifn                            << "|" << endl;
            cout << "| nama peminjaman                 : " << n << "-" << ns                    << "|" << endl;
            cout << "| kelas                           : " << ks << "-" << js                   << "|" << endl;
            cout << "| judul buku                      : " << mp                               << "|" << endl;
            cout << "| pengambilan pada                : " << tgla<<"-"<<blna<<"-"<<thn<< "|" << endl;
            cout << "| waktu pengambilan pada          : " << wa << endl;
            cout << "|==============================================================================|"<< endl;
            cout << "| pengembalian pada               : " << tgl << "-" << bln << "-" << thn   << "|" << endl;
            cout << "| =============================================================================|" << endl;
            system("pause"); //untuk menjeda program dan akan muncul "press any key to continue...."
            system("cls");
            beranda();
        }
        else
        {
            cout << "<LOGIN ERROR>\n";
            cout << "Tolong Masukkan Nama Siswa/Username/Password Yang Benar\n";
            cin.get();
            cin.get();
            system("pause");
            login();
        }
}
