/*
Runtime: 4 ms, faster than 97.70% of C++ online submissions for Maximum Students Taking Exam.
Memory Usage: 7.7 MB, less than 5.07% of C++ online submissions for Maximum Students Taking Exam.
*/
class Solution {
public:
	int maxStudents(vector<vector<char>>& seats) {
		int n=seats.size(),m=seats[0].size(),i,j,k,max_=0;
		int st[8],f[8][256];
		memset(f,-1,sizeof(f));

		for (i=0;i<n;++i){
			k=0;
			for (j=0;j<m;++j){
				k <<= 1;
				k |= seats[i][j]=='.';
			}
			st[i]=k;
		}

		// 0^th row
		for (j=0;j<(1<<m);++j){  // student arrangement
			if ((j & st[0])==j && !(j & (j>>1))){  // no broken chairs && no adjacent 
				f[0][j]=__builtin_popcount(j);
				if (f[0][j]>max_) max_=f[0][j];
			}
		}

		for (i=1;i<n;++i){  // i^th row
			for (j=0;j<(1<<m);++j){  // student arrangement
				if ((j & st[i])==j && !(j & (j>>1))){  // no broken chairs && no adjacent 
					for (k=0;k<(1<<m);++k){
						if (!((k>>1) & j) && !((j>>1) & k) && f[i-1][k]!=-1){
							f[i][j]=max(f[i][j],f[i-1][k]+__builtin_popcount(j));
							if (f[i][j]>max_) max_=f[i][j];
						}
					}
				}
			}
		}

		return max_;
	}
};