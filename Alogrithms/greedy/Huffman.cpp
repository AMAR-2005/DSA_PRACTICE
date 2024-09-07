// You are using GCC
#include<iostream>
#include<queue>
using namespace std;
struct node{
    int f;
    char c;
    node*l,*r;  
    node(char a,int b){
        c=a;
        f=b;
    }
};
struct compare{
    bool operator()(node*n1,node*n2){
        return (n1->f>n2->f);
    }
};
void print(node*root,string s){
    if(root==NULL)
    return;
    if(root->c!='#')
    cout<<root->c<<":"<<s<<endl;
    print(root->l,s+"0");
    print(root->r,s+"1");
}
void Huffman(char ch[],int fr[],int n){
    priority_queue<node*,vector<node*>,compare>q;
    for(int i=0;i<n;i++){
        node* newn=new node(ch[i],fr[i]);
        q.push(newn);
    }
    node*root=NULL;
    while(q.size()>1){
        node *lf=q.top();
        q.pop();
        node *ri=q.top();
        q.pop();
        node* merge=new node('#',lf->f+ri->f);
        merge->l=lf;
        merge->r=ri;
        root=merge;
        q.push(merge);
    }
    print(root,"");
}
int main(){
    int n;
    cin>>n;
    char ch[n];
    int fr[n];
    for(int i=0;i<n;i++)
    cin>>ch[i];
    for(int i=0;i<n;i++)
    cin>>fr[i];
    Huffman(ch,fr,n);
}
