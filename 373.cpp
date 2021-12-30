class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        // max heap
        priority_queue< pair< int, pair<int,int> > > pq;

        int m = nums1.size();
        int n = nums2.size();

        if(m > k)
            m = k;
        if(n > k)
            n = k;
        
        int x = 0;
        // to heap, add pairs (sum, (i,j))
        for (int i=0; i<m; ++i) 
        {
            for (int j=0; j<n; ++j) 
            {
                // maintain max heap size to be k
                if (x < k || pq.empty()) 
                {
                    pq.push(make_pair(nums1[i]+nums2[j], make_pair(nums1[i],nums2[j])));
                } 
                else
                {
                    // once k elements are in heap,
                    // only add new pair if it's sum is less than top of heap
                    // this way, min value pairs will be left in heap of size k
                    if (nums1[i]+nums2[j] < pq.top().first) 
                    {
                        pq.pop();
                        pq.push(make_pair(nums1[i]+nums2[j], make_pair(nums1[i],nums2[j])));
                    }
                }
                x += 1;
            }
        }

        vector< vector<int> > ans;

        // since heap size is k, and only elements less than heap's top are added
        // this ensures that minimum sum k pairs are in heap
        while (!pq.empty()) 
        {
            vector<int> temp;
            auto p = pq.top();
            temp.push_back(p.second.first);
            temp.push_back(p.second.second);
            pq.pop();
            ans.push_back(temp);
        }

        return ans;
    }
};


