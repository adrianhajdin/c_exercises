#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...)printf(_VA_ARGS_)
#endif

#define MAXA 200

int main() {
    int n, starost;
    int br; // broj mladih
    int mn; // godine starosti najmladje osobe
    int *pbr=NULL, *pmn=NULL;

    pbr = &br, *pbr = 0;
    pmn = &mn, *pmn = MAXA;
  
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &starost);

        if(starost >= 10 && starost <= 30) {
            (*pbr)++;
        }

        if(starost < *pmn) {
            *pmn = starost;
        }  
    }

    printf("%d\n", *pbr);
    printf("%d\n", *pmn);

    return 0;
}