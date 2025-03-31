#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int pn_str_len(const char *str) {
    if (str == NULL) {
        return -1;
    }
    int i = 0;
    while (str[i] != 0) {
        i++;
    }
    return i;
}

bool pn_str_cmp(const char *a, const char * b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    }
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
    }
    return a[i] == b[i];
}

void pn_str_capitalize(char *str) {
    if (str == NULL) {
        return;
    }
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
}

void pn_str_trim(char *str) {
    int i = pn_str_len(str) - 1;
    for (i; str[i] = ' '; i--) {
        str[i] = 0;
    }
    int j = 0;
    for (j; str[j] == ' '; j++);
    int k = j;
    for (k; str[k] != 0; k++) {
        str[k-j] = str[k];
    }
    str[k-j] = '\0';
}

void pn_str_rev(char *str) {
    if (str == NULL) return;
    int len = pn_str_len(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int main() {
    char *str[] = 'Hello World';
    printf("pn_str_len(\"%s\") = %d\n", *str, pn_str_len(*str));
    printf("pn_str_len(NULL) = %d\n\n", pn_str_len(NULL));

    char *a = "aaa";
    char *b = "aaa";
    printf("%d\n", pn_str_cmp(a,b));
}

