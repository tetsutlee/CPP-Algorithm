#pragma once
#include<iostream>
#include<stdlib.h>
#include<cmath>

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	void swap(int* a, int* b);
	void quickSort(int arrangement[], int size);
	void insertSort(int arrangement[], int size);
	void shellSort(int arrangement[], int size);
	void bubbleSort(int arrangement[], int size);
	void combSort(int arrangement[], int size);
	void shakerSort(int arrangement[], int size);
	void gnomeSort(int arrangement[], int size);
	void selectionSort(int arrangement[], int size);
	void showArray(int arrangement[], int size);
	void shuffle(int arrangement[], int size);

private:
	int mid(int x, int y, int z); //中央値探索(クイックソート内部で利用)
	void quick(int sort[], int top, int last); //クイックソート(クイックソート内部で利用)

};