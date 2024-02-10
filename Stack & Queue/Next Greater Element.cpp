#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int>& arr, int n) {
    vector<int> ans;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top());
        }

        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end()); // Reverse the answer vector
    return ans;
}
