#include<iostream>
using namespace std;

int main(){
    string var = "Aku Variabel";
    string* varPtr = &var;

    string va = "Aku Vaariabel";
    string* vaPtr = va;

    cout << "Hasil dari varPtr (Alamat): " << varPtr << endl;
    cout << "Hasil dari *varPtr (Nilai): " << *varPtr << endl;

    cout << "Hasil dari vaPtr (Alamat): " << vaPtr << endl;
    cout << "Hasil dari *vaPtr (Nilai): " << *vaPtr << endl;
    cout << endl << "Kesimpulannya varPtr isi nya alamatnya var" << endl;
    cout << "*varPtr hasilnya value dari var" << endl;
    cout << endl;
    cout << "Hasil/value dari var: " << var << endl;
    cout << "Hasil/value dari alamat var (&var): " << &var << endl;
    cout << "Hasil/value dari varPtr: " << varPtr << endl;
    cout << "Hasil/value dari *varPtr: " << *varPtr << endl;
    return 0;
}