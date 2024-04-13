#include <iostream>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // Normalize rotation amount
        if (k <= 0)
            return; // No rotation needed

        std::vector<int> temp(k);
        for (int i = n - k; i < n; i++)
        {
            temp[i - n + k] = nums[i];
        }
        for (int i = n - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};

int main()
{
    Solution solution;

    // Example usage
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;

    std::cout << "Original array: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    solution.rotate(nums, k);

    std::cout << "Array after rotating " << k << " positions to the right: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
