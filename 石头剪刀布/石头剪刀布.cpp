/*
石头剪刀布是常见的猜拳游戏。石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。

一天，小 AA 和小 BB 正好在玩石头剪刀布。已知他们的出拳都是有周期性规律的，比如：“石头-布-石头-剪刀-石头-布-石头-剪刀……”，就是以“石头-布-石头-剪刀”为周期不断循环的。请问，小 AA 和小 BB 比了 NN 轮之后，谁赢的轮数多？

输入格式
输入包含三行。

第一行包含三个整数：NN，NANA，NBNB，分别表示比了 NN 轮，小 AA 出拳的周期长度，小 BB 出拳的周期长度。0 < N,NA,NB < 1000<N,NA,NB<100。

第二行包含 NANA 个整数，表示小 AA 出拳的规律。

第三行包含 NBNB 个整数，表示小 BB 出拳的规律。

其中，00 表示“石头”，22 表示“剪刀”，55 表示“布”。相邻两个整数之间用单个空格隔开。

输出格式
输出一行，如果小 AA 赢的轮数多，输出"A"；如果小 BB 赢的轮数多，输出"B"；如果两人打平，输出 "draw"。

提示
对于测试数据，猜拳过程为：

\text{A：0 2 5 0 2 5 0 2 5 0}A：0 2 5 0 2 5 0 2 5 0
\text{B：0 5 0 2 0 5 0 2 0 5}B：0 5 0 2 0 5 0 2 0 5

AA 赢了 44 轮，BB 赢了 22 轮，双方打平 44 轮，所以 AA 赢的轮数多。

输出时每行末尾的多余空格，不影响答案正确性

样例输入
10 3 4
0 2 5
0 5 0 2
样例输出
A
 */

#include <iostream>
using namespace std;

class Node {
	enum caiquan {
		shitou = 0,
		jiandao = 2,
		bu = 5
	};

public:
	Node() = default;
	Node(int val) {
		this->value = val;
	}
	int value;
	Node* next;
	void judge(Node* node, int* counter) {
		if (this->value == node->value) {
			return;
		}
		if (this->value == shitou && node->value == jiandao
			|| this->value == jiandao && node->value == bu
			|| this->value == bu && node->value == shitou) {
			++counter[0];
		}
		else {
			++counter[1];
		}
	}
};


void deleteNode(Node* head) {
	Node* cur = head->next;
	while (cur != head) {
		Node* temp = cur->next;
		delete cur;
		cur = temp;
	}
	delete head;
}

int main(int argc, char* argv[]) {
	int counter[2] = { 0 };
	int n, na, nb;
	cin >> n >> na >> nb;
	Node* head1 = new Node();
	cin >> head1->value;
	Node* cur = head1;
	for (int i = 1; i < na; ++i) {
		Node* temp = new Node();
		cin >> temp->value;
		cur->next = temp;
		cur = temp;
	}
	cur->next = head1;

	Node* head2 = new Node();
	cin >> head2->value;
	cur = head2;
	for (int i = 1; i < nb; ++i) {
		Node* temp = new Node();
		cin >> temp->value;
		cur->next = temp;
		cur = temp;
	}
	cur->next = head2;
	for (int i = 0; i < n; ++i) {
		head1->judge(head2, counter);
		head1 = head1->next;
		head2 = head2->next;
	}

	if (counter[0] > counter[1]) {
		cout << "A";
	}
	else if (counter[0] < counter[1]) {
		cout << "B";
	}
	else {
		cout << "draw";
	}

	deleteNode(head1);
	deleteNode(head2);

	return 0;
}
