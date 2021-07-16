function solution(s) {
    let answer = '';
    s = s.split(' ');
    for(let i=0;i<s.length;i++){
        s[i] = parseInt(s[i]);
    }
    s = s.sort((a,b)=>{
        return a-b;
    });
    answer = s[0]+' '+s[s.length-1];
    return answer;
}