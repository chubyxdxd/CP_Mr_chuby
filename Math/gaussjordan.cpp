#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
typedef vector<int> row;
typedef vector<row> Mat;


// to mod inverse
ll binPow(ll b,int p){
  ll res=1;
  while(p){
    if(p&1)(res*=b)%=mod;
    (b*=b)%=mod;
    p/=2;
  }
  return res;
}

Mat gaussJordan(Mat A){
  int n =A.size();
  int m =A[0].size();
  int i =0; //para iterar sobre las filas
  int j =0; //para iterar sobre las columnas
  while( j < m - 1){
    int ind = i;
    while (ind < n && !A[ind][j]){
      ind++;
    }
    if(ind == n){
      j++;
      continue;
    }
    swap(A[ind],A[i]);
    int inv = binPow(A[i][j],mod-2);
    for(int l=j;l < m;l++){
      A[i][j] = 1ll * A[i][l] * inv % mod;
      A[i][j]%=mod;
    }

    for(int k=0; k < n;k++){
      if( k == i )continue;
      int fac = A[k][j];
      for(int l=j;l<m;l++){
	A[k][l] = (A[k][l]-1ll * fac * A[i][l])%mod;
	if(A[k][l] < 0){
	  A[k][l]+=mod;
	}
      }
      
    }
    i++;j++;
  }
  return A;
}

int main(){
  
}
