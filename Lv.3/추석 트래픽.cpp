#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start;
    vector<int> end;
    for(int i=0;i<lines.size();i++){
        string h,m,s,ms;
        int ih,im,is,dot;
        cout<<lines[i]<<' ';
        lines[i].pop_back();
        cout<<lines[i]<<' ';
        h = lines[i].substr(11,2);
        m = lines[i].substr(14,2);
        s = lines[i].substr(17,2);
        ms = lines[i].substr(20,3);
        dot = stof(lines[i].substr(24,5))*1000;
        
        ih = stoi(h)*3600*1000;
        im = stoi(m)*60*1000;
        is = stoi(s)*1000+stoi(ms);
        start.push_back(ih+im+is-dot+1);
        end.push_back(ih+im+is);
    }
    for(int i=0;i<lines.size();i++){
        int end_time = end[i]+1000;
        int cnt=0;
        for(int j=i;j<lines.size();j++){
            if(start[j]<end_time){
                cnt++;
            }
        }
        answer = max(answer,cnt);
    }
    return answer;
}