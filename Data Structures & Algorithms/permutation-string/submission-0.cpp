class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1count(26,0), windowCount(26,0);
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;
        for (int i = 0; i < n1; i++) {
            s1count[s1[i]-'a']++;
            windowCount[s2[i]-'a']++;
        }
        if (s1count == windowCount) return true;
        for (int right = n1; right < n2; right++) {
            windowCount[s2[right]-'a']++;
            windowCount[s2[right - n1]-'a']--;
            if (s1count == windowCount) return true;
        }
        return false;
    }
};
