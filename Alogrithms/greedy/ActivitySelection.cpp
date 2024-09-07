
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    string m;
    int s,e;
};
bool com(node a,node b){
    return a.e<b.e;
}
void ActivitySelection(node a[],int n){
    sort(a,a+n,com);
    node pre=a[0];
    cout<<"Selected Activities are:\n";
    cout<<a[0].m<<" ";
    for(int i=1;i<n;i++){
        if(pre.e<=a[i].s){
            cout<<a[i].m<<" ";
            pre=a[i];
        }
    }
}
int main(){
    int n;
    cin>>n;
    node a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].m>>a[i].s>>a[i].e;
    }
    ActivitySelection(a,n);
}