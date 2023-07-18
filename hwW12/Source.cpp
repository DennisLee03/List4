#include<iostream>
using namespace std;
struct sNode
{
	double data;
	sNode *next;
};
class cLinkElement {
private:
	sNode *head;
public:
	cLinkElement():head(NULL){}

	void Output() {
		sNode *buf = head;
		while (buf != NULL) {
			cout << "Data=" << buf->data << endl;
			buf = buf->next;
		}
	}
	void operator += (double d) {
		sNode *newnode = new sNode;
		newnode->data = d;
		newnode->next = head;
		head = newnode;
	}
	void operator --(int) {
		sNode *buf = head->next;
		//cout << "delete data= " << head->data << endl;
		delete head;
		head = buf;
	}//cLink--
	bool Check() {
		if (head != NULL) return true;
		else return false;
	}
};

void main() {
	cLinkElement list;
	for (int i = 0;i < 10;i++) list += i;
	cout << "Elements in the list are:" << endl;
	list.Output();
	while (list.Check()) list--;
}