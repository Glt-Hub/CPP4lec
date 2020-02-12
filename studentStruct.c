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

	printf("이름 입력 : ");
	scanf_s("%s", name, sizeof(name));
	s->name = name;
	printf("1학년 성적 입력 : ");
	scanf_s("%f", &temp);
	s->firstYear = temp;
	printf("2학년 성적 입력 : ");
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
	printf("삭제할 학생의 id 입력");
	scanf_s("%d", &id);

	if (head->next != NULL) {
		while (cursor->next != NULL)
		{
			if (id == cursor->id)
			{
				prev->next = cursor->next;
				free(cursor);
				printf("삭제 완료.");
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
			printf("삭제 완료.\n");
		}
		else
		{
			printf("삭제할 학생 정보가 없습니다.\n");
		}
	}
	else
		printf("저장된 학생 정보가 없습니다.\n");

	printf("메뉴로 돌아가려면 아무 숫자를 입력하고 엔터를 누르세요.\n");
	scanf_s("%d");
	system("cls");
	selectfunc(head);
	
}

void selectfunc(struct student * head) 
{
	int selectval;
	printf("=== 메뉴 선택 ===\n");
	printf("1. 학생 추가\n");
	printf("2. 학생 삭제\n");
	printf("3. 전체 학생 출력\n");
	printf("4. 종료\n");
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
		printf("잘못된 선택입니다. 다시 선택하세요.\n");
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
	printf("학번 : %d\n", s.id);
	printf("이름 : %s\n", s.name);
	printf("1학년 성적 : %f\n", s.firstYear);
	printf("2학년 성적 : %f\n", s.secondYear);
	printf("평균성적 : %f\n", s.percentage);
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
		printf("표시할 정보가 없습니다.\n");
	printf("메뉴로 돌아가려면 아무 숫자를 입력하고 엔터를 누르세요.");
	scanf_s("%d");
	system("cls");
	selectfunc(head);
}
