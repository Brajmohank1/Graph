/*

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 


*/


class Solution {
public:
    
    double dfs(unordered_map<string , vector<pair<string , double>>> &mp , string source , string destination , unordered_set<string> &visited , double curval){
         
        if(source == destination)
            return curval;
        visited.insert(source);
    for(auto cur = mp[source].begin() ; cur != mp[source].end() ; cur++ ){

            if((*cur).first == destination){
                return curval*(*cur).second;
            }else if(visited.find((*cur).first) == visited.end()){
                
                    double ans =  dfs(mp,(*cur).first , destination , visited , curval*(*cur).second);
                if(ans != -1)
                    return ans;
                
            }
    
    }
        
        return -1 ;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // construction of grapph
        unordered_map<string , vector<pair<string , double>>> mp;
        
        
        for(int i = 0 ; i < equations.size() ; i++){
            
                mp[equations[i][0]].push_back({equations[i][1] , values[i]});
                  mp[equations[i][1]].push_back({equations[i][0] , 1/values[i]});
        
        }
        
        vector<double> res(queries.size());
        
        for(int i = 0 ; i < queries.size() ; i++){
            
            string source = queries[i][0];
            string destination = queries[i][1];
            
            if(mp.find(source) == mp.end() ||  mp.find(destination) == mp.end()){
                res[i] = -1;
            }else{
                unordered_set<string> visited;
        
                res[i] = dfs(mp , source , destination , visited , 1);

            }
            
            
        }
        
        return res;
        
    }
};
