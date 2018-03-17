#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "list.h"
#include <cstdio>
using namespace std;


int main() {
	char* string;
	char s[1000];
	List list;
	SortedRecords RecordList;
	elem raspar;
	elem_record* record;
	string = s;
	int counter = 0;
	ifstream file("file.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			file >> string;
			int n = sscanf(string, "%[^;];%i;%[A-z]", raspar.id, &raspar.count, raspar.product);
			counter += 1;
			if (n != 3 ) {
				printf("ERROR! String number %d is wrong\n", counter);
				printf("%s\n", string);
			}
			else {
				list.ListCreate(raspar.product, &raspar.count, raspar.id);
			}
		}
	}
	file.close();
	while (list.ListSize() != 0) {
		record = list.Parser_record(list.GetCountry());
		RecordList.AddListInSort(record);
	}
	RecordList.OutInFile();
	system("pause");
	return 0;
}

