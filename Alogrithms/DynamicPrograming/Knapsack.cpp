#include<iostream>
using namespace std;
int knapsack(int W,int wt[ ],int v[ ],int n)
{
    int dp[n+1][W+1];
    for(int i = 0 ; i <= n ; i++){
        for(int w = 0 ; w <= W ; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(wt[i-1] <= w){
                dp[i][w] = max(dp[i-1][w],v[i-1]+dp[i-1][w-wt[i-1]]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
        
    }
    return dp[n][W];
}
int main(){
    int n;
    cin>>n;
    int wt[n],v[n];
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>wt[i];
    }
    int c;
    cin>>c;
    cout<<knapsack(c,wt,v,n);
}