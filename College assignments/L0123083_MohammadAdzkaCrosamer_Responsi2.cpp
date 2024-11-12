/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/
#include <bits/stdc++.h>
using namespace std;

// Struktur untuk menyimpan data buku
struct Data {
    vector<string> judul;
    vector<string> pengarang;
    vector<int> tahunTerbit;
    vector<double> harga;
};

// Fungsi untuk menampilkan data buku
void displayData(const Data& data) {
    int n = data.judul.size();
    for (int i = 0; i < n; ++i) {
        cout << "Judul: " << data.judul[i] << endl << "Pengarang: " << data.pengarang[i] << endl
            << "Tahun Terbit: " << data.tahunTerbit[i] << endl << "Harga: " << data.harga[i] << endl;
    }
}

// Fungsi Bubble Sort berdasarkan tahun terbit
void bubbleSort(Data& data) {
    int n = data.tahunTerbit.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (data.tahunTerbit[j] > data.tahunTerbit[j+1]) {
                swap(data.tahunTerbit[j], data.tahunTerbit[j+1]);
                swap(data.judul[j], data.judul[j+1]);
                swap(data.pengarang[j], data.pengarang[j+1]);
                swap(data.harga[j], data.harga[j+1]);
            }
        }
    }
}

// Fungsi Selection Sort berdasarkan harga
void selectionSort(Data& data) {
    int n = data.harga.size();
    for (int i = 0; i < n-1; ++i) {
        int minIndex = i;
        for (int j = i+1; j < n; ++j) {
            if (data.harga[j] < data.harga[minIndex]) {
                minIndex = j;
            }
        }
        swap(data.harga[i], data.harga[minIndex]);
        swap(data.judul[i], data.judul[minIndex]);
        swap(data.pengarang[i], data.pengarang[minIndex]);
        swap(data.tahunTerbit[i], data.tahunTerbit[minIndex]);
    }
}

// Fungsi Insertion Sort berdasarkan judul
void insertionSort(Data& data) {
    int n = data.judul.size();
    for (int i = 1; i < n; ++i) {
        string keyJudul = data.judul[i];
        string keyPengarang = data.pengarang[i];
        int keyTahun = data.tahunTerbit[i];
        double keyHarga = data.harga[i];
        int j = i - 1;
        while (j >= 0 && data.judul[j] > keyJudul) {
            data.judul[j+1] = data.judul[j];
            data.pengarang[j+1] = data.pengarang[j];
            data.tahunTerbit[j+1] = data.tahunTerbit[j];
            data.harga[j+1] = data.harga[j];
            j = j - 1;
        }
        data.judul[j+1] = keyJudul;
        data.pengarang[j+1] = keyPengarang;
        data.tahunTerbit[j+1] = keyTahun;
        data.harga[j+1] = keyHarga;
    }
}

// Fungsi untuk partition dalam Quick Sort
int partition(Data& data, int low, int high) {
    int pivot = data.tahunTerbit[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (data.tahunTerbit[j] < pivot) {
            ++i;
            swap(data.tahunTerbit[i], data.tahunTerbit[j]);
            swap(data.judul[i], data.judul[j]);
            swap(data.pengarang[i], data.pengarang[j]);
            swap(data.harga[i], data.harga[j]);
        }
    }
    swap(data.tahunTerbit[i + 1], data.tahunTerbit[high]);
    swap(data.judul[i + 1], data.judul[high]);
    swap(data.pengarang[i + 1], data.pengarang[high]);
    swap(data.harga[i + 1], data.harga[high]);
    return (i + 1);
}

