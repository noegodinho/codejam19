#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>


char* result(char maze[], int m);


int main(){
    int n, m;
    char maze[100000];

    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &m);

        std::cin >> maze;

        printf("Case #%d: %s\n", (i + 1), result(maze, m));
    }

    return 0;
}

char* result(char maze[], int m){
    char* new_maze = maze;
    int end_e = 0;
    int actual_e = 0;
    int end_s = 0;
    int actual_s = 0;

    for(int i = 0; i < 2 * m - 2; ++i){
        if(maze[i] == 'S'){
            ++actual_s;

            if(actual_s == end_e + 1){
                new_maze[i] = 'E';
                ++end_e;
            }

            else{
                ++end_s;
            }
        }

        else{
            ++actual_e;

            if(actual_e == end_s + 1){
                new_maze[i] = 'S';
                ++end_s;
            }

            else{
                ++end_e;
            }
        }
    }

    //printf("%d - %d\n%d - %d\n%d\n", actual_e, end_e, actual_s, end_s, m);

    return new_maze;
}
