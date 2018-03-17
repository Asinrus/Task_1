#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "list.h"

SortedRecords::SortedRecords() {
	_top = NULL;
	_end = NULL;
	_size = 0;
}

SortedRecords::~SortedRecords() {
	printf("Bye,bye \n");
	elem_record* temp = new elem_record;
	temp = _end;
	while (_size != 0) {
		RemoveElem(temp);
		temp = _end;
	}
}

void SortedRecords::RemoveElem(elem_record* l) {
	if (l == NULL) {
		return;
	}
	if (l->prev == NULL) {
		free(l);
	}
	else {
		if (l->next == NULL) {
			l->prev->next = NULL;
			_end = l->prev;
			free(l);
		}
		else {
			elem_record* temp = new elem_record;
			temp = l->next;
			l->prev->next = temp;
			temp->prev = l->prev;
			free(l);
		}
	}
	_size -= 1;;
}

void SortedRecords::AddListInSort(elem_record* l){
	elem_record* temp = new elem_record;
	sscanf(l->product, "%s", temp->product);
	temp->sum_count = l->sum_count;
	temp->sum_uniq = l->sum_uniq;
	if (_size == 0) {
		_top = temp;
		_end = _top;
		_top->prev = NULL;
		_end->next = NULL;
		_size++;
		return;
	}
	elem_record* temp2 = new elem_record;
	temp2 = _top;
	while (temp2 != NULL) {
		if (temp->sum_count < temp2->sum_count) 
			temp2 = temp2->next;
		else {
			if (temp->sum_count == temp2->sum_count) {
				if (temp->sum_uniq >= temp2->sum_uniq) {
					InsertRecordBeforeOld(temp, temp2);
					_size++;
					return;
				}
				else {
					InsertRecordAfterOld(temp, temp2);
					_size++;
					return;
				}
			}
			else {
				InsertRecordBeforeOld(temp, temp2);
				_size++;
				return;
			}
		}
	}
	_end->next = temp;
	temp->prev = _end;
	temp->next = NULL;

	_end = temp;
	_size++;
}


void SortedRecords::OutInFile() {
	elem_record* temp = new elem_record;
	temp = _top;
	FILE * file;
	file = fopen("result.txt","w");
	fprintf(file, "_______________________________________ \n");
	fprintf(file, "| Product  |  Sum(count) | Count_uniq  | \n");
	fprintf(file, "|__________|_____________|_____________| \n");
	while (temp != NULL) {
		if (temp->sum_count >= INT_MAX) {
			fprintf(file, "|%9s | NaN| %10d | \n", temp->product, temp->sum_uniq);
		}
		fprintf(file, "|%9s | %10d | %10d | \n",temp->product,temp->sum_count,temp->sum_uniq);
		temp = temp->next;
	}
	fprintf(file, "_______________________________________ \n");
	fclose(file);
}

void SortedRecords::InsertRecordAfterOld(elem_record* new_list, elem_record* old_list) {
	//Проверка, является ли старый элемент последним
	if (old_list->next != NULL) {
		new_list->prev = old_list;
		new_list->next = old_list->next;
		old_list->next->prev = new_list;
		old_list->next = new_list;
		if (old_list->prev == NULL)
			_top = old_list;
	}
	else {
		old_list->next = new_list;
		new_list->next = NULL;
		new_list->prev = old_list;
		_end = new_list;
	}
}

void SortedRecords::InsertRecordBeforeOld(elem_record* new_list, elem_record* old_list) {
	//Проверка, является ли старый элемент первым
	if (old_list->prev != NULL) {
		new_list->prev = old_list->prev;
		new_list->next = old_list;

		old_list->prev->next = new_list;
		old_list->prev = new_list;
		if (old_list->next == NULL)
			_end = old_list;
	}
	else {
		old_list->prev = new_list;
		new_list->prev = NULL;
		new_list->next = old_list;
		_top = new_list;
	}
}

int SortedRecords::Size() {
	return _size;
}