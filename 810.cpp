class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int len = nums.size(),t = 0;
        for(auto& x:nums) t ^= x;
        if(len%2){
            if(t) return false;
            else return true;
        }
        return true;
    }
};

