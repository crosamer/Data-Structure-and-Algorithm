/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/

#include <iostream> // untuk menambahkan file iostream pada program
#include <queue> // untuk mengimplementasikan struktur data queue
#include <stack> // untuk mengimplementasikan struktur data stack

using namespace std; // mempermudah penggunaan std yang mana kita tidak perlu menuliskan std pada main

int main()
{
    // Stack untuk menyimpan perintah
    stack<int> perintah;
    // Queue untuk menyimpan hasil
    queue<int> queue;
    // Variabel untuk  menyimpan input pilihan
    int choice = 0;

    while (choice != 5)
    {
        cout << "Pilih perintah :\n";
        cout << "1. PUSH 0\n2. PUSH 1\n3. TOP\n4. POP\n5. Selesai\n";
        cout << "Pilihan anda : ";

        cin >> choice;

        switch(choice){
            case 1:
                perintah.push(0); // perintah push 0
                break;
            case 2:
                perintah.push(1); // perintah push 1
                break;
            case 3:
                queue.push(perintah.top()); // perintah top
                break;
            case 4:
                perintah.pop(); // perintah pop
                break;
        }
    }

    cout << "Isi queue:" << endl;
    // Iterasi while akan dijalankan selama isi queue tidak kosong
    while (!queue.empty())
    {
        cout << queue.front(); // Menampilkan elemen queue paling depan
        queue.pop(); // Menghapus elemen queue paling depan
    }
    cout << endl;

    return 0;
}