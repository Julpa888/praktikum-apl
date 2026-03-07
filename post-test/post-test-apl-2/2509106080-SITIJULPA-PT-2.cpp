#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX_KARAKTER 10

struct Akun {
    string usnUser;
    string pwUser;
    string usnAdmin;
    string pwAdmin;
};

Akun akun;
bool loginAdmin = false;
bool loginUser = false;

struct Build {
    string weapon;
    string sonata;
    string echo;
    int cost;
    string team[2];
};

struct Karakter {
    string name;
    struct Build build;
};

Karakter karakter[MAX_KARAKTER] = {
    {"Aemeth", {"Everbright Polestar", "Trailblazing Star", "Sigillum", 43311, {"Lyney", "Mornye"}}},
    {"Cartethyia", {"Defier's Thorn", "Windward Pilgimare", "Reminiscence: Fleurdelys", 44111, {"Ciaccona", "Chisa"}}},
    {"Carlotta", {"The Last Dance", "Frosty Resolve", "Sentry Construct", 43311, {"Zhezhi", "Shorekeeper"}}},
    {"Phrolova", {"Lethean Elegy", "Dream of the lost", "Nightmare: Hecate", 43311, {"Cantarella", "Qiuyuan"}}},
    {"Augusta", {"Thunderflare Dominion", "Crown of Valor", "The False Sovereign", 43311, {"Iuno", "Shorekeeper"}}}
};

