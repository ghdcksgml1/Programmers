#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int arr_num[16];
    int num = 1;
    int N = arr.size();
    
    // vector는 값을 바꾸기 힘들기 때문에 배열로 복사
    for(int i=0;i<arr.size();i++){
        arr_num[i] = arr[i];
    }
    // 오름차순 정렬
    sort(arr_num,arr_num+N);
    // 마지막 인덱스가 MAX값
    int MAX = arr_num[N-1];
    // MAX까지 루프를 돌려준다.
    for(int i=2;i<=MAX;i++){
        // 나누어 떨어지는 수의 개수를 저장하는 변수 trigger
        int trigger=0;
        // arr_num 배열을 순회하면서 i로 나누어 떨어지는
        // 배열이 있으면 trigger++해준다.
        for(int j=0;j<N;j++){
            if(arr_num[j]%i==0) trigger++;
        }
        // 나누어 떨어지는게 2개 이상이면
        if(trigger >= 2){
            num *= i; // 결과값에 i의 값을 곱해주고
            // arr_num 배열을 순회하면서 조건에 맞는 값들을 나눠준다.
            for(int j=0;j<N;j++){
                if(arr_num[j]%i==0) arr_num[j] /= i;
            }
            // i=1로 바꿔준다.
            i=1; // 이유: 이 루프가 끝나면 i++가 되기때문에
        }
    }
    // 소인수 분해된 값들을 곱해주는 과정
    for(int i=0;i<N;i++){
        num *= arr_num[i];
    }
    
    return num;
}