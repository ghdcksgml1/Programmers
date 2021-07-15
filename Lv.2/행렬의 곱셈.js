function solution(arr1, arr2) {
    const cross = [];

    for (let i = 0 ; i < arr1.length ; i ++) {
        const rows = [];
        for(let j = 0 ; j < arr2[0].length ; j ++) {
            rows.push(0);
        }
        cross.push(rows);
    }

    for (let i = 0 ; i < arr1.length ; i ++) {
        for (let j = 0 ; j < arr1[0].length ; j ++) {
            for (let k = 0 ; k < arr2[0].length ; k ++) {
                cross[i][k] += arr1[i][j] * arr2[j][k];
            }
        }
    }

    return cross;
}