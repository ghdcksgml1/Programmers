#include <string>
#include <vector>

using namespace std;
// 'a' - 32 = 'A'
// 'A' + 32 = 'a'
string solution(string s) {
    int index =0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') index=0;
        if(s[i] >= '0' && s[i] <= '9' && index==0){
            index++;
            continue;   
        }
        if(s[i] >= 'a' && s[i] <= 'z' && index==0){
            s[i] -= 32;
            index++;
            continue;
        }
        if(s[i] >= 'A' && s[i] <= 'Z' && index==0){
            index++;
            continue;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
            index++;
            continue;
        }
    }
    return s;
}