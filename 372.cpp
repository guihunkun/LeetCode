class Solution {  
public:  
  
    bool notZero(vector<int>& b) {  
        for(int i = b.size()-1; i >= 0; i--) {  
            if(b[i] > 0) return true;  
        }  
          
        return false;  
    }  
      
    void div(vector<int>& b) {  
        int tmp = 0;  
        for(int i = 0; i < b.size(); i++) {  
            b[i] += tmp*10;  
            tmp = b[i] % 2;  
            b[i] = b[i] / 2;  
        }  
    }  
      
    int superPow(int a, vector<int>& b) {  
        int ans = 1;  
          
        a = a % 1337;  
          
        while(notZero(b)) {  
            if(b[b.size()-1] % 2 != 0) ans = (ans * a) % 1337;  
              
            div(b);  
              
            a = (a * a) % 1337;  
        }  
          
        return ans;  
    }  
};
