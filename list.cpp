#include <iostream>
#include <cstdlib>
#include <string>

using Data = int;

struct Node {
	Node* next;
	Data data;
};

//�������� ������
//�����������. count (����� ��������� � ������), count >  0
//�����������. ��������� �� ������ ������
Node* CreateList(short count);

//����������� ������� ������ ������ ���� �� ��������
//�����������. ��������� ������������� ����� �����
//�����������. ����� ���������� ����
Node* FindItem(Node* node, Data item);

int main() {
	while (true) {
		setlocale(LC_ALL, "rus");
		int n;
		Data item;
		Node *node, *temp;
		while (true) {
			std::cout << "������� ���������� ��������� ������: ";
			std::cin >> n;
			std::cout << "������� " << n << " ��������� ������: ";
			node = CreateList(n);
			std::cout << "������� �������, ������� ���������� �����: ";
			std::cin >> item;
			temp = FindItem(node, item);
			std::cout << "����� ��������: " << temp << ". � ��� ��������: " << (temp ? std::to_string(temp->data) : "") << std::endl;
			temp = node;

			while (temp != nullptr) {
				temp = temp->next;
				delete node;
				node = temp;
			}
			node = nullptr;

			system("pause");
			system("cls");
		}
	}
}

Node* CreateList(short count) {
	Node* temp = new Node;
	Node* start = temp;
	--count;

	while (count != 0) {
		temp->next = new Node;
		std::cin >> temp->data;
		temp = temp->next;
		--count;
	}

	std::cin >> temp->data;
	temp->next = nullptr;
	return start;
}

Node* FindItem(Node* node, Data item) {
	if (node == nullptr) {
		return nullptr;
	}

	if (node->data == item) {
		return node;
	}

	return FindItem(node->next, item);
}