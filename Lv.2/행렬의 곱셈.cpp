#include <string>
#include <vector>

using namespace std;
// 1 4  3 3
// 3 2  3 3
// 4 1
//          j
// i 2 3 2  5 4 3
//   4 2 4  2 4 1
//   3 1 4  3 1 1
// 
// 1   3  4
// 2
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(),0));
    
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2[0].size();j++){
            for(int k=0;k<arr1[i].size();k++){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}