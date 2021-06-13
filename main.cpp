/*
PROGRAM KAMUS MENGGUNAKAN BINARY SEARCH TREE
Anggota Kelompok : Della Fauziyyah Husna (140810200020)
                   Andaru Danurdara Wibisana (140810200020)
*******************************************************************/

#include <iostream>
#include <fstream>
#include <string>

struct Node{
  std::string kata;
  std::string desc;
  Node* left;
  Node* right;
};

typedef Node* pointer;

void setNode (pointer& data){
  data->kata = "";
  data->desc = "";
  data->left = nullptr;
  data->right = nullptr;
}

bool isHigherThanRoot (pointer root, pointer data){
  int i=0;
  bool hasil = 0;
  bool null = 0;
  while (root->kata[i] != NULL && data->kata[i] != NULL){
    if (root->kata[i] > data->kata[i]){
      hasil = 0;
      break;
    }
    else if (root->kata[i] < data->kata[i]){
      hasil = 1;
      break;
    }
    else if (root->kata[i+1] == NULL || data->kata[i+1] == NULL){
      null = 1;
      i++;
      continue;
    }
    else{
      i++;
      continue;
    }
  }

  if (null){
    if (root->kata[i] == NULL){
      hasil = 0;
    }
    else{
      hasil = 1;
    }
  }

  return hasil;
}

pointer search(pointer& root, std::string kata){
  pointer hasil = nullptr;
  
  if (root != nullptr){
    if (root->kata == kata){
      hasil = root;
    }
    else{
      hasil = search(root->left, kata);
      if (hasil == nullptr){
        hasil = search(root->right, kata);
      }
    }
  }
  return hasil;
}

void print (pointer data){
    std::cout << "Kata yang dicari : " << data->kata << "\n";
    std::cout << "Penjelasan : " << "\n" << data->desc;
}

void insert(pointer & root, pointer newElement) {
  if(root == nullptr){
    root = newElement;
  } else if(isHigherThanRoot(root, newElement) == true){
    insert(root->right, newElement);
  } else insert(root->left, newElement);
}

void load_data(pointer& root){                                       //Fungsi untuk load data dari file kata.txt dan desc.txt
  pointer newData = nullptr;
  std::ifstream kata;
  std::ifstream desc;
  std::string temp;
  bool first = 1;
  kata.open("kata.txt");
  desc.open("desc.txt");
  while (!kata.eof()){
    newData = new Node;
    setNode(newData);
    if (first == 1){
        std::getline(kata, temp);
    }
    std::getline(kata, temp);                       
    if (temp == ""){                                //Jika data.txt kosong, loop diberhentikan dan fungsi load_data() dihentikan/tidak load data apapun dari data.txt
        break;
    }
    newData->kata = temp;
    std::getline(desc, temp);
    newData->desc = temp;
    temp = "";
    insert(root, newData);
    // first = 0;
  }
  kata.close();
  desc.close();
}

void title(std::string text){                                   //Fungsi untuk mencetak judul dari sebuah fungsi/program utama
    int panjang = text.length();
    for (int i=1; i<=panjang; i++){
        std::cout << "=";
    }
    std::cout << "\n" << text << "\n";
    for (int i=1; i<=panjang; i++){
        std::cout << "=";
    }
    std::cout << "\n\n";
}

void clrscr(){                                                   //Fungsi clear screen dengan mencetak new line sebanyak 60 kali
    for (int i=1; i<=60; i++){
        std::cout << "\n";
    }
}

int main(){
  int kodeProgram = 0;
  bool ulang = true;
  while(ulang){
    clrscr();
    title("PROGRAM SISTEM ANTRIAN PEMESANAN TOKO TEKSTIL");
    std::cout << "1. Tambah Pesanan\n2. Hapus Pesanan\n3. Search\n4. Daftar Pesanan\n5. Edit Pesanan\n6. Undo\n7. Save & Exit\n8. Exit without Saving\n";

    // Tampilkan kode-kode untuk masuk ke salah satu programnya. 
    // 1 untuk program utama/pencarian kamus
    // 2 untuk laman tentang program
    // 3 untuk keluar program
    std::cout << "Masukan Pilihan   :\n";
    std::cin >> kodeProgram;
    
    // Jangan lupa sediakan opsi save dan exit dan exit without saving (mungkin bisa diletakkan di pilihan menu kode 7 dan 8)
    // Exit wihout saving cuma untuk error handling ketika pengguna mau membatalkan semua perubahan
    // Untuk variabel kode untuk pilih programnya disepakati aja kali ya, jadi "kodeProgram"
    
    switch (kodeProgram){
      case 1: {//Case Tambah Pesanan
        clrscr();
        title("TAMBAH PESANAN");

        break;}
      case 2: {//Case Hapus Pesanan
        clrscr();
        title("HAPUS PESANAN");

        break;}
      case 3: {//case search (display value dari pesanan yang ingin dicari)

        break;}
      default: {

        break;}
    }
  }
  return 0;
}