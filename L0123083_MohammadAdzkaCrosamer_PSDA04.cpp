/*
Nama    : Mohammad Adzka Crosamer
NIM     : L0123083
Kelas   : C
*/
#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

// deklarasi set dan map
set<string> dataUser;
map<string, string> dataPw;

// daftar akun
void signUp(string username, string password)
{
    // mengecek apakah usn sudah terdaftar
    if (dataUser.count(username) == 1)   {
        cout << "Pendaftaran gagal. Username telah digunakan." << endl;
        }
    // memasukkan data jika belum terdaftar
    else{ 
        dataUser.insert(username);
        dataPw[username] = password;
        cout << "Pendaftaran berhasil." << endl;
    }
}

// masuk akun
void login(string username, string password)
{   
    // cek apakah password yang dimasukkan sama dengan password yang terdaftar
    if (dataPw[username] == password){
        cout << "Login berhasil."<< endl;
    // cek apakah username yang dimasukkan tidak ada di dalam set dataUser
    } else if (dataUser.count(username) != 1){
        cout << "Login gagal. Username tidak ditemukan." << endl;
    } else{
        cout << "Login gagal. Password salah" << endl;
    } 
}

int main(){
    
    signUp("user1", "password123");
    signUp("user2", "hello456");
    login("user1", "password123");
    login("user1", "wrongpassword");
    login("user3", "password789");

    return 0;
}