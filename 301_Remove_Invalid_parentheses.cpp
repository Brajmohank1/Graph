class Solution {
public:
    
    bool isValid(string str){
        
        int count = 0;
        int n = str.size();
        for(int i = 0 ; i < n ; i++){
            if(str[i] == '(') count++;
            if(str[i] == ')') count--;
            
            if(count < 0)
                return false;
        }
        
        return count == 0;
        
    }
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        queue<string> q;
        unordered_set<string> brajset;
        int len = INT_MAX;
        q.push(s);
        
        while(!q.empty()){

            
            
            string temp = q.front() ;
            q.pop();
             if(len != INT_MAX && len != temp.size())
                    break;
            
            if(isValid(temp)){
                len = temp.size(); 
                res.push_back(temp);
                    
                    
           
                continue;
                
            }
            
            for(int i = 0 ; i < temp.size() ; i++){
                if(temp[i] == '(' || temp[i] == ')')
                {  string left = temp.substr(0 , i) + temp.substr(i + 1 );
                  if(brajset.find(left) == brajset.end())   
                      q.push(left);
                 brajset.insert(left);
                 
                }
            }
        
        
        
        
        }
        
        if(res.size() == 0)
            res.push_back(" ");
        
        return res;
        
    }
};