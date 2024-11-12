/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class link {
private:
    unordered_map<string, unordered_set<string>> linked;

public:
    // 1. Menambahkan mahasiswa baru beserta daftar teman-temannya
    void tambahMahasiswa(const string& mahasiswa, const vector<string>& temanTeman) {
        for (const auto& namaTeman : temanTeman) {
            linked[mahasiswa].insert(namaTeman);
            linked[namaTeman].insert(mahasiswa);
        }
    }

    // 2. Menambahkan hubungan pertemanan antara dua mahasiswa yang sudah terdaftar
    void tambahPertemanan(const string& mahasiswa1, const string& mahasiswa2) {
        linked[mahasiswa1].insert(mahasiswa2);
        linked[mahasiswa2].insert(mahasiswa1);
    }

    // 3. Menghapus mahasiswa beserta seluruh hubungan pertemanannya
    void hapusMahasiswa(const string& mahasiswa) {
        if (linked.find(mahasiswa) != linked.end()) {
            for (const auto& namaTeman : linked[mahasiswa]) {
                linked[namaTeman].erase(mahasiswa);
            }
            linked.erase(mahasiswa);
        }
    }

    // 4. Mencari teman bersama antara dua mahasiswa yang sudah terdaftar
    vector<string> cariTemanBersama(const string& mahasiswa1, const string& mahasiswa2) {
        vector<string> temanBersama;
        if (linked.find(mahasiswa1) != linked.end() && linked.find(mahasiswa2) != linked.end()) {
            for (const auto& namaTeman : linked[mahasiswa1]) {
                if (linked[mahasiswa2].find(namaTeman) != linked[mahasiswa2].end()) {
                    temanBersama.push_back(namaTeman);
                }
            }
        }
        return temanBersama;
    }

    // 5. Menampilkan daftar teman dari seorang mahasiswa tertentu
    vector<string> daftarTeman(const string& mahasiswa) {
        vector<string> daftarTeman;
        if (linked.find(mahasiswa) != linked.end()) {
            for (const auto& namaTeman : linked[mahasiswa]) {
                daftarTeman.push_back(namaTeman);
            }
        }
        return daftarTeman;
    }

};

void tampilkanMenu() {
    cout << "Menu: " << endl;
    cout << "1. Tambahkan mahasiswa baru beserta daftar teman-temannya" << endl;
    cout << "2. Tambahkan hubungan pertemanan antara dua mahasiswa yang sudah terdaftar" << endl;
    cout << "3. Hapus mahasiswa beserta seluruh hubungan pertemanannya" << endl;
    cout << "4. Cari teman bersama antara dua mahasiswa yang sudah terdaftar" << endl;
    cout << "5. Tampilkan daftar teman dari seorang mahasiswa tertentu" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main() {
    link js;
    int input;
    string mahasiswa, mahasiswa1, mahasiswa2, namaTeman;
    vector<string> temanTeman;
    int jumlahTeman;

    do {
        tampilkanMenu();
        cin >> input;

        switch (input) {
        case 1:
            cout << "Masukkan nama mahasiswa baru: ";
            cin >> mahasiswa;
            cout << "Masukkan jumlah teman: ";
            cin >> jumlahTeman;
            temanTeman.clear();
            for (int i = 0; i < jumlahTeman; ++i) {
                cout << "Masukkan nama teman ke-" << i + 1 << ": ";
                cin >> namaTeman;
                temanTeman.push_back(namaTeman);
            }
            js.tambahMahasiswa(mahasiswa, temanTeman);
            break;

        case 2:
            cout << "Masukkan nama mahasiswa pertama: ";
            cin >> mahasiswa1;
            cout << "Masukkan nama mahasiswa kedua: ";
            cin >> mahasiswa2;
            js.tambahPertemanan(mahasiswa1, mahasiswa2);
            break;

        case 3:
            cout << "Masukkan nama mahasiswa yang akan dihapus: ";
            cin >> mahasiswa;
            js.hapusMahasiswa(mahasiswa);
            break;

        case 4:
            cout << "Masukkan nama mahasiswa pertama: ";
            cin >> mahasiswa1;
            cout << "Masukkan nama mahasiswa kedua: ";
            cin >> mahasiswa2;
            {
                auto temanBersama = js.cariTemanBersama(mahasiswa1, mahasiswa2);
                cout << "Teman bersama " << mahasiswa1 << " dan " << mahasiswa2 << ": ";
                for (const auto& nama : temanBersama) {
                    cout << nama << " ";
                }
                cout << endl;
            }
            break;

        case 5:
            cout << "Masukkan nama mahasiswa: ";
            cin >> mahasiswa;
            {
                auto daftarTeman = js.daftarTeman(mahasiswa);
                cout << "Daftar teman " << mahasiswa << ": ";
                for (const auto& nama : daftarTeman) {
                    cout << nama << " ";
                }
                cout << endl;
            }
            break;

        case 0:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "input tidak valid. Silakan coba lagi." << endl;
            break;
        }
    } while (input != 0);

    return 0;
}
