class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int sum = 0;

        int result = INT_MAX;
        for (int right = 0; right < n; right++)
        {
            sum = sum + nums[right];
            while (sum >= target)
            {
                result = min(result, right - left + 1);
                sum = sum - nums[left++];
            }
        }
        return (result == INT_MAX) ? 0 : result;
    }
};