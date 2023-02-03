class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // This function returns the largest string x 
        // such that x divides both str1 and str2

        // If str1 is smaller than str2, swap their positions
        if (str1.size() < str2.size()) 
            return gcdOfStrings(str2, str1);

        // If str2 is empty, return str1
        if (str2.empty()) 
            return str1;

        // If the first str2.size() characters of 
        // str1 is not equal to str2, return an empty string
        if (str1.substr(0, str2.size()) != str2) 
            return "";
            
        // Otherwise, divide str1 by str2 and continue with the recursion
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
