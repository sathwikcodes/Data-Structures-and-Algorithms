class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxi = 0;
        unordered_set<char> st;
        for (int right = 0; right < s.length(); right++)
        {
            while (st.find(s[right]) != st.end())
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};