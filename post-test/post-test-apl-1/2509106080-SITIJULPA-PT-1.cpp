#include <iostream>
using namespace std;

int main() {
    while(true){
        string opsi;
        cout << "Selamat datang di service konversi Julpa (˶ᵔ ᵕ ᵔ˶) <3" << endl;
        cout << "============================================" << endl;
        cout << "1. LOGIN" << endl;
        cout << "2. KELUAR" << endl;
        cout << "\n⸜(｡˃ ᵕ <)⸝♡ Input your option here!: "; 
        cin >> opsi;

        if (opsi == "1"){
            break;
        }
        else if(opsi == "2"){
            cout << "Leave already? have a nice day! you can comeback anytime (っ˕ -｡)ᶻ𐰁";
            return 0;
        }
        else {
                cout << "\nInvalid option! please try again ^~^\n" << endl;
        }
    }


    string usnBenar = "Julpa";
    string pwBenar = "080";
    int percobaan = 0;
    while (percobaan < 3) {
        string usn;
        string pw;

        cout << "\n====== SILAHKAN LOGIN >.< ======\n" << endl;
        cout << "Input Username : ";
        cin >> usn;
        cout << "Input Password : ";
        cin >> pw;

        if (pw == pwBenar && usn == usnBenar) {
            cout << "\nYayy, your login are succes!" << endl;
            cout << "Please do enjoy our service (˶ > ₃ < ˶)\n" << endl;
            break;
        } 
        else if (usn != usnBenar && pw == pwBenar){
            percobaan++;
            cout << "Username Invalid! Sisa percobaan = " << 3 - percobaan << endl;
        }
        else if (usn == usnBenar && pw != pwBenar){
            percobaan++;
            cout << "Password Invalid! Sisa percobaan = " << 3 - percobaan << endl;
        }
        else {
            percobaan++;
            cout << "Password dan Username Invalid! Sisa percobaan = " << 3 - percobaan << endl;
        }
    }

    if (percobaan == 3) {
        cout << "Invalid login three times. Program will be stoped!" << endl;
        return 0;
    }


    while (true) {
        string pilihan;
        double nilai;

        cout << "\n===== MENU KONVERSI PANJANG ૮ ˶ᵔ ᵕ ᵔ˶ ა =====" << endl;
        cout << "1. Meter ke Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer ke Meter dan Centimeter" << endl;
        cout << "3. Centimeter ke Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "\n⸜(｡˃ ᵕ <)⸝♡ Input your option here!: ";
        cin >> pilihan;

        if (pilihan == "1") {
            cout << "\n₊˚⊹ ᰔ Input panjang dalam meter: ";
            cin >> nilai;
            cout << "-----> Hasil konversi: " << nilai / 1000 << " km dan " << nilai * 100 << " cm\n\n";
        }
        else if (pilihan == "2") {
            cout << "\n₊˚⊹ ᰔ Input panjang dalam kilometer: ";
            cin >> nilai;
            cout << "-----> Hasil konversi: " << nilai * 1000 << " m dan " << nilai * 100000 << " cm\n\n";
        }
        else if (pilihan == "3") {
            cout << "\n₊˚⊹ ᰔ Input panjang dalam centimeter: ";
            cin >> nilai;
            cout << "-----> Hasil konversi: " << nilai / 100 << " m dan " << nilai / 100000 << " km\n\n";
        }
        else if (pilihan == "4") {
            cout << "Thank you! Program ended ₍^. .^₎Ⳋ" << endl;
            break;
        }
        else {
            cout << "\nInvalid option! please try again ^~^\n" << endl;
        }
    }

    return 0;
}