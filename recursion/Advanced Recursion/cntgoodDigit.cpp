// Leetcode 1922 :
// goood question 

class Solution {
    public:
        const long long MOD = 1e9 + 7; // declared the moudlo integer of type long long 
    
        long long pow(long long x, long long n) {
            if(n == 0) return 1;
    
            x = x % MOD;  // to keep x under the limits 
    
            if(n % 2 == 0) {
                long long half = pow((x * x) % MOD, n / 2); 
                //checking modulo again while passig x 
                return half;
            } else {
                return (x * pow(x, n - 1)) % MOD;
                // checking modulo after multiplying with x 
            }
        }
    
        int countGoodNumbers(long long n) {
            long long even = (n + 1) / 2;
            long long odd = n / 2;
    
            return (pow(5, even) * pow(4, odd)) % MOD; 
            // again checking if the answer is withing the bounds or not 
        }
    };