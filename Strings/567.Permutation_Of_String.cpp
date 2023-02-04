class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();
        // Return false if the size of s2 is less than the size of s1.
        if (s2Size < s1Size) return false;
        vector<int> str1(26),str2(26);

        for(int i=0; i<s1Size; i++){
            str1[s1[i]-'a']++;
            str2[s2[i]-'a']++;
        }
        // Loop through s2 and check if the current substring of length s1Size is a permutation of s1.
        for(int i=0; i<s2Size-s1Size; i++){
            // If the current substring is a permutation of s1, return true.
            if(str1==str2)
                return true;
            // Update the str2 vector for the next iteration.
            --str2[s2[i] - 'a'];
            ++str2[s2[i + s1Size] - 'a'];
        }
        // Return true if the last substring of length s1Size is a permutation of s1.
        return str1==str2;
    }
};
