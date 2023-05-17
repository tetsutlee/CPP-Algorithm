#include"algorithm.h"

int main() {
	
	Algorithm algorithm = Algorithm();
	//配列作成
	int sort[5] = { 0,4,2,3,1 }; //配列

	//クイックソート
	algorithm.selectionSort(sort, 5);

	for (int i = 0; i < 5; i++) {

		std::cout << sort[i] << ' '; //標準出力
	}

	std::cout << std::endl;

	return 0;
}