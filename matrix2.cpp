#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef vector<int> row;
typedef vector<row> Mat;

Mat matMul(Mat &a,Mat &b){
  Mat c(a.size(),row(b.size(),0));
  for(int i=0;i<c.size();i++){
    for(int j=0;j<c[i].size();j++){
      for(int k=0;k<b.size();k++){
	c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  return c;
}

Mat MatPow(Mat A, int p){
  Mat ans(A.size(),row(A.size(),0));
  for(int i=0;i<A.size();i++)ans[i][i]=1;
  while(p){
    if(p&1)ans=matMul(ans,A);
    A = matMul(A,A);
    p>>1;
  }
  return ans;
}

int main(){
  
}
