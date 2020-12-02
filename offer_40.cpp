/*
class Solution 
{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        vector<int> res(k);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; i ++)
        {
            res[i] = arr[i];
        }
        return res;
    }
};
*/
class Solution 
{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        vector<int> res;
        if(k == 0) {
            return res;
        }
        res.resize(k);
        priority_queue<int> pq;
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++) {
            if(pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};
