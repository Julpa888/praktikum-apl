#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAX_KARAKTER 10

struct Akun {
    string usnUser;
    string pwUser;
    string usnAdmin;
    string pwAdmin;
};

Akun akun;
bool sudahTerdaftar = false;

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

void bubbleSort(Karakter arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name < arr[j+1].name) { 
                swap(arr[j], arr[j+1]);
    }}}}

void selectionSort(Karakter arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].build.cost < arr[minIdx].build.cost) {
                minIdx = j;
            }}
        swap(arr[i], arr[minIdx]);
    }}

void insertionSort(Karakter arr[], int n) {
    for (int i = 1; i < n; i++) {
        Karakter key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].build.echo > key.build.echo) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }}

string toLowerStr(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void cariNamaLinear(Karakter* arr, int size, string target, Karakter* resultArr, int* resultCount) {
    *resultCount = 0;
    string key = toLowerStr(target);
    
    for (int i = 0; i < size; i++) {
        if (toLowerStr((arr + i)->name) == key) {
            resultArr[*resultCount] = *(arr + i);
            (*resultCount)++;
        }
    }
}

void cariCostBinary(Karakter* sortedArr, int size, int target, Karakter* resultArr, int* resultCount) {
    *resultCount = 0;
    int left = 0, right = size - 1;
    int foundIdx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((sortedArr + mid)->build.cost == target) {
            foundIdx = mid;
            break;
        } else if ((sortedArr + mid)->build.cost < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (foundIdx == -1) return;

    int l = foundIdx, r = foundIdx;
    while (l > 0 && (sortedArr + l - 1)->build.cost == target) l--;
    while (r < size - 1 && (sortedArr + r + 1)->build.cost == target) r++;

    for (int i = l; i <= r; i++) {
        resultArr[*resultCount] = *(sortedArr + i);
        (*resultCount)++;
    }
}

void lihatKarakter(Karakter* karakter, int panjang){
    if (panjang == 0) {
        cout << "\nBelum ada data build karakter" << endl;
        return;
    }
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

void registrasi(Akun &akun){
    cout << "\n";
    cout << "┌────────────────────────────────────────────────┐" << endl;
    cout << "│                 REGISTRASI AKUN                │" << endl;
    cout << "└────────────────────────────────────────────────┘" << endl;

    string usnBaru, pwBaru;
    cout << "\nSilahkan masukkan username: ";
    cin.ignore();
    getline(cin, usnBaru);
    cout << "Silahkan masukkan password: ";
    getline(cin, pwBaru);

    if (usnBaru.empty() || pwBaru.empty()) {
        cout << "\nInput tidak boleh kosong!" << endl;
        return;
    }

    if (usnBaru == akun.usnAdmin) {
        cout << "Username sudah terdaftar!\n";
    } else if (sudahTerdaftar && usnBaru == akun.usnUser) {
        cout << "Username sudah terdaftar!\n";
    } else {
        akun.usnUser = usnBaru;
        akun.pwUser = pwBaru;
        sudahTerdaftar = true;
        cout << "\nRegistrasi berhasil! Silahkan login. (◕‿◕)\n";
}}

int login(Akun akun){
    int percobaan = 0;
    cin.ignore(); 
    
    while (percobaan < 3) {
        string usn, pw;
        cout << "\n";
        cout << "┌────────────────────────────────────────────────┐" << endl;
        cout << "│                   LOGIN AKUN                   │" << endl;
        cout << "└────────────────────────────────────────────────┘" << endl;
        cout << "\nMasukkan username akun: ";
        getline(cin, usn);
        cout << "Masukkan password akun: ";
        getline(cin, pw);

        if (usn.empty() || pw.empty()) {
            cout << "\nInput tidak boleh kosong!" << endl;
            continue;
        }

        if (usn == akun.usnAdmin && pw == akun.pwAdmin) {
            cout << "\nSelamat login admin berhasil! (ﾉ^ヮ^) ﾉ*:・ﾟ✧" << endl;
            return 1;
        } else if (usn == akun.usnUser && pw == akun.usnUser) {
            cout << "\nSelamat login user berhasil! (ﾉ^ヮ^) ﾉ*:・ﾟ✧" << endl;
            return 2;
        } else if (usn != akun.usnUser && pw == akun.usnUser) {
            percobaan++;
            cout << "\nUsername salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
        } else if (usn == akun.usnUser && pw != akun.usnUser) {
            percobaan++;
            cout << "\nPassword salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
        } else if (usn != akun.usnAdmin && pw == akun.usnAdmin) {
            percobaan++;
            cout << "\nUsername salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
        } else if (usn == akun.usnAdmin && pw != akun.usnAdmin) {
            percobaan++;
            cout << "\nPassword salah! (sisa percobaan: " << 3 - percobaan << ")" << endl;
        } else {
            percobaan++;
            cout << "\nAkun tidak tersedia! (sisa percobaan: " << 3 - percobaan << ")" << endl;
        }}

    if (percobaan == 3) {
        cout << "\nPercobaan habis! program berhenti~" << endl;
        return 0;
    }
    return 0;
}

void tambahKarakter(Karakter karakter[], int* panjang){
    if (*panjang >= MAX_KARAKTER) {
        cout << "\nData mencapai batas" << endl;
        return;
    }
    cout << "\n";
    cout << "┌────────────────────────────────────────────────┐" << endl;
    cout << "│                 TAMBAH KARAKTER                │" << endl;
    cout << "└────────────────────────────────────────────────┘" << endl;
    
    cin.ignore(); 
    cout << "\nMasukkan nama karakter: ";
    getline(cin, karakter[*panjang].name);
    cout << "Masukkan weapon: ";
    getline(cin, karakter[*panjang].build.weapon);
    cout << "Masukkan sonata effect: ";
    getline(cin, karakter[*panjang].build.sonata);
    cout << "Masukkan main echo: ";
    getline(cin, karakter[*panjang].build.echo);
    cout << "Masukkan cost pattern: ";
    cin >> karakter[*panjang].build.cost;
    cin.ignore(); 
    cout << "Masukkan team comp:" << endl;
    cout << "1. ";
    getline(cin, karakter[*panjang].build.team[0]);
    cout << "2. ";
    getline(cin, karakter[*panjang].build.team[1]);

    (*panjang)++;
    cout << "\nData berhasil ditambahkan! (ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
}

void ubahKarakter(Karakter karakter[], int panjang){
    int index;
    cout << "\nMasukkan nomor karakter yang ingin diubah: ";
    cin >> index;

    if (index > 0 && index <= panjang) {
        Karakter* target = &karakter[index - 1];
        cout << "\nAnda akan mengubah karakter: " << target->name << endl;
        cin.ignore(); 
        cout << "Masukkan weapon: ";
        getline(cin, target->build.weapon);
        cout << "Masukkan sonata effect: ";
        getline(cin, target->build.sonata);
        cout << "Masukkan main echo: ";
        getline(cin, target->build.echo);
        cout << "Masukkan cost pattern: ";
        cin >> target->build.cost;
        cin.ignore();
        cout << "Masukkan team comp:" << endl;
        cout << "1. ";
        getline(cin, target->build.team[0]);
        cout << "2. ";
        getline(cin, target->build.team[1]);
        cout << "\nBuild berhasil diubah! (◕‿◕)" << endl;
    } else {
        cout << "\nNomor karakter tidak valid!" << endl;
    }}

void hapusKarakter(Karakter karakter[], int* panjang){
    int index;
    cout << "\nMasukkan nomor karakter yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= *panjang) {
        for (int i = index - 1; i < *panjang - 1; i++) {
            karakter[i] = karakter[i + 1];
        }
        (*panjang)--;
        cout << "\nKarakter berhasil dihapus! (ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
    } else {
        cout << "\nNomor karakter tidak valid!" << endl;
    }}

void lihatWishlist(int wishlistIndex[], int jumlahWishlist, Karakter karakter[], int panjang){
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
            }}
        cout << "└────┴──────────────────────────────────────────┘" << endl;
    }}

