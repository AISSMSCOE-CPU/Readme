#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node *left,*right;
    string keyword,meaning;
};

Node *createnode(string k, string m){
    Node *temp = new Node;
    temp->keyword = k;
    temp->meaning = m;
    temp->right = nullptr;
    temp->left = nullptr;
    return temp;
}

Node *insert(Node *root, string k,string m){
    if(root == nullptr){
        return createnode(k,m);
    }
    if(k < root->keyword){
        root->left = insert(root->left,k,m);
    }
    else if(k>root->keyword){
        root->right = insert(root->left,k,m);
    }
    else{
        cout << "Keyword already exists..";

    }
    return root;
}

Node *search(Node *root , string  k , string m){
    int count=0;
    while(root != nullptr){
        count++;

        if(k == root->keyword){
            return root;
        }
        else if( k < root->keyword){
            root = root->left;
        }
        else if(k > root->keyword){
            root = root->right;
        }
    }
   
    return nullptr;
}
Node *minimum(){
    if(root == nullptr){
        return nullptr;
    }
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}
Node *deletenode(Node *root, string k){
    if(root == nullptr){
        return nullptr;
    }
}