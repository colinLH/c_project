#include <stdio.h>
#include "file_input.h"

void queryDept(record *r)
{
	record *p = r->next;
	char dept_name[10][16];
	diagnose * dia[10][1000];
	int num[10];
	for(int i=0; i<10; i++) num[i]=0;

	while( p != null )
	{
		int dept_num = (p->doctor->did) % 10000;
		dept_name[dept_name] = p->doctor->department;
		dia[dept_num][(num[dept_num])++] = p;
		
		p = p->next;
	}

	for(int i=0; i<10; i++)
	{
		if(dept_name[i] != null)
		{
			printf("%s:\n", dept_name[i]);
			for(int j=0; j<num[i]; j++)
			{
				printf("diagnose money: %d\n", dia[i][j]->check->total);
				//medicial
				printf("begin time: %d %d %d:%d, end time: %d %d %d:%d, yajin: %d\.%d\.%d\n", dia[i][j]->hospital->begin>month, dia[i][j]->hospital->begin->day, dia[i][j]->hospital->begin->hour, dia[i][j]->hospital->begin->minute, dia[i][j]->hospital->end->month, dia[i][j]->hospital->end->day, dia[i][j]->hospital->end->hour, dia[i][j]->hospital->end->minute,dia[i][j]->hospital->yajin->yuan, dia[i][j]->hospital->yajin->jiao, dia[i][j]->hospital->yajin->fen);
			}
			printf("\n\n");
		}
	}
}

void queryDoc(){}
