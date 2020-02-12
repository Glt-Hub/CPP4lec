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
		cout << i + 1 << "번째 로또 번호는 " << lotto[i] << " 입니다. " << endl;
	}

	return 0;
}