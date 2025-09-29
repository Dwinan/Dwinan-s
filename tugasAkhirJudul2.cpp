#include <iostream>
#include <string>
using namespace std;

struct Siswa {
    string nama;
    int nilai;
};

// Fungsi Selection Sort (descending)
void selectionSort(Siswa arr[], int n) {
    int maxIndex;
    Siswa temp;

    for (int i = 0; i < n - 1; i++) {
        maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nilai > arr[maxIndex].nilai) {
                maxIndex = j;
            }
        }
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    
    cout << "Program Mengurutkan Peringkat Nilai Siswa\n";
    cout << "Masukkan jumlah siswa: ";
    cin >> n;
    cin.ignore();

    Siswa *data = new Siswa[n];

    // Input data siswa
    cout << "Masukkan nama dan nilai siswa:\n";
    
    for (int i = 0; i < n; i++) {
        cout << "Siswa ke-" << (i+1) << ":\n";
        cout << "Nama  : ";
        getline(cin, data[i].nama);
        cout << "Nilai : ";
        cin >> data[i].nilai;
        cin.ignore();
    }

    //Panggil fungsi untuk mengurutkan peringkat
    selectionSort(data, n);

    // Tampilkan hasil
    cout << "\nPeringkat Nilai Siswa\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << data[i].nama << " - Nilai: " << data[i].nilai << endl;
    }
    delete[] data;
    return 0;
}

