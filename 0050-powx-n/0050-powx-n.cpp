class Solution {
public:
    double myPow(double x, int n) {
	double ans=1;
    long binform=n;
    if(x==1){return 1;}
    if(n==0){return 1;}
    if(n==1){return x;}
    if(x==-1){if(n%2==0){return 1;}
    else{return -1;}}
    if(binform<0){
        binform*=-1;
        x=1/x;
    }
    
	while(binform>0){
		if(binform%2==1){
			ans*=x;
		}
		binform=binform/2;
		x*=x;
	}
	return ans;
}};

