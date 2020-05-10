class Solution {
public:
    long long mul(vector<int>& p1, vector<int>& p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>v;
        v.push_back(p1);v.push_back(p2);v.push_back(p3);v.push_back(p4);
        sort(v.begin(),v.end());
        long long l1,l2,l3,l4,l5,l6;
        l1=mul(v[0],v[1]);
        l2=mul(v[0],v[2]);
        l3=mul(v[3],v[2]);
        l4=mul(v[1],v[3]);
        l5=mul(v[0],v[3]);
        l6=mul(v[1],v[2]);
        if(l1==0||l2==0||l3==0||l4==0) return false;
        return l1==l2&&l2==l3&&l3==l4&&l4==l1&&l5==l6;
    }
};
