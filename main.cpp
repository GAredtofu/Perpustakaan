#include <iostream> //untuk menggunakan cin cout dll
#include <fstream>  //input database
#include <string>   //aktivasi string
#include <ctime>    //input real time
#include <sstream>  //untuk mengolah string atau teks dalam program
#include "databuku.h" //untuk menyambungkan file databuku.h

using namespace std;

//PUSAT VARIABEL
string nama, nama_belakang, pengembalian, jurusan,nma;
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
int bulan_pengembalian;

//variabel char int dan float
int menu, jawabpinjam, opsikelas, opsibuku, utama, menumapel, jawabpeminjaman, kategori,menulogin;
int kelas, pilihkelas, jumlah_buku, pilihbuku, buku_p,tipe_novel,tanggal_pengembalian,opsiakun;
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
void ketentuan_peminjaman();
void struk();
void login();
void login_struk();
void isi_data();

int main()
{
    
    inputlogin:
    system("cls");
    cout << "=======================================" << endl;
    cout << "PERPUSTAKAAN SMKN 1 BOYOLANGU " << endl;
    cout << "=======================================" << endl;
    cout << "SILAHKAN MEMILIH OPSI!!                " << endl;
    cout << "1.Login                                " << endl;
    cout << "2.Create account                       " << endl;
    cout << "3.Guest account                        " << endl;
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
    cout << "=======================================" << endl;
    cout << "PERPUSTAKAAN SMKN 1 BOYOLANGU " << endl;
    cout << "=======================================" << endl;
    cout << "Masukkan nama depan    : "; cin >> nama;
    cout << "masukkan nama belakang : "; cin >> nama_belakang;
    cout << "Masukkan kelas         : "; cin >> kelas;
    cout << "masukkan jurusan       : "; cin >> jurusan;
    cout << "buat password          : "; cin >> password;
    cout << "=======================================" << endl;
    ofstream reg("akun.txt",ios::app);
    reg << nama << ' ' << nama_belakang << ' ' << kelas << ' ' << jurusan << ' ' << password << endl;
    }
    else if (opsiakun == 3)
    {
        beranda();
    }
    else
    {
        cout << "===========================================" << endl;
        cout << "MAAF OPSI SALAH!!" << endl;
        cout << "Silahkan ulangi lagi!!" << endl;
        cout << "===========================================" << endl;
        system("pause");
        goto inputlogin;
    }

    beranda();

    // sistem back
    cout << "apakah kamu ingin melakukan layanan ini lagi ? (Y / T)" << endl;
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
        pertanyaan2:    
        system("cls");
        cout << "maaf opsi salah! ulangi lagi (Y/T) ? ; " << endl;
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
            goto pertanyaan2;
        }
    }
    return 0;
}

