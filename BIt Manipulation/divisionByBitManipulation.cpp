// divison of 2 numbers using the concept of repeated subtraction of powers of 2 as any number can be represented as power of 2 
// leetcode 29 

class Solution {
    public:
        int divide(int dividend, int divisor) {
    
            if(dividend == divisor) return 1 ;
    
            // check if the num or den is -ve 
            int flag = 1 ;
            if(dividend / divisor < 0){
                flag = -1 ;
            }
            long a = abs(dividend) ;
            long b = abs(divisor) ;
    
            long ans = 0 ;
    
            while(a >= b){
                int cnt = 0 ;
    
                while(a > (b << cnt+1) ){
                    cnt++ ;
                }
                ans = ans +  (1 << cnt) ;
                a = a - b << cnt ;
            }
    
    
            if(ans > INT_MAX) return INT_MAX ;
            if(ans < INT_MIN) return INT_MIN ;
    
            return ans*flag ;
    
    
    
            // // TC is O(divided / divisor) 
            // // Approch of repeated Subtraction is written below 
            // int flag = 1 ;
    
            // if(dividend < 0 || divisor < 0 ){
            //     if(dividend < 0 ){
            //         dividend = dividend * -1;
            //         flag = flag * -1 ;
            //     } 
            //     if(divisor < 0){
            //         divisor = divisor * -1 ;
            //         flag = flag * -1 ;
            //     }
            // }
    
    
            // int cnt = 0 ;
            // while(dividend > 0){
            //     dividend = dividend - divisor ;
            //     cnt++ ;
            // }
    
            // return (cnt - 1)*flag ;
        }
    };