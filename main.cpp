#include <bits/stdc++.h>

#define st string
#define pb push_back
#define vec vector
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define int long long

using namespace std;
using vi = vec<int>;
using vvi = vec<vi>;
using pi = pair<int, int>;
using vpi = vec<pi>;

using namespace std;


template<typename T>
struct Node {
    T val;
    Node *next = nullptr;
    Node *prev = nullptr;
};

template<typename T>
class List {
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    Node<T> *cur = nullptr;
    int sz = 0;
public:

    List() {
        head = nullptr;
        tail = nullptr;
        cur = nullptr;
    }

    List(T val) {
        auto *x = new Node<T>{val};
        head = x;
        tail = x;
        sz = 1;
    }

    int empty() {
        return (sz == 0);
    }

    void push_front(T val) {
        if (sz == 0) {
            auto *x = new Node<T>{val};
            head = x;
            tail = x;
            sz = 1;
            return;
        }
        auto *x = new Node<T>{val};
        x -> next = head;
        head -> prev = x;
        head = x;
        sz++;
    }

    void push_back(T val) {
        if (sz == 0) {
            auto *x = new Node<T>{val};
            head = x;
            tail = x;
            sz = 1;
            return;
        }
        auto *x = new Node<T>{val};
        tail -> next = x;
        x -> prev = tail;
        tail = x;
        sz++;
    }

    void push(T val) {
        if (cur == nullptr) {
            return;
        }
        if (head == cur) {
            push_front(val);
            sz++;
            return;
        }
        auto *x = new Node<T>{val};
        x -> next = cur;
        cur -> prev -> next = x;
        cur -> prev = x;
        sz++;
    }

    void pop_front() {
        if (sz == 0) {
            return;
        }
        sz--;
        if (sz == 1) {
            delete head;
            List();
            return;
        }
        Node<T> *del = head;
        if (head == cur) {
            cur = head -> next;
        }
        head = head -> next;
        delete del;
    }

    void pop_back() {
        if (sz == 0) {
            return;
        }
        sz--;
        if (sz == 1) {
            delete tail;
            List();
            return;
        }
        Node<T> *del = tail;
        if (tail == cur) {
            cur = tail -> prev;
        }
        tail = tail -> prev;
        delete del;
    }

    void pop() {
        if (cur == nullptr) {
            return;
        }
        sz--;
        if (sz == 1) {
            delete cur;
            List();
            return;
        }
        Node<T> *del = cur;
        if (head == cur) {
            pop_front();
            return;
        }
        if (tail == cur) {
            pop_back();
            return;
        }
        del -> prev -> next = del -> next;
        del -> next -> prev = del -> prev;
        delete del;
    }

    // -1 => left, 1 => right
    void move(int x) {
        if (cur == nullptr) {
            cur = head;
            return;
        }
        if (x == -1) {
            cur = cur -> prev;
        }
        else {
            cur = cur -> next;
        }
    }

    friend ostream& operator<<(ostream &fout, const List<T> &a) {
        Node<T> *now = a.head;
        while (now != nullptr) {
            fout << now -> val << " ";
            now = now -> next;
        }
        return fout;
    }
};

signed main() {
    system("chcp 65001");

//    List<int> a;
//    cout << a << endl;
//    a.push_back(5);
//    a.push_front(10);
//    cout << a << endl;
//    a.move(1);
//    a.push(3);
//    cout << a << endl;
//    a.move(-1);
//    a.move(-1);
//    a.pop();
//    cout << a << endl;

    cout << "Введите ... если хотите:\n1 - узнать пустой ли список\n2 - добавить в начало элемент\n3 - добавить в конец списка\n4 - добавить перед элементом, на который указывает курсор\n5 - удалить первый элемент\n6 - удалить последний элемент\n7 - удалить элемент, на который указывает курсор\n8 - сдвинуть курсор вперед/назад(1 - если вперед, -1 - назад\n";
    cout << "Введите количество операций над первым односвязном списком\n";
    List<int> lst1;
    int x; cin >> x;
    while (x--) {
        int t; cin >> t;
        if (t == 1) {
            cout << lst1.empty() << "\n";
        }
        if (t == 2) {
            int val; cin >> val;
            lst1.push_front(val);
        }
        if (t == 3) {
            int val; cin >> val;
            lst1.push_back(val);
        }
        if (t == 4) {
            int val; cin >> val;
            lst1.push(val);
        }
        if (t == 5) {
            lst1.pop_front();
        }
        if (t == 6) {
            lst1.pop_back();
        }
        if (t == 7) {
            lst1.pop();
        }
        if (t == 8) {
            int xx; cin >> xx;
            lst1.move(xx);
        }
        cout << lst1 << endl;
    }
}