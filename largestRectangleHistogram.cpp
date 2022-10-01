#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> next_smaller_on_left(n, -1);
        
        vector<int> next_smaller_on_right(n, n);
        
        // find next smaller element on left
        
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty()&& heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            if(st.empty() == false)
            {
                next_smaller_on_left[i] = st.top();
            }
            
            st.push(i);
        }
        
        // find next smaller element on right
        
        while(!st.empty())
        {
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            if(!st.empty())
            {
                next_smaller_on_right[i] = st.top();
            }
            
            st.push(i);
        }
        
        // calculate and update the maxi
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            int width = next_smaller_on_right[i] - next_smaller_on_left[i] - 1;
            
            int temp_max = heights[i] * (width);
            
            maxi = max(maxi, temp_max);
        }
        
        return maxi;
    }
};