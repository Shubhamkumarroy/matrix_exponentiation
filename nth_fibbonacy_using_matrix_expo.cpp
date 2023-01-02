#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define mia -1e18
#define maa 1e18
#define pii pair<int,int>
using namespace std;
// if n wiil be very large then we have to use modular
vector<vector<int>>multiply(vector<vector<int>>v1,vector<vector<int>>v2){
    int n=v1.size();
    int m=v1[0].size();
    int l=v2[0].size();
    vector<vector<int>>ans(n,vector<int>(l,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            int sum=0;
            for(int k=0;k<m;k++){
                sum+=v1[i][k]*v2[k][j];
                sum=sum%mod;
            }
            ans[i][j]=sum;
        }
    }
    return ans;
}
vector<vector<int>>nthpowerofmatrix(vector<vector<int>>v,int n){
    if(n==0){
        // return an identity matrix of size of v
        int sz=v.size();
        vector<vector<int>>id(sz,vector<int>(sz,0));
        for(int i=0;i<sz;i++){
            id[i][i]=1;
        }
        return id;
    }
    vector<vector<int>>vv=nthpowerofmatrix(v,n/2);
    vector<vector<int>>v1=multiply(vv,vv);
    return (n%2==0)?v1:multiply(v1,v);

}
signed main(){
    //fib(n)=fib(n-1)+fib(n-2);
    //fib(n+1)=fib(n)+fib(n-1);
    //fib[0]=0,fib(1)=1;
    /*
    |fib(n+1)|= M*|fib(n) 
    |fib(n)  |    |fib(n-1)|    so M={{1,1},{1,0}};

    if recurrence is f(n) = a1f(n − 1) + a2f(n − 2) + a3f(n − 3) + . . . + ad f(n − d) n>d
    for this M will be size of d*d ist row will be a1,a2.....ad

    //one more imp pt is if f(0) &&f(1) given means we have to start from f(2) and for f(2), M will be multipled one times
    // while for f(3) M wiil be multiplied by 2 times

    // if f(1) and f(2) is given then we have to start from f(3) so for f(3) M will be multiplied ones and so on..
    so for f(n+k) ....M^k
    and if start from f(0) then f(n+k)... M^(K+1)

    */
    int tt;
    cin>>tt;
    while(tt--)
    {
                int n;
                cin>>n;
                vector<vector<int>>ans{{1},{0}}; //
                vector<vector<int>>M{{1,1},{1,0}};
                vector<vector<int>>vv=nthpowerofmatrix(M,n-1);
                ans=multiply(vv,ans);
                cout<<ans[0][0]<<endl;
                




    }
}