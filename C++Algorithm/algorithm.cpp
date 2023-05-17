#include"algorithm.h"

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{

}

void Algorithm::swap(int* a, int* b)
{
	//一時格納
	int temp = *a;

	//Swap
	*a = *b;
	*b = temp;
}

int Algorithm::mid(int x, int y, int z)
{
	//3点の中央値を返す
	if ((x < y && x > z) || (x < z && x > y))
	{
		return x; //xが中央値
	}
	else if ((x < y && y < z) || (x > y) && (y > z))
	{
		return y; //yが中央値
	}
	else
	{
		return z; //xでもyでもない場合(zが中央値ではない場合も含む)
	}
}

void Algorithm::quick(int arrangement[], int top, int last)
{
	if (top < last)
	{
		int i = top, j = last;
		int pivot = mid(arrangement[i], arrangement[i + (j - i) / 2], arrangement[i]); //３点の中央値をピボットに指定


		while (true)
		{
			//pivotより大きな値を先頭から探す
			while (arrangement[i] < pivot)
			{
				i++; //探索位置をずらす
			}
			//pivotより小さな値を最後から探す
			while (arrangement[j] > pivot)
			{
				j--; //探索位置をずらす
			}

			if (i > j - 1)
			{
				break;
			}

			swap(&arrangement[i], &arrangement[j]);
			//スワップを行なった場合範囲を一つずつ狭めて(スワップした場所を探索しないで)再探索
			i++;
			j--;
		}

		quick(arrangement, top, i - 1);
		quick(arrangement, j + 1, last);
	}
}

void Algorithm::quickSort(int arrangement[], int size)
{
	quick(arrangement, 0, size - 1);
}

void Algorithm::insertSort(int arrangement[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int temp = arrangement[i + 1];

		if (arrangement[i] > temp)
		{
			int j = i;

			do {

				arrangement[j + 1] = arrangement[j];
			} while (j + 1 > 0 && arrangement[j] > temp);

			arrangement[j + 1] = temp;
		}
	}
}

void Algorithm::shellSort(int arrangement[], int size)
{
	int i = 0; //間隔用変数

	//適切な間隔の探索
	while ((pow(3, i) - 1) / 2 < size)
	{
		i++;
	}

	int h = (pow(3, i) - 1) / 2; //間隔の初期値(要素数より大きい,以前のコムソートに似せて作るため)
	bool flag = false; //間隔1の時の判定用

	while (h > 1 || flag)
	{
		//間隔の変更
		if (h > 1)
		{
			h = (h - 1) / 3;
		}
		//フラグの初期化
		flag = false;
		//間隔でグループ分け
		for (size_t i = 0; i < size - h; i++)
		{
			//グループ毎に挿入ソートの実施
			int temp = arrangement[i + h];

			//比較(1回目)
			if (arrangement[i] > temp)
			{
				int j = i;//要素番号のコピー

				//挿入場所の探索,挿入場所を空ける(挿入地点より右の整列要素を1つずつずらす)
				do {
					arrangement[j + h] = arrangement[j]; //要素を間隔分右にずらす
					j -= h; //調べる要素を左にずらす
				} while (j + h > 0 && arrangement[j] > temp);  //継続条件,整列済要素に挿入する要素より値の大きい要素が存在

				arrangement[j + h] = temp; //挿入
				flag = true;
			}
		}
	}
}

void Algorithm::bubbleSort(int arrangement[], int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = size - 1; i < j - 1; j--)
		{
			if (arrangement[j] < arrangement[j - 1]) //左の数値が大きければスワップ（交換）
			{
				swap(&arrangement[j], &arrangement[j - 1]);
			}
		}
	}
}

void Algorithm::combSort(int arrangement[], int size)
{
	int h = size; //間隔用変数
	bool flag = false; //間隔1の時の変更フラグ

	while (h > 1 || flag)
	{
		//間隔の変更
		if (h > 1)
		{
			h /= 1.3;
		}
		
		flag = false;

		//比較
		for (size_t i = 0; i < size - h; i++)
		{
			//左からソート
			if (arrangement[i] > arrangement[i + h])
			{
				swap(&arrangement[i], &arrangement[i + h]);
				flag = true;
			}
		}
	}
}

void Algorithm::shakerSort(int arrangement[], int size)
{
	int top = 0, bottom = size - 1;

	while (top != bottom) //開始位置と終了位置が一致すればソート終了
	{
		int w_swap = top;

		//左からソート
		for (size_t i = top; i < bottom; i++)
		{
			if (arrangement[i] > arrangement[i + 1])
			{
				swap(&arrangement[i], &arrangement[i + 1]);
				w_swap = i;
			}
		}

		bottom = w_swap;
		w_swap = bottom;

		//右からソート
		for (size_t i = bottom; i > top; i--) {

			//左のデータより小さければ交換
			if (arrangement[i] < arrangement[i - 1]) {
				//swap
				swap(&arrangement[i], &arrangement[i - 1]);
				w_swap = i;
			}
		}
		top = w_swap;
	}
}

void Algorithm::gnomeSort(int arrangement[], int size)
{
	int top = 0; //比較元

	//左からソート
	while (top < size - 1)
	{
		//Compare
		if (arrangement[top] > arrangement[top + 1])
		{
			swap(&arrangement[top], &arrangement[top + 1]);
			//前に戻る
			if (top > 0)
			{
				top--;
			}
		}
		else
		{
			//次に進む
			top++;
		}
	}
}

void Algorithm::selectionSort(int arrangement[], int size)
{
	//左から順にソート
	for (size_t i = 0; i < size; i++)
	{
		int min_val = i; //最小値,初期値は未定の部分の先頭

		//未定の部分の先頭から最後までを探索
		for (size_t j = 0; j < size; j++)
		{
			//暫定の最小値より小さい数値があれば変更
			if (arrangement[j] < arrangement[min_val])
			{
				min_val = j;
			}
		}

		//swap（この時点で最小値の要素は判別済）
		swap(&arrangement[i], &arrangement[min_val]);
	}
}

void Algorithm::showArray(int arrangement[], int size)
{
	for (size_t i = 0; i <= size - 1; i++)
	{
		printf("%d", arrangement[i]);
		if (i != size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}

void Algorithm::shuffle(int arrangement[], int size)
{
	srand((unsigned int)time(NULL)); //乱数をリセットする

	for (size_t i = 0; i < size; i++)
	{
		int j = rand() % size;
		int t = arrangement[i];
		arrangement[i] = arrangement[j];
		arrangement[j] = t;
	}

	printf("Shuffle !\n");
}

