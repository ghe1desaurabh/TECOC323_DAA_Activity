#include <bits/stdc++.h> 
using namespace std; 
bool is_magic_square(vector<int> v) 
{ 
    int a[3][3];  
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j) 
            a[i][j] = v[3 * i + j];     

    int s = 0; 
    for (int j = 0; j < 3; ++j) 
        s += a[0][j]; 

     for (int i = 1; i <= 2; ++i) { 
        int tmp = 0; 
        for (int j = 0; j < 3; ++j) 
            tmp += a[i][j]; 
        if (tmp != s) 
            return 0; 
    } 

    for (int j = 0; j < 3; ++j) { 
        int tmp = 0; 
        for (int i = 0; i < 3; ++i) 
            tmp += a[i][j]; 
        if (tmp != s) 
            return 0; 
    }     

 
    int tmp = 0; 
    for (int i = 0; i < 3; ++i) 
        tmp += a[i][i]; 
    if (tmp != s) 
        return 0;     

    tmp = 0; 
    for (int i = 0; i < 3; ++i) 
        tmp += a[2 - i][i]; 
    if (tmp != s) 
        return 0; 
    return 1; 
} 

void find_magic_squares(vector<vector<int> >& magic_squares) 
{ 
    vector<int> v(9); 

    // Initialing the vector 
    for (int i = 0; i < 9; ++i) 
        v[i] = i + 1; 

    do { 
        if (is_magic_square(v)) { 
            magic_squares.push_back(v); 
        } 
    } while (next_permutation(v.begin(), v.end())); 
} 

int diff(vector<int> a, vector<int> b) 
{ 
    int res = 0; 

    for (int i = 0; i < 9; ++i) 
        res += abs(a[i] - b[i]); 

    return res; 
} 

int wrapper(vector<int> v) 
{ 
    int res = INT_MAX; 
    vector<vector<int> > magic_squares; 

    find_magic_squares(magic_squares); 

    for (int i = 0; i < magic_squares.size(); ++i) { 

        res = min(res, diff(v, magic_squares[i])); 
    } 
    return res; 
} 

int main() 
{ 
    vector<int> v; 
    int arr[9];
    for(int i=0;i<9;i++)
      cin>>arr[i];
    v.push_back(arr[0]); 
    v.push_back(arr[1]); 
    v.push_back(arr[2]); 

    v.push_back(arr[3]); 
    v.push_back(arr[4]); 
    v.push_back(arr[5]); 

    v.push_back(arr[6]); 
    v.push_back(arr[7]); 
    v.push_back(arr[8]); 

    cout << wrapper(v) << endl; 

    return 0; 
} 

