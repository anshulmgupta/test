#include <iostream>
#include <algorithm>
using namespace std;

int count_paths(int maze[][4], int rows, int cols, int i, int j){
    if(maze[i][j] == 0 || i > rows-1 || j > cols-1)
        return 0;
 
    if(i == rows-1 && j == cols-1)
        return 1;

    int right = count_paths(maze, rows, cols, i, j+1);
    int down = count_paths(maze, rows, cols, i+1, j);
    
    return right + down;
}

bool is_safe(int maze[][4], int rows, int cols, int i, int j){
    if(maze[i][j] == 1 && i <= rows-1 && j <= cols-1)
        return true;
    return false;
}

bool solve_rat_maze(int maze[][4], int solution[][4], int rows, int cols, int i, int j){
    if(i == rows-1 && j == cols-1){
        solution[i][j] = 1;
        return true;
    }
    if(is_safe(maze, rows, cols, i, j)){
        solution[i][j] = 1;
        if(solve_rat_maze(maze, solution, rows, cols, i, j+1))
            return true;

        if(solve_rat_maze(maze, solution, rows, cols, i+1, j))
            return true;

        solution[i][j] = 0;
        return false;
    }
    return false;
}


void test_case_one(){
    int maze[][4] =  {{1, 1, 1, 1},
                      {1, 0, 1, 1},
                      {0, 1, 1, 1},
                      {1, 1, 1, 1}};
    int r = sizeof(maze)/sizeof(maze[0]);
    int c = 4;
    int total_paths = count_paths(maze, r, c, 0, 0);
    cout << "Total Number of Paths = " << total_paths << endl;
}

void test_case_two(){
    int maze[][4]  =  {{1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {0, 1, 0, 0},
                       {1, 1, 1, 1}};
    int r = sizeof(maze)/sizeof(maze[0]);
    int c = 4;
    int solution[r][4];
    fill(solution[0], solution[0] + r * c, 0);
    bool path_exists = solve_rat_maze(maze, solution, r, c, 0, 0);
    if(path_exists){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    test_case_one();
    test_case_two();
    return 0;
}
