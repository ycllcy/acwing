#include <iostream>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

double x;

int main() {
    scanf("%lf", &x);

    if (x >= 0) {
        double l = 0.0, r = x;
        if (x < 1) r = 1;
        while (r - l > eps) {
            double mid = (l + r) / 2.0;
            if (mid * mid * mid < x) l = mid;
            else r = mid; 
        }
        printf("%f", l);
    } else {
        double l = x, r = 0.0;
        if (x > -1) l = -1;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (mid * mid * mid < x) l = mid;
            else r = mid;
        }
        printf("%f", l);
    }

    return 0;
}