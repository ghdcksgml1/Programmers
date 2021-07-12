function solution(arr) {
    let answer =1;
    const N = arr.length;
    
    arr.sort(function(a,b){
        return a-b;
    });
    
    const MAX = arr[N-1];
    for(let i=2;i<=MAX;i++){
        let trigger = 0;
        for(let j=0;j<N;j++){
            if(arr[j]%i==0) trigger++;
        }
        if(trigger>=2){
            answer *= i;
            for(let j=0;j<N;j++){
                if(arr[j]%i==0) arr[j]/=i;
            }
            i=1;
        }
    }
    
    for(let i=0;i<N;i++){
        answer *= arr[i];
    }
    
    return answer;
}