// Fungsi Quick Sort berdasarkan tahun terbit
void quickSort(Data& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

// Fungsi untuk merge dalam Merge Sort
void merge(Data& data, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    vector<string> Ljudul(n1), Rjudul(n2), Lpengarang(n1), Rpengarang(n2);
    vector<double> Lharga(n1), Rharga(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = data.tahunTerbit[l + i];
        Ljudul[i] = data.judul[l + i];
        Lpengarang[i] = data.pengarang[l + i];
        Lharga[i] = data.harga[l + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = data.tahunTerbit[m + 1 + i];
        Rjudul[i] = data.judul[m + 1 + i];
        Rpengarang[i] = data.pengarang[m + 1 + i];
        Rharga[i] = data.harga[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data.tahunTerbit[k] = L[i];
            data.judul[k] = Ljudul[i];
            data.pengarang[k] = Lpengarang[i];
            data.harga[k] = Lharga[i];
            ++i;
        } else {
            data.tahunTerbit[k] = R[j];
            data.judul[k] = Rjudul[j];
            data.pengarang[k] = Rpengarang[j];
            data.harga[k] = Rharga[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        data.tahunTerbit[k] = L[i];
        data.judul[k] = Ljudul[i];
        data.pengarang[k] = Lpengarang[i];
        data.harga[k] = Lharga[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        data.tahunTerbit[k] = R[j];
        data.judul[k] = Rjudul[j];
        data.pengarang[k] = Rpengarang[j];
        data.harga[k] = Rharga[j];
        ++j;
        ++k;
    }
}

// Fungsi Merge Sort berdasarkan tahun terbit
void mergeSort(Data& data, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);
        merge(data, l, m, r);
    }
}

// Fungsi Binary Search berdasarkan tahun terbit
int binarySearch(const Data& data, int target) {
    int left = 0;
    int right = data.tahunTerbit.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data.tahunTerbit[mid] == target) {
            return mid;
        }

        if (data.tahunTerbit[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout << "------------------------------" << endl;
    cout << "SELAMAT DATANG DI PERPUSTAKAAN" << endl;
    cout << "------------------------------" << endl;

    Data data;
    int n;
    cout << "Masukkan jumlah buku: ";
    cin >> n;
    data.judul.resize(n);
    data.pengarang.resize(n);
    data.tahunTerbit.resize(n);
    data.harga.resize(n);

    for (int i = 0; i < n; ++i) {
        cout << "Masukkan judul buku ke-" << i+1 << ": ";
        cin.ignore();
        getline(cin, data.judul[i]);
        cout << "Masukkan pengarang buku ke-" << i+1 << ": ";
        getline(cin, data.pengarang[i]);
        cout << "Masukkan tahun terbit buku ke-" << i+1 << ": ";
        cin >> data.tahunTerbit[i];
        cout << "Masukkan harga buku ke-" << i+1 << ": ";
        cin >> data.harga[i];
    }

    cout << "\nData sebelum diurutkan:\n";
    displayData(data);

    // Mengurutkan data berdasar tahun terbit menggunakan Bubble Sort
    bubbleSort(data);
    cout << "\nData setelah diurutkan menggunakan Bubble Sort berdasarkan tahun terbit:\n";
    displayData(data);

    // Mengurutkan data berdasar harga menggunakan Selection Sort
    selectionSort(data);
    cout << "\nData setelah diurutkan menggunakan Selection Sort berdasarkan harga:\n";
    displayData(data);

    // Mengurutkan data berdasar judul menggunakan Insertion Sort
    insertionSort(data);
    cout << "\nData setelah diurutkan menggunakan Insertion Sort berdasarkan judul:\n";
    displayData(data);

    // Mengurutkan data berdasar tahun terbit menggunakan Quick Sort
    quickSort(data, 0, n - 1);
    cout << "\nData setelah diurutkan menggunakan Quick Sort berdasarkan tahun terbit:\n";
    displayData(data);

    // Mengurutkan data berdasar tahun terbit menggunakan Merge Sort
    mergeSort(data, 0, n - 1);
    cout << "\nData setelah diurutkan menggunakan Merge Sort berdasarkan tahun terbit:\n";
    displayData(data);

    // Mencari tahun terbit menggunakan Binary Search
    int targetYear;
    cout << "\nMasukkan tahun terbit yang ingin dicari: ";
    cin >> targetYear;

    int index = binarySearch(data, targetYear);
    if (index != -1) {
        cout << "Buku ditemukan:\n";
        cout << "Judul: " << data.judul[index] << ", Pengarang: " << data.pengarang[index]
            << ", Tahun Terbit: " << data.tahunTerbit[index] << ", Harga: " << data.harga[index] << endl;
    } else {
        cout << "Buku dengan tahun terbit " << targetYear << " tidak ditemukan.\n";
    }
    cout << "-------------------------------------------" << endl;
    cout << "Terima Kasih Sudah Menggunakan Program Kami" << endl;
    cout << "-------------------------------------------" << endl;
    return 0;
}
