#include <iostream>
using namespace std;

const int SIZE = 10;

enum SlotState { EMPTY, OCCUPIED, DELETED };

struct Entry {
    int key;
    int value;
    SlotState state;
};

int hashFunction(int key) {return (key % SIZE + SIZE) % SIZE;}

void initTable(Entry table[]) {
    for (int i = 0; i < SIZE; ++i)
        table[i].state = EMPTY;
}

bool insertEntry(Entry table[], int key, int value) {
    int idx = hashFunction(key);
    int firstDeleted = -1;

    for (int step = 0; step < SIZE; ++step) {
        int i = (idx + step) % SIZE;

        if (table[i].state == OCCUPIED) {
            if (table[i].key == key) { // update jika sudah ada
                table[i].value = value;
                return true;
            }
        } else if (table[i].state == DELETED) {
            if (firstDeleted == -1) firstDeleted = i;
        } else { // slot kosong
            int target = (firstDeleted != -1) ? firstDeleted : i;
            table[target].key = key;
            table[target].value = value;
            table[target].state = OCCUPIED;
            return true;
        }
    }
    return false; // tabel penuh
}

Entry* searchEntry(Entry table[], int key) {
    int idx = hashFunction(key);
    for (int step = 0; step < SIZE; ++step) {
        int i = (idx + step) % SIZE;
        if (table[i].state == EMPTY) return nullptr;
        if (table[i].state == OCCUPIED && table[i].key == key)
            return &table[i];
    }
    return nullptr;
}

bool removeKey(Entry table[], int key) {
    Entry* e = searchEntry(table, key);
    if (!e) return false;
    e->state = DELETED;
    return true;
}

void displayTable(Entry table[]) {
    cout << "Isi Hash Table (Open Addressing, Linear Probing):\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << ": ";
        if (table[i].state == EMPTY) cout << "EMPTY\n";
        else if (table[i].state == DELETED) cout << "DELETED\n";
        else cout << "(" << table[i].key << "," << table[i].value << ")\n";
    }
}

int main() {
    Entry table[SIZE];
    initTable(table);
    int pilihan, key, value;

    do {
        cout << "=== HASH MAP (Open Addressing) ===\n";
        cout << "1. Insert / Update\n2. Search\n3. Delete\n4. Display\n5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "Masukkan key: ";
                cin >> key;
                cout << "Masukkan value: ";
                cin >> value;
                if (insertEntry(table, key, value)) {cout << "Data berhasil dimasukkan!\n";
                } else {cout << "Tabel penuh, insert gagal.\n";}
                break;}
            case 2: {
                cout << "Masukkan key yang dicari: ";
                cin >> key;
                Entry* result = searchEntry(table, key);
                if (result) {cout << "Key ditemukan, value = " << result->value << "\n";
                } else {cout << "Key tidak ditemukan.\n";}
                break;}
            case 3: {
                cout << "Masukkan key yang ingin dihapus: ";
                cin >> key;
                if (removeKey(table, key)){cout << "Key berhasil dihapus.\n";
                } else {cout << "Key tidak ditemukan.\n";}
                break;}
            case 4: {
                displayTable(table);
                break;}
            case 5:{
                cout << "Program selesai.\n";
                break;}
            default:{
                cout << "Pilihan tidak valid.\n";}
        }
    } while (pilihan != 5);

    return 0;
}