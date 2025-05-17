#include <iostream>
#include <string>
using namespace std;

class Mahasiswa;

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string n, string id, string p, float g) : nama(n), NIDN(id), pangkat(p), gaji(g) {}

    void beriNilai(Mahasiswa *m, float nilai);

    friend float aksesGajiDosen(Dosen *d); // friend function, didefinisikan di class Universitas

    string getPangkat()
    {
        return pangkat;
    }

    void setPangkat(string p)
    {
        pangkat = p;
    }

    string getNama()
    {
        return nama;
    }
};

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string nim) : nama(n), NIM(nim), nilai(0) {}

    friend class Dosen; // Dosen bisa akses private members

    void tampilkan()
    {
        cout << "Nama: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }
};

void Dosen::beriNilai(Mahasiswa *m, float nilai)
{
    m->nilai = nilai;
}

class Staff
{
private:
    string nama;
    string ID;
    float gaji;

public:
    Staff(string n, string id, float g) : nama(n), ID(id), gaji(g) {}

    void ubahPangkat(Dosen *d, string pangkatBaru)
    {
        d->setPangkat(pangkatBaru);
    }

    friend float lihatGajiStaff(Staff *s); // didefinisikan di class Universitas
};

float aksesGajiDosen(Dosen *d)
{
    return d->gaji;
}

float lihatGajiStaff(Staff *s)
{
    return s->gaji;
}

int main()
{
    Mahasiswa mhs("Ali", "123456");
    Dosen dosen("Pak Budi", "001122", "Lektor", 8000000);
    Staff staff("Bu Rani", "STF001", 5000000);

    dosen.beriNilai(&mhs, 85);
    mhs.tampilkan();

    cout << "Gaji Dosen: " << aksesGajiDosen(&dosen) << endl;
    cout << "Gaji Staff: " << lihatGajiStaff(&staff) << endl;

    cout << "Pangkat Dosen sebelum diubah: " << dosen.getPangkat() << endl;
    staff.ubahPangkat(&dosen, "Guru Besar");
    cout << "Pangkat Dosen setelah diubah oleh Staff: " << dosen.getPangkat() << endl;

    return 0;
}
