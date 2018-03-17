#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "list.h"

List::List() {
	_top = NULL;
	_end = NULL;
	_size = 0;
}
List::~List() {
	printf("Bye,bye \n");
}

void List::RemoveElem(elem* l) {
	if (l == NULL) {
		return;
	}
	if (l->prev == NULL) {
		if (l->next != NULL) {
			_top = l->next;
			l->next->prev = _top;
			_top->prev = NULL;
		}
		free(l);
	}
	else {
		if (l->next == NULL) {
			l->prev->next = NULL;
			_end = l->prev;	
			free(l);
		}
		else {
			elem* temp = new elem;
			temp = l->next;
			l->prev->next = temp;
			temp->prev = l->prev;
			free(l);
		}
	}
	_size -= 1;;
}

void List::ListCreate(char* product, long int* count, char* id) {
	elem* temp = new elem;
	sscanf(product, "%s", temp->product);
	sscanf(id, "%s", temp->id);
	temp->count = *count;
	if (_size == 0) {
		_top = temp;
		_end = _top;
		_top->prev = NULL;		
		_size++;
		return;
	}
	_end->next = temp;
	temp->prev = _end;
	temp->next = NULL;

	_end = temp;
	_size++;
}
int List::ListSize() {
	return _size;
}


char* List::GetCountry() {
	return _end->product;
}

bool List::Uniq_Id(char* product, char* id, elem* el) {
	elem* temp = new elem;
	temp = el->prev;
	if (temp == NULL) 
		return true;
	while (temp != NULL) {
		if (!strcmp(product, temp->product)) 
			if (!strcmp(id, temp->id)) 
				return false;
		temp = temp->prev;
	}
	return true;
}

elem_record* List::Parser_record(char* product){
	elem* temp = new elem;
	elem_record* record = new elem_record;
	long int count_unique = 0;
	long int sum = 0;
	temp = _end;
	sscanf(temp->product, "%s", record->product);
	while (temp != NULL) {
		if (!strcmp(product, temp->product))
			if (Uniq_Id(product, temp->id, temp)) 
				count_unique += 1;
		temp = temp->prev;
	}
	record->sum_uniq = count_unique;
	temp = _end;
	elem* temp2 = new elem;
	while (temp != NULL) {
		if (!strcmp(product, temp->product)) {
			sum += temp->count;
			temp2 = temp;
			temp = temp->prev;
		}
		else 
			temp = temp->prev; 
	}
	record->sum_count = sum;
	RemoveElemCountry(product);
	return record;
}

void List::RemoveElemCountry(char* product) {
	elem* temp = new elem;
	elem* temp2 = new elem;
	char c[256];
	sscanf(product, "%s", c);
	temp = _end;
	while (temp != NULL) {
		if (!strcmp(c, temp->product)) {
			temp2 = temp;
			temp = temp->prev;
			RemoveElem(temp2);
		}
		else  
			temp = temp->prev; 
	}
}