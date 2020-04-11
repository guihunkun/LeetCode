class Solution 
{
public:
	bool PredictTheWinner(vector<int>& nums) 
    {
		// 模拟真实情况下，A，B轮流选牌的过程，求出结果
		return helper(0, nums.size() - 1, 0, 0, true, nums);
	}

	//分别为  左边可取的位置，右边可取的位置，A的得分，B的得分，   轮到谁选牌，   nums数组
	bool helper(int left, int right, int score_A, int score_B, bool turn_to_A, vector<int>& nums) 
    {
		if(left > right) //左右越界，没有牌了，比较得分，判断胜负（以A为主角）
			return score_A >= score_B;
		if(turn_to_A) //轮到A选牌,A是主角，只要左边或者右边有一种必胜情况，就说明可以必胜
			return helper(left + 1, right, score_A + nums[left], score_B, false, nums) || helper(left, right - 1, score_A + nums[right], score_B, false, nums);
		else //轮到B选牌，不管B怎么选，此时只有左右两边都保证A是必胜的，才能保证A最终必胜！
			return helper(left + 1, right, score_A, score_B + nums[left], true, nums) && helper(left, right - 1, score_A, score_B + nums[right], true, nums);
	}
};

