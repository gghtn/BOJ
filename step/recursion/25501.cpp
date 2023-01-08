#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int call;

int recursion(const char* s, int l, int r) {
    call++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int T;
    char s[1000];
    scanf("%d", &T);

    while (T--)
    {
        memset(s, '\0', 1000);
        scanf("%s", &s);
        call = 0;
        printf("%d ", isPalindrome(s));
        printf("%d\n", call);
    }

    return 0;
}