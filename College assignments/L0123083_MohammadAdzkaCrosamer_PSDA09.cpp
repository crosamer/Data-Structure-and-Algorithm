/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/
#include <bits/stdc++.h>
using namespace std;

struct Song {
    string judul;
    string artis;
    int durasi;
};

vector<Song> songs = {
    {"Indonesia Raya", "Wage Rudolf Supratman", 111},
    {"Never Gonna Give You Up", "Rick Astley", 213},
    {"Everything Is Awesome!!!", "Tegan and Sara", 164},
    {"I Want It That Way", "Backstreet Boys", 220},
    {"Balonku", "Abdullah Totong Mahmud", 180}
};

// Function to partition the array for quicksort
int partition(vector<Song>& arr, int low, int high, string key) {
    Song pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (key == "judul" && arr[j].judul < pivot.judul) {
            i++;
            swap(arr[i], arr[j]);
        } else if (key == "artis" && arr[j].artis < pivot.artis) {
            i++;
            swap(arr[i], arr[j]);
        } else if (key == "durasi" && arr[j].durasi < pivot.durasi) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement quicksort
void quickSort(vector<Song>& arr, int low, int high, string key) {
    if (low < high) {
        int pi = partition(arr, low, high, key);
        quickSort(arr, low, pi - 1, key);
        quickSort(arr, pi + 1, high, key);
    }
}

// Function to merge two halves for mergesort
void merge(vector<Song>& arr, int l, int m, int r, string key) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Song> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (key == "judul" && L[i].judul <= R[j].judul) {
            arr[k] = L[i];
            i++;
        } else if (key == "artis" && L[i].artis <= R[j].artis) {
            arr[k] = L[i];
            i++;
        } else if (key == "durasi" && L[i].durasi <= R[j].durasi) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement mergesort
void mergeSort(vector<Song>& arr, int l, int r, string key) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, key);
        mergeSort(arr, m + 1, r, key);
        merge(arr, l, m, r, key);
    }
}

// Function to output the sorted list
void outputList() {
    for (const auto& song : songs) {
        cout << song.judul << "\t\t\t" << song.artis << "\t\t" << song.durasi << endl;
    }
}

int main() {
    cout << "List Judul Artis Durasi sebelum sorting" << endl;
    outputList();
    cout << endl;

    int pilihan;
    do {
        cout << "Pilih " << endl;
        cout << "1. Sorting list berdasarkan Judul menggunakan quicksort." << endl;
        cout << "2. Sorting list berdasarkan Artis menggunakan quicksort." << endl;
        cout << "3. Sorting list berdasarkan Durasi menggunakan quicksort." << endl;
        cout << "4. Sorting list berdasarkan Judul menggunakan mergesort." << endl;
        cout << "5. Sorting list berdasarkan Artis menggunakan mergesort." << endl;
        cout << "6. Sorting list berdasarkan Durasi menggunakan mergesort." << endl;
        cout << "0. Keluar dari program." << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                quickSort(songs, 0, songs.size() - 1, "judul");
                cout << "List setelah sorting berdasarkan Judul:" << endl;
                outputList();
                cout << endl;
                break;
            case 2:
                quickSort(songs, 0, songs.size() - 1, "artis");
                cout << "List setelah sorting berdasarkan Artis:" << endl;
                outputList();
                cout << endl;
                break;
            case 3:
                quickSort(songs, 0, songs.size() - 1, "durasi");
                cout << "List setelah sorting berdasarkan Durasi:" << endl;
                outputList();
                cout << endl;
                break;
            case 4:
                mergeSort(songs, 0, songs.size() - 1, "judul");
                cout << "List setelah sorting berdasarkan Judul:" << endl;
                outputList();
                cout << endl;
                break;
            case 5:
                mergeSort(songs, 0, songs.size() - 1, "artis");
                cout << "List setelah sorting berdasarkan Artis:" << endl;
                outputList();
                cout << endl;
                break;
            case 6:
                mergeSort(songs, 0, songs.size() - 1, "durasi");
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
