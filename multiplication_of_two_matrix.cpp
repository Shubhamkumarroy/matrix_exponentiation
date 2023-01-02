#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define mia -1e18
#define maa 1e18
#define pii pair<int,int>
using namespace std;

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
            }
            ans[i][j]=sum;
        }
    }
    return ans;
}
signed main(){
    int tt;
    cin>>tt;
    while(tt--)
    {

                vector<vector<int>>v{{1,1},{1,0}};
                vector<vector<int>>v1{{1,0},{0,1}};
                vector<vector<int>>ans=multiply(v,v1);
                
    }
}