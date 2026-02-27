STUDI KASUS

1. Buatlah flowchart, pseudocode, dan program yang meminta input Tahun (angka)
dari pengguna. Program harus menentukan apakah tahun tersebut termasuk Tahun
Kabisat atau Bukan Tahun Kabisat dengan ketentuan:
● Jika tahun habis dibagi 400, maka Kabisat.
● Jika tidak habis dibagi 400, tetapi habis dibagi 100, maka Bukan Kabisat.
● Jika tidak habis dibagi 100, tetapi habis dibagi 4, maka Kabisat.
● Selain itu, maka Bukan Kabisat.

2. Buatlah flowchart, pseudocode. dan program kasir sederhana yang memungkinkan
pengguna memasukkan Harga Barang secara berulang-ulang. Berikut ketentuannya:
● Program akan terus meminta input harga hingga pengguna memasukkan angka
0 (sebagai tanda selesai).
● Program harus menghitung Total Belanja.
● Kondisi Khusus: Jika Total Belanja lebih dari Rp 100.000, pengguna mendapatkan
Diskon 10%. Jika tidak, tidak ada diskon.
● Tampilkan Total Akhir yang harus dibayar.

#include <iostream>
using namespace std;

int main(){
    int tahun;
    cout << "Masukkan Tahun: ";
    cin >> tahun;

    if ((tahun % 400 == 0) || (tahun % 4 == 0 && tahun % 100 != 0)) {
        cout << tahun << " adalah Tahun Kabisat." << endl;
    } else {
        cout << tahun << " adalah Bukan Tahun Kabisat." << endl;
    }

    return 0; 
}

int main() {
    float harga, totalBelanja = 0.0;
    cout << "Masukkan Harga Barang (0 untuk berhenti): " << endl;

    while (true) {
        cin >> harga;
        if (harga == 0) {
            break;
        }
        totalBelanja += harga;
    }

    float diskon = 0.0;
    if (totalBelanja > 100000) {
        diskon = totalBelanja * 0.10;
    }

    float totalAkhir = totalBelanja - diskon;
    cout << "Total Belanja: Rp " << totalBelanja << endl;
    cout << "Diskon: Rp " << diskon << endl;
    cout << "Total Akhir yang harus dibayar: Rp " << totalAkhir << endl;

    return 0;
}

#include <iostream>
using namespace std;
// int main() {
//     cout << "Hello, World! ";
//     cout << "Belajar C + sangat seru😀";
//     string nama;
//     cout << "\nMasukkan nama Anda: ";
//     cin >> nama;
//     cout << "Halo, " << nama << "! Selamat belajar C++!";
// return 0;
// }

int main() {
int nilai;
cout << " = Konversi Nilai Akademik =\n";
cout << "Masukkan nilai akhir (0-100): ";
cin >> nilai;
if (nilai < 0 || nilai > 100) {
cout << "Error: Nilai harus 0-100.\n";
return 1;
}
switch (nilai / 10) {
case 10:
cout << "Predikat: A (Sangat Baik)\n";
break;
case 9:
cout << "Predikat: A (Sangat Baik)\n";
break;
case 8:
cout < "Predikat: B (Baik)\n";
break;
case 7:
cout < "Predikat: C (Cukup)\n";
break;
case 6:
cout < "Predikat: D (Kurang)\n";
break;
default:
cout < "Predikat: E (Gagal)\n";
break;

}
return 0;
}
