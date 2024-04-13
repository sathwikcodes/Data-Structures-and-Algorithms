#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                count++;
            }
        }
        if (nums[n - 1] > nums[0])
        {
            count++;
        }
        return count <= 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << "Is the vector sorted with a single rotation? " << boolalpha << solution.check(nums) << endl;
    return 0;
}
