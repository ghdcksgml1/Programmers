function solution(n, s) {
    let answer = [];
    if(s>=n){
        const p = parseInt(s/n);
        const r = s%n;
        for(let i=0;i<n;i++){
            if(i<n-r){
                answer.push(p);
            }else{
                answer.push(p+1);
            }
        }
    }else{
        answer.push(-1);
    }
    return answer;
}