class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string word, ans;
        stack<string> st;

        // Extract words from the input string
        while (ss >> word)
        {
            st.push(word);
        }

        // Construct the reversed string
        while (!st.empty())
        {
            ans += st.top() + " ";
            st.pop();
        }

        // Remove trailing space
        if (!ans.empty())
        {
            ans.pop_back();
        }

        return ans;
    }
};