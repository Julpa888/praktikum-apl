#include <iostream>
#include <string>
using namespace std;

string buah[5] = {"Jeruk", "Mangga", "Nanas", "Apel"};

int main() {
    buah[5] = "Rambutan";
    for (int i = 0; i < 5; i ++) {
        cout << buah[i] << endl;
}
}