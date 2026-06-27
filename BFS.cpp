#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int>*l;
 public:
    graph(int v){
        this->v=v;
        l=new list<int>[v];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS(){
        queue<int>qu;
        vector<bool>vis(v,false);

        qu.push(0);
        vis[0]=true;

        while(qu.size()>0){
            int u=qu.front();
            qu.pop();

            cout << u << " ";

            for(int v:l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    qu.push(v);
                }
            }

        }

    }


};

int main(){

    graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    

    g.BFS();
    return 0;
}