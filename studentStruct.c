/**************
Student management program
with struct & C
**************/

#include<stdio.h>
#include<Windows.h>

struct student {
	int id;
	char* name;
	float firstYear;
	float secondYear;
	float percentage;
	struct student *next;
};

float totPercent(struct student s);
void printInfo(struct student s);
void studentAdd(struct student * head);
void studentDeletion(struct student * head);
void selectfunc(struct student * head);
void printall(struct student * head);

int main(void)
{
	struct student * head = malloc(sizeof(struct student));
	head->next = NULL;
	selectfunc(head);
	return 0;
}

void studentAdd(struct student * head)
{
	struct student * cursor = head;
	struct student * s;
	float temp;
	s = malloc(sizeof(struct student));
	char name[20];

	if (head->next != NULL) {
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
		s->id = cursor->id + 1;
		cursor->next = s;
		s->next = NULL;
	}
	else {
		head->next = s;
		s->id = 1;
		s->next = NULL;
	}

	printf("�̸� �Է� : ");
	scanf_s("%s", name, sizeof(name));
	s->name = name;
	printf("1�г� ���� �Է� : ");
	scanf_s("%f", &temp);
	s->firstYear = temp;
	printf("2�г� ���� �Է� : ");
	scanf_s("%f", &temp);
	s->secondYear = temp;
	totPercent(*s);
	system("cls");
	selectfunc(head);
}

void studentDeletion(struct student * head)
{
	struct student * cursor = head->next;
	struct student * prev = head;
	int id;
	printf("������ �л��� id �Է�");
	scanf_s("%d", &id);

	if (head->next != NULL) {
		while (cursor->next != NULL)
		{
			if (id == cursor->id)
			{
				prev->next = cursor->next;
				free(cursor);
				printf("���� �Ϸ�.");
				break;
			}
			else {
				prev = cursor;
				cursor = cursor->next;
			}
		}
		if (id == cursor->id)
		{
			prev->next = cursor->next;
			free(cursor);
			printf("���� �Ϸ�.\n");
		}
		else
		{
			printf("������ �л� ������ �����ϴ�.\n");
		}
	}
	else
		printf("����� �л� ������ �����ϴ�.\n");

	printf("�޴��� ���ư����� �ƹ� ���ڸ� �Է��ϰ� ���͸� ��������.\n");
	scanf_s("%d");
	system("cls");
	selectfunc(head);
	
}

void selectfunc(struct student * head) 
{
	int selectval;
	printf("=== �޴� ���� ===\n");
	printf("1. �л� �߰�\n");
	printf("2. �л� ����\n");
	printf("3. ��ü �л� ���\n");
	printf("4. ����\n");
	scanf_s("%d", &selectval);
		
	switch (selectval)
	{
	case 1:
		system("cls");
		studentAdd(head);
		break;
	case 2:
		system("cls");
		studentDeletion(head);
		break;
	case 3:
		system("cls");
		printall(head);
		break;
	case 4:
		system("cls");
		exit(0);
		break;
	default:
		system("cls");
		printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		selectfunc(head);
		break;
	}
}

float totPercent(struct student s) {

	float tot = 0;
	tot = s.firstYear + s.secondYear;
	s.percentage = tot / 2;
	return tot / 2;
}

void printInfo(struct student s)
{
	printf("�й� : %d\n", s.id);
	printf("�̸� : %s\n", s.name);
	printf("1�г� ���� : %f\n", s.firstYear);
	printf("2�г� ���� : %f\n", s.secondYear);
	printf("��ռ��� : %f\n", s.percentage);
}

void printall(struct student * head)
{
	struct student * cursor = head->next;

	if (head->next != NULL) {
		while (cursor->next != NULL)
		{
			printInfo(*cursor);
			printf("\n\n======================================\n\n");
			cursor = cursor->next;
		}
		printInfo(*cursor);
	}
	else
		printf("ǥ���� ������ �����ϴ�.\n");
	printf("�޴��� ���ư����� �ƹ� ���ڸ� �Է��ϰ� ���͸� ��������.");
	scanf_s("%d");
	system("cls");
	selectfunc(head);
}
