#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<int>> l;
    int timer = 0;

public:

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsAP(int node, int parent,
               unordered_map<int,bool>& visited,
               unordered_map<int,int>& disc,
               unordered_map<int,int>& low,
               unordered_map<int,bool>& isAP){

        visited[node] = true;
        disc[node] = low[node] = ++timer;

        int children = 0;

        for(int nbr : l[node]){

            if(nbr == parent) continue;

            if(!visited[nbr]){
                children++;

                dfsAP(nbr, node, visited, disc, low, isAP);

                low[node] = min(low[node], low[nbr]);

                // Case 1: root node
                if(parent == -1 && children > 1)
                    isAP[node] = true;

                // Case 2: non root
                if(parent != -1 && low[nbr] >= disc[node])
                    isAP[node] = true;
            }
            else{
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    void articulationPoints(){

        unordered_map<int,bool> visited;
        unordered_map<int,int> disc, low;
        unordered_map<int,bool> isAP;

        for(auto p : l){
            if(!visited[p.first])
                dfsAP(p.first, -1, visited, disc, low, isAP);
        }

        cout<<"Articulation Points:\n";
        for(auto p : isAP){
            if(p.second)
                cout<<p.first<<" ";
        }
        cout<<endl;
    }
};

int main(){

    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);

    g.articulationPoints();

    return 0;
}