void tambahWishlist(int wishlistIndex[], int* jumlahWishlist, int panjang){
    int index, pilih;
    if (*jumlahWishlist >= MAX_KARAKTER) {
        cout << "\nData mencapai batas" << endl;
        return;
    }
    cout << "\nPilih nomor karakter untuk dimasukkan ke wishlist: ";
    cin >> pilih;
    index = pilih - 1;

    if (index >= 0 && index < panjang){
        for(int i = 0; i < *jumlahWishlist; i++){
            if(wishlistIndex[i] == index){
                cout << "\nKarakter sudah ada di wishlist!" << endl;
                return;
            }
        }
        wishlistIndex[*jumlahWishlist] = index;
        (*jumlahWishlist)++;
        cout << "\nWishlist berhasil ditambahkan!(ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
    } else {
        cout << "\nNomor tidak valid!" << endl;
    }}

void hapusWishlist(int wishlistIndex[], int* jumlahWishlist){
    int pilih, index;
    cout << "\nPilih nomor wishlist untuk dihapus: ";
    cin >> pilih;
    index = pilih - 1;

    if (index >= 0 && index < *jumlahWishlist){
        for (int i = index; i < *jumlahWishlist - 1; i++) {
            wishlistIndex[i] = wishlistIndex[i + 1];
        }
        (*jumlahWishlist)--;
        cout << "\nWishlist berhasil dihapus! (ﾉ◕ヮ◕) ﾉ*:・ﾟ✧" << endl;
    } else {
        cout << "\nNomor tidak valid!" << endl;
    }}

