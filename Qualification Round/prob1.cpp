#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>


int result(int value);
bool check(int v, int value);


int main(){
    int n;
    int value;
    int v;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &v);

        value = result(v);
        printf("Case #%d: %d %d\n", (i + 1), value, v - value);
    }

    return 0;
}


int result(int value){
    bool cond = false;
    int v = 1;
    time_t t;

    srand((unsigned) time(&t));

    while(!cond){
        v = rand() % value + 1;
        cond = check(v, value - v);
    }

    return v;
}


bool check(int v, int value){
    while(value > 0 || v > 0){
        if(v % 10 == 4){
            return false;
        }

        if(value % 10 == 4){
            return false;
        }

        value /= 10;
        v /= 10;
    }

    return true;
}
