#include <stdio.h>

struct money {
	int yuan;
	int jiao;
	int fen;
};

struct date {
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

struct hospital {	//סԺ
	date begin;
	date end;
	money yajin;	//Ѻ��
};

struct medicial {	//��ҩ
	char name[16];
	money single;	//ҩƷ����
	int num;			//ҩƷ����
	money total;	//ҩƷ�ܼ�
};

struct check {	//���
	int item[5];	//ÿ�ּ��ķ���
	int total;		//����ܷ���
};

struct diagnose {	//�������
	check c;
	medicial m;
	hospital h;
	struct diagnose*next = NULL;
};

struct doctor {
	char name[16];
	int level;
	char department[16];
	int did;
	int work[7];
	struct doctor * next = NULL;
};

struct patient {
	char name[20];
	int age;
	int pid;
	struct patient * next = NULL;
};

struct record {
	patient* p;
	doctor *doc;
	diagnose* dia;
	struct record * next = NULL;
};
