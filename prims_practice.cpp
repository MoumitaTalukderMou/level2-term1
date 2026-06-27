#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int u,v,wt;
    edge(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};

class graph{
    public:
    int V;
    vector<vector<pair<int,int>>>adj;

    graph(int V){
        this.V=V;
        adj.resize(V);
    }


    int prims_algo(){
        vector<bool>inMST(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int mst_cost=0;

        pq.push({0,0});

        while(pq.size()>0){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int u=p.second;
             if(!inMST[u]){
                inMST[u]=true;
                mst_cost+=wt;
             }

             for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i].first;
                int w=adj[u][i].second;

                if(!inMST[v]){
                    pq.push({w,v});
                }
             }

        }
        return mst_cost;
    }

    
};
int main(){

    graph graph(4);

    
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    cout << graph.prims_algo() << endl;
    return 0;
}