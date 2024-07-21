class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> v;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        int m = s.size();
        int n = p.size();
        if (n > m)
            return v;
        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            v1[s[i] - 'a']++;
            v2[p[i] - 'a']++;
            right++;
        }
        right--;
        for (int i = right; i < m; i++)
        {
            if (v1 == v2)
                v.push_back(left);

            right++;
            if (right != m)
                v1[s[right] - 'a']++;
            v1[s[left] - 'a']--;
            left++;
        }

        return v;
    }
};