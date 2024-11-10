#include<iostream>
#include<algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}
int find(int parent[],int i){
    while(parent[i]!=-1){
        i=parent[i];
    }
    return i;
}
void unions(int parent[],int x,int y){
    parent[x]=y;
}
void kruskalMST(int V,int E,Edge edge[]){
    sort(edge, edge+E, compareEdges);
    int parent[V];
    fill(parent,parent+V,-1);
    Edge res[V];
    int eCount=0;
    for(int i=0;i<E && eCount<V-1;i++){
        int src=edge[i].src;
        int dest=edge[i].dest;
        int weig=edge[i].weight;
        int parentsrc=find(parent,src);
        int parentdest=find(parent,dest);
        if(parentsrc != parentdest){
            res[eCount].src=src;
            res[eCount].dest=dest;
            res[eCount].weight=weig;
            eCount++;
            unions(parent,parentsrc,parentdest);
        }
    }
    cout<<"Following are the edges in the constructed MST\n";
    int mincost=0;
    for(int i=0;i<eCount;i++){
        cout<<res[i].src<<" -- "<<res[i].dest<<" == "<<res[i].weight<<endl;
        mincost+=res[i].weight;
    }
    cout<<"Minimum Cost Spanning Tree: "<<mincost<<endl;
}
int main(){
    int V, E;
    cin >>V>>E;
    Edge edges[E];
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    kruskalMST(V, E, edges);
    return 0;
}