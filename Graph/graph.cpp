/* 
  Can buit 4 types of graphs:
    1. Adjacency Matrix 
    2. Adjacency List
    3. Edge List
    4. IMplicit Graphs
*/

#include <bits/stdc++.h>
using namespace std;

/* 
2. Adjacency List
  - More space efficient for sparse graphs
  - Each vertex has a list of its adjacent vertices
  - Faster to iterate over neighbors of a vertex

  Example representation using vector of vectors:
    vector<vector<int>> adjList(n); // n is number of vertices
    adjList[u].push_back(v); // add edge from u to v
    adjList[v].push_back(u); // for undirected graph

*/

class Graph{
  int V;
  list<int> *l;
  
  public:
    Graph(int v){
      this->V = v;
      l = new list<int> [v]; // create 
    }

    void addEdge(int u, int v){
      l[u].push_back(v);
      l[v].push_back(u);
    }

    void print(){
      for(int u = 0; u< V; u++){
        list<int> neighbours = l[u];
        cout<<u<<"->[ ";
        for(int v:neighbours){
          cout << v <<",";
        }
        cout<<"]"<<endl;

      }
    }

    void bfs(){
      vector<bool> visited(V, false);
      queue<int> q;
      int start = 0;
      q.push(start);
      visited[start] = true;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr: l[node]){
          if(!visited[nbr]){
            q.push(nbr);
            visited[nbr] = true;
          }
        }
      } 
    }
};

int main(){
  Graph graph(5);
  graph.addEdge(0,1);
  graph.addEdge(1,2);
  graph.addEdge(1,3);
  graph.addEdge(2,3);
  graph.addEdge(2,4);
  graph.addEdge(0,1);
  graph.print();
  return 0;
}