/*
#include <stdio.h>
#include <stdbool.h>

int Index(int A[], int len, int k){
    if(k == len - 1)	return len;
    int t = -2, minn = -1, maxn = 100, tk = k;
    bool f = true;
    while(f){
        if(A[tk] < A[tk+1]){
            for(int i=tk; i < len; ++i){
                if(minn <= A[i]){
                    minn = A[i];
                    t = i;
                }
                else{
                    f = false;
                    break;
                }
            }
        }
        else if(A[tk] > A[tk+1]){
            for(int i=tk; i < len; ++i){
                if(maxn >= A[i]){
                    maxn = A[i];
                    t = i;
                }
                else{
                    f = false;
                    break;
                }
            }
        }
        else{
            tk++;
            if(tk == len - 1)
                return len;
        }
    }
    return t+1;
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i < n; ++i){
        scanf("%d", &A[i]);
    }
    int t = 0;
    int id = 0;
    while(id < n){
        id = Index(A, n, id);
        if(id == -1)	break;
        t++;
    }
    printf("%d\n", t);
    return 0;
}
*/
