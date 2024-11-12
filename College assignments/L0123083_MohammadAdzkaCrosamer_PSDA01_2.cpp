/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/

#include <iostream> // untuk menambahkan file iostream pada program
#include <stack> // untuk menggunakan fungsi visit dan back
#include <string> // menyimpan dan menampilkan nama website sebagai objek tipe data

using namespace std; // mempermudah penggunaan std yang mana kita tidak perlu menuliskan std lagi

// Mendeklarasikan stack dengan nama history
stack<string> history;

// Mendeklarasikan fungsi visit dengan parameter string
void visit(string website)
{
    // Memasukkan string dalam stack history dengan operasi push
    history.push(website);
    cout << "Mengunjungi " << website << endl;
}

void back()
{
    // Jika stack tidak kosong maka perintah di dalam fungsi if akan dijalankan
    if (history.size() != 0){
        // Menghapus string yang terakhir masuk dalam stack history dengan operasi pop
        history.pop();
        string current_page = history.top();
        cout << "Mengunjungi " << current_page << endl;
    }else {
        cout << "Tidak ada halaman sebelumnya" << endl;
    }
}

int main()
{
    visit("google.com");
    visit("instagram.com");
    visit("github.com");
    back();
    back();
    visit("stackoverflow.com");

    return 0;
}
