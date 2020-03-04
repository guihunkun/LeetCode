class SummaryRanges 
{
private:
    vector<vector<int>> res;
public:
    /** Initialize your data structure here. */
    SummaryRanges() 
    {
        res = {};
    }
    
    void addNum(int val) 
    {
        // 结果为空时直接返回
        if(res.size() < 1) 
        {
            res.push_back({val, val});
            return;
        }
        // 当前插入的数 - 1 > 结果数组的最大数时，直接在结果数组最后面插入
        if(res.back()[1] < val - 1) 
        {
            res.push_back({val, val});
            return;
        }
        // 当前插入的数 - 1 == 结果数组的最大数时，将结果数组的最后的末尾位置更新为val
        if(res.back()[1] == val - 1) 
        {
            res.back()[1] = val;
            return;
        }

        // 其他情况：二分找最右边的小于val的res[i][0]
        int left = 0, right = res.size() - 1;
        while(left < right) 
        {
            int mid = (left + right + 1) / 2;
            if(res[mid][0] > val) 
            {
                right = mid - 1;
            } 
            else 
            {
                left = mid;
            }
        }

        // 判断，如果val小于结果数组最小的数 - 1则在最前面添加-------- 其实可以移动前面判结尾的位置比较连贯
        if(left == 0 && res[left][0] > val && res[left][0] - val > 1) 
        {
            res.insert(res.begin(), {val, val});
            return;
        }
        // 如果val + 1 == res[0][0]则更新res[0][0]
        if(left == 0 && res[left][0] > val && res[left][0] - val == 1) 
        {
            res[left][0] = val;
            return;
        }

        // 特殊情况判断完之后，left为二分找到的结果数组中的某个位置，此时有res[left][0] <= val && res[left + 1][0] > val
        // 判断val是否在left的范围内
        if(val <= res[left][1]) 
        {
            return;
        } 
        else if(val - res[left][1] == 1 && left < res.size() - 1 && res[left + 1][0] - val == 1) 
        {
            // 判断加入val是否能让left和left + 1连通
            res[left][1] = res[left + 1][1];
            res.erase(res.begin() + left + 1);
            return;
        } 
        else if(val - res[left][1] == 1) 
        {
            // 判断val是否能更新left的最大值
            res[left][1] = val;
            return;
        } 
        else if(left < res.size() - 1 && res[left + 1][0] - val == 1) 
        {
            // 判断val是否能更新left + 1的最小值
            res[left + 1][0] = val;
            return;
        } 
        else
        {
            // 都不能更新时，只能插入一个新的区间
            res.insert(res.begin() + left + 1, {val, val});
            return;
        }

        return;
    }
    vector<vector<int>> getIntervals()
    {
        return res;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
