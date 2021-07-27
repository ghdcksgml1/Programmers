function solution(lines) {
    let answer = 0;
    let start = [];
    let end = [];
    for(let i=0;i<lines.length;i++){
        let h,m,s,ms;
        let ih,im,is,dot;
        
        
        h = lines[i].substring(11);
        m = lines[i].substring(14);
        s = lines[i].substring(17);
        ms = lines[i].substring(20);
        dot = parseFloat(lines[i].substring(24))*1000;
        
        ih = parseInt(h)*3600*1000;
        im = parseInt(m)*60*1000;
        is = parseInt(s)*1000+parseInt(ms);
        
        start.push(ih+im+is-dot+1);
        end.push(ih+im+is);
    }
    
    for(let i=0;i<lines.length;i++){
        let end_time = end[i]+1000;
        let cnt = 0;
        for(let j=i;j<lines.length;j++){
            if(start[j] < end_time){
                cnt += 1;
            }
        }
        if(answer < cnt){
            answer = cnt;
        }
    }
    
    return answer;
}