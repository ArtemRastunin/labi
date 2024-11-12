#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cstring>
void SearchSort(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		int k = i;
		for (int j = i + 1; j < size; ++j) {
			if (mas[j] < mas[k]) {
				k = j;
			}
		}
		int tmp = mas[k];
		mas[k] = mas[i];
		mas[i] = tmp;
	}
}
void BubbleSort(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		bool if_replaced = false;
		for (int j = 0; j < size - i - 1; ++j) {
			if (mas[j + 1] < mas[j]) {
				int tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
				if_replaced = true;
			}
		}
		if (!if_replaced) {
			break;
		}
	}
}
void InsertionSort(int mas[], int size) {
	for (int i = 0; i < size; ++i) {
		int tmp = mas[i];
		int j;
		for (j = i - 1; j >= 0 && mas[j] > tmp; --j) {
			mas[j + 1] = mas[j];
		}
		mas[j + 1] = tmp;
	}
}
int main() {
	clock_t start, end;
	double time1;
	double time2;
	double time3;
	printf("Choose the lenght of the array:");
	int lenght = 0;
	int flag = 1;
	while (flag == 1) {
		scanf_s("%d", &lenght);
		if (lenght <= 0 || lenght > 100000) {
			printf("Choose the lenght from the range 1-100000:");
		}
		if (lenght >= 0 && lenght < 100000) {
			flag = 0;
		}

	}
	int* (array) = (int*)malloc(lenght * sizeof(int));
	int* (copy) = (int*)malloc(lenght * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < lenght; i++) {
		array[i] = rand() % 10;
	}
	printf("Select the sorting mode");
	printf("1-SearchSort");
	printf("2-BubbleSort");
	printf("3-InsertionSort");
	printf("4-Finish the program execution");
	int flazok = 0;
	int choose = 0;
	while (flazok == 0) {
		scanf_s("%d", &choose);
		if (choose == 1) {
			memcpy(copy, array, sizeof(int) * lenght);
			printf("\n");
			start = clock();
			SearchSort(copy, lenght);
			end = clock();
			time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("Time of bubble sort %f seconds\n", time1);
		}
		if (choose == 2) {
			memcpy(copy, array, sizeof(int) * lenght);
			printf("\n");
			start = clock();
			BubbleSort(copy, lenght);
			end = clock();
			time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("Time of search sort %f seconds\n", time2);
		}
		if (choose == 3) {
			memcpy(copy, array, sizeof(int) * lenght);
			printf("\n");
			start = clock();
			InsertionSort(copy, lenght);
			end = clock();
			time3 = ((double)(end - start)) / CLOCKS_PER_SEC;
			printf("Time of insertion sort %f seconds\n", time3);
		}
		if (choose == 4) {
			flazok = 1;
		}
	}
	if (array) {
		free(array);
	}
	if (copy) {
		free(copy);
	}
	return 0;
}