#include"algorithm.h"

int main() {
	
	Algorithm algorithm = Algorithm();
	//テスト用配列作成
	int sort[5] = { 0,4,2,3,1 };

	algorithm.selectionSort(sort, 5);

	for (int i = 0; i < 5; i++) {

		std::cout << sort[i] << ' ';
	}

	std::cout << std::endl;

	return 0;
}