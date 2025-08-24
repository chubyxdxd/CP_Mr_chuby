#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
typedef vector<int> row;
typedef vector<row> Mat;

Mat matMul(Mat &a,Mat &b){
  int n = a.size();
  int m = a[0].size();
  int p = b[0].size();
  Mat c(n,row(p,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<p;k++){
	c[i][k]=(c[i][k]%mod+(a[i][j]%mod*b[j][k]%mod)%mod)%mod;
      }
    }
  }
  return c;
}
Mat MatPow(Mat A, ll p){
  Mat ans(A.size(),row(A.size(),0));
  for(int i=0;i<A.size();i++)ans[i][i]=1;
  while(p){
    if(p&1)ans=matMul(ans,A);
    A = matMul(A,A);
    p>>=1;
  }
  return ans;
}

int main(){
  
}
