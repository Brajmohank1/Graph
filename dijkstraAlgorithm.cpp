#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int> iPair;
// implementation of weighted graph in c++ using vector with pair;

void pritGraph(vector<iPair> adj[] , int n){
    
    
    // printing graph with their source to destinatiojn and corresponding their weight;
    
    for(int i =0 ; i < n ; i++){
        
        cout<<"Sorce vertex is " << i << " - > destiantion and weight \n\n\n";
        for(auto x: adj[i]){
            
            int dest = x.first;
            int weight = x.second;
            
            cout<<dest << "  " << weight << "\n";
        }
        
        
        cout<<"\n\n\n\n";
    }
}


    
vector<ll> dijkstraAlgorithm(vector<vector<iPair>> &adj , int n  , int src){
    
    // Dijkstra algorithm is used for find shortest distance of all vertices from a source vertices
    
    priority_queue<iPair , vector<iPair> , greater<iPair>> pq;
    vector<ll> dist(n , INF);
    
    dist[src] = 0;
    pq.push({0,src});
    
    while(!pq.empty()){
        
        iPair temp = pq.top();
        pq.pop();
        
        int u = temp.second;
        ll w = temp.first;
        if(dist[u] < w)
            continue;
          
        for(auto [v,curWeight] : adj[u])
        {
            // int v = x.first;
            // int curWeight = x.second;
            
            if(dist[v] > dist[u] + curWeight){
                dist[v] = dist[u] + curWeight;
                pq.push({w + curWeight , v});
            }
        }
        
    }
    
    return dist;
    
}
    


void  addEdge(vector<iPair> adj[] , int src , int des , int w){
    adj[src].push_back(make_pair(des , w));
    adj[des].push_back(make_pair(src,w));
}

int main()
{
    int v = 9;
    
    vector<iPair> adj[v];
    
     addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    
    pritGraph(adj , v);
    
    dijkstraAlgorithm(adj , v , 0);
    return 0;
}