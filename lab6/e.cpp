#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    for(int j=0;j<cols;j++){
        vector<int>col;
        
        for(int i=0;i<rows;i++){
            col.push_back(matrix[i][j]);
        }
        sort(col.begin(), col.end());

        for(int i=0;i<rows;i++){
            matrix[i][j]=col[i];
        }
    }

    for (int i = rows-1; i >= 0; --i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}