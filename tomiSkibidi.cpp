#include <iostream>
#include <string>
using namespace std;

class mahasiswa
{
private:
    static int jumlahMhs;

public:
    string nama;
    // fungsi konstruktor adalah memberikan nilai default awal
    mahasiswa(string pNama) // konstruktor
    {
        nama = pNama;
        ++jumlahMhs;
        cout << "mahasiswa dibuat " << nama << endl;
    }

    ~mahasiswa() // destruktor
    {
        --jumlahMhs;
        cout << "nama terhapus= " << nama << endl;
    }

    static void setJumlah(int pJumlah)
    {
        jumlahMhs = pJumlah;
    }

    static int getJumlahMhs() // method/function dalam bentuk static
    {
        return jumlahMhs;
    }
};

int mahasiswa::jumlahMhs = 0; // static dipanggil

int main()
{
    cout << "jumlah mahasiswa= " << mahasiswa::getJumlahMhs() << endl;

    mahasiswa mhs1("andi");
    mahasiswa mhs2("lulu");
    cout << "jumlah mahasiswa= " << mahasiswa::getJumlahMhs() << endl;
    mahasiswa::setJumlah(5);
    {
        mahasiswa mhs3("husna");
        cout << "jumlah mahasiswa= " << mahasiswa::getJumlahMhs() << endl;
    }

    cout << "jumlah mahasiswa= " << mahasiswa::getJumlahMhs() << endl;
    return 0;
}