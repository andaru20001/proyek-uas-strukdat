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
  while (root->kata[i] != 0 && data->kata[i] != 0){
    if (root->kata[i] > data->kata[i]){
      hasil = 0;
      break;
    }
    else if (root->kata[i] < data->kata[i]){
      hasil = 1;
      break;
    }
    else if (root->kata[i+1] == 0 || data->kata[i+1] == 0){
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
    if (root->kata[i] == 0){
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
    std::cout << "Kata yang dicari :\n" << data->kata << "\n\n";
    std::cout << "Penjelasan :\n" << data->desc << "\n\n";
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
  // bool first = 1;
  kata.open("kata.txt");
  desc.open("desc.txt");
  while (!kata.eof()){
    newData = new Node;
    setNode(newData);
    // if (first == 1){
    //     std::getline(kata, temp);
    // }
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
  pointer root = nullptr;
  load_data(root);
  while(ulang){
    clrscr();
    title("PROGRAM KAMUS");
    std::cout << "1. Laman Cari Kosakata\n2. Laman Tentang Program\n3. Tutup Program\n";

    // Tampilkan kode-kode untuk masuk ke salah satu programnya. 
    // 1 untuk program utama/pencarian kamus
    // 2 untuk laman tentang program
    // 3 untuk keluar program
    std::cout << "Masukkan Pilihan   :\n";
    std::cin >> kodeProgram;
    
    switch (kodeProgram){
      case 1: {//Case Laman Cari Kata
        clrscr();
        title("CARI KOSAKATA");
        std::string kata = "";
        pointer temp = nullptr;

        std::cout << "Masukkan kosakata yang ingin dicari :\n";
        std::cin >> kata;

        std::cout << "\n";
        temp = search(root, kata);
        if (temp == nullptr){
          std::cout << "\nKata tidak ditemukan.\n\n";
        }
        else{
          print(temp);
        }

        std::cout << "Tekan Enter untuk kembali ke menu utama\n";
        std::cin.get();
        std::cin.get();
        break;}
      case 2: {//Case Laman Tentang
        clrscr();
        title("TENTANG PROGRAM");

        std::cout << "Program ini memiliki manfaat bagi masyarakat, yaitu berguna untuk pencarian kosakata dalam kamus dengan mudah dalam skala kecil.\n\n"
                  << "Program ini dibuat berdasarkan ide yang diambil dari sebuah paper dengan judul 'Aplikasi Binary Search Tree Sebagai Metode Pencarian Dalam Kamus'. Sumber kosakata dan penjelasan setiap kosakata diambil dari web KBBI (https://www.kbbi.co.id)\n\n"
                  << "Program ini dibuat oleh :\n"
                  << "Della Fauziyyah Husna (NPM 140810200012)\n"
                  << "Andaru Danurdara Wibisana (NPM 140810200020)\n\n";

        std::cout << "Tekan Enter untuk kembali ke menu utama\n";
        std::cin.get();
        std::cin.get();
        break;}
      case 3: {//Case Tutup Program
        clrscr();
        title("TUTUP PROGRAM");
        char konfirm;

        std::cout << "Apakah anda yakin ingin menutup program? (y/n)\n";
        while(1){
          std::cin >> konfirm;

          if (konfirm == 'y' || konfirm == 'Y'){
            ulang = false;
            break;
          }
          else if (konfirm == 'n' || konfirm == 'N'){
            break;         
          }
          else{
            std::cout << "Kode yang dimasukkan tidak valid. Masukkan kembali kode (y/n)\n";
          }
        }
        break;}
      default: {
        std::cout << "Kode yang dimasukkan tidak valid. Masukkan kembali kode program.\n";
        std::cin.get();
        std::cin.get();
        break;}
    }
  }
  return 0;
}