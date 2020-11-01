class Solution {
public:
    int numberOf2sInRange(int n) {
        if(n <= 1)
            return 0;
        if(n <= 11)
            return 1;
        int a=0, b=0, res=0;
        for(long long i=1; i<=n; i*=10){
            a = n/i; 
            b = n%i;
            res += (a+7)/10*i + (a%10 == 2)*(b+1);
        }
        return res;
    }
};
