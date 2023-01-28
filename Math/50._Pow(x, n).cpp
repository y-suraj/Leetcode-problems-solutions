class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n;

        if(nn<0) nn = nn*-1;

        while(nn>0){
            if(nn%2==1){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n<0) 
            return 1.0/ans;
        else
            return ans;
    }
};

// Recursive solution
/*
class Solution {
public:
    double fun(double x, int n){
        if(x==0) return 0;
        if(n==0) return 1;

        double res = fun(x*x, n/2);
        
        if(n%2) return x * res;
        else return res;
    }
    double myPow(double x, int n) {
        
        double ans = fun(x, n);

        return (n<0) ? 1/ans : ans;
    }
};
*/
