#include <stdio.h>
#include <stdlib.h>

#define NMAX 20000

int* push(int, int *, int *);
int pop(int *);

int main() {
    char array[NMAX];
    int n;
    int total_s = 0;
    int i, j;
    int tmp_s, tmp_ts;
    int top1 = 0;
    int top2_p = 0;
    int top2_s = 0;

    for (i = 0;; i++) if (scanf("%c", &array[i]) == EOF) break;
    n = i;

    int *stack1 = (int *)malloc(n * sizeof(int));
    int *stack2_p = (int *)malloc(n * sizeof(int));
    int *stack2_s = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        if (array[i] == '/') {
            if (top1 > 0) {
                tmp_ts = i - stack1[top1 - 1];
                total_s += tmp_ts;
                //printf("top2_p=%d\n",top2_p);
                //printf("entered for\nstack2_p[j]=%d\ni=%d\nstack1[top1]=%d\n\n",stack2_p[j],i,stack1[top1-1]);
                while (top2_p > 0 && stack2_p[top2_p - 1] > stack1[top1 - 1]) {
                    //printf("entered while\n");
                    tmp_s = stack2_s[top2_s - 1];
                    tmp_ts += tmp_s;
                    pop(&top2_p);
                    pop(&top2_s);
                }

                stack2_p = push(stack1[top1 - 1], stack2_p, &top2_p);
                stack2_s = push(tmp_ts, stack2_s, &top2_s);
                pop(&top1);
            }
        } else if (array[i] == '\\') {
            stack1 = push(i, stack1, &top1);
        }
    }

    printf("%d\n%d", total_s, top2_p);
    if (top2_p > 0) {
        for (i = 0; i < top2_p; i++) {
            printf(" %d", stack2_s[i]);
            //printf("entered yen \ntop1=%d\nstack1[top1]=%d\ni=%d\n\n",top1-1,stack1[top1-1],i);
        }
    }
    printf("\n");

    free(stack1);
    free(stack2_p);
    free(stack2_s);

    return 0;
}

int* push(int n, int *stack, int *top) {
    stack[*top] = n;
    (*top)++;
    return stack;
}

int pop(int *top) {
    (*top)--;
    return *top;
}
