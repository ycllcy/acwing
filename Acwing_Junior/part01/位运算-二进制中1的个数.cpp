#include <iostream>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T --) {
        int x;
        int cnt = 0;
        scanf("%d", &x);
        while (x) {
            x -= lowbit(x);
            cnt ++;
        }
        printf("%d ", cnt);
    }
    
    return 0;
}