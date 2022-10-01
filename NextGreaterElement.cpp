#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int>
    nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();

        int n2 = nums2.size();

        unordered_map<int, int> mp;

        vector<int> res(n1, -1);

        stack<int> st;

        for (int i = n2 - 1; i >= 0; i--)
        {
            while (st.empty() == false && st.top() <= nums2[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < n1; i++)
        {
            res[i] = mp[nums1[i]];
        }

        return res;
    }
};

void ngle(vector<int> &ngl, vector<int> &v)
{
    stack<int> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] < v[i])
        {
            st.pop();
        }
        ngl[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}
void ngre(vector<int> &ngr, vector<int> &v)
{
    stack<int> st;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] < v[i])
        {
            st.pop();
        }
        ngr[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}
