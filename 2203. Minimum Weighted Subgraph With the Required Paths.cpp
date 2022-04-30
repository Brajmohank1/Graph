typedef long long ll;
typedef pair<int, int> iPair;
long long INF = 1e12;
class Solution {
public:
    
    
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
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<iPair>> Graph(n);
        vector<vector<iPair>> revGraph(n);
        
        for(int i = 0 ; i < edges.size() ; i++){
            Graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            revGraph[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        
        
        vector<ll> fSrc1 = dijkstraAlgorithm(Graph , n  , src1);
        vector<ll> fSrc2 = dijkstraAlgorithm(Graph , n  , src2);
        vector<ll> lDes = dijkstraAlgorithm(revGraph , n  , dest);
        
        ll ans = INF;
        
        for(int i = 0 ; i <n  ; i++){
            if(fSrc1[i] != INF && fSrc2[i] != INF && lDes[i] != INF){
                ans = min(ans , fSrc1[i] + fSrc2[i] + lDes[i]);
            }
        }
        
        return ans == INF ? -1 : ans;
    }
};