int main() {
    int panjang = 5;
    int wishlistIndex[MAX_KARAKTER];
    int jumlahWishlist = 0;

    akun.usnAdmin = "Julpa";
    akun.pwAdmin = "080";

    while (true) {
        string opsi;
        cout << "\n";
        cout << "╔════════════════════════════════════════════════════╗" << endl;
        cout << "║      Wuthering Waves Build Guide  (˶ᵔ ᵕ ᵔ˶) <3     ║" << endl;
        cout << "╚════════════════════════════════════════════════════╝" << endl;
        cout << "\n1. REGISTRASI" << endl;
        cout << "2. LOGIN" << endl;
        cout << "3. KELUAR" << endl;
        cout << "\n⸜(｡˃ ᵕ <)⸝♡ Input your option here!: ";
        cin >> opsi;

        if (opsi == "1") {
            cout << "\n";
            cout << "┌────────────────────────────────────────────────┐" << endl;
            cout << "│                 REGISTRASI AKUN                │" << endl;
            cout << "└────────────────────────────────────────────────┘" << endl;
            cout << "\nSilahkan masukkan username: ";
            cin.ignore();
            getline(cin, akun.usnUser);
            cout << "Silahkan masukkan password: ";
            getline(cin, akun.pwUser);
            cout << "\nRegistrasi berhasil! Silahkan login. (◕‿◕)" << endl;
        }
        else if (opsi == "2") {
            int percobaan = 0;
            cin.ignore(); 
            
            while (percobaan < 3) {
                string usn;
                string pw;

                cout << "\n";
                cout << "┌────────────────────────────────────────────────┐" << endl;
                cout << "│                   LOGIN AKUN                   │" << endl;
                cout << "└────────────────────────────────────────────────┘" << endl;
                cout << "\nMasukkan username akun: ";
                getline(cin, usn);
                cout << "Masukkan password akun: ";
                getline(cin, pw);

                if (usn == akun.usnUser && pw == akun.pwUser) {
                    cout << "\nSelamat login user berhasil! (ﾉ^ヮ^) ﾉ*:・ﾟ✧" << endl;
                    loginUser = true;
                    break;
                } else if (usn == akun.usnAdmin && pw == akun.pwAdmin) {
                    cout << "\nSelamat login admin berhasil! (ﾉ^ヮ^) ﾉ*:・ﾟ✧" << endl;
                    loginAdmin = true;
                    break;
                } else if (usn != akun.usnUser && pw == akun.pwUser) {
                    percobaan++;
                    cout << "\nUsername salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
                } else if (usn == akun.usnUser && pw != akun.pwUser) {
                    percobaan++;
                    cout << "\nPassword salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
                } else if (usn != akun.usnAdmin && pw == akun.pwAdmin) {
                    percobaan++;
                    cout << "\nUsername salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
                } else if (usn == akun.usnAdmin && pw != akun.pwAdmin) {
                    percobaan++;
                    cout << "\nPassword salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
                } else {
                    percobaan++;
                    cout << "\nAkun tidak tersedia! (sisa percobaan: " << 3 - percobaan << ")" << endl;
                }
            }

            if (percobaan == 3) {
                cout << "\nPercobaan habis! program berhenti~" << endl;
                return 0;
            } else if (loginUser || loginAdmin) {
                break;
            }
        }
        else if (opsi == "3") {
            cout << "\nProgram berhenti! Sampai jumpa~ (´｡• ᵕ •｡`)" << endl;
            return 0;
        } else {
            cout << "\nInvalid option! please try again ^~^" << endl;
        }
    }

    if (loginAdmin) {
        while (true) {
            int pilihan, index;
            cout << "\n";
            cout << "╔════════════════════════════════════════════════════╗" << endl;
            cout << "║                  === MENU ADMIN ===                ║" << endl;
            cout << "╚════════════════════════════════════════════════════╝" << endl;
            cout << "\n1. Lihat Karakter Build" << endl;
            cout << "2. Tambahkan Karakter Build" << endl;
            cout << "3. Ubah Build" << endl;
            cout << "4. Hapus Karakter" << endl;
            cout << "5. Keluar Menu" << endl;
            cout << "\nInput your option here!: ";
            cin >> pilihan;

            if (pilihan == 1) {
                if (panjang == 0) {
                    cout << "\nBelum ada data build karakter" << endl;
                } else {
                    cout << "\n";
                    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
                    cout << "│                                        DAFTAR BUILD KARAKTER                                                 │" << endl;
                    cout << "└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
                    cout << "\n";
                    cout << "┌────┬──────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬────────┬─────────────────────┐" << endl;
                    cout << "│ No │     Karakter     │       Weapon         │    Sonata Effect     │        Main Echo     │  Cost  │       Team Comp     │" << endl;
                    cout << "├────┼──────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼────────┼─────────────────────┤" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "│ " << left << setw(2) << i + 1 
                            << " │ " << left << setw(16) << karakter[i].name.substr(0, 16)
                            << " │ " << left << setw(20) << karakter[i].build.weapon.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.sonata.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.echo.substr(0, 20)
                            << " │ " << left << setw(6) << karakter[i].build.cost
                            << " │ " << left << setw(19) << (karakter[i].build.team[0].substr(0, 9) + "," + karakter[i].build.team[1].substr(0, 9)) 
                            << " │" << endl;
                    }
                    cout << "└────┴──────────────────┴──────────────────────┴──────────────────────┴──────────────────────┴────────┴─────────────────────┘" << endl;
                }
            }
            else if (pilihan == 2) {
                if (panjang < MAX_KARAKTER) {
                    cout << "\n";
                    cout << "┌────────────────────────────────────────────────┐" << endl;
                    cout << "│                 TAMBAH KARAKTER                │" << endl;
                    cout << "└────────────────────────────────────────────────┘" << endl;
                    cout << "\nMasukkan nama karakter: ";
                    cin.ignore();
                    getline(cin, karakter[panjang].name);
                    cout << "Masukkan weapon: ";
                    getline(cin, karakter[panjang].build.weapon);
                    cout << "Masukkan sonata effect: ";
                    getline(cin, karakter[panjang].build.sonata);
                    cout << "Masukkan main echo: ";
                    getline(cin, karakter[panjang].build.echo);
                    cout << "Masukkan cost pattern: ";
                    cin >> karakter[panjang].build.cost;
                    cout << "Masukkan team comp:" << endl;
                    cout << "1. ";
                    cin >> karakter[panjang].build.team[0];
                    cout << "2. ";
                    cin >> karakter[panjang].build.team[1];

                    panjang++;
                    cout << "\nData berhasil ditambahkan! (ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
                } else {
                    cout << "\nKapasitas penuh! (max 10 karakter)" << endl;
                }
            }
            else if (pilihan == 3) {
                if (panjang == 0) {
                    cout << "\nBelum ada data build karakter" << endl;
                } else {
                    cout << "\n";
                    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
                    cout << "│                                        DAFTAR BUILD KARAKTER                                                 │" << endl;
                    cout << "└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
                    cout << "\n";
                    cout << "┌────┬──────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬────────┬─────────────────────┐" << endl;
                    cout << "│ No │     Karakter     │       Weapon         │    Sonata Effect     │        Main Echo     │  Cost  │       Team Comp     │" << endl;
                    cout << "├────┼──────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼────────┼─────────────────────┤" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "│ " << left << setw(2) << i + 1 
                            << " │ " << left << setw(16) << karakter[i].name.substr(0, 16)
                            << " │ " << left << setw(20) << karakter[i].build.weapon.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.sonata.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.echo.substr(0, 20)
                            << " │ " << left << setw(6) << karakter[i].build.cost
                            << " │ " << left << setw(19) << (karakter[i].build.team[0].substr(0, 9) + "," + karakter[i].build.team[1].substr(0, 9)) 
                            << " │" << endl;
                    }
                    cout << "└────┴──────────────────┴──────────────────────┴──────────────────────┴──────────────────────┴────────┴─────────────────────┘" << endl;

                    cout << "\nMasukkan nomor karakter yang ingin diubah: ";
                    cin >> index;

                    if (index > 0 && index <= panjang) {
                        cout << "\nAnda akan mengubah karakter: " << karakter[index - 1].name << endl;
                        cout << "Masukkan weapon: ";
                        cin.ignore();
                        getline(cin, karakter[index - 1].build.weapon);
                        cout << "Masukkan sonata effect: ";
                        getline(cin, karakter[index - 1].build.sonata);
                        cout << "Masukkan main echo: ";
                        getline(cin, karakter[index - 1].build.echo);
                        cout << "Masukkan cost pattern: ";
                        cin >> karakter[index - 1].build.cost;
                        cout << "Masukkan team comp:" << endl;
                        cout << "1. ";
                        cin >> karakter[index - 1].build.team[0];
                        cout << "2. ";
                        cin >> karakter[index - 1].build.team[1];
                        cout << "\nBuild berhasil diubah! (◕‿◕)" << endl;
                    } else {
                        cout << "\nNomor karakter tidak valid!" << endl;
                    }
                }
            }
            else if (pilihan == 4) {
                if (panjang == 0) {
                    cout << "\nBelum ada data build karakter" << endl;
                } else {
                    cout << "\n";
                    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
                    cout << "│                                        DAFTAR BUILD KARAKTER                                                 │" << endl;
                    cout << "└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
                    cout << "\n";
                    cout << "┌────┬──────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬────────┬─────────────────────┐" << endl;
                    cout << "│ No │     Karakter     │       Weapon         │    Sonata Effect     │        Main Echo     │  Cost  │       Team Comp     │" << endl;
                    cout << "├────┼──────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼────────┼─────────────────────┤" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "│ " << left << setw(2) << i + 1 
                            << " │ " << left << setw(16) << karakter[i].name.substr(0, 16)
                            << " │ " << left << setw(20) << karakter[i].build.weapon.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.sonata.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.echo.substr(0, 20)
                            << " │ " << left << setw(6) << karakter[i].build.cost
                            << " │ " << left << setw(19) << (karakter[i].build.team[0].substr(0, 9) + "," + karakter[i].build.team[1].substr(0, 9)) 
                            << " │" << endl;
                    }
                    cout << "└────┴──────────────────┴──────────────────────┴──────────────────────┴──────────────────────┴────────┴─────────────────────┘" << endl;

                    cout << "\nMasukkan nomor karakter yang ingin dihapus: ";
                    cin >> index;

                    if (index > 0 && index <= panjang) {
                        for (int i = index - 1; i < panjang - 1; i++) {
                            karakter[i] = karakter[i + 1];
                        }
                        panjang--;
                        cout << "\nKarakter berhasil dihapus! (ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
                    } else {
                        cout << "\nNomor karakter tidak valid!" << endl;
                    }
                }
            }
            else if (pilihan == 5) {
                cout << "\nKeluar dari menu admin. Sampai jumpa! (´｡• ᵕ •｡`)" << endl;
                break;
            }
            else {
                cout << "\nOpsi tidak valid!" << endl;
            }
        }
    }

    else if (loginUser) {
        while (true) {
            int pilihan, index;
            cout << "\n";
            cout << "╔════════════════════════════════════════════════════╗" << endl;
            cout << "║               === MENU USER ===                    ║" << endl;
            cout << "╚════════════════════════════════════════════════════╝" << endl;
            cout << "\n";
            cout << "1. Lihat Karakter Build" << endl;
            cout << "2. Lihat Wishlist" << endl;
            cout << "3. Tambahkan Wishlist" << endl;
            cout << "4. Hapus Wishlist" << endl;
            cout << "5. Keluar Menu" << endl;
            cout << "\nInput your option here!: ";
            cin >> pilihan;

            if (pilihan == 1) {
                if (panjang == 0) {
                    cout << "\nBelum ada data build karakter" << endl;
                } else {
                    cout << "\n";
                    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
                    cout << "│                                        DAFTAR BUILD KARAKTER                                                 │" << endl;
                    cout << "└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
                    cout << "\n";
                    cout << "┌────┬──────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬────────┬─────────────────────┐" << endl;
                    cout << "│ No │     Karakter     │       Weapon         │    Sonata Effect     │        Main Echo     │  Cost  │       Team Comp     │" << endl;
                    cout << "├────┼──────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼────────┼─────────────────────┤" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "│ " << left << setw(2) << i + 1 
                            << " │ " << left << setw(16) << karakter[i].name.substr(0, 16)
                            << " │ " << left << setw(20) << karakter[i].build.weapon.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.sonata.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.echo.substr(0, 20)
                            << " │ " << left << setw(6) << karakter[i].build.cost
                            << " │ " << left << setw(19) << (karakter[i].build.team[0].substr(0, 9) + "," + karakter[i].build.team[1].substr(0, 9)) 
                            << " │" << endl;
                    }
                    cout << "└────┴──────────────────┴──────────────────────┴──────────────────────┴──────────────────────┴────────┴─────────────────────┘" << endl;
                }
            }
            else if (pilihan == 2) {
                if (jumlahWishlist == 0) {
                    cout << "\nWishlist masih kosong! Tambahkan karakter favoritmu~ (◕‿◕)" << endl;
                } else {
                    cout << "\n";
                    cout << "┌────┬──────────────────────────────────────────┐" << endl;
                    cout << "│ No │           KARAKTER WISHLIST              │" << endl;
                    cout << "├────┼──────────────────────────────────────────┤" << endl;
                    for (int i = 0; i < jumlahWishlist; i++) {
                        int idx = wishlistIndex[i];
                        if(idx >= 0 && idx < panjang){
                            cout << "│ " << left << setw(2) << i + 1 
                                << " │ " << left << setw(38) << karakter[idx].name.substr(0, 38) 
                                << " │" << endl;
                        }
                    }
                    cout << "└────┴──────────────────────────────────────────┘" << endl;
                }
            }
            else if (pilihan == 3) {
                int pilih;
                if (panjang == 0) {
                    cout << "\nBelum ada data build karakter" << endl;
                } else {
                    cout << "\n";
                    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
                    cout << "│                                        DAFTAR BUILD KARAKTER                                                 │" << endl;
                    cout << "└──────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
                    cout << "\n";
                    cout << "┌────┬──────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬────────┬─────────────────────┐" << endl;
                    cout << "│ No │     Karakter     │       Weapon         │    Sonata Effect     │        Main Echo     │  Cost  │       Team Comp     │" << endl;
                    cout << "├────┼──────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼────────┼─────────────────────┤" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "│ " << left << setw(2) << i + 1 
                            << " │ " << left << setw(16) << karakter[i].name.substr(0, 16)
                            << " │ " << left << setw(20) << karakter[i].build.weapon.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.sonata.substr(0, 20)
                            << " │ " << left << setw(20) << karakter[i].build.echo.substr(0, 20)
                            << " │ " << left << setw(6) << karakter[i].build.cost
                            << " │ " << left << setw(19) << (karakter[i].build.team[0].substr(0, 9) + "," + karakter[i].build.team[1].substr(0, 9)) 
                            << " │" << endl;
                    }
                    cout << "└────┴──────────────────┴──────────────────────┴──────────────────────┴──────────────────────┴────────┴─────────────────────┘" << endl;

                    cout << "\nPilih nomor karakter untuk dimasukkan ke wishlist: ";
                    cin >> pilih;
                    index = pilih - 1;

                    if(index >= 0 && index < panjang){
                        wishlistIndex[jumlahWishlist] = index;
                        jumlahWishlist++;
                        cout << "\nWishlist berhasil ditambahkan!(ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
                    } else {
                        cout << "\nNomor tidak valid!" << endl;
                    }
                }
            }
            else if (pilihan == 4) {
                int pilih;
                if (jumlahWishlist == 0) {
                    cout << "\nWishlist masih kosong!" << endl;
                } else {
                    cout << "\n";
                    cout << "┌────┬──────────────────────────────────────────┐" << endl;
                    cout << "│ No │           KARAKTER WISHLIST              │" << endl;
                    cout << "├────┼──────────────────────────────────────────┤" << endl;
                    for (int i = 0; i < jumlahWishlist; i++) {
                        int idx = wishlistIndex[i];
                        if(idx >= 0 && idx < panjang){
                            cout << "│ " << left << setw(2) << i + 1 
                                << " │ " << left << setw(38) << karakter[idx].name.substr(0, 38) 
                                << " │" << endl;
                        }
                    }
                    cout << "└────┴──────────────────────────────────────────┘" << endl;

                    cout << "\nPilih nomor wishlist untuk dihapus: ";
                    cin >> pilih;
                    index = pilih - 1;

                    if(index >= 0 && index < jumlahWishlist){
                        for (int i = index; i < jumlahWishlist - 1; i++) {
                            wishlistIndex[i] = wishlistIndex[i + 1];
                        }
                        jumlahWishlist--;
                        cout << "\nWishlist berhasil dihapus! (ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
                    } else {
                        cout << "\nNomor tidak valid!" << endl;
                    }
                }
            }
            else if (pilihan == 5) {
                cout << "\nKeluar dari menu user. Sampai jumpa! (´｡• ᵕ •｡`)" << endl;
                break;
            }
            else {
                cout << "\nOpsi tidak valid!" << endl;
            }
        }
    }

    cout << "\nTerima kasih telah menggunakan panduan ini!" << endl;
    return 0;
}