int main() {
    int hasilLogin;
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

        if (opsi == "1"){
            registrasi(akun);
        } else if (opsi == "2"){
            hasilLogin = login(akun);

            if (hasilLogin == 0){
                return 0;
            } else if (hasilLogin == 1){
                while (true) {
                    int pilihan;
                    cout << "\n";
                    cout << "╔════════════════════════════════════════════════════╗" << endl;
                    cout << "║                  === MENU ADMIN ===                ║" << endl;
                    cout << "╚════════════════════════════════════════════════════╝" << endl;
                    cout << "\n1. Lihat Karakter Build" << endl;
                    cout << "2. Tambahkan Karakter Build" << endl;
                    cout << "3. Ubah Build" << endl;
                    cout << "4. Hapus Karakter" << endl;
                    cout << "5. Cari Karakter" << endl;
                    cout << "6. Cari Cost Pattern Karakter" << endl;
                    cout << "7. Keluar Menu" << endl;
                    cout << "\nInput your option here!: ";
                    cin >> pilihan;

                    if (pilihan == 1){
                        int sort;
                        cout << "\n┌────────────────────────────────────────────────┐\n";
                        cout << "│          PILIH METODE PENGURUTAN               │\n";
                        cout << "├────────────────────────────────────────────────┤\n";
                        cout << "│ 1. Nama Karakter (Descending)                  │\n";
                        cout << "│ 2. Cost Pattern (Ascending)                    │\n";
                        cout << "│ 3. Main Echo (Ascending)                       │\n";
                        cout << "│ 0. Tanpa Pengurutan                            │\n";
                        cout << "└────────────────────────────────────────────────┘\n";
                        cout << "Pilihan: ";
                        cin >> sort;

                        Karakter tempKarakter[MAX_KARAKTER];
                        for(int i = 0; i < panjang; i++) {
                            tempKarakter[i] = karakter[i];
                        }

                        if (sort == 1) bubbleSort(tempKarakter, panjang);
                        else if (sort == 2) selectionSort(tempKarakter, panjang);
                        else if (sort == 3) insertionSort(tempKarakter, panjang);

                        lihatKarakter(tempKarakter, panjang);
                    } else if (pilihan == 2){
                        lihatKarakter(karakter, panjang);
                        tambahKarakter(karakter, &panjang);
                    } else if (pilihan == 3){
                        lihatKarakter(karakter, panjang);
                        ubahKarakter(karakter, panjang);
                    } else if (pilihan == 4){
                        lihatKarakter(karakter, panjang);
                        hapusKarakter(karakter, &panjang);
                    } 
                    else if (pilihan == 5){
                        string namaCari;
                        cout << "\nMasukkan nama karakter yang dicari: ";
                        cin.ignore(); 
                        getline(cin, namaCari);
                        
                        Karakter hasil[MAX_KARAKTER];
                        int jumlahHasil = 0;
                        cariNamaLinear(karakter, panjang, namaCari, hasil, &jumlahHasil);
                        
                        if(jumlahHasil == 0) cout << "\n>> Karakter tidak ditemukan!" << endl;
                        else lihatKarakter(hasil, jumlahHasil);
                    } 
                    else if (pilihan == 6){
                        int costCari;
                        cout << "\nMasukkan cost pattern yang dicari: ";
                        cin >> costCari;
                        
                        Karakter tempSort[MAX_KARAKTER];
                        for(int i=0; i<panjang; i++) tempSort[i] = karakter[i];
                        selectionSort(tempSort, panjang);
                        
                        Karakter hasil[MAX_KARAKTER];
                        int jumlahHasil = 0;
                        cariCostBinary(tempSort, panjang, costCari, hasil, &jumlahHasil);
                        
                        if(jumlahHasil == 0) cout << "\n>> Karakter dengan cost tersebut tidak ditemukan!" << endl;
                        else lihatKarakter(hasil, jumlahHasil);
                    } 
                    else if (pilihan == 7) {
                        cout << "\nKeluar dari menu admin. Sampai jumpa! (´｡• ᵕ •｡`)" << endl;
                        break;
                    } else {
                        cout << "\nOpsi tidak valid!" << endl;
                    }}
            } else if (hasilLogin == 2){
                while (true) {
                    int pilihan;
                    cout << "\n";
                    cout << "╔════════════════════════════════════════════════════╗" << endl;
                    cout << "║               === MENU USER ===                    ║" << endl;
                    cout << "╚════════════════════════════════════════════════════╝" << endl;
                    cout << "\n1. Lihat Karakter Build" << endl;
                    cout << "2. Lihat Wishlist" << endl;
                    cout << "3. Tambahkan Wishlist" << endl;
                    cout << "4. Hapus Wishlist" << endl;
                    cout << "5. Cari Karakter" << endl;
                    cout << "6. Cari Cost Pattern Karakter" << endl;
                    cout << "7. Keluar Menu" << endl;
                    cout << "\nInput your option here!: ";
                    cin >> pilihan;

                    if (pilihan == 1){
                        int sort;
                        cout << "\n┌────────────────────────────────────────────────┐\n";
                        cout << "│          PILIH METODE PENGURUTAN               │\n";
                        cout << "├────────────────────────────────────────────────┤\n";
                        cout << "│ 1. Nama Karakter (Descending)                  │\n";
                        cout << "│ 2. Cost Pattern (Ascending)                    │\n";
                        cout << "│ 3. Main Echo (Ascending)                       │\n";
                        cout << "│ 0. Tanpa Pengurutan                            │\n";
                        cout << "└────────────────────────────────────────────────┘\n";
                        cout << "Pilihan: ";
                        cin >> sort;

                        Karakter tempKarakter[MAX_KARAKTER];
                        for(int i = 0; i < panjang; i++) {
                            tempKarakter[i] = karakter[i];
                        }

                        if (sort == 1) bubbleSort(tempKarakter, panjang);
                        else if (sort == 2) selectionSort(tempKarakter, panjang);
                        else if (sort == 3) insertionSort(tempKarakter, panjang);

                        lihatKarakter(tempKarakter, panjang);
                    } else if (pilihan == 2){
                        lihatWishlist(wishlistIndex, jumlahWishlist, karakter, panjang);
                    } else if (pilihan == 3){
                        lihatKarakter(karakter, panjang);
                        tambahWishlist(wishlistIndex, &jumlahWishlist, panjang);
                    } else if (pilihan == 4){
                        lihatWishlist(wishlistIndex, jumlahWishlist, karakter, panjang);
                        hapusWishlist(wishlistIndex, &jumlahWishlist);
                    }
                    else if (pilihan == 5){
                        string namaCari;
                        cout << "\nMasukkan nama karakter yang dicari: ";
                        cin.ignore(); 
                        getline(cin, namaCari);
                        
                        Karakter hasil[MAX_KARAKTER];
                        int jumlahHasil = 0;
                        cariNamaLinear(karakter, panjang, namaCari, hasil, &jumlahHasil);
                        
                        if(jumlahHasil == 0) cout << "\n>> Karakter tidak ditemukan!" << endl;
                        else lihatKarakter(hasil, jumlahHasil);
                    }
                    else if (pilihan == 6){
                        int costCari;
                        cout << "\nMasukkan cost pattern yang dicari: ";
                        cin >> costCari;
                        
                        Karakter tempSort[MAX_KARAKTER];
                        for(int i=0; i<panjang; i++) tempSort[i] = karakter[i];
                        selectionSort(tempSort, panjang);
                        
                        Karakter hasil[MAX_KARAKTER];
                        int jumlahHasil = 0;
                        cariCostBinary(tempSort, panjang, costCari, hasil, &jumlahHasil);
                        
                        if(jumlahHasil == 0) cout << "\n>> Karakter dengan cost tersebut tidak ditemukan!" << endl;
                        else lihatKarakter(hasil, jumlahHasil);
                    }
                    else if (pilihan == 7) {
                        cout << "\nKeluar dari menu user. Sampai jumpa! (´｡• ᵕ •｡`)" << endl;
                        break;
                    } else {
                        cout << "\nOpsi tidak valid!" << endl;
                    }}
            } else {
                break;
            }
            
        } else if (opsi == "3") {
            cout << "\nProgram berhenti! Sampai jumpa~ (´｡• ᵕ •｡`)" << endl;
            return 0;
        } else {
            cout << "\nInvalid option! please try again ^~^" << endl;
        }}

    cout << "\nTerima kasih telah menggunakan panduan ini!" << endl;
    return 0;
}