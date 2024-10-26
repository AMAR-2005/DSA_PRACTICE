
#include <iostream>
using namespace std;

int isSafe(int **sol, int x, int y,int n){

    if(x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1){
        return 1;
    }
    return 0;
}

int knightTour(int **sol, int x, int y, int num, int xMove[], int yMove[],int n){
    if((n * n) == num){
        return 1;
    }
    for(int i = 0; i < 8; i ++){
        int Xnext = x + xMove[i];
        int Ynext = y + yMove[i];
        
        if(isSafe(sol, Xnext, Ynext,n) == 1){
            sol[Xnext][Ynext] = num;
            if(knightTour(sol, Xnext, Ynext, num + 1, xMove, yMove,n) == 1){
                return 1;
            }
            else{
                sol[Xnext][Ynext] = -1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int **sol=new int *[n];

    for(int i=0;i<n;i++){
        sol[i]=new int[n];
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            sol[i][j] = -1;
        }
    }
    
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    sol[0][0] = 0;
    
    int ans = knightTour(sol, 0, 0, 1, xMove, yMove,n);
    cout << ans << endl;
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}