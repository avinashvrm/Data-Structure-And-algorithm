#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// `N × N` matrix
#define N 10
 
// Stores cell coordinates of the matrix
typedef pair<int, int> Node;
 
// Below arrays detail all four possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
 
// Function to check if it is possible to go to position `pt`
// from the current position. The function returns false if `pt` is
// not a valid position, or it is already visited
bool isValid(vector<Node> const &path, Node pt)
{
    return (pt.first >= 0) && (pt.first < N) &&
        (pt.second >= 0) && (pt.second < N) &&
        (find(path.begin(), path.end(), pt) == path.end());
}
 
// Function to print the complete path from source to destination
void printPath(vector<Node> const &path)
{
    for (Node cell: path) {
        cout << "(" << cell.first << ", " << cell.second << ") ";
    }
    cout << endl;
}
 
// Find a route in a matrix `mat` from source cell `(0, 0)` to
// destination cell `(N-1, N-1)`
bool findPath(int mat[][N], vector<Node> &path, Node &curr)
{
    // include the current cell in the path
    path.push_back(curr);
 
    // if the destination is found, return true
    if (curr.first == N - 1 && curr.second == N - 1) {
        return true;
    }
 
    // get the value of the current cell
    int n = mat[curr.first][curr.second];
 
    // check all four possible movements from the current cell
    // and recur for each valid movement
    for (int i = 0; i < 4; i++)
    {
        // get the next position using the value of the current cell
        int x = curr.first + row[i] * n;
        int y = curr.second + col[i] * n;
 
        Node next = make_pair(x, y);
 
        // check if it is possible to go to a position `(x, y)`
        // from the current position
        if (isValid(path, next) && findPath(mat, path, next)) {
            return true;
        }
    }
 
    // backtrack: exclude the current cell from the path
    path.pop_back();
    return false;
}
 
int main()
{
    int mat[N][N] =
    {
        { 7, 1, 3, 5, 3, 6, 1, 1, 7, 5 },
        { 2, 3, 6, 1, 1, 6, 6, 6, 1, 2 },
        { 6, 1, 7, 2, 1, 4, 7, 6, 6, 2 },
        { 6, 6, 7, 1, 3, 3, 5, 1, 3, 4 },
        { 5, 5, 6, 1, 5, 4, 6, 1, 7, 4 },
        { 3, 5, 5, 2, 7, 5, 3, 4, 3, 6 },
        { 4, 1, 4, 3, 6, 4, 5, 3, 2, 6 },
        { 4, 4, 1, 7, 4, 3, 3, 1, 4, 2 },
        { 4, 4, 5, 1, 5, 2, 3, 5, 3, 5 },
        { 3, 6, 3, 5, 2, 2, 6, 4, 2, 1 }
    };
 
    vector<Node> path;
 
    Node source = make_pair(0, 0);
 
    // Find a route in a matrix `mat` from source cell `(0, 0)` to
    // destination cell `(N-1, N-1)`
    if (findPath(mat, path, source)) {
        printPath(path);
    }
 
    return 0;
}
