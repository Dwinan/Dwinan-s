#include <iostream>
using namespace std;

int main() {
    const int n = 5;  
    string mahasiswa[n] = {"Faqih", "Luna", "Farel", "Faye", "Nanda"};
    string cari;
    bool ditemukan = false;

    cout << "Program Sequential Search Mahasiswa\n";
    cout << "Data Mahasiswa: ";
    for (int i = 0; i < n; i++) {
        cout << mahasiswa[i] << " ";
    }
    cout << "\n\nMasukkan nama mahasiswa yang ingin dicari: ";
    cin >> cari;

    // Sequential Search
    for (int i = 0; i < n; i++) {
        if (mahasiswa[i] == cari) {
            cout << "Mahasiswa dengan nama \"" << cari 
                 << "\" ditemukan pada index ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan nama \"" << cari << "\" tidak ditemukan." << endl;
    }

    return 0;
}
