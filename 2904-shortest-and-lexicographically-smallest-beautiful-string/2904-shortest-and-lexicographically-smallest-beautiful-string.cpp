class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1') {
                ones++;
            }

            // We have more than k ones.
            // Move left until we have at most k ones.
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Now the window has exactly k ones.
            if (ones == k) {

                // Remove leading zeroes.
                // This makes the window as short as possible.
                while (s[left] == '0') {
                    left++;
                }

                int len = right - left + 1;
                string curr = s.substr(left, len);

                if (len < minLen) {
                    minLen = len;
                    ans = curr;
                }
                else if (len == minLen && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};