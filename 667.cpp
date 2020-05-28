class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v(n);
        v[0] = 1;
        for (int i=1, interval = k; i<=k; i++,interval--) {
            v[i] = (i%2 == 1 ? v[i-1]+interval:v[i-1]-interval);
        }
        for (int i=k+1; i<n; i++) {
            v[i] = i+1;
        }
        return v;
    }
};

