#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
vector<string> split(string input,char delimiter){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss,temp,delimiter)){
        answer.push_back(temp);
    }
    return answer;
}

string solution(string s) {
    vector<string> ans = split(s,' ');
    vector<int> temp(ans.size());
    for(int i=0;i<ans.size();i++){
        temp[i] = stoi(ans[i]);
    }
    sort(temp.begin(),temp.end());
    string answer = to_string(temp[0])+" "+to_string(temp[ans.size()-1]);
    
    return answer;
}