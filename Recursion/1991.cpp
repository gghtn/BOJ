#include <iostream>
#include <vector>
using namespace std;

int N;
pair<char, char> Tree[26];

void Preorder_Traversal(char _root)
{
	if (_root == '.') return;
	cout << _root;
	Preorder_Traversal(Tree[(int)(_root - 'A')].first);
	Preorder_Traversal(Tree[(int)(_root - 'A')].second);
}

void Inorder_Traversal(char _root)
{
	if (_root == '.') return;
	Inorder_Traversal(Tree[(int)(_root - 'A')].first);
	cout << _root;
	Inorder_Traversal(Tree[(int)(_root - 'A')].second);
}

void Postorder_Traversal(char _root)
{
	if (_root == '.') return;
	Postorder_Traversal(Tree[(int)(_root - 'A')].first);
	Postorder_Traversal(Tree[(int)(_root - 'A')].second);
	cout << _root;
}

int main()
{
	cin >> N;

	char chRoot, chLeft, chRight;
	for (int i = 0; i < N; ++i)
	{
		cin >> chRoot >> chLeft >> chRight;
		Tree[(int)(chRoot - 'A')] = { chLeft, chRight };
	}

	Preorder_Traversal('A');
	cout << '\n';
	Inorder_Traversal('A');
	cout << '\n';
	Postorder_Traversal('A');

	return 0;
}