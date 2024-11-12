/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

queue<int> antrian;

// Definisikan struktur simpul Tree
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    // Konstruktor untuk membuat simpul baru dengan data tertentu
    TreeNode(const string& value) : data(value), left(nullptr), right(nullptr) {}
};

// Struktur untuk menyimpan data mahasiswa
struct DataMahasiswa {
    string nama;
    string nim;
    int umur;
    string asal;
};

// Fungsi untuk menyisipkan nilai ke dalam BST berdasarkan NIM
TreeNode* insertByNIM(TreeNode* root, const DataMahasiswa& mhs) {
    if (root == nullptr) {
        return new TreeNode(mhs.nim); // Gunakan NIM sebagai kunci
    }

    if (mhs.nim < root->data) {
        root->left = insertByNIM(root->left, mhs);
    } else {
        root->right = insertByNIM(root->right, mhs);
    }

    return root;
}

// Fungsi untuk traversal inorder (urutan terurut)
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << endl;
        inorderTraversal(root->right);
    }
}

// Menyambut para pengguna
void sambutan(){
    cout << "--------------------------------" << endl;
    cout << "|SELAMAT DATANG DI PERPUSTAKAAN|" << endl;
    cout << "|     SILAHKAN MENGISI DATA    |" << endl;
    cout << "|   JIKA BELUM MEMPUNYAI KTM   |" << endl;
    cout << "--------------------------------" << endl << endl;
}

// Penutup di akhir program
void penutup(){
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "|TERIMA KASIH TELAH MENGGUNAKAN PROGRAM SAYA|" << endl;
    cout << "---------------------------------------------" << endl;
}

// Menentukan apakah pengguna butuh mengisi data atau tidak
bool KTM() {
    string jawab;
    while (true) {
        cout << "Apakah anda memiliki Kartu Tanda Mahasiswa? (y/t): ";
        cin >> jawab;

        // Ubah input menjadi huruf kecil agar tidak terjadi kesalahan penulisan besar kecil
        for (char &c : jawab) {
            c = tolower(c);
        }

        // Periksa jika respons adalah ya atau tidak
        if (jawab == "ya" || jawab == "y") {
            return true;
        } else if (jawab == "tidak" || jawab == "t") {
            return false;
        } else {
            cout << "Mohon masukkan ya atau tidak saja." << endl;
        }
    }
}

// mengambil nomor antrian
void ambil(){
    int ant = 1;
    antrian.push(ant);
    cout << "nomor antrian ke-" << ant << endl;
    ant++;
}

// menghapus nomor antrian pada queue
void panggil(){
    cout << "silahkan masuk" << endl;
    antrian.pop();
}

int main(){

    sambutan();
    
    // Panggil fungsi KTM dan simpan nilai kembalinya
    bool punyaKTM = KTM();
    if(punyaKTM){ // Panggil fungsi KTM() dengan menambahkan tanda kurung
        cout << "Silahkan masuk" << endl << endl;
        penutup();
        return 0;
    }
    else {
        cout << "Silahkan masukkan data diri dan mengambil nomor antrian" << endl;
    }

    ambil();
    panggil();

    vector<DataMahasiswa> datanama; 
    DataMahasiswa mhs;
    int a;
    cout << "Masukkan jumlah mahasiswa yang diinginkan: ";
    cin >> a;

    for (int i = 0; i < a; i++){
        cout << "Masukkan nama anda: ";
        cin >> mhs.nama;
        cout << "Masukkan NIM anda: ";
        cin >> mhs.nim;
        cout << "Masukkan umur anda: ";
        cin >> mhs.umur;
        cout << "Masukkan asal anda: ";
        cin >> mhs.asal;

        datanama.push_back(mhs);
        }

    cout << "\nData Mahasiswa:" << endl;
    for (const auto& mahasiswa : datanama) {
        cout << "Nama: " << mahasiswa.nama << ", NIM: " << mahasiswa.nim << ", Umur: " << mahasiswa.umur << ", Asal: " << mahasiswa.asal << endl;

        // Membuat struktur tree dan menambahkan data mahasiswa ke dalamnya
        TreeNode* root = new TreeNode("Data Mahasiswa");
        root->left = new TreeNode("Nama: " + mhs.nama);
        root->left->left = new TreeNode("NIM: " + mhs.nim);
        root->left->right = new TreeNode("Umur: " + to_string(mhs.umur));
        root->right = new TreeNode("Asal: " + mhs.asal);

        // Menampilkan struktur tree
        cout << "Struktur data mahasiswa:" << endl;
        cout << root->data << endl;
        cout << "|-- " << root->left->data << endl;
        cout << "|   |-- " << root->left->left->data << endl;
        cout << "|   |-- " << root->left->right->data << endl;
        cout << "|-- " << root->right->data << endl;
        
        // Dealokasi memori untuk mencegah kebocoran memori
        delete root->left->left;
        delete root->left->right;
        delete root->left;
        delete root->right;
        delete root;
    }
    // Membuat BST untuk menyimpan data mahasiswa berdasarkan NIM
    TreeNode* root = nullptr;
    for (const auto& mahasiswa : datanama) {
        root = insertByNIM(root, mahasiswa);
    }

    // Menampilkan data mahasiswa yang telah diurutkan berdasarkan NIM
    cout << "\nData Mahasiswa yang diurutkan berdasarkan NIM:" << endl;
    inorderTraversal(root);

    penutup();

    return 0;
}