void login()
{
    system("cls");
    int count = 0;
    string line;
    string n,nb,c,j,pw;
    string s,ps;
    string nma = s;
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
        nama = n;
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
    cout << "|HALLO SELAMAT DATANG "<< nama     <<"  |" << endl;
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
        exit(0);
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
    cout << "|4.ketentuan peminjaman                |" << endl;
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
    else if (pilihbuku == 4)
    {
        ketentuan_peminjaman();
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
            case 1 : 
            pinjam_buku = BindoA;
            isi_data();
            break;

            case 2 : 
            pinjam_buku = BinggrisA;
            isi_data();
            break;

            case 3 : 
            pinjam_buku = PKNA; 
            isi_data();
            break;
            
            default : 
            cout << "maaf menu yang anda pilih tidak ada" << endl;
            cout << "ulangi lagi (y/t) : ";
            cin >> pertanyaan_pengulangan;

            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan =='Y')
            {
                bukupelajaran();
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();
            }
            else 
            {
                pertanyaan_bp10:
                cout << "maaf menu yang anda inputkan tidak ada!" << endl;
                cout << "ulangi lagi ? (y/t) : ";
                cin >> pertanyaan_pengulangan;   
                if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan =='Y')
                {
                    bukupelajaran();
                }
                else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
                {
                    beranda();
                }
                else 
                {
                    goto pertanyaan_bp10;
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
            case 1 : 
            pinjam_buku = BindoB;
            isi_data();
            break;

            case 2 : 
            pinjam_buku = BinggrisB;
            isi_data();
            break;

            case 3 : 
            pinjam_buku = PKNB;
            isi_data();
            break;
            
            default : 
            pertanyaan_bp11:
            cout << "maaf menu yang anda pilih tidak ada" << endl;
            cout << "ulangi lagi (y/t) ? : ";
            cin  >> pertanyaan_pengulangan;

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
                goto pertanyaan_bp11;
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
            case 1 : 
            pinjam_buku = BindoC;
            isi_data();
            break;

            case 2 : 
            pinjam_buku = BinggrisC;
            isi_data();
            break;

            case 3 : 
            pinjam_buku = PKNC;
            isi_data();
            break;
            
            default:
            pertanyaan_bp:
            cout << "maaf menu yang anda pilih tidak ada" << endl;
            cout << "ulangi lagi (y/t) ? : ";
            cin  >> pertanyaan_pengulangan;

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
                goto pertanyaan_bp;
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
        system("cls");
    pertanyaanbp:
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
            goto pertanyaanbp;
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
        cout << "pilh buku  : ";
        cin >> buku_p;
        cout << "|====================================|" << endl;
    if (buku_p == 1)
    {
        pinjam_buku = bukupython;
        isi_data();
    }
    else if (buku_p == 2)
    {
        pinjam_buku = bukucpp;
        isi_data();
    }
    else if (buku_p == 3)
    {
        pinjam_buku = bukujava;
        isi_data();
    }
    else if (buku_p == 0)
    {
        beranda();
    }
     else {
        pertanyaan_p:
        cout << "maaf menu yang anda pilih tidak ada" << endl;
        cout << "ulangi lagi (y/t) ? : ";
        cin  >> pertanyaan_pengulangan;

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
            goto pertanyaan_p;
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
        pinjam_buku = terjadinya_ngawi;
        isi_data ();
    }
    else if (tipe_novel == 2)
    {
        pinjam_buku = sang_rogersumatra;
        isi_data ();
    }
     else if (tipe_novel == 3)
    {
        pinjam_buku = dilan_1990;
        isi_data ();
    }
    else if (tipe_novel == 0)
    {
        beranda();
    }
    else
    {
        system("cls");
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

void isi_data()
{
    system("cls");
        cout << "===============================================================" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << pinjam_buku[i] << endl;
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
            tipebuku();
        }
        else 
        {
            pertanyaan_salah: 
            cout << "maaf menu yang anda inputkan salah,ulangi lagi (y/t)? ";
            cin  >> pertanyaan_pengulangan;

            if (pertanyaan_pengulangan == 'y' || pertanyaan_pengulangan == 'Y')
            {
                isi_data();
            }
            else if (pertanyaan_pengulangan == 't' || pertanyaan_pengulangan == 'T')
            {
                beranda();
            }
            else 
            {
                goto pertanyaan_salah;
            }
            
        }
}

void ketentuan_peminjaman()
{
    system("cls");
    cout << "=============================================" << endl;
    cout << "            KETENTUAN PEMINJAMAN             " << endl;
    cout << "=============================================" << endl;
    cout << "1.Setiap akhir bulan buku di data ulang!  \n " << endl;
    cout << "2.Setiap Peminjam wajib memperlakukan        " << endl;
    cout << "  buku dengan sebaik-baiknya \n              " << endl;
    cout << "3.Apabila terjadi kerusakan/kehilangan buku  " << endl;
    cout << "  yang dipinjam maka peminjam wajib mengganti" << endl;
    cout << "  buku yang sama                             " << endl; 
    cout << "=============================================" << endl;
    system("pause");
    beranda();
   
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
    cout << a                                                                   << "|" << endl;
    cout << "| =============================================================================|" << endl;
    ofstream reg("struk.txt",ios::app); //ios::app dapat menambahkan data tanpa menghapus data sebelumnya yang sudah ada
    reg << a << ' ' << nama <<' '<< nama_belakang << ' '<< password << ' ' << kelas <<' '<< jurusan << ' ' << *pinjam_buku << ' ' << tanggal << ' ' <<
    bulan<< ' ' << ' ' << waktu_ambil << ' ' <<  tanggal_pengembalian << ' ' << bulan_pengembalian << ' ' << tahun << ' ' << endl;
    //program diatas menunjukkan data dari struk dimasukkan ke dalam "struk.txt". fungsi dari << ' ' << adalah untuk memberikan spasi dalam file "struk.txt"
    system("pause");
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
            stringstream ss(line);  //berfungsi sebagai pembagi data yang sudah tersimpan dalam variabel line
            ss >> verifn >> n >> ns >> pw >> ks >> js >> mp >> tgla >> blna >> wa >> tgl >> bln >> thn;
            if (n == siswa && pw == password_siswa) {
                count = 1;
                break;
            }
        }
        myfile.close(); // untuk menutup FILE  struk.txt
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
            system("pause");
            login();
        }
}
