class ProductOfNumbers 
{
public:
    vector<int>vec,zero,pre;
    int n;
    ProductOfNumbers() 
    {
        vec.clear();
        zero.clear();
        pre.clear();
        n=0;
    }
    
    void add(int num) 
    {
        n++;
        vec.push_back(num);
        pre.push_back(-1);
        if(n>1) {
            if (vec[n-2]!=1 && vec[n-2]!=0) pre[n-1]=n-2;
            else pre[n-1]=pre[n-2];
        }
        zero.push_back(num==0?1:0);
        if(n>1) 
            zero[n-1]+=zero[n-2];
    }
    
    int getProduct(int k) 
    {
        int tot=zero[n-1];
        if(n-k>=1) 
            tot-=zero[n-1-k];
        if(tot>0) 
            return 0;
        int ans=1;
        for(int i=n-1;i>=n-k;) {
            ans*=vec[i];
            i=pre[i];
        }
        return ans;
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

