#include"algorithm.h"

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{

}

void Algorithm::swap(int* a, int* b)
{
	//�ꎞ�i�[
	int temp = *a;

	//Swap
	*a = *b;
	*b = temp;
}

int Algorithm::mid(int x, int y, int z)
{
	//3�_�̒����l��Ԃ�
	if ((x < y && x > z) || (x < z && x > y))
	{
		return x; //x�������l
	}
	else if ((x < y && y < z) || (x > y) && (y > z))
	{
		return y; //y�������l
	}
	else
	{
		return z; //x�ł�y�ł��Ȃ��ꍇ(z�������l�ł͂Ȃ��ꍇ���܂�)
	}
}

void Algorithm::quick(int arrangement[], int top, int last)
{
	if (top < last)
	{
		int i = top, j = last;
		int pivot = mid(arrangement[i], arrangement[i + (j - i) / 2], arrangement[i]); //�R�_�̒����l���s�{�b�g�Ɏw��


		while (true)
		{
			//pivot���傫�Ȓl��擪����T��
			while (arrangement[i] < pivot)
			{
				i++; //�T���ʒu�����炷
			}
			//pivot��菬���Ȓl���Ōォ��T��
			while (arrangement[j] > pivot)
			{
				j--; //�T���ʒu�����炷
			}

			if (i > j - 1)
			{
				break;
			}

			swap(&arrangement[i], &arrangement[j]);
			//�X���b�v���s�Ȃ����ꍇ�͈͂�������߂�(�X���b�v�����ꏊ��T�����Ȃ���)�ĒT��
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
	int i = 0; //�Ԋu�p�ϐ�

	//�K�؂ȊԊu�̒T��
	while ((pow(3, i) - 1) / 2 < size)
	{
		i++;
	}

	int h = (pow(3, i) - 1) / 2; //�Ԋu�̏����l(�v�f�����傫��,�ȑO�̃R���\�[�g�Ɏ����č�邽��)
	bool flag = false; //�Ԋu1�̎��̔���p

	while (h > 1 || flag)
	{
		//�Ԋu�̕ύX
		if (h > 1)
		{
			h = (h - 1) / 3;
		}
		//�t���O�̏�����
		flag = false;
		//�Ԋu�ŃO���[�v����
		for (size_t i = 0; i < size - h; i++)
		{
			//�O���[�v���ɑ}���\�[�g�̎��{
			int temp = arrangement[i + h];

			//��r(1���)
			if (arrangement[i] > temp)
			{
				int j = i;//�v�f�ԍ��̃R�s�[

				//�}���ꏊ�̒T��,�}���ꏊ���󂯂�(�}���n�_���E�̐���v�f��1�����炷)
				do {
					arrangement[j + h] = arrangement[j]; //�v�f���Ԋu���E�ɂ��炷
					j -= h; //���ׂ�v�f�����ɂ��炷
				} while (j + h > 0 && arrangement[j] > temp);  //�p������,����ϗv�f�ɑ}������v�f���l�̑傫���v�f������

				arrangement[j + h] = temp; //�}��
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
			if (arrangement[j] < arrangement[j - 1]) //���̐��l���傫����΃X���b�v�i�����j
			{
				swap(&arrangement[j], &arrangement[j - 1]);
			}
		}
	}
}

void Algorithm::combSort(int arrangement[], int size)
{
	int h = size; //�Ԋu�p�ϐ�
	bool flag = false; //�Ԋu1�̎��̕ύX�t���O

	while (h > 1 || flag)
	{
		//�Ԋu�̕ύX
		if (h > 1)
		{
			h /= 1.3;
		}
		
		flag = false;

		//��r
		for (size_t i = 0; i < size - h; i++)
		{
			//������\�[�g
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

	while (top != bottom) //�J�n�ʒu�ƏI���ʒu����v����΃\�[�g�I��
	{
		int w_swap = top;

		//������\�[�g
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

		//�E����\�[�g
		for (size_t i = bottom; i > top; i--) {

			//���̃f�[�^��菬������Ό���
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
	int top = 0; //��r��

	//������\�[�g
	while (top < size - 1)
	{
		//Compare
		if (arrangement[top] > arrangement[top + 1])
		{
			swap(&arrangement[top], &arrangement[top + 1]);
			//�O�ɖ߂�
			if (top > 0)
			{
				top--;
			}
		}
		else
		{
			//���ɐi��
			top++;
		}
	}
}

void Algorithm::selectionSort(int arrangement[], int size)
{
	//�����珇�Ƀ\�[�g
	for (size_t i = 0; i < size; i++)
	{
		int min_val = i; //�ŏ��l,�����l�͖���̕����̐擪

		//����̕����̐擪����Ō�܂ł�T��
		for (size_t j = 0; j < size; j++)
		{
			//�b��̍ŏ��l��菬�������l������ΕύX
			if (arrangement[j] < arrangement[min_val])
			{
				min_val = j;
			}
		}

		//swap�i���̎��_�ōŏ��l�̗v�f�͔��ʍρj
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
	srand((unsigned int)time(NULL)); //���������Z�b�g����

	for (size_t i = 0; i < size; i++)
	{
		int j = rand() % size;
		int t = arrangement[i];
		arrangement[i] = arrangement[j];
		arrangement[j] = t;
	}

	printf("Shuffle !\n");
}

