class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prevDayIndex = s.top();
                s.pop();
                answer[prevDayIndex] = i - prevDayIndex;
            }
            s.push(i);
        }
        return answer;
    }
};
