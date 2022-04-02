#include<iostream>
#include<algorithm>
#include<time.h>
#include<Windows.h>
#include<vector>
using namespace std;
#define SIZE 1000000
void merge2(int* S, int low, int mid, int high,int* U ) {
	int i = low;
	int j = mid+1;
	int k = low;
	while (i <= mid && j <= high) {
		if (S[i] < S[j]) {
			U[k++] = S[i++];
		}
		else {
			U[k++] = S[j++];
		}
	}
	while (i <= mid) {
		U[k++] = S[i++];
	}
	while (j <= high) {
		U[k++] = S[j++];
	}
}
void mergesort2(int* S, int low, int high,int* U) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort2(U,low, mid, S);
		mergesort2(U,mid+1, high, S);
		merge2(U, low, mid, high, S);
	}
}
void merge3(int* S, int low, int mid, int mid2, int high,int* U) {
	int i = low;
	int j = mid;
	int k = mid2;
	int w = low;

	while ((i < mid) && (j < mid2) && (k < high)) {
		if (S[i] < S[j] && S[i] < S[k]) {
			U[w++] = S[i++];
		}
		if (S[j] < S[i] && S[j] < S[k]) {
			U[w++] = S[j++];
		}
		if (S[k] < S[i] && S[k] < S[j]) {
			U[w++] = S[k++];
		}
	}
	while ((i < mid) && (j < mid2)) {
		if (S[i] < S[j]) {
			U[w++] = S[i++];
		}
		else {
			U[w++] = S[j++];
		}
	}
	while ((j < mid2) && (k < high)) {
		if (S[j] < S[k]) {
			U[w++] = S[j++];
		}
		else {
			U[w++] =S[k++];
		}
	}
	while ((i < mid) && (k < high)) {
		if (S[i] < S[k]) {
			U[w++] = S[i++];
		}
		else {
			U[w++] = S[k++];
		}
	}

	while (i < mid) {
		U[w++] = S[i++];
	}
	while (j < mid2) {
		U[w++] = S[j++];
	}
	while (k < high) {
		U[w++] = S[k++];
	}
}
void mergesort3(int* S, int low, int high,int* U) {
	if (high - low<2)return;

	int mid= low + ((high - low) / 3);
	int mid2 = low + 2 * ((high - low) / 3) + 1;

	mergesort3(U, low, mid, S);
	mergesort3(U, mid, mid2, S);
	mergesort3(U, mid2, high, S);

	merge3(U, low, mid, mid2, high,S);

}
void merge4(int* S, int low, int mid1, int mid2,int mid3, int high, int* U) {
	int i = low;
	int j = mid1;
	int k = mid2;
	int w = mid3;
	int l = low;

	while ((i < mid1) && (j < mid2) && (k < mid3) && (w < high)) {
		if (S[i] < S[j] && S[i] < S[k] && S[i] < S[w]) {
			U[l++] = S[i++];
		}
		if (S[j] < S[i] && S[j] < S[k] && S[j] < S[w]) {
			U[l++] = S[j++];
		}
		if (S[k] < S[j] && S[k] < S[i] && S[k] < S[w]) {
			U[l++] = S[k++];
		}
		if (S[w] < S[j] && S[w] < S[k] && S[w] < S[i]) {
			U[l++] = S[w++];
		}

	}
	while ((i < mid1) && (j < mid2) && (k < mid3)) {
		if (S[i] < S[j] && S[i] < S[k]) {
			U[l++] = S[i++];
		}
		if (S[j] < S[i] && S[j] < S[k]) {
			U[l++] = S[j++];
		}
		if (S[k] < S[j] && S[k] < S[i]) {
			U[l++] = S[k++];
		}
	}
	while ((i < mid1) && (j < mid2) && (w < high)) {
		if (S[i] < S[j] && S[i] < S[w]) {
			U[l++] = S[i++];
		}
		if (S[j] < S[i] && S[j] < S[w]) {
			U[l++] = S[j++];
		}
		if (S[w] < S[j] && S[w] < S[i]) {
			U[l++] = S[w++];
		}
	}
	while ((i < mid1) && (k < mid3) && (w < high)) {
		if (S[i] < S[k] && S[i] < S[w]) {
			U[l++] = S[i++];
		}
		if (S[k] < S[i] && S[k] < S[w]) {
			U[l++] = S[k++];
		}
		if (S[w] < S[k] && S[w] < S[i]) {
			U[l++] = S[w++];
		}
	}
	while ((j < mid2) && (k < mid3) && (w < high)) {
		if (S[k] < S[j] && S[k] < S[w]) {
			U[l++] = S[k++];
		}
		if (S[j] < S[k] && S[j] < S[w]) {
			U[l++] = S[j++];
		}
		if (S[w] < S[j] && S[w] < S[k]) {
			U[l++] = S[w++];
		}
	}

	while ((i < mid1) && (j < mid2)) {
		if (S[i] < S[j]) {
			U[l++] = S[i++];
		}
		else {
			U[l++] = S[j++];
		}
	}
	while ((i < mid1) && (k < mid3)) {
		if (S[i] < S[j]) {
			U[l++] = S[i++];
		}
		else {
			U[l++] = S[k++];
		}
	}
	while ((i < mid1) && (w < high)) {
		if (S[i] < S[j]) {
			U[l++] = S[i++];
		}
		else {
			U[l++] = S[w++];
		}
	}
	while ((j < mid2) && (k < mid3)) {
		if (S[j] < S[k]) {
			U[l++] = S[j++];
		}
		else {
			U[l++] = S[k++];
		}
	}
	while ((j < mid2) && (w < high)) {
		if (S[j] < S[w]) {
			U[l++] = S[j++];
		}
		else {
			U[l++] = S[w++];
		}
	}
	while ((k < mid3) && (w < high)) {
		if (S[k] < S[w]) {
			U[l++] = S[k++];
		}
		else {
			U[l++] = S[w++];
		}
	}
	while (i < mid1) {
		U[l++] = S[i++];
	}
	while (j < mid2) {
		U[l++] = S[j++];
	}
	while (k < mid3) {
		U[l++] = S[k++];
	}
	while (w < high) {
		U[l++] = S[w++];
	}
}
void mergesort4(int* S, int low, int high, int* U) {
	int mid1 = 0;
	int mid2 = 0;
	int mid3 = 0;
	if (high - low < 3) return;
	mid1 = low + ((high - low) / 4);
	mid2 = low + ((high - low) / 2);
	mid3 = mid1 + mid2 - low;
	mergesort4(U, low, mid1, S);
	mergesort4(U, mid1, mid2, S);
	mergesort4(U, mid2, mid3, S);
	mergesort4(U, mid3, high, S);
	merge4(U, low, mid1, mid2, mid3, high, S);

}
int main() {
	int* arr=new int[SIZE];
	LARGE_INTEGER freq1, freq2, freq3, t_before1, t_after1,t_before2,t_after2, t_before3, t_after3;
	LONGLONG t_diff1, t_diff2, t_diff3 ;
	double elapsed_time1, elapsed_time2, elapsed_time3;
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
	random_shuffle(arr, arr + SIZE);
	int* Array=new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		Array[i] = arr[i];
	}
	for (int i = 0; i < 30; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";

	}
	cout << endl << "/////////////////////" << endl;
	for (int i = SIZE - 30; i < SIZE; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;
	QueryPerformanceFrequency(&freq1);
	QueryPerformanceCounter(&t_before1);
	mergesort2(arr, 0, SIZE-1,Array);
	QueryPerformanceCounter(&t_after1);
	
	t_diff1 = t_after1.QuadPart - t_before1.QuadPart;
	elapsed_time1 = ((double)t_diff1 / freq1.QuadPart);
	cout << "100만개 합병정렬 파티션 2개 시간 :" << elapsed_time1 * 1000<<"ms"<<endl;
	for (int i = 0; i < 30; i++) {
		if (i%10==0) {
			cout << endl;
		}
		cout << arr[i] << " ";

	}
	cout <<endl<< "/////////////////////"<<endl;
	for (int i = SIZE - 30; i < SIZE; i++) {
		if(i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	random_shuffle(arr, arr + SIZE);
	for (int i = 0; i < SIZE; i++) {
		Array[i] = arr[i];
	}
	QueryPerformanceFrequency(&freq2);
	QueryPerformanceCounter(&t_before2);
	mergesort3(arr, 0, SIZE, Array);
	QueryPerformanceCounter(&t_after2);
	t_diff2 = t_after2.QuadPart - t_before2.QuadPart;
	elapsed_time2 = ((double)t_diff2 / freq2.QuadPart);
	cout << "100만개 합병정렬 파티션 3개 시간 :" << elapsed_time2 * 1000 << "ms" << endl;
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";

	}
	cout << endl << "/////////////////////" << endl;
	for (int i = SIZE - 100; i < SIZE; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	cout << endl;

	random_shuffle(arr, arr + SIZE);
	for (int i = 0; i < SIZE; i++) {
		Array[i] = arr[i];
	}
	QueryPerformanceFrequency(&freq3);
	QueryPerformanceCounter(&t_before3);
	mergesort4(arr, 0, SIZE, Array);
	QueryPerformanceCounter(&t_after3);
	t_diff3 = t_after3.QuadPart - t_before3.QuadPart;
	elapsed_time3 = ((double)t_diff3 / freq3.QuadPart);
	cout << "100만개 합병정렬 파티션 4개 시간 :" << elapsed_time3 * 1000 << "ms" << endl;
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";

	}
	cout << endl << "/////////////////////" << endl;
	for (int i = SIZE - 100; i < SIZE; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	delete[]arr;
	delete[]Array;
}
