class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
            } 
            else {
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        ans += char('a' + c);
                        cnt[c]--;
                        for (int k = 0; k < 26; k++)
                            ans += string(cnt[k], 'a' + k);

                        return ans;
                    }
                }
                break;
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--) {

            cnt[ans[i] - 'a']++;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string res = target.substr(0, i);
                    res += char('a' + c);
                    cnt[c]--;

                    for (int k = 0; k < 26; k++)
                        res += string(cnt[k], 'a' + k);

                    return res;
                }
            }
        }

        return "";
    }
};