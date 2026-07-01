class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==dividend){return 1;}
        if(divisor==1){return dividend;}
        if(divisor==-1){
            if(dividend==INT_MIN){return INT_MAX;}
            return -dividend;
        }
        long ans=0;
        bool sign=true;
        if(dividend>0 && divisor<0){sign=false;}
        if(dividend<0 && divisor>0){sign=false;}
        long long n=llabs(dividend);
        long long m=llabs(divisor);
        while(n>=m){
            int count=0;
            while(n>=(m<<(count+1))){
                count++;
            }
            n= n-(m<<(count));
            ans+=1<<count;
        }
        if(ans==(1<<31) && sign){return INT_MAX;}
        if(ans==(1<<31) && !sign){return INT_MIN;}
        return sign?ans:-1*ans;
    }
};