// You are using GCC
#include<iostream>
using namespace std;
int Solve(int coin[],int n,int amt){
    int dp[n+1][amt+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=amt;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(j<coin[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=1+dp[i][j-coin[i-1]];
            }
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return dp[n][amt];
}
int main(){
    int n;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
    cin>>coin[i];
    int amt;cin>>amt;
    cout << Solve(coin,n,amt);
}