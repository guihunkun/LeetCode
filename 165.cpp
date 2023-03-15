class Solution {
    int parseNumber(string input){
        int n(0);
        for(const char c: input){
            n = n*10 + (c - '0');
        }
        return n;
    }
	
    public:
    int compareVersion(string version1, string version2) {
        int i(0), j(0);
        while(i < version1.size() && j < version2.size()){
            string v1, v2;
            while(i < version1.size() && version1[i] != '.'){
                v1.push_back(version1[i]);
                i++;
            }
            while(j < version2.size() && version2[j] != '.'){
                v2.push_back(version2[j]);
                j++;
            }
            int n1 = parseNumber(v1);
            int n2 = parseNumber(v2);
            
            if(n1 > n2) return 1;
            if(n1 < n2) return -1;
            i++;
            j++;
        }
        
        while(i < version1.size()){
            string rem;
            while(i < version1.size() && version1[i] != '.'){
                rem.push_back(version1[i]);
                i++;
            }
            if(parseNumber(rem) != 0) return 1;
            i++;
        }
        
        while(j < version2.size()){
            string rem;
            while(j < version2.size() && version2[j] != '.'){
                rem.push_back(version2[j]);
                j++;
            }
            if(parseNumber(rem) != 0) return -1;
            j++;
        }
        
        return 0;
    }
};



