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

void insertBST(pointer & root, pointer newElement) {
  if(root == nullptr){
    root = newElement;
  } else if(isHigherThanRoot(root, newElement) == true){
    insertBST(root->right, newElement);
  } else insertBST(root->left, newElement);
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
        if (first != 1){
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
        insertBST(root, newData);
        first = 0;
    }
    kata.close();
    desc.close();
}