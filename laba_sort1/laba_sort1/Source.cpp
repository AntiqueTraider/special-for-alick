#include<iostream>
#include <string>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
struct Somebody {
	string name;
	int nomber;
};
struct List {
	Somebody man;
	List *next;
};
void FirstBuf(Somebody *arr, int i, List *head, List *other);
void SecondBuf(Somebody *arr, int i, List *head, List *other);
void JustAnotheSort(Somebody *arr) {
	List *head1 = new List;
	List *head2 = NULL;
	head1->man.nomber = arr[0].nomber;
	head1->man.name = arr[0].name.substr(0, arr[0].name.length());
	head1->next = NULL;
	FirstBuf(arr,1,head1,head2);
	for (int i = 0; i < 5; i++) {
		if (head1->man.nomber < head2->man.nomber)
		{
			arr[i].name = head1->man.name.substr(0, head1->man.name.length());
			arr[i].nomber = head1->man.nomber;
			head1 = head1->next;
		}
		else
		{
			arr[i].name = head2->man.name.substr(0, head2->man.name.length());
			arr[i].nomber = head2->man.nomber;
			head2 = head2->next;

		}
	}
}
void main() {

	Somebody *they=new Somebody[5];
    

	ifstream in("input.txt");
	for (int i = 0; i < 5; i++)
	{
		in >> they[i].name;
		in >> they[i].nomber;
	}
	for (int i = 0; i < 5; i++)
		cout << they[i].nomber << endl;

	JustAnotheSort(they);

    for (int i = 0; i < 5; i++)
		cout << they[5].nomber << endl;

	system("pause");
}

void FirstBuf(Somebody *arr, int i, List *head, List *other)  {
	while (arr[i].nomber > head->man.nomber) {
		head->next = new List;
		head = head->next;
		head->next = NULL;
		head->man.nomber = arr[i].nomber;
		head->man.name = arr[i].name.substr(0, arr[i].name.length());
		i++;
	}
	if (i < 5)
	{
		if (other != NULL) {
			
			
			other->next = new List;
			other = other->next;
			other->next = NULL;
			other->man.nomber = arr[i].nomber;
			other->man.name = arr[i].name.substr(0, arr[i].name.length());
		}
		else
		{
			List *buf = new List;
			buf->next = NULL;
			buf->man.nomber = arr[i].nomber;
			buf->man.name = arr[i].name.substr(0, arr[i].name.length());
			other = buf;
		}
		SecondBuf(arr, i, other, head);
	}
}

void SecondBuf(Somebody *arr, int i, List *head, List *other) {
	while (arr[i].nomber > head->man.nomber) {
		head->next = new List;
		head = head->next;
		head->next = NULL;
		head->man.nomber = arr[i].nomber;
		head->man.name = arr[i].name.substr(0, arr[i].name.length());
		i++;
	}
	if (i < 5)
	{
		other->next = new List;
		other = other->next;
		other->next = NULL;
		other->man.nomber = arr[i].nomber;
		other->man.name = arr[i].name.substr(0, arr[i].name.length());
		FirstBuf(arr, i, other, head);
	}
}
