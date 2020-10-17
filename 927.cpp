class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> bit; // 记录1出现的下标
        int len = A.size(); 
        for(int i = 0; i < len; i++){
            if(A[i] == 1)  bit.push_back(i);
        }
        if(bit.size() % 3 != 0)  return {-1, -1}; //1的个数不能被3整除
        if(bit.empty()) return {0, 2}; //全是0, 随便返回一组
        int count = bit.size() /3; //均分的数组长度
        int back_zero = len - 1 - bit.back(); //后导0数量 
        if(back_zero > bit[2*count] - bit[2*count - 1] - 1 || back_zero > bit[count] - bit[count - 1] - 1) //后导0数量大于组间0的数量
            return {-1, -1};

        //将bit的分段成三组
        vector<int> first(bit.begin(), bit.begin() + count); 
        vector<int> second(bit.begin() + count, bit.begin() + 2*count);
        vector<int> third(bit.begin() + 2*count, bit.end());
        //判断相邻两个索引的位置差是否均相等
        for(int i = count - 1; i > 0; i--){
            if(first[i] - first[i-1] != second[i] - second[i-1] || first[i] - first[i-1] != third[i] - third[i-1]) //判断间距是否相等
                return {-1, -1};
        }

        int i = bit[count - 1] + back_zero; //后导0个数为 len - 1 - bit.back(), 即由最后一个1所在的位置可求出. 那么前两段后面追加相应个数的0. 分界点为bit[count - 1] bit[2*count - 1]
        int j = bit[2*count - 1] + back_zero + 1; //  第二组是到j-1. 故需要加1
        return {i, j};
    }
};
