// You are using GCC
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct node{
    float w, p, r;
};
bool com(node a,node b){
    return a.r>b.r;
}
void Knapsack(node k[],int n,int cap){
    sort(k,k+n,com);
    float profit=0;
    for(int i=0;i<n;i++){
        if(k[i].w<=cap){
        profit+=k[i].p;
        cap-=k[i].w;
        }
        else{
            profit+=cap*k[i].r;
            break;
        }
    }
    cout<<"Maximum profit is:- "<<fixed<<setprecision(2)<<profit;

}
int main(){
    int n;
    cin>>n;
    node k[n];
    for(int i=0;i<n;i++){
        float a,b;
        cin>>a>>b;
        k[i].w=a;
        k[i].p=b;
        k[i].r=b/a;
    }
    int c;
    cin>>c;
    Knapsack(k,n,c);
    
}