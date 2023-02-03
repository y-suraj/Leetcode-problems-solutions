class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderIdx(123, 0);

        for(int i=1; i<=26; i++){
            orderIdx[order[i]] = i;
        }

        int wordsSize = words.size();

        for(int i=0; i<wordsSize-1; i++){
            if(words[i]==words[i+1]) continue;

            for(int j=0; words[i][j]!='\0'; j++){
                // if(orderIdx[words[i+1][j]]=='\0')
                //     return false;
                if (j >= words[i+1].size()) 
                    return false;
                    
                if(orderIdx[words[i][j]] < orderIdx[words[i+1][j]])
                    break;

                if(orderIdx[words[i][j]] > orderIdx[words[i+1][j]])
                    return false;
            }
        }

        return true;
    }
};
