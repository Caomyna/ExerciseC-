#include<bits/stdc++.h>
using namespace std;


int n, m;
vector<int> adj[1001]; //lưu ds kề
bool visited[1001]; 

void inp(){
    cin>>n>>m;
    for(int i = 0; i <m ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));

}

void BFS (int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int v =q.front();
        q.pop();
        cout<< v << " ";
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void DFS(int u){
    cout << u <<" ";
    visited[u] = true; //đánh dấu đã duyệt qua
    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main(){
    while(true){
        cout<<"\n1. Traverse the graph using breadth-first search method"<<endl;
        cout<<"2. Traverse the graph using depth-first search method"<<endl;
        int choose;
        cout<<"Choose: "; cin>>choose;
        if(choose==1){
            inp();
            cout<<"BFS: ";BFS(1); cout<<endl;
        }else if(choose==2){
            inp();
            cout<<"DFS: ";DFS(1); cout<<endl;
        }
    }
    return 0;
}
