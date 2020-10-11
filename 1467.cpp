class Solution {
public:
    int left[10]; //剩余的球的数量，用于剪枝
    double powerof2[15] = {1, 2, 4, 8, 16,32, 64, 128, 256,512,1024,2048,4096,8192,16384}; //2的幂，用来算所有组合情况
    int n = 0;
    long long factorial[15];//算阶乘，用于计算组合数
    double getProbability(vector<int>& balls) {
        calculatefactorial();
        n = balls.size();
        int sum = 0; //一共有多少个球，用于最后的除法
        for(int i = 0; i < n; i++)
            sum += balls[i];
        double q = 1; //计算出C(2n, n)/2^(2n)，即满足左n右n的概率
        for(int i = 1; i <= sum/2; i++){
            q *= (i+sum/2)*1.0/i/4;
        }
        left[n-1] = balls[n-1]; //计算剩余球数，用于剪枝
        for(int i = n-2; i >= 0; i--)
            left[i] = left[i+1] + balls[i];
        return dfs(balls, 0, 0, 0)/q;
    }
    //计算阶乘，不解释
    void calculatefactorial(){
        factorial[0] = 1;
        for(int i = 1; i <= 10; i++)
            factorial[i] = i * factorial[i-1];
    }
    //根据公式算组合数
    int combination(int a, int b){
        return factorial[a]/(factorial[b]*factorial[a-b]);
    }
    //深搜函数，balls是题目给的数组，m代表当前搜索颜色m，greatersum是左边的箱子比右边箱子多几个球，greatercolor是左边比右边多几种颜色
    double dfs(vector<int> & balls, int m, int greatersum, int greatercolor){
        if(m == n) //只有左边右边球的数量和颜色种类的数量相等时才算，否则免谈
            return greatersum == 0 && greatercolor == 0;
        //剪枝，假设目前还剩余x个球没有分配，但是左边比右边的球多的数量，或者右边箱子比左边箱子多出的球的数量大于x，那么我们无论怎么分配，都不可能在最后满足左右球的数量相等这个条件，所以剪枝
        if(abs(greatersum) > left[m])
            return 0;
        double result = 0;
        //计算取不同数量的球放在左边，最后满足条件的概率 （感谢来自 @金木盐 的改进）
        for(int i = 0; i <= balls[m];i ++){
            int color = i == 0 ? -1 : (i == balls[m] ? 1 : 0);
            result += (combination(balls[m], i) / powerof2[balls[m]]) * 
                dfs(balls, m + 1, greatersum + i - (balls[m] - i), greatercolor + color);
        }
        return result;
    }

};
