function solution(s) {
    let arr = s;
    let index = 0;
    arr=arr.split('');
    // 0: 48, 9:57 , a:97, z:122 , A:65 , Z:90
    for(let i=0;i<s.length;i++){
        if(arr[i]==' ') index=0;
        if(arr[i].charCodeAt(0) >= 48 && arr[i].charCodeAt(0) <= 57 && index == 0){
            index++;
            continue;
        }
        if(arr[i].charCodeAt(0) >= 97 && arr[i].charCodeAt(0) <= 122 && index==0){
            arr[i] = arr[i].toUpperCase();
            index++;
            continue;
        }
        if(arr[i].charCodeAt(0) >= 65 && arr[i].charCodeAt(0) <= 90 && index==0){
            index++;
            continue;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            arr[i] = arr[i].toLowerCase();
            index++;
            continue;
        }
    }
    arr = arr.join('');
    return arr;
}