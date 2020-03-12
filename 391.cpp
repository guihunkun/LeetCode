class Solution 
{
public:

    static bool cmp(vector<int> &a, vector<int> &b) 
    {
        return a[1] < b[1];
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        if(rectangles.size() < 1) 
            return false;

        int n = rectangles.size();
        pair<int, int> left_down;
        pair<int, int> right_top;
        int l1 = INT_MAX, l2 = INT_MAX, l3 = INT_MIN, l4 = INT_MIN;
        for(auto it : rectangles) 
        {
            l1 = min(l1, it[0]);
            l2 = min(l2, it[1]);
            l3 = max(l3, it[2]);
            l4 = max(l4, it[3]);
        }
        left_down = {l1, l2};
        right_top = {l3, l4};

        int len = right_top.first - left_down.first;
        vector<int> h(len, left_down.second);

        // 对左下角的高度排序
        sort(rectangles.begin(), rectangles.end(), cmp);

        for(auto it : rectangles) 
        {
            for(int i = it[0]; i < it[2]; i++) 
            {
                // 判断每个位置下的高度是否与当前的高度相等，不相等则发生了重合或者空缺
                if(h[i - left_down.first] != it[1]) 
                    return false;
                h[i - left_down.first] = it[3];
            }
        }
        
        // 判断处理完所有矩形之后，每个位置的高是否等于完美矩形的高
        for(int x = 0; x < h.size(); x++) 
        {
            if(h[x] != right_top.second) 
                return false;
        }
        return true;
    }
};
