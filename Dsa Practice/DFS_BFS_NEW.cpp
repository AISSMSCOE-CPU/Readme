#include <iostream>
#include <string>
using namespace std;

const int N = 5;

string places[N] = {
    "City", "Busstop", "Hospital", "Mall", "Garden"
};

int adj[N][N];
int count[N] = {0};
int visited[N] = {0};
void addRoad(int u, int v){
    adj[u][count[u]++] = v;
    adj[v][count[v]++]= u;
}

void DFS(int v){
    cout << places[v] << " ";
    visited[v] = 1;

    for(int i =0; i<count[v];i++){
        int next = adj[v][i];
        if(visited[next] == 0){
            DFS(next);
        }
    }

}

void BFS(int start){
    int q[N];
    int front = 0, rear = 0;
    visited[start] = 1;
    q[rear++] = start;

    while(front<rear){
        int v = q[front++];
        cout <<places[v] <<" ";
        for(int i=0; i<count[v] ; i++){
            int next = adj[v][i];
            if(visited[next] == 0){
            visited[next] = 1;
            q[rear++] = next;
}

        }
    }   

}

int main(){
    addRoad(0, 1);
    addRoad(0, 2);
    addRoad(1, 3);
    addRoad(2, 4);
    addRoad(3, 4);

    cout << "DFS: " << " ";
    DFS(0);

    for(int i =0;i<N; i++){
        visited[i] = 0;
    }
    cout << "BFS: " << " ";
    BFS(0);

    return 0;

}

