class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tCount(128,0), windowCount(128,0);
        if (t.size() > s.size()) return "";
        for (char c : t) {
            tCount[c]++;
        }
        int need = 0, have = 0;
        
        for (int i = 0; i < 128; i++) {
            if (tCount[i] > 0) {
                need++;
            }
        }
        int bestLen = INT_MAX, left = 0;
        int bestStart = 0;
        for (int right = 0; right < s.size(); right++) {
            windowCount[s[right]]++;
            if (windowCount[s[right]]==tCount[s[right]]) have++;
            while (have == need) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                windowCount[s[left]]--;
                if (windowCount[s[left]] < tCount[s[left]]) have--;
                left++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
