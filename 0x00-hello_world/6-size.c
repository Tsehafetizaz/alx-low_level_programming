#!/bin/bash
int main(void) { if (printf("Size of a char: %zu byte(s)\nSize of an int: %zu byte(s)\nSize of a long int: %zu byte(s)\nSize of a long long int: %zu byte(s)\nSize of a float: %zu byte(s)\n", sizeof(char), sizeof(int), sizeof(long int), sizeof(long long int), sizeof(float))) {} return 0; }
