#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template<class T>
struct Node
{
   T data;
   Node<T> *next;
   Node<T> *prev;
};

template<class T>
class DoublyLinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
	int count;
public:
	DoublyLinkedList() { count=0; };

	~DoublyLinkedList() {};

    void deleteNode(Node<T> * del)
	{
		if(count==0)
			return;

		if(head!=tail)
		{
			if(del==tail)
			{
				del->prev->next=NULL;
				tail=del->prev;
			}
			else
			{
				del->next->prev=del->prev;
				if(del==head)
				{
					head=del->next;
				}
				else
				{
					del->prev->next=del->next;
				}
			}
		}
		count--;
		delete del;
	};

	void deleteNodeNum(int pos)
	{
		if(pos<0 || pos>count)
		{
			cout<<"Неверная позиция"<<endl;
			return;
		}
		if(count==0)
			return;

	    int i = 1;
		Node<T> *del = new Node<T>;
		del = head;
		while(i!=pos)
		{
			del = del->next;
			i++;
		}

		if(head!=tail)
		{
			if(del==tail)
			{
				del->prev->next=NULL;
				tail=del->prev;
			}
			else
			{
				del->next->prev=del->prev;
				if(del==head)
				{
					head=del->next;
				}
				else
				{
					del->prev->next=del->next;
				}
			}
		}
		count--;
		delete del;
	};

	void pasteNode(Node<T> * pur, T value)
	{
		Node<T> *cur = new Node<T>;
		cur->data=value;
		cur->prev=pur->prev;
		if(pur!=head)
			pur->prev->next=cur;
		else
			head=cur;
		pur->prev = cur;
		cur->next = pur;
		count++;
	};

	void pasteNodeNum(int pos, T value)
	{
		if(pos<0 || pos>count)
		{
			cout<<"Неверная позиция"<<endl;
			return;
		}
		Node<T> *cur = new Node<T>;
		Node<T> *pur = new Node<T>;
		cur->data=value;
		int i = 1;
		pur=head;

		while(i!=pos)
		{
			pur = pur->next;
			i++;
		}

		cur->prev=pur->prev;
		if(pur!=head)
			pur->prev->next=cur;
		else
			head=cur;
		pur->prev = cur;
		cur->next = pur;
		count++;
	};

	void addNodeToStart(T value)
	{
		Node<T> *cur=new Node<T>;
		cur->data=value;
		cur->prev=NULL;
		if(count)
		{
			cur->next=head;
			cur->next->prev=cur;
		}
		else
		{
			cur->next=NULL;
			tail=cur;
		}
		head=cur;
		count++;
	};

	void addNodeToEnd(T value)
	{
		Node<T> *cur=new Node<T>;
		cur->data=value;
		cur->next=NULL;
		if(count)
		{
			cur->prev=tail;
			cur->prev->next=cur;
		}
		else
		{
			cur->prev=NULL;
			head=cur;
		}
		tail=cur;
		count++;
	};

	Node<T> * getNodeByNumber(int number)
	{
		Node<T> *cur=new Node<T>;
		if(number<count)
		{
			cur=head;
			int i=1;
			while(i<=number)
			{
				cur=cur->next;
				++i;
			}
		}
		return cur;
	};

	void clearList()
	{
		Node<T> *cur=new Node<T>;
		while(count>0)
		{
			cur=head;
			deleteNode(cur);
		}
		cout<<"Список очищен"<<endl;
	};

	void printList()
	{
	    if(count == 0)
        {
            cout<<"Список пуст"<<endl;
            return;
        }
		Node<T> *cur=new Node<T>; int i = 1;
		cur=head;
		while(cur!=NULL)
		{
			cout<<setw(3)<<i<<" "<<cur->data<<" ";
			cur=cur->next;
			cout<<endl; i++;
		}
		cout<<endl;
	};

	T& getData(Node<T> * cur)
	{
		return cur->data;
	};

	int getCount()
	{
		return count;
	};

	T& operator [] (unsigned pos)
	{
		int i = 0;
		Node<T> *f = head;
		while (f != NULL)
		{
			if (i == pos)
			{
				return getData(f);
					break;
			}
			i++;
			f = f->next;
		}
	};

	const T operator [] (unsigned pos) const
	{
		int i = 0;
		Node<T> *f = head;
		while (f != NULL) {
			if (i == pos) {
				return getData(f);
				break;
			}
			i++;
			f = f->next;
		}
	};

	void Swaplinks(Node<T> *node1, Node<T> *node2)
	{
		Node<T> *tmp = node1;
		node1 = node2;
		node2 = tmp;
	};

	void SwapNodes(int one, int two)
	{
		if (one > two)
		{
			int tmp = one;
			one = two;
			two = tmp;
		}

		if (one < 0 || two >= count)
		{
			cout << "Номера элементов выходят за пределы списка"<<endl;
		}

		Node<T> *node1 = new Node<T>;
		Node<T> *node2 = new Node<T>;
		int i = 1;
		node1 = head;

		while((one+1) != i)
		{
			node1 = node1->next;
			i++;
		}

		node2 = node1;
		while((two+1) != i)
		{
			node2 = node2->next;
			i++;
		}

		if( node1->next == node2)
		{
			if(node1 == head)
			{
				node2->next->prev = node1;
				node2->prev = node1->prev;
				node1->next = node2->next;
				node2->next = node1;
				node1->prev = node2;
			}
			else
			{
				if(node2 == tail)
				{
                    node1->prev->next = node2;
					node2->prev = node1->prev;
					node1->next = node2->next;
					node2->next = node1;
					node1->prev = node2;
				}
				else
				{
					node1->prev->next = node2;
					node2->next->prev = node1;
					node2->prev = node1->prev;
					node1->next = node2->next;
					node2->next = node1;
					node1->prev = node2;
				}
			}
		}
		else
		{
			if(node1 == head)
			{
				node2->next->prev = node1;
				node1->next->prev = node2;
				node2->prev->next = node1;
				Swaplinks(node1->next, node2->next);
				Swaplinks(node1->prev, node2->prev);
			}
			else
			{
				if(node2 == tail)
				{
					node1->prev->next = node2;
					node1->next->prev = node2;
					node2->prev->next = node1;
					Swaplinks(node1->next, node2->next);
					Swaplinks(node1->prev, node2->prev);
				}
				else
				{
					node1->prev->next = node2;
					node2->next->prev = node1;
					node1->next->prev = node2;
					node2->prev->next = node1;
					Swaplinks(node1->next, node2->next);
					Swaplinks(node1->prev, node2->prev);
				}
			}
		}

		if(node2->prev == NULL)
			head = node2;
		if(node1->next == NULL)
			tail = node1;
	};
};




