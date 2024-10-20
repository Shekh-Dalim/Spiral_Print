
/**************** Leetcode 54 Q:2:Spiral Print  TC- (m*n)**************/

#include<iostream>
#include<vector>
using namespace std;

// Function to print matrix in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;
    int row = matrix.size(); // Number of rows
    int col = matrix[0].size();  // Number of columns  (koi vi row ka size nikal loo)

    int count = 0;  // Count initialization
    int total = row * col;  // Total number of elements in the matrix

    // Index Initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while(count < total)
    {
        // Print starting row
        for(int index = startingCol; count < total && index <= endingCol; index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // Print ending column
        for(int index = startingRow; count < total && index <= endingRow; index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // Print ending row
        for(int index = endingCol; count < total && index >= startingCol; index--){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // Print starting column
        for(int index = endingRow; count < total && index >= startingRow; index--){
             ans.push_back(matrix[index][startingCol]);
             count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    // Input the matrix
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Call the spiralOrder function
    vector<int> result = spiralOrder(matrix);

    // Output the spiral order
    cout << "Spiral order of the matrix is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}