#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>


struct prime_value{
    int pos;
    int num;

    bool operator<(struct prime_value &a){
        return num < a.num;
    }
};


void add_primes(int max_prime, int primes[], int pos);
void obtain_first_primes(int list_of_values[], struct prime_value list_of_primes[], int primes[], int max_prime);
void obtain_primes(int list_of_values[], struct prime_value list_of_primes[], int primes[], int num_of_values, int max_prime);
void result(struct prime_value list_of_primes[], int num_of_values);


int main(){
    int n;
    int max_prime, num_of_values;
    int last_n = 2;
    int list_of_values[100];
    int primes[10000] = {};
    struct prime_value list_of_primes[101];

    scanf("%d", &n);
    primes[0] = primes[1] = 1;

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &max_prime, &num_of_values);

        for(int j = 0; j < num_of_values; ++j){
            scanf("%d", &list_of_values[j]);
        }

        if(last_n < max_prime){
            add_primes(max_prime, primes, last_n);
            last_n = max_prime;
        }

        obtain_first_primes(list_of_values, list_of_primes, primes, max_prime);
        obtain_primes(list_of_values, list_of_primes, primes, num_of_values, max_prime);

        printf("Case #%d: ", (i + 1));
        result(list_of_primes, num_of_values);
        printf("\n");
    }

    return 0;
}


void add_primes(int max_prime, int primes[], int pos){
    int i, j, m;

    for(i = pos, m = sqrt(max_prime); i <= m; ++i){
        if(primes[i] == 0){
            for(j = i*i; j <= max_prime; j += i){
                primes[j] = 1;
            }
        }
    }
}


void obtain_first_primes(int list_of_values[], struct prime_value list_of_primes[], int primes[], int max_prime){
    for(int j = 2; j < max_prime; ++j){
        if(primes[j] == 0){
            for(int k = 2; k <= max_prime; ++k){
                if(primes[k] == 0 && j * k == list_of_values[0]){
                    list_of_primes[0].pos = 0;
                    list_of_primes[0].num = j;
                    list_of_primes[1].pos = 1;
                    list_of_primes[1].num = k;
                    primes[j] = 2;
                    primes[k] = 2;
                    return;
                }
            }
        }
    }
}


void obtain_primes(int list_of_values[], struct prime_value list_of_primes[], int primes[], int num_of_values, int max_prime){
    bool entered;

    for(int i = 1; i < num_of_values; ++i){
        entered = false;

        for(int k = 2; k <= max_prime; ++k){
            if(primes[k] == 0 && list_of_values[i] % k == 0 && (list_of_primes[i].num * k == list_of_values[i])){
                list_of_primes[i+1].pos = i+1;
                list_of_primes[i+1].num = k;
                primes[k] = 2;
                entered = true;
                break;
            }
        }

        if(!entered){
            for(int k = 2; k <= max_prime; ++k){
                if(primes[k] == 2 && list_of_values[i] % k == 0 && (list_of_primes[i].num * k == list_of_values[i])){
                    list_of_primes[i+1].pos = i+1;
                    list_of_primes[i+1].num = k;
                    break;
                }
            }
        }
    }
}


void result(struct prime_value list_of_primes[], int num_of_values){
    int last, counter;
    char msg[num_of_values + 2];

    std::sort(list_of_primes, list_of_primes + num_of_values + 1);
    last = list_of_primes[0].num;
    counter = 0;

    //printf("%d\n", num_of_values);

    for(int i = 0; i <= num_of_values; ++i){
       // printf("%d\n", list_of_primes[i].num);

        if(last != list_of_primes[i].num){
            last = list_of_primes[i].num;
            ++counter;
        }

        msg[list_of_primes[i].pos] = 65 + counter;
    }

    for(int i = 0; i <= num_of_values; ++i){
        printf("%c", msg[i]);
    }

    /*for(int i = 0; i <= num_of_values; ++i){
        last = list_of_primes[0].num;
        counter = 0;

        for(int j = 0; j <= num_of_values; ++j){
            if(list_of_primes[j].pos == i){
                printf("%c", (65 + counter));
                break;
            }

            if(last != list_of_primes[j].num){
                last = list_of_primes[j].num;
                ++counter;
            }
        }
    }*/
}
