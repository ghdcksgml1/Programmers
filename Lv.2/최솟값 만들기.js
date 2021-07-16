function solution(A,B){
    let answer = 0;
    
    A.sort((a,b)=>{
        return a-b;
    });
    B.sort((a,b)=>{
        return b-a;  
    })
    
    for(let i=0;i<A.length;i++){
        answer += A[i]*B[i];
    }
    return answer;
}