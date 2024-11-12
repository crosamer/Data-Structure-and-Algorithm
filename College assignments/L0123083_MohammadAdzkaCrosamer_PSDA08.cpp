/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> Judul = {"Indonesia Raya", "Never Gonna Give You Up", "Everything Is Awesome!!!", "I Want It That Way", "Balonku"};
vector<string> Artis = {"Wage Rudolf Supratman", "Rick Astley", "Tegan and Sara", "Backstreet Boys", "Abdullah Totong Mahmud"};
vector<int> Durasi = {111, 213, 164, 220, 180};

// Function to sort based on Judul using bubble sort
void bubbleSort() {
    int n = Judul.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(Judul[j] > Judul[j + 1]) {
                swap(Judul[j], Judul[j + 1]);
                swap(Artis[j], Artis[j + 1]);
                swap(Durasi[j], Durasi[j + 1]);
            }
        }
    }
}

// Function to sort based on Artis using selection sort
void selectionSort() {
    int n = Artis.size();
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(Artis[j] < Artis[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(Judul[i], Judul[minIndex]);
            swap(Artis[i], Artis[minIndex]);
            swap(Durasi[i], Durasi[minIndex]);
        }
    }
}

// Function to sort based on Durasi using insertion sort
void insertionSort() {
    int n = Durasi.size();
    for(int i = 1; i < n; i++) {
        int key = Durasi[i];
        string keyJudul = Judul[i];
        string keyArtis = Artis[i];
        int j = i - 1;
        while(j >= 0 && Durasi[j] > key) {
            Durasi[j + 1] = Durasi[j];
            Judul[j + 1] = Judul[j];
            Artis[j + 1] = Artis[j];
            j--;
        }
        Durasi[j + 1] = key;
        Judul[j + 1] = keyJudul;
        Artis[j + 1] = keyArtis;
    }
}

// Function to output the sorted list
void outputList() {
    for (int i = 0; i < Judul.size(); i++){
        cout << Judul[i] << "\t\t\t" << Artis[i] << "\t\t" << Durasi[i] << endl;
    }
}

int main() {
    cout << "List Judul Artis Durasi sebelum sorting" << endl;
    outputList();
    cout << endl;

    int pilihan;
    do {
        cout << "Pilih " << endl;
        cout << "1. Sorting list berdasarkan Judul menggunakan bubble sort." << endl;
        cout << "2. Sorting list berdasarkan Artis menggunakan selection sort." << endl;
        cout << "3. Sorting list berdasarkan Durasi menggunakan insertion sort." << endl;
        cout << "0. Keluar dari program." << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                bubbleSort();
                cout << "List setelah sorting berdasarkan Judul:" << endl;
                outputList();
                cout << endl;
                break;
            case 2:
                selectionSort();
                cout << "List setelah sorting berdasarkan Artis:" << endl;
                outputList();
                cout << endl;
                break;
            case 3:
                insertionSort();
                cout << "List setelah sorting berdasarkan Durasi:" << endl;
                outputList();
                cout << endl;
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Masukkan nilai yang ada" << endl << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
