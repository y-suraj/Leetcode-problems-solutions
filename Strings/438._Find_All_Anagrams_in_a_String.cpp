class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        vector<int> pins;
        if(sLen<pLen)
            return pins;

        pins.push_back(0);
        if(s==p)
            return pins;

        pins.pop_back();

        vector<int> pFreq(26);
        for(int i=0; i<pLen; i++)
            pFreq[p[i]-'a']++;

        int left = 0, right = 0;
        vector<int> window(26);

        while (right < sLen) {
            window[s[right] - 'a']++;
            right++;

            if (right - left == pLen) {
                if (window == pFreq) pins.push_back(left);
                window[s[left] - 'a']--;
                left++;
            }
        }
        return pins;
    }
};

/*
EXPLANATION:
The purpose of the function is to find the starting indices of all anagrams of the string `p` in the string `s`.

The first step is to check if the length of `s` is less than the length of `p`. If it is, then an empty vector is returned since there can't be any anagrams of `p` in `s`.

Then, a check is made to see if `s` is equal to `p`. If they are equal, then the vector with a single element 0 is returned, since the entire string `s` is an anagram of `p`.

Next, the frequency of each character in `p` is recorded in a 26-element vector `pFreq` using the indices of the characters in the alphabet.

A sliding window approach is used to keep track of the frequency of characters in the current window of `s` that has the same length as `p`. The indices of the start and end of the window are kept track of with `left` and `right` respectively. Another 26-element vector `window` is used to keep track of the frequency of characters in the current window.

As `right` increases and moves the window along `s`, the frequency of the character at the new `right` is incremented in `window`. If the length of the current window is equal to the length of `p`, it is compared to `pFreq`. If they are equal, the index of the start of the current window, `left`, is added to the result vector `pins`.

Finally, the vector `pins` is returned as the result of the function.

*/
