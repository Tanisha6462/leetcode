class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < target.size(); i++) {

            // First, try to make prefix equal to target
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                freq[x]--;
                ans += target[i];
            }
            else {
                // Cannot match target[i].
                // Try the smallest character greater than target[i].
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;

                        // Put remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // No larger character at this position.
                // Need to backtrack.
                break;
            }
        }

        /*
            If we reached here, we matched some prefix of target
            but couldn't make it greater.

            Backtrack through the prefix we constructed.
        */

        for (int i = ans.size() - 1; i >= 0; i--) {

            // Put ans[i] back into frequency
            freq[ans[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string result = target.substr(0, i);
                    result += char('a' + c);

                    freq[c]--;

                    // Add all remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            result += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};