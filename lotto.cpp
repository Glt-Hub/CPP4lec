#include<iostream>
#include<ctime>
using namespace std;
int main(void)
{
	int lotto[7];
	srand((unsigned int)time(0));
	for (int i = 0; i < 7; i++)
	{
		lotto[i] = rand() % 45 + 1;
	}

	for (int i = 0; i < 7; i++) {
		cout << i + 1 << "��° �ζ� ��ȣ�� " << lotto[i] << " �Դϴ�. " << endl;
	}

	return 0;
}