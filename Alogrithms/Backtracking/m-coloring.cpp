#include<iostream>
using namespace std;
#define V 4
bool isSafe(int graph[V][V],int color[],int c,int v){
    for(int i=0;i<v;i++){
        if(graph[v][i] && c==color[i])
            return false;
    }
    return true;
}
bool coloring(int graph[V][V],int color[],int m,int v){
    if( v == V)
    return true;

    for(int c=1;c<=m;c++){
        if(isSafe(graph,color,c,v))
        {
            color[v] = c;
            if(coloring(graph,color,m,v+1))
                return true;

            color[v] = 0;//backtracking
        }
    }
    return false;
}
void print(int color[],int v){
    for(int i=0;i<v;i++){
        cout<<color[i]<<" ";
    }
}
bool mColor(int graph[V][V],int m){
    int color[V]={0};
    if(coloring(graph,color,m,0)){
        print(color,V);
        return true;
    }
    else{
        cout<<"No Solution";
        return true;
    }
}
int main(){
    int graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m=3;
    mColor(graph,m);
    return 0;
}