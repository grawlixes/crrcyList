#include "arrayList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define INITSIZE 16

bool arrayListEnlarge(arrayList list);

arrayList arrayListCreate() {
	arrayList list = (arrayList)malloc(sizeof(struct arrayListStruct));
	if (list==NULL) return list;
	list->data=(int *)malloc(sizeof(int)*INITSIZE);
	list->numUsed=0;
	list->numAlloc=INITSIZE;
	return list;
}

bool arrayListEnlarge(arrayList list) {
	list->data=(int *)realloc(list->data,sizeof(int) * (2*list->numAlloc));
	if (list->data==NULL) return false;
	list->numAlloc *=2;
	return true;
}

bool arrayListAdd(arrayList list, int item) {
	if(list->numUsed>=list->numAlloc) { arrayListEnlarge(list); }
	list->numUsed += 1;
	list->data[list->numUsed-1] = item;
	return true;
}

void arrayListClear(arrayList list) {
	int x;
	for(x=0;x<list->numUsed;x++) {
		list->data[x] = 0;
	}
	list->numUsed=0;
}

bool arrayListContains(arrayList list, int item) {
	int x;
	for(x=0;x<list->numUsed;x++) {
		if(item==list->data[x]) {
			return true;
		}
	}
	return false;
}

int arrayListGet(arrayList list,int index) {
	return list->data[index];
}

int arrayListIndexOf(arrayList list, int item) {
	int x;
	for(x=0;x<list->numUsed;x++) {
		if(item==list->data[x]) {
			return x;
		}
	}
	return -1;
}

bool arrayListIsEmpty(arrayList list) {
	return list->numUsed==0;
}

int arrayListSet(arrayList list, int index, int item) {
	if(list->numUsed>index) {
		list->data[index] = item;
		return 1;
	}
	return -1;
}

int arrayListSize(arrayList list) {
	return list->numUsed;
}

char * arrayListToString(arrayList list,char *buffer) {
	char cbuf[2056] = "";
	strcpy(buffer, cbuf);
	strcat(buffer, "[");
	int i;
	for(i=0;i<list->numUsed;i++) {
		int item = list->data[i];
		char str[100] = "";
		sprintf(str, "%d", item);
		strcat(buffer, str);
		if(i!=list->numUsed-1) { strcat(buffer, ", "); }
	}
	strcat(buffer, "]");
	return buffer;
}
/* Put definitions of the other arrayList methods in arrayList.h here */

void arrayListFree(arrayList list) {
	free(list->data);
	free(list);
}