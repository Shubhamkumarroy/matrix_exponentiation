//f(n) = a1f(n − 1) + a2f(n − 2) + a3f(n − 3) + . . . + ad f(n − d) n>d f(1),f(2),f(3)..f(d) is given
//print f(n)%m 
/*
Input file contains several test cases. Each test case begins with three integers: d, n, m, followed by
two sets of d non-negative integers. The first set contains coefficients: a1, a2, . . . , ad. The second set
gives values of f(1), f(2), . . . , f(d).
You can assume that: 1 ≤ d ≤ 15, 1 ≤ n ≤ 2
31 − 1, 1 ≤ m ≤ 46340. All numbers in the input will
fit in signed 32-bit integer.
Input is terminated by line containing three zeroes instead of d, n, m. Two consecutive test cases
are separated by a blank line.
*/
#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define mia -1e18
#define maa 1e18
#define pii pair<int,int>
using namespace std;

vector<vector<int>>multiply(vector<vector<int>>v1,vector<vector<int>>v2,int& m){
    int r1=v1.size();//row in 
    int c1=v1[0].size();
    int c2=v2[0].size();
    vector<vector<int>>ans(r1,vector<int>(c2,0));
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int sum=0;
            for(int k=0;k<c1;k++){
                sum+=((v1[i][k]%m)*(v2[k][j]%m))%m;
                sum=sum%m;
            }
            ans[i][j]=sum;
        }
    }
    return ans;
}

vector<vector<int>>nthpowerofmatrix(vector<vector<int>>M,int n,int &m){
    if(n==0){
        // return an identity matrix of size of M
        int sz=M.size();
        vector<vector<int>>id(sz,vector<int>(sz,0));
        for(int i=0;i<sz;i++){
            id[i][i]=1;
        }
        return id;
    }
    vector<vector<int>>vv=nthpowerofmatrix(M,n/2,m);
    vector<vector<int>>v1=multiply(vv,vv,m);
    return (n%2==0)?v1:multiply(v1,M,m);

}
signed main(){
    int tt;
    cin>>tt;
    /*
    M will be like the {{a1,a2,a3,......ad},{1,0,0,.......,0},{0,1,0,....0}.... go on}
    */
    while(tt--)
    {
                int d,n,m;
                cin>>d>>n>>m;
                // for fibonaccy d=2
                vector<vector<int>>M(d,vector<int>(d,0)),ans(d);
                
                int j=0;
                int x;
                int t=d;
                while(t--){
                    cin>>x;
                    M[0][j++]=x%m; // coeff of f(n) lie in ist row
                }
                t=d;
                j=0;
                while(t--){
                    cin>>x;
                    ans[j++]={x%m};
                }
                // i/p done after that find M 
                j=0;
                for(int i=1;i<d;i++){
                    M[i][j++]=1;   // if all linear recurrence are present
                }
                int k=n-d;
                vector<vector<int>>vv=nthpowerofmatrix(M,k,m); //kthpower
                ans=multiply(vv,ans,m);
                cout<<ans[0][0]<<endl;



                
                
               



    }
}