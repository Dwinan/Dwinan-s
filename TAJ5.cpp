#include <iostream>
using namespace std;

// Struktur node BST
struct Node {
    int nilai;
    Node* kiri;
    Node* kanan;
    Node(int n) : nilai(n), kiri(nullptr), kanan(nullptr) {}
};

// Fungsi menambah nilai ke BST
Node* tambah(Node* root, int nilai) {
    if (!root) {
        cout << "Nilai " << nilai << " berhasil ditambahkan.\n";
        return new Node(nilai);
    }
    if (nilai < root->nilai)
        root->kiri = tambah(root->kiri, nilai);
    else if (nilai > root->nilai)
        root->kanan = tambah(root->kanan, nilai);
    else
        cout << "Nilai " << nilai << " sudah ada di BST!\n";
    return root;
}

// Fungsi mencari nilai
bool cari(Node* root, int nilai) {
    if (!root) return false;
    if (root->nilai == nilai) return true;
    if (nilai < root->nilai) return cari(root->kiri, nilai);
    return cari(root->kanan, nilai);
}

// Menampilkan nilai secara inorder (urut dari kecil ke besar)
void tampilInorder(Node* root) {
    if (!root) return;
    tampilInorder(root->kiri);
    cout << root->nilai << " ";
    tampilInorder(root->kanan);
}

// Mencari nilai minimum (paling kecil)
int cariMin(Node* root) {
    if (!root) return -1;
    while (root->kiri) root = root->kiri;
    return root->nilai;
}

// Mencari nilai maksimum (paling besar)
int cariMax(Node* root) {
    if (!root) return -1;
    while (root->kanan) root = root->kanan;
    return root->nilai;
}

// Menghitung jumlah semua node
int hitungNode(Node* root) {
    if (!root) return 0;
    return 1 + hitungNode(root->kiri) + hitungNode(root->kanan);
}

int main() {
    Node* root = nullptr;
    int pilih, nilai;

    do {
        cout << "\n=== PENGELOLAAN NILAI (BST) ===\n";
        cout << "1. Tambah Nilai\n";
        cout << "2. Cari Nilai\n";
        cout << "3. Tampilkan Semua Nilai (Urut)\n";
        cout << "4. Nilai Tertinggi\n";
        cout << "5. Nilai Terendah\n";
        cout << "6. Hitung Jumlah Nilai\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                root = tambah(root, nilai);
                break;

            case 2:
                cout << "Masukkan nilai yang dicari: ";
                cin >> nilai;
                cout << (cari(root, nilai) ? "Ditemukan\n" : "Tidak ditemukan\n");
                break;

            case 3:
                if (!root) cout << "Belum ada data.\n";
                else {
                    cout << "Data nilai (terurut): ";
                    tampilInorder(root);
                    cout << endl;
                }
                break;

            case 4:
                cout << "Nilai tertinggi: " << cariMax(root) << endl;
                break;

            case 5:
                cout << "Nilai terendah: " << cariMin(root) << endl;
                break;

            case 6:
                cout << "Jumlah data nilai: " << hitungNode(root) << endl;
                break;

            case 7:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 7);

    return 0;
}
