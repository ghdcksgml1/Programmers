let sum = 0;
let queen_2 = new Array(20);
let queen_3 = new Array(50);
let queen_4 = new Array(50);

function backtracking(x,n) {
    if(x==n){
        sum++;
        return;
    }
    for(let y=0;y<n;y++){
        if(!queen_2[y] && !queen_3[y-x+n] && !queen_4[x+y]){
            queen_2[y] = true;
            queen_3[y - x + n] = true;
            queen_4[x + y] = true;
            backtracking(x + 1, n);
            queen_2[y] = false;
            queen_3[y - x + n] = false;
            queen_4[x + y] = false;
        }
    }
}

function solution(n) {
    var answer = 0;
    queen_2.fill(false);
    queen_3.fill(false);
    queen_4.fill(false);
    backtracking(0,n);
    answer = sum;
    return answer;
}