//Problem link - https://leetcode.com/problems/divide-two-integers/

class Solution 
{
public:
    int divide(int dividend, int divisor) {
        
        if( divisor == -1 && dividend == INT_MIN )//Corner case
            return INT_MAX;
        
        long a = abs( dividend );
        long b = abs( divisor );
        long quotient = 0;
        
        while( a >= b )
        {
            // Let Quotient = 2^x then
            int x = 0; // i.e. 2^0 = 1 --> it means a/b >= 1 
            while( a >= ( b << (1+x) ) )//b<<1 is (b x 2)
                x++;
            
            quotient += ( 1 << x );//x-times 2 has been multiplied with divisor
            a -= ( b << x ); // a -= b*Q
        }
        return (dividend < 0) == (divisor < 0) ? quotient : -quotient;//if both have same sign then no need to change sign of quotient
    }
};
