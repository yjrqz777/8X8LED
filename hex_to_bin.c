#include <stdio.h>
#include <stdlib.h>

void fillBinaryArray(int binaryArray[][8], int n, int value) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            binaryArray[top][i] = value;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            binaryArray[i][right] = value;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                binaryArray[bottom][i] = value;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                binaryArray[i][left] = value;
            }
            left++;
        }
    }
}

void printBinaryArray(int binaryArray[][8], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", binaryArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int binaryArray[8][8];

    for (int i = 0; i < 2; i++) {
        fillBinaryArray(binaryArray, 8, i);
        printBinaryArray(binaryArray, 8);
    }

    return 0;
}
