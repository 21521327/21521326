#include<iostream>
#include<string>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *NODE(int x)
{
    node *a = new node;
    a->data = x;
    a->next = NULL;
    return a;
}

struct list
{
    node *head, *tail;
};

void taolist(list &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void addtail(list &l, node *a)
{
    if (l.head == NULL)
    {
        l.head = a;
        l.tail = a;
    }
    else 
    {
        l.tail->next = a;
        l.tail = a;
    }
}

void addhead(list &l, node *a)
{
    if (l.head == NULL)
    {
        l.head = a;
        l.tail = a;
    }
    else
    {
        a->next =l.head;
        l.head = a;
    } 
}

void xuat(list l)
{
    for (node *i = l.head; i !=NULL; i = i->next)
    {
        cout << i->data;
    }
}

int size(list l)
{
    int sum = 0;
    node *a = l.head;
    while(a != NULL)
    {
        sum ++;
        a = a->next;
    }
    return sum;
}


list add0(list &l, int a)
{
    int b = a - size(l);
    for (int i = 0; i < b; i++)
    {
        addtail(l, NODE(0));
    }
    return l;
}

list add(list l, list p)
{
    if (size(l) > size(p)) add0(p, size(l));
    else add0(l, size(p));
    list q;
    node *c = new node;
    taolist(q);
    for (node *a = l.head, *b = p.head; a != NULL, b != NULL;b = b->next, a = a->next)
    {
        int d;
        d = a->data + b->data;
        if (d > 9)
        {
            d %= 10;
            (a->next)->data += 1;  
        }
        addhead(q, NODE(d));
    }
    return q;
}


void chuyenkieu(string a, int c[])
{
    int b = a.length();
    for (int i = 0; i < b; i++)
        c[i] = a[i] - 48;
}

int main()
{
    fflush(stdin);
    cout << "nhap so thu nhat: ";
    string d; getline(cin, d);
    cout << endl << "nhap so thu 2: ";
    string e; getline(cin, e);
    int c[100]; int f[100];
    chuyenkieu(d, c);
    chuyenkieu(e, f);
    
    list l, p;
    taolist(l);
    taolist(p);

    for (int i = 0; i < d.length(); i++)
        addhead( l, NODE(c[i]) );                         
    for (int i = 0; i < e.length(); i++)         
        addhead( p, NODE(f[i]) );              

    cout << endl;
    cout << "tong 2 so la: ";
    add0(p, size(l));
    xuat(add(l, p));
    system("pause");
    cout << endl;
}

