#include<iostream>
#include<vector>
using namespace std;    
void showPath(vector<vector<int> >&sol) {
   cout << "The solution maze: " << endl;   
   int N=sol.size();
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << sol[i][j] << " ";
      cout << endl;
   }
}
// function to check place is inside the maze and have value 1
bool isValidPlace(vector<vector<int> >&maze,int x, int y) {   
   int N=maze.size();  
   if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
      return true;
   return false;
}
bool solveRatMaze(vector<vector<int> >&sol,vector<vector<int> >&maze,int x, int y) {
   // when (x,y) is the bottom right room
   int N=sol.size();
   if(x == N-1 && y == N-1) {       
      sol[x][y] = 1;
      return true;
   }
   //check whether (x,y) is valid or not
   if(isValidPlace(maze,x, y) == true) {     
      //set 1, when it is valid place
      sol[x][y] = 1; 
      //go for bottom direction     
      if (solveRatMaze(sol,maze,x+1, y) == true)      
         return true;
      //find path by moving right direction
      if (solveRatMaze(sol,maze,x,y+1) == true)         
         return true;
      //if both are closed, there is no path     
      sol[x][y] = 0;         
      return false;
   }  
   return false;
}
bool findSolution() {
    int n;
    cin>>n;
   vector<vector<int> >maze(n,vector<int>(n));
    vector<vector<int> >sol(n,vector<int>(n, 0));
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cin>>maze[i][j];
    }
   }
   if(solveRatMaze(sol,maze,0, 0) == false) {
      cout << "There is no path";
      return false;
   }
   showPath(sol);
   return true;
}
int main() {
   findSolution();
}
