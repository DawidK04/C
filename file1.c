#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    int hex = (argc > 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (hex) {
                printf("%4X", i * j);
            } else {
                printf("%4d", i * j);
            }
        }
        printf("\n");
    }
    return 0;
}
