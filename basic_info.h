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

struct hospital {	//住院
	date begin;
	date end;
	money yajin;	//押金
};

struct medicial {	//开药
	char name[16];
	money single;	//药品单价
	int num;			//药品数量
	money total;	//药品总价
};

struct check {	//检查
	int item[5];	//每种检查的费用
	int total;		//检查总费用
};

struct diagnose {	//诊疗情况
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
