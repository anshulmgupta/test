#include <iostream>
#include <vector>
using namespace std;

int max_product_of_four(vector<vector<int>> &matrix){
  
    if(matrix.empty())
      return 0;
    
    
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    
    // TODO: Raise execption for invalid input rows||cols < 4
    int max_product = 1;
    
    for(int i = 0; i< rows; i++){
      
        for(int j = 0; j < cols; j++){
      
            int row_prod = 1;
            if(cols - j + 1 >= 4){
            // Row product
                for(int k = 0; k<4; k++){
                    row_prod *= matrix[i][k];
                }
            }
            int col_prod = 1;
            if(rows - i + 1 >= 4){
            // Col product
                for(int k = 0; k<4;k++){
                    col_prod *= matrix[k][j];
                }
            }
       
            // TOP Left
            int left_diag = 1;
            int left_diag_final = 0;
            int l_count = 0;
            for(int k = i, l = j; k < rows && l < cols; k++,l++){
                if(++l_count <= 4)
                    left_diag *= matrix[k][l];
                else
                    break;
            }
       
            if(l_count == 4)
                left_diag_final = left_diag;
       
       
            // TOP right
            int right_diag_final = 0;
            int r_count = 0;
            int right_diag = 1;
            for(int k = i, l = j; k < rows && l>=0; k++,l--){
                if(++r_count <= 4)
                    right_diag *= matrix[k][l];
                else
                    break;
            }
       
            if(r_count == 4)
                right_diag_final = right_diag;
       
            int max_rows_cols = max(row_prod, col_prod);
            int max_diags = max(left_diag_final, right_diag_final);
       
            max_product = max(max_product, max(max_rows_cols, max_diags));    
        }
      
    }
    return max_product;
}


// To execute C++, please define "int main()"
int main() {
  
    vector<vector<int>> arr =  {{1 ,1 ,1 ,1},
                                {0 ,500,0,4},
                                {6 ,6 ,7 ,5},
                                {0 ,0 ,0 ,1}};
  
  
    cout << "Max adjacent Product = " <<max_product_of_four(arr) << endl;
    return 0;
}


/* 

Given:
M x N grid of numbers

Return:
Max product of 4 adjacent numbers in a straight line

1 1 1 1 1 1 1 5 1 1 1 1 

5
0 1 2 3

1 1 1 1
0 0 0 0
0 0 0 0
0 0 0 0

1

1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 3

3
*/
