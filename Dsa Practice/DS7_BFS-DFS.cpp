#include <iostream>
#include <string>
using namespace std;

int n=7;
string places[7]{
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G"
};

int adj[7][7] = {0};

int head[7], to[20],next[20];
int idx = 0;

int vis[7] n= {0};
void addlist(int u,int v){ // Eg addlist(0,1)
    to[idx] = v;
    next[idx] = head[u];
    head[u] = idx;
    idx++;
}

void DFS(int v){
    cout << places[v] << " ";
    vis[v] = 1;

    while(adj[v][i] ==1 && vis[i] == 0 ){
        DFS(i);
    }
}
void BFS(int start){
    int q[7] , front = 0, rear = 0;
    int vis[7] = {0};

    q[rear++] = start;
    vis[start] = 1;

    while(front<rear){
        int v = to[front++];
        cout << places[v] << " ";
    }
    for(int i =head[i]; i!= -1 ; i = next[i]){
        int u = to[i];
        if(vis[u] == 0){
            vis[u] = 1;
            q[rear++] = u;
        }

    }


}