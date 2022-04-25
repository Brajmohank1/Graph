/*

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

*/

class Solution {
public:
    
    int findParrent(vector<int> &parrent , int src){
        
        if(parrent[src] == src)
            return src;
        
        return findParrent(parrent , parrent[src]);
    }
    
    void union1(vector<int> &parrent , vector<int> &rank , int u , int v){
        
        u = findParrent(parrent , u);
          v = findParrent(parrent , v);
            if(rank[u] > rank[v]){
                parrent[v] = u;
                
            }
            else if(rank[u] < rank[v]){
                 parrent[u] = v;
                
            }
        else{
            parrent[v] = u;
        	rank[u]++; 
        }
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parrent(n+1) , rank(n+1,0);
        
        for(int i = 1 ; i <=n ; i++)
                parrent[i] = i;
        
        for(int i = 0 ; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(findParrent(parrent , u) == findParrent(parrent , v))
                return {u , v};
            else
                union1(parrent , rank , u , v);
        }
        
        return {-1,-1};
        
        
    }
};