class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        if (s.length() == 0 || s.length() == 1)
            return s.length();
        int res = 0;
        vector<bool>vis(26, false);
    int left = 0, right = 0;
    while (right < s.length()) {
        while (vis[s[right] - 'a'] == true) {
            vis[s[left] - 'a'] = false;
            left++;
           }
        vis[s[right] - 'a'] = true;
        res = max(res, (right - left + 1));
        right++;
    }
    return res;
    }
};