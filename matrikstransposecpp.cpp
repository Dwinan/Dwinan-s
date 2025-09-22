#include <iostream>
using namespace std;

// Program transpose matriks menggunakan array 2D
int main() {
    int baris, kolom;

    // Input ukuran matriks
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    int matriks[9][9], transpose[9][9];

    // Input elemen matriks
    cout << "\nMasukkan elemen matriks:" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Elemen [" << i << "][" << j << "] : ";
            cin >> matriks[i][j];
        }
    }
    // Proses transpose (baris ke kolom, kolom ke baris)
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            transpose[j][i] = matriks[i][j];
        }
    }
    // Tampilkan matriks asli
    cout << "\nMatriks Asli:" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
    // Tampilkan hasil transpose
    cout << "\nHasil Transpose Matriks:" << endl;
    for (int i = 0; i < kolom; i++) {        // ukuran menjadi terbalik
        for (int j = 0; j < baris; j++) {
            cout << transpose[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
