#include"iostream"
#include"vector"
#include"unordered_map"
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max= 0, dist=INT_MAX; //max keeps track of max count
        if (nums.size() ==1 ) return 1;
        unordered_map<int,pair<int,pair<int ,int>>> values;
        for(int i=0; i <nums.size(); i++)
        {
            auto yes=values.begin();
            yes= values.find(nums[i]);
            if (yes==values.end()) // number is not in the hash table
            {
                int count=1;
                values[nums[i]]={count,{i,i}}; //start position is i;
            }
            else // number is already in the hastable
            {
                values[nums[i]].second.second=i; //update the last position
                values[nums[i]].first+=1; //update the count ;
            }

        }
        // loop through map to find the largest count
        for (auto it=values.begin();it!=values.end();it++)
        {
            int count=it->second.first;
            if (count >= max)
            {
                max=count;
            }

        }

        // loop through map to find the smallest distance
        for (auto it=values.begin();it!=values.end();it++)
        {
            int count=it->second.first;
            if (count == max )
            {
                int start_pos=it->second.second.first;
                int last_pos = it->second.second.second;
                if (last_pos - start_pos < dist )
                {
                   dist = last_pos-start_pos;
                }
            }
        }
        return dist+1;
    }
};
int main()
{
    vector<int> nums={1, 2, 2, 3, 1};
    cout<<Solution().findShortestSubArray(nums)<<endl;
	return 0;
}