#include <stdio.h>
#include "file_input.h"

void queryDept(record *r)
{
	record *p = r->next;
	char dept_name[10][16];
	char query_dept[16];
	diagnose * dia[10][1000];
	int num[10];
	for(int i=0; i<10; i++) num[i]=0;
	printf("please enter the department name:");
	scanf("%s", query_dept);

	while( p != null )
	{
		int dept_num = (p->doctor->did) % 10000;
		dept_name[dept_name] = p->doctor->department;
		dia[dept_num][(num[dept_num])++] = p;
		
		p = p->next;
	}

	for(int i=0; i<10; i++)
	{
		if(dept_name[i] == query_dept)
		{
			printf("%s:\n", dept_name[i]);
			for(int j=0; j<num[i]; j++)
			{
				printf("check money: %d\n", dia[i][j]->c->total);
				printf("medicial cost: %d\.%d\.%d\n", dia[i][j]->m->total->yuan, dia[i][j]->m->total->total->jiao, dia[i][j]->m->total->fen);
				printf("begin time: %d %d %d:%d, end time: %d %d %d:%d, yajin: %d\.%d\.%d\n", dia[i][j]->h->begin>month, dia[i][j]->h->begin->day, dia[i][j]->h->begin->hour, dia[i][j]->h->begin->minute, dia[i][j]->h->end->month, dia[i][j]->h->end->day, dia[i][j]->h->end->hour, dia[i][j]->h->end->minute,dia[i][j]->h->yajin->yuan, dia[i][j]->h->yajin->jiao, dia[i][j]->h->yajin->fen);
			}
			
			printf("\n\n");
			break;
		}
	}
}

void queryDoc(record * r)
{
	record *  p = r->next;
	int did;
	printf("please enter the doctor's id:");
	scanf("%d", &did);
	while( p != null )
	{
		if(p->doc->did == did)
		{
			printf("chcek money: %d\n", p->dia->c->total);
			printf("medicial cost: %d\.%d\.%d\n", p->dia->m->yuan, p->dia->m->jiao, p->dia->m->fen);
			printf("begin time: %d %d %d:%d, end time: %d %d %d:%d, yajin: %d\.%d\.%d\n\n",p->dia->h->begin>month, p->dia->h->begin->day, p->dia->h->begin->hour, p->dia->h->begin->minute, p->dia->h->end->month, p->dia->h->end->day, p->dia->h->end->hour, p->dia->h->end->minute, p->dia->h->yajin->yuan, p->dia->h->yajin->jiao, p->dia->h->yajin->fen);
		}

		p = p->next;
	}
}

void queryPat(record * p)
{
	record *p = r->next;
	printf("please enter the patient id:");
	int pid;
	scanf("%d", &pid);

	while( p != null)
	{
		if(pid%10 == (p->pat->pid)%10)
		{
			printf("patient name: %s", p->pat->name);
			//medicial
			printf("begin time: %d %d %d:%d, end time: %d %d %d:%d, yajin: %d\.%d\.%d\n",p->dia->h->begin>month, p->dia->h->begin->day, p->dia->h->begin->hour, p->dia->h->begin->minute, p->dia->h->end->month, p->dia->h->end->day, p->dia->h->end->hour, p->dia->h->end->minute, p->dia->h->yajin->yuan, p->dia->h->yajin->jiao, p->dia->h->yajin->fen);
		}
		p = p->next;
	}
}

void docBusy(doctor * doc)
{
	doctor * p = doc->next;
	char work_day[7][3] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	while( p != null )
	{
		printf("%d\t%s\t", p->did, p->name);
		int busy_level = 0;
		for(int i=0; i<7; i++)
		{
			if(p->work[i] == 1)	busy_level++;
		}
		printf("busy level: %d\t", busy_level);
		printf("work day: ");
		for(int i=0; i<7; i++)
		{
			if(p->work[i] == 1)
			{
				printf("%s\t", work_day[i]);
			}
		}

		printf("\n");
		p = p->next;
	}
}


money initMoney()
{
	money m;
	m.yuan = 0;
	m.jiao = 0;
	m.fen = 0;
	return m;
}

money addMoney(money x, money y)
{
	money ans;
	ans.fen = x.fen + y.fen;
	ans.jiao = x.jiao + y.jiao;
	ans.yuan = x.yuan + y.yuan;
	if(ans.fen > 60)
	{
		ans.fen -= 60;
		ans.jiao ++;
	}
	if(ans.jiao > 60)
	{
		ans.jiao -= 60;
		ans.yuan ++;
	}
	return ans;
}

//return 1 means x is later than b, 0 means y is later than x, -1 means same time
int compareDate(Date x, Date y)
{

	if(x.month > y.month)	return 1;
	else if(x.month < y.month)	return 0;

	if(x.day > y.day)	return 1;
	else if(x.day < y.day)	return 0;
	
	if(x.hour > y.hour)	return 1;
	else if(x.hour < y.hour)	return 0;
	
	if(x.minute > y.minute)	return 1;
	else if(x.minute < y.minute)	return 0;
	
	return -1;
}

int calPeriod(Date begin, Date end)
{
	int period = 0;
	int month_day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(int i=begin.month; i<end.month; i++)	period += month[i];
	
	period -= begin.day;
	period += end.day;
	if(end.hour>0 && end.hour<=9) period--;
	return period;
}

void calMoney(record * r)
{
	record * p = r->next;
	money diagnose_money, medical_money, hospital_money, total_money;
	diagnose_money = initMoney();
	medical_money = initMoney();
	hospital_money = initMoney();
	total_money = init_money();
	
	Date now;
	printf("please input the date like aa\.bb cc:dd\n");
	scanf("%d\.%d %d:%d", &(now.month), &(now.day), &(now.hour), &(now.minute));

	while( p != null )
	{
		if(compareDate(now, p->dia->h->end) == 1)
		{
			diagnose_money = addMoney(diagnose_money, p->dia->c->total);
			medicial_money = addMoney(medicial_money, p->dia->m->total);
			hospital_money.yuan += 200 * calPeriod(p->dia->h>begin, p->dia->h->end);
		}

		p = p->next;
	}

	total_money = addMoney(total_money, diagnose_money);
	total_money = addMoney(total_money, medicial_money);
	total_money = addMoney(total_money, hospital_money);

	printf("diagnose earning : %d\.%d\.%d\n", diagnose_money.yuan, diagnose_money.jiao, diagonse_money.fen);
	printf("medicial earning : %d\.%d\.%d\n", medicial_money.yuan, medicial_money.jiao, medicial_money.fen);
	printf("hospital earning : %d\.%d\.%d\n", hospital_money.yuan, hospital_money.jiao, hospital_money.fen);
	printf("total earning : %d\.%d\.%d\n", total_money.yuan, total_money.jiao, total_money.fen);
}

void printLiving(record * r)
{
	record * p = r->next;
	printf("please input the date like aa\.bb cc:dd\n");
	Date now;
	scanf("%d\.%d %d:%d", &(now.month), &(now.day), &(now.hour), &(now.minute));

	printf("patients living in hospital right now :\n");
	while( p != null )
	{
		if(compareDate(p->dia->h->end, now) == 1)
		{
			printf("patient id: %d\t name:%s\t age: %d\t begin date: %d\.%d %d:%d\n", p->pat->pid, p->pat->name, p->pat->age, p->dia->h->begin->month, p->dia->h->begin->day, p->dia->h->begin->hour, p->dia->h->begin->minute);
		}

		p = p->next;
	}
}
