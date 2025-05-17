#include <iostream>
using namespace std;

class angka
{
private:
    int *arr;
    int panjang;

public:
    angka(int); // constructor
    ~angka();   // destructor
    void cetakData();
    void isiData();
};

// definisi member function
angka::angka(int i) // constructor
{
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::cetakData()
{
    for (int i = 1; i <= panjang; i++)
    {
        cout << i << " = " << arr[i] << endl;
    }
}