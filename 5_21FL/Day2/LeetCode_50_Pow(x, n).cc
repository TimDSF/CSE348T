class Solution {
public:
	double myPow(double x, int n) {
		long long N = n; 
		// since -2^31 <= int <= 2^31, int does not have a representation for the negation of the smallest number
		
		if (n < 0){ // x ^ (-n) = (1/x) ^ n
			x = 1.0 / x;
			N = - N;
		}
		
		double ans = 1; // initialize cumulative product
		
		while (N){ // if still bits left
			if (N & 1){ // if the lowest bit is 1
				ans *= x; // multiply by the corresponding power
			}
			x *= x; // binary lifting
			N >>= 1; // remove the lowest bit
		}
		
		return ans;
	}
};