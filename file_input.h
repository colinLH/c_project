#pragma once
#include <iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include"basic_info.h"
using namespace std;

//链表头指针，尾指针
record *head=new record(), *tail= new record();
patient *head1 = new patient(), *tail1 = new patient();
doctor* head2 = new doctor(), *tail2 = new doctor();
diagnose *head3 = new diagnose(), *tail3 = new diagnose();

void readFile() {
	FILE*f = fopen("patient.txt","a+");
	FILE*f1 = fopen("doctor.txt", "a+");
	FILE*f2 = fopen("diagnose.txt", "a+");
	if (!f || !f1 || !f2) {
		printf("Opening file is failed");
		return;
	}
	//尾部指针初始时指向头结点
	tail = head;
	tail1 = head1;
	tail2 = head2;
	tail3 = head3;

	while (true) {
		int result;
		char buffer[100] = { 0 };
		
		record*temp = new record();
		patient*node1 = new patient();
		doctor*node2 = new doctor();
		diagnose*node3 = new diagnose();
		
		if (fgets(buffer, sizeof(buffer), f) == NULL)
			break;
		//1. 针对patient文件输入
		if (buffer[0] == '\r' || buffer[0] == '\n') {}
		else
		{
			sscanf(buffer, "%s %d %d", node1->name, &node1->age, &node1->pid);
			memset(buffer, 0, sizeof(buffer));
			//将node1患者信息记录到record中
			temp->p = node1;
			//将node1患者信息添加到患者链表中
			tail1->next = node1;
			tail1 = node1;
		}
		//2.针对doctor文件输入
		fgets(buffer,sizeof(buffer), f1);
		if (buffer[0] == '\r' || buffer[0] == '\n') {}
		else
		{
			sscanf(buffer, "%s %d %s %d %d %d %d %d %d %d %d\n", node2->name, &node2->level, &node2->department, &node2->did, &node2->work[0], &node2->work[1], &node2->work[2], &node2->work[3], &node2->work[4], &node2->work[5], &node2->work[6]);
			memset(buffer, 0, sizeof(buffer));
			//将node2医生信息记录到record中
			temp->doc = node2;
			//将node2医生信息添加到医生链表中
			tail2->next = node2;
			tail2 = node2;
		}
		//3.针对diagnose文件输入
		
		fgets(buffer, sizeof(buffer), f2);
		if (buffer[0] == '\r' || buffer[0] == '\n') {}
		else {
			sscanf(buffer, "%d %d %d %d %d %s %d %d %d %d %d %d %d %d %d\n", &node3->h.begin.month, &node3->h.begin.day, &node3->h.end.month, &node3->h.end.day, &node3->h.yajin, &node3->m.name, &node3->m.single, &node3->m.num, &node3->m.total, &node3->c.item[0], &node3->c.item[1], &node3->c.item[2], &node3->c.item[3], &node3->c.item[4], &node3->c.total);
			memset(buffer, 0, sizeof(buffer));
			//将node3诊疗情况记录到record中
			temp->dia = node3;
			//将node3诊疗情况添加到诊疗信息链表中
			tail3->next = node3;
			tail3 = node3;
		}
		//4.将record诊疗记录添加到诊疗记录链表中
		tail->next = temp;
		tail = temp;
		
	}
	return;
}
