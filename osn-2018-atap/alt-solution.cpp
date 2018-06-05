#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100007];
    long long k, q;
    
    scanf("%s", &s); // header
    scanf("%s", &s);
    scanf("%lld %lld", &k, &q);
    
    long long len = strlen(s);
    long long n = len * k + 1;
    
    long long sumA[100007];
    long long sumB[100007];
    if (s[0] == 'A') {
        sumA[0] = 1;
        sumB[0] = 0;
    } else {
        sumA[0] = 0;
        sumB[0] = 1;
    }
    for (int i = 1; i < len; i++) {
        if (s[i] == 'A') {
            sumA[i] = sumA[i-1] + 1;
            sumB[i] = sumB[i-1];
        } else {
            sumA[i] = sumA[i-1];
            sumB[i] = sumB[i-1] + 1;
        }
    }
    
    long long peak_pos = 1 + sumB[len-1] * k;
    
    for (int i = 0; i < q; i++) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        
        long long ans;
        if (l <= peak_pos && peak_pos <= r) {
            ans = n;
        } else {
            long long pos;
            if (peak_pos < l) pos = l; else pos = r;
            
            long long base, mid, top;
            
            base = 1;
            top = k;
            while (base != top) {
                mid = (base + top + 1) / 2;
                long long l2 = 1 + sumB[len-1] * (mid - 1);
                long long r2 = n - sumA[len-1] * (mid - 1);
                if (l2 <= pos && pos <= r2) base = mid; else top = mid - 1;
            }
            long long layer = top;
            
            base = 0;
            top = len - 1;
            while (base != top) {
                mid = (base + top) / 2;
                long long l2 = 1 + (sumB[len-1] * (layer - 1) + sumB[mid]);
                long long r2 = n - (sumA[len-1] * (layer - 1) + sumA[mid]);
                if (l2 <= pos && pos <= r2) base = mid + 1; else top = mid;
            }
            long long letter = top;
            
            ans = (layer - 1) * len + letter + 1;
        }
        
        printf("%lld\n", ans);
    }
}
