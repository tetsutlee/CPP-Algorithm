#include"algorithm.h"

int main() {
	
	Algorithm algorithm = Algorithm();
	//�z��쐬
	int sort[5] = { 0,4,2,3,1 }; //�z��

	//�N�C�b�N�\�[�g
	algorithm.selectionSort(sort, 5);

	for (int i = 0; i < 5; i++) {

		std::cout << sort[i] << ' '; //�W���o��
	}

	std::cout << std::endl;

	return 0;
}