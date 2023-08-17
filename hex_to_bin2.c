#include <stdio.h>

void hexToBinaryArray(const unsigned int *hexArray, int length, unsigned char binaryArray[][8]) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 8; j++) {
            binaryArray[i][j] = (hexArray[i] >> (7 - j)) & 0x01;
        }
    }
}

void printBinaryArray(unsigned char binaryArray[][8], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", binaryArray[i][j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned int hexArray[8] = {0x66, 0x71, 0xff, 0xff, 0x7e, 0x7e, 0x3c, 0x18};
    int length = sizeof(hexArray) / sizeof(hexArray[0]);

    unsigned char binaryArray[8][8];

    hexToBinaryArray(hexArray, 8, binaryArray);
    printBinaryArray(binaryArray, 8, 8);

    return 0;
}