int main()
{
    setlocale(LC_ALL, "rus");
	int m;
	DoublyLinkedList<string> list;
	list.addNodeToEnd("fisrt");
	list.addNodeToEnd("second");
	list.addNodeToEnd("third");

	do
	{
	    cout<<endl<<"Текущее состояние списка:"<<endl<<endl;
		list.printList();
		cout<<"Выберите номер операции"<<endl;
		cout<<"1. Добавить элемент"<<endl;
		cout<<"2. Удалить элемент"<<endl;
		cout<<"3. Сортировать список"<<endl;
		cout<<"4. Очистить список"<<endl;
		cout<<"5. Выйти"<<endl<<endl;
		cin>>m;

        if(m == 1)
        {
            string nstr;
            int pos;
            cout<<"Введите строку для новой записи"<<endl;
            cin.ignore();
            getline(cin, nstr);
            cout << "Выберите позицию для вставки записи" << endl << "1. В начало списка" << endl << "2. В конец списка" << endl
				 << "3. На место определенной записи (она сдвинется вниз)" << endl;
			cin>>pos;
            if(pos == 1) list.addNodeToStart(nstr);
			if(pos == 2) list.addNodeToEnd(nstr);
			if(pos == 3)
			{
				cout<<"Введите номер этой записи"<<endl;
				cin>>pos;
				if(pos<0 || pos>list.getCount())
                    cout<<"Неверный номер позиции для вставки, попробуйте еще раз"<<endl;
                else
				list.pasteNodeNum(pos,nstr);
			}

        }

        if(m == 2)
        {
            int del;
			cout<<"Введите номер удаляемой записи"<<endl;
			cin>>del;
			list.deleteNodeNum(del);

        }

        if(m==3)
        {
            for(int j=0; j<list.getCount(); j++)
			{
				for(int i=0; i<list.getCount() - 1 - j; i++)
				{
					if(list[i] > list[i+1])
						list.SwapNodes(i,i+1);
				}
			}
        }

        if(m==4)
        {
            list.clearList();
        }
	}
	while(m!=5);

	list.clearList();

    return 0;
}
