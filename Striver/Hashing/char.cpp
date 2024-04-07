#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int hash[26] = {0}; // taken 26 coz of lower case letters if uppercase then will take 256
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}