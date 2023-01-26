class Solution {
public:
    long long reverse(long long x) {
        
        long long res = 0;
        long long temp = abs(x);

        while(temp>0)
        {
            res = (res*10) + (temp%10);

        temp/=10;
        }

        if((x>0 && res>(pow(2, 31) - 1)) || (x<0 && res>pow(2, 31))) return 0;

        if(x>=0) return res;
        else return (-1*res);

    }
};
