#include <iostream>
using namespace std;

struct Node{
    Node *left,*right;
    int data;
};

Node* createnode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

Node *insert(Node *root,int x){
    if(root == nullptr){
        return createnode(x);
    }
    if(x < root->data){
        root->left = insert(root->left , x);
    }
    else if(x>root->data){
        root->right = insert(root->right,x);
    }

    return root;
}

int height(Node *root){
    if(root == nullptr){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
}

int minimum(Node *root){
    if(root == nullptr){
        return 0;
    }

    while(root->left != nullptr){
        root = root->left;
    }
    return root->data;
}

void swaptree(Node *root){
    if(root == nullptr){
        return;
    }
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    swaptree(root->left);
    swaptree(root->right);
}

int search(Node *root, int x){
    if(root == nullptr){
        return 0;
    }
    if(x == root->data){
        return 1;
    }
    else if( x<root->data){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}

void inorder(Node *root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right); 
    }
    
}

int main(){
    Node *root = nullptr;
    int n,x,choice;

    cout << "Enter the values: ";
    cin >> n;

    for(int i = 0;i<n; i++){
        cin >> x;
        root = insert(root,x);
    }
    do
    {
        cout << "\n\n--- BINARY SEARCH TREE ---\n";
        cout << "1. Insert new node\n";
        cout << "2. Longest path from root\n";
        cout << "3. Minimum value\n";
        cout << "4. Swap left and right pointers\n";
        cout << "5. Search a value\n";
        cout << "6. Display tree (Inorder)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                root = insert(root, x);
                cout << "Node inserted.\n";
                break;

            case 2:
                cout << "Number of nodes in longest path: "
                     << height(root) << endl;
                break;

            case 3:
                if (root == NULL)
                    cout << "Tree is empty.\n";
                else
                    cout << "Minimum value: "
                         << minimum(root) << endl;
                break;

            case 4:
                swaptree(root);
                cout << "Left and right pointers swapped.\n";
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> x;

                if (search(root, x))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;

            case 6:
                cout << "Tree values: ";
                inorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;

}