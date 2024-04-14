class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        for (int i = 0; i < s.length(); i++)
        {
            s = s.substr(1) + s.substr(0, 1);
            if (goal == s)
                return true;
        }
        return false;
    }
};