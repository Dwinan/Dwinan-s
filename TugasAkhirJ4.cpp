#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* topPtr = nullptr;

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return topPtr == nullptr;
}

// Fungsi untuk menambahkan teks ke stack (push)
void push(string text) {
    Node* newNode = new Node;
    newNode->data = text;
    newNode->next = topPtr;
    topPtr = newNode;
    cout << "Teks \"" << text << "\" telah ditambahkan.\n";
}

// Fungsi untuk menghapus teks terakhir (undo)
void pop() {
    if (isEmpty()) {
        cout << "Tidak ada yang bisa di-undo!\n";
        return;
    }
    Node* temp = topPtr;
    cout << "Undo: \"" << temp->data << "\"\n";
    topPtr = topPtr->next;
    delete temp;
}

// Fungsi untuk melihat teks terakhir tanpa menghapusnya (peek)
void peek() {
    if (isEmpty()) {
        cout << "Tidak ada teks yang tersimpan.\n";
        return;
    }
    cout << "Teks terakhir yang dimasukkan: \"" << topPtr->data << "\"\n";
}

// Fungsi untuk menampilkan isi stack
void display() {
    if (isEmpty()) {
        cout << "Tidak ada riwayat teks.\n";
        return;
    }
    cout << "Riwayat teks (dari terbaru ke terlama):\n";
    Node* cur = topPtr;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next != nullptr) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
}

// Fungsi utama
int main() {
    int pilihan;
    string teks;

    do {
        cout << "=== SIMULASI UNDO TEKS ===\n";
        cout << "1. Tambah teks\n";
        cout << "2. Undo teks terakhir\n";
        cout << "3. Lihat teks terakhir\n";
        cout << "4. Tampilkan riwayat teks\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan teks: ";
                getline(cin, teks);
                push(teks);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    while (!isEmpty()) pop();
    return 0;
}
