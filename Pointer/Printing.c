#include <stdio.h>

int main() {
    double d = 2.5;
    int i = 7;
    char ch = 'A';

    double* p_d = &d;
    int* p_i = &i;
    char* p_ch = &ch;

    printf("d: %f, i: %d, ch: %c, p_d: %p, p_i: %p, p_ch: %p", d, i, ch, p_d, p_i, p_ch);
    printf("\n");
    printf("d: %p, i: %p, ch: %p, p_d: %p, p_i: %p, p_ch: %p", &d, &i, &ch, &p_d, &p_i, &p_ch);
    printf("\n");
    printf("d: %lu, i: %lu, ch: %lu, p_d: %lu, p_i: %lu, p_ch: %lu", sizeof(d), sizeof(i), sizeof(ch), sizeof(p_d), sizeof(p_i), sizeof(p_ch));

}