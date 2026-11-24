#include <iostream>
using namespace std;

struct Node{
    int roll;
    Node *next;
};

Node *insert(Node *head,int x){
    Node *temp = new Node;
    temp->roll = x;
    temp->next = nullptr;

    if(head == nullptr){
        return temp;
    }
    Node *p = head;
    while(p->next != nullptr){
    p = p->next;
    }
    p->next = temp;
    return head;
    
}

int search(Node *head, int x){
    if(head == nullptr){
        return 0;
    }
    Node *p = head;
    while(p != nullptr){
        if(x == p->roll){
            return 1;
        }
        else{
            p = p->next;
        }
    }
    return 0;
}

void display(Node *head){
    while(head != nullptr){
        cout << head->roll << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node *A = nullptr,*B = nullptr;
    Node *p;
    int v,s,x,total;

    cout << "Enter the number of students: ";
    cin >> total;

    cout << "Enter the number of students that like Vanila: ";
    cin >> v;

    cout << "Enter the roll number of students that like Vanilla: ";
    for(int i = 0; i<v;i++){
        cin >> x;
        A = insert(A,x);
    }
    cout << "Enter the number of students that like Butterscotch: ";
    cin >> s;

    cout << "Enter the roll numbers of the students that like Butterscotch";
    for(int i=0; i<s;i++){
        cin >> x;
        B = insert(B,x);
    }

    cout << "\n Students who like either or both";
    p= B;
    while(p!=nullptr){
        if(!search(A,p->roll)){
            cout << p->roll << " ";
            
        }
        p = p->next;
    }
    cout << endl;

    cout <<"\n Students who like both";
    p = B;
    while(p!=nullptr){
        if(search(A,p->roll)){
            cout << p->roll << " ";
            
        }
        p = p->next;
    }
        cout << endl;


    cout << "Students who like butterscotch: ";
    p = A;
    while(p!=nullptr){
        if(!search(B,p->roll)){
            cout << p->roll << " ";
            
        }
        p = p->next;
    }
        cout << endl;

    cout << "Students who lik Vanilla: ";
    p = B;
    while(p!= nullptr){
        if(!search(A,p->roll)){
            cout << p->roll << " ";
            
        }
        p = p->next;
    }
    cout << endl;

    int count = 0;
    cout << "Students who like neither butterscotch or Vanilla: ";

    for(int i = 0;i<total;i++){
        if(!search(A,i) && !search(B,i)){
            count++;

        }

    }
    cout <<count;
    cout << endl;
return 0;
}