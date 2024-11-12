/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/

#include <iostream> // untuk menambahkan file iostream pada program
#include <list> // untuk menggunakan linked list

using namespace std; // mempermudah penggunaan std yang mana kita tidak perlu menuliskan std lagi

int main() {
    // Membuat linked list untuk menyimpan sekumpulan string
    list<string> stringList = {"Rambutan", "Jambu", "Jeruk", "Melon", "Semangka", "Durian"};

    // Menentukan titik pemisahan
    auto middleIter = next(stringList.begin(), 3);  // 3 adalah indeks pertengahan

    // Membagi linked list menjadi dua bagian
    list<string> list1(stringList.begin(), middleIter);
    list<string> list2(middleIter, stringList.end());

    // Menampilkan isi list1
    cout << "Isi List:\n"; // \n berfungsi sama seperti end line
    for (const auto& str : list1) {
        cout << str << endl;
    }
    for (const auto& str : list2) {
        cout << str << endl;
    }

    // Menghapus "Jambu" dari list1
    list1.remove("Jambu");

    // Menghapus "Durian" dari list2
    list2.remove("Durian");

    // Menampilkan isi list1 setelah penghapusan
    cout << "List 1:\n";
    for (const auto& str : list1) {
        cout << str << endl;
    }

    // Menampilkan isi list2 setelah penghapusan
    cout << "List 2:\n";
    for (const auto& str : list2) {
        cout << str << endl;
    }

    return 0;
}
