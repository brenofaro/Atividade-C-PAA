#include <stdio.h>
#include <stdlib.h>

void redux(float *num1, float *num2){
    printf("%.2f ", *num1 - *num2);
}


int main() {
    float num1, num2;
    scanf("%f %f", &num1, &num2);
    redux(&num1, &num2);
    printf("%.2f", num2);
    return 0;
}
