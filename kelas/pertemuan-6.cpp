// #include<iostream>
// using namespace std;

// int main(){
//     int data[] = {250, 85, 45, 120, 30};
//     int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen

//     int cari;
//     bool found = false;

//     cout << "Masukkan angka yang ingin dicari: ";
//     cin >> cari;

//     // Proses Linear Search
//     for(int i = 0; i < n; i++){
//         if(data[i] == cari){
//             cout << "Data ditemukan pada indeks ke-" << i << endl;
//             found = true;
//             break; // Berhenti jika sudah ketemu
//         }
//     }

//     if(!found){
//         cout << "Data tidak ditemukan dalam array." << endl;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

int main (){
    int data[] = {250, 85, 45, 120, 30};
    int n = sizeof(data)/sizeof(data[0]);

    bool found = false;
    int cari;
    cout << "Masukkan data yang ingin dicari";
    cin >> cari;

    for (int i = 0; i < n; i++){
        if(data[i] == cari){
            cout << "Data berhasil ditemukan pada indeks ke-" << i << endl;
            found = true;
            break;
        }
    }
    if (!found){
        cout << "data gagal";
    }

    return 0;
}