
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

class Queue {
public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1, s2;
};

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        while (!stk.empty() && (i == n || heights[stk.top()] > heights[i])) {
            int h = heights[stk.top()];
            stk.pop();
            int w = stk.empty() ? i : i - stk.top() - 1;
            ans = max(ans, h * w);
        }
        stk.push(i);
    }
    return ans;
}

int main() {
    srand(time(nullptr));
    for (int t = 1; t <= 10; ++t) {
        int n = 10;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            heights[i] = rand() % 105 + 1;
        }
        cout << "Test case #" << t << " : ";
        cout << largestRectangleArea(heights) << endl;
    }

    return 0;
}

