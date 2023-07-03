# Strings

## [859. Buddy Strings](https://leetcode.com/problems/buddy-strings/description/)
```cpp
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int sLength = s.size();
        int gLength = goal.size();

        if(sLength==1 || gLength==1 || sLength != gLength)
            return false;
        
        int diffCnt = 0;
        vector<int> sHash('z' - 'a' + 1, 0), gHash('z' - 'a' + 1, 0);

        for(int i=0; i<sLength; i++) {
    
            sHash[s[i]-'a']++;
            gHash[goal[i]-'a']++;
            
            if(s[i]!=goal[i]) {
                diffCnt++;
            }
            // if s different at more than 2 indices
            if(diffCnt > 2) 
                return false;
        }
        // if occurance of letters in s is different from goal
        // example: s = "abc", goal = "bca"
        if(sHash!=gHash) 
            return false;

        // if occurance of letters are same in both s and goal
        // then check if there is any letter that is present more than once
        // example: s = "aa", goal = "aa" (i.e., s = goal)
        for(int i=0; i<26; i++) {
            if(sHash[i] > 1 && sHash[i] > 1)
                return true;
        }

        // If s != goal, but can be made equal by swapping at least 2 indices in s
        // example: s = "abcd", goal = "bacd"
        if(s!=goal)
            return true;
        else
            return false;
    }
};
// TC: O(N), where, N is the length of the string s
```
