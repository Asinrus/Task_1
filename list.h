#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>



struct elem_record {
	char product[256];
	long int sum_uniq;
	long int sum_count;

	elem_record* next;
	elem_record* prev;
};

	
struct elem{
	char product[256];
	char id[256];
	long int count;

	elem* next;
	elem* prev;
};

class SortedRecords {
public: 
	SortedRecords();
	~SortedRecords();
	void AddListInSort(elem_record* l);
	void OutInFile();
	int Size();
	void RemoveElem(elem_record* el);
	void InsertRecordAfterOld(elem_record* new_list, elem_record* old_list);
	void InsertRecordBeforeOld(elem_record* new_list, elem_record* old_list);
private:
	int _size;
	elem_record* _top;
	elem_record* _end;
};

class List {
public:
	List();
	~List();
	void ListCreate(char* product, long int* count,char* id);
	int ListSize();
	void RemoveElem(elem* el);
	void RemoveElemCountry(char* product);
	char* GetCountry();
	elem_record* Parser_record(char* product);
	bool Uniq_Id(char* product,char* id,elem* el);
private:
	int _size;
	elem* _top;
	elem* _end;

};
