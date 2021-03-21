#include <iostream>
#include <cstring>
using namespace std;
 
// `M × N` matrix
#define M 10
#define N 10
 
// Check if it is possible to go to position `(x, y)` from
// the current position. The function returns false if the cell
// has a value 0, or it is already visited.
bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y]) {
        return false;
    }
 
    return true;
}
 
// Returns false if not a valid position
bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0) {
        return true;
    }
 
    return false;
}
 
// Find the longest possible route in a matrix `mat` from the source cell
// `(0, 0)` to destination cell `(x, y)`.
// `max_dist` —> keep track of the length of the longest path from source to
// destination. It is passed by reference.
// `dist` —> length of the path from the source cell to the current cell `(i, j)`.
void findLongestPath(int mat[M][N], int visited[M][N], int i, int j,
                int x, int y, int &max_dist, int dist)
{
    // if the destination is not possible from the current cell
    if (mat[i][j] == 0) {
        return;
    }
 
    // if the destination is found, update `max_dist`
    if (i == x && j == y)
    {
        max_dist = max(dist, max_dist);
        return;
    }
 
    // set `(i, j)` cell as visited
    visited[i][j] = 1;
 
    // go to the bottom cell
    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j)) {
        findLongestPath(mat, visited, i + 1, j, x, y, max_dist, dist + 1);
    }
 
    // go to the right cell
    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1)) {
        findLongestPath(mat, visited, i, j + 1, x, y, max_dist, dist + 1);
    }
 
    // go to the top cell
    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j)) {
        findLongestPath(mat, visited, i - 1, j, x, y, max_dist, dist + 1);
    }
 
    // go to the left cell
    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1)) {
        findLongestPath(mat, visited, i, j - 1, x, y, max_dist, dist + 1);
    }
 
    // backtrack: remove `(i, j)` from the visited matrix
    visited[i][j] = 0;
}
 
int main()
{
    // input matrix
    int mat[M][N] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
 
    // construct a matrix to keep track of visited cells
    int visited[M][N];
    memset(visited, 0, sizeof visited);
 
    int max_dist = 0;
 
    // `(0, 0)` are the source cell, and `(5, 7)` are the destination cell coordinates
    findLongestPath(mat, visited, 0, 0, 5, 7, max_dist, 0);
 
    cout << "The Maximum length path is " << max_dist;
 
    return 0;
}
