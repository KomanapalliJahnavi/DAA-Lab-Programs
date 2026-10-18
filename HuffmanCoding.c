#include <stdio.h>
struct Node {
    char ch;
    int freq;
    int left, right;
};

int main(){
    int n, i, j, min1, min2;
    int used[100] = {0};
    struct Node h[100];
    printf("Enter number of characters: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &h[i].ch, &h[i].freq);
        h[i].left = h[i].right = -1;
    }
    int total = n;
    while (total<2*n-1){
        min1 = min2 = -1;
        for (i = 0; i < total; i++) {
            if (!used[i]) {
                if (min1 == -1 ||
                    h[i].freq < h[min1].freq) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 ||
                           h[i].freq < h[min2].freq) {
                    min2 = i;
                }
            }
        }
        h[total].freq = h[min1].freq + h[min2].freq;
        h[total].ch = '#';
        h[total].left = min1;
        h[total].right = min2;
        used[min1] = 1;
        used[min2] = 1;
        used[total] = 0;
        total++;
    }
    printf("\nHuffman Codes:\n");
    for (i = 0; i < n; i++) {
        char code[100];
        int len = 0, cur = i, p;
        while (cur != total - 1) {
            for (p = n; p < total; p++) {
                if (h[p].left == cur || h[p].right == cur)
                    break;
            }
            if (p == total)
                break;
            code[len++] = (h[p].left == cur) ? '0' : '1';
            cur = p;
        }
        printf("%c: ", h[i].ch);
        for (j = len - 1; j >= 0; j--)
            printf("%c", code[j]);
        printf("\n");
    }
    return 0;
}

