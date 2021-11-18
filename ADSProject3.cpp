#include <iostream>
using namespace std;
class node{
public:
	node* next;
	int val;
	node(int val);
};
node::node(int val)
{
	this->val = val;
}
class list {
	node* current, * h;
public:
	void add(int val);
	list();
	int j(int st,int k);
	void pr();
	void pr3();
	void dele(int val);
};
list::list()
{
	current = h = NULL;
}
void list::add(int val)
{
	node* n = new node(val);
	if (h == NULL)
	{
		h = n;
		h->next = h;
		current = h;
		return;
	}
	current->next = n;
	current = current->next;
	current->next = h;
}
void list::pr()
{
	current = h;
	cout << "[ ";
	do
	{
		cout << current->val << " ";
		current = current->next;
	} while (current != h);
	cout << " ] \n";
}
void list::pr3()
{
	current = h;
	int nr;
	cout << "list third element from given one: ";
	cin >> nr;
	cout << "[ ";
	while (nr != current->val)
	{
		current = current->next;
		if (current == h)
		{
			cout << "The value is not located here \n";
			break;
		}
	}
	for (int j = 0; j < 3; j++)
		current = current->next;
	cout << current->val << " ";
	cout << " ] \n";
}
int list::j(int st,int k)
{
	current = h;
	node* del = h->next;
	int val;
	while (h->next != h)
	{
		for (int i = st; i < k-1; i++)
		{
			current = current->next;
			del = del->next;
		}
		current->next = del->next;
		if (del == h)
		{
			h = h->next;
		}
		val = del->val;
		delete del;
		current = current->next;
		del = current->next;
		cout << "( " << val << " out )" << " ";
	}
	cout << "\n";
	return h->val;
}
void list::dele(int val)
{
	node* x,*y;
	if (h)
	{
		x = h;
		if (h->val == val && h->next == h)
		{
			delete x;
			h = nullptr;
		}
		else
		{
			while (x->next->val != val && x->next!=h)
				x = x->next;
			y = x->next;
			if (y->val == val)
			{
				if (y == h)
					h = h->next;
				x->next = y->next;
				delete y;
			}
		}
	}
}
int main()
{
	int k, st, val;
	bool y, z;
	cout << "starting point: ";
	cin >> st;
	cout << "skip: ";
	cin >> k;
	list l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.add(4);
	l.add(5);
	l.add(6);
	l.add(7);
	l.add(8);
	l.pr();
	cout << "Do you want to delete a person?(1|0) ";
	cin >> y;
	if (y == 1)
	{
		cout << "Which person would you like to be deleted? ";
		cin >> val;
		l.dele(val);
		l.pr();
	}
	cout << "Do you want to print out the third element from the given person?(1|0) ";
	cin >> z;
	if (z == 1)
		l.pr3();
	cout << "The winner is ( " << l.j(st,k) << " )";
}