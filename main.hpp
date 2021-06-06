#include <iostream>

struct Node{
    std::string kata;
    std::string desc;
    Node* left;
    Node* right;
};

typedef Node* pointer;

pointer search(pointer& root, std::string kata) {
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