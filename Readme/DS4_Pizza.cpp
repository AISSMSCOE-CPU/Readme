#include <iostream>
using namespace std;
#define M 5

class pizzaparlour{
    int queue[M];
    int front,rear;
    
    public:
    pizzaparlour(){
        front = -1;
        rear = -1;
    }

    void placeorder(){
        int order;
        if((rear+1)%M == front){
            cout << "Queue is full...";
            return;
        }

        cout << "Enter the order number";
        cin >> order;

        if(front == -1){
            front =0;
        }

        rear = (rear+1)%M;
        queue[rear] = order;
        cout << "Order is placed";
    }

    void serveorder(){
        if(front==-1){
            cout << "No orders being served...";
            return;
        }
        cout << "Order Ready!!" << queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%M;
        }
    }

    void display(){
        if(front == -1){
            cout << "Queue is empty...";
            return;
        }
        int i = front;
        for(int i =front ; ; i = (i+1)%M){
            cout << queue[i] << " ";
            if(i == rear){
                break;
            }
        }
        cout << endl;
    }
};
int main(){
    pizzaparlour p;
    int choice;

    do{
        
        cout << "\n--- Pizza Parlor ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                p.placeorder();
                break;

            case 2:
                p.serveorder();
                break;

            case 3:
                p.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }


    }while(choice !=4);
    return 0;
}
