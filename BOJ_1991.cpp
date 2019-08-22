#include <iostream>
using namespace std;

typedef struct node{
	char left;
	char right;
};

	node arr[27 * 3];
	
void preorder(char t)
{
	if(t == '.') return;
	cout << t;
	preorder(arr[t].left);
	preorder(arr[t].right);
}

void inorder(char t)
{
	if(t == '.') return;
	inorder(arr[t].left);
	cout << t;
	inorder(arr[t].right);
}

void postorder(char t)
{
	if(t == '.') return;
	postorder(arr[t].left);
	postorder(arr[t].right);
	cout << t;
}

int main()
{
	int n;
	cin >> n;
	char n1, n2, n3;
	for(int i = 1; i<=n; i++)
	{
		cin >> n1 >> n2 >> n3;
		arr[n1].left = n2;
		arr[n1].right = n3;
	}
	
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
	
	return 0;
}
