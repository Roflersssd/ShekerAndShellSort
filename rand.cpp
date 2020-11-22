
#include "rand.h"
void randArr(int* arr, int min, int max, int size) {
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = min + rand() % (max - min);
	}
}
void incrArr(float* arr, float min, float max, int size) {
	float delta = (max - min + 1) / size * 1.0;
	arr[0] = min;
	for (int i = 1; i < size; i++) {
		arr[i] = arr[i - 1] + delta;
	}

}
void decrArr(float* arr, float min, float max, int size) {
	float delta = (max - min + 1) / size;
	arr[0] = max;
	for (int i = 1; i < size; i++) {
		arr[i] = arr[i - 1] - delta;
	}

}
void incrArr(int* arr, int min, int max, int size) {
	float delta = (max - min + 1) / size * 1.0;
	arr[0] = min;
	for (int i = 1; i < size; i++) {
		arr[i] = arr[i - 1] + delta;
	}

}
void decrArr(int* arr, int min, int max, int size) {
	float delta = (max - min + 1)*1.0 / size;
	arr[0] = max;
	for (int i = 1; i < size; i++) {
		arr[i] = arr[i - 1] - delta;
	}

}

