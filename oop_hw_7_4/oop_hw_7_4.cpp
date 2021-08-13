#include <iostream>

using namespace std;

struct BTNode
{
	int data;
	BTNode* pleft;
	BTNode* pright;

	BTNode(int data = 0, BTNode* pleft = nullptr, BTNode* pright = nullptr)
	{
		this->data = data;
		this->pleft = pleft;
		this->pright = pleft;

	}
};

void addElement(BTNode*& root, int value);
bool tree_search(BTNode*& root);
void printTree(BTNode* root);
void reset_tree(BTNode* root); // обнуляет все елементы
void clearTree(BTNode*& root); // удаляет все BTNode кроме root
void delete_tre(BTNode*& root); // удаляет все BTNode вместе с root




int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	//BTNode* root = new BTNode(5); // или
	BTNode* root = new BTNode;

	//добавление в дерево вручную
	/*root->pleft = new BTNode(3);
	root->pright = new BTNode(7);
	root->pright->pleft = new BTNode(6);
	root->pleft->pright = new BTNode(4);
	root->pright->pright = new BTNode(9);*/


	//добавление в дерево при помощи функции addElement()

	addElement(root, 3);
	addElement(root, 12);
	addElement(root, 8);
	addElement(root, 2);
	addElement(root, 3);
	addElement(root, 5);
	addElement(root, 16);
	addElement(root, 11);
	addElement(root, 26);

	printTree(root);

	// поиск по дереву
	bool isIn = tree_search(root);
	cout << "isIn = "<< isIn << endl;





	// удаление дерева при помощи функции clearTree(root); много текста в main()
	cout << "удаление дерева при помощи функции clearTree(root); много текста в main()\n";
	clearTree(root);
	delete root;
	root = nullptr;
	if (root != nullptr)
	{
		printTree(root);
	}
	else
	{
		cout << "Tree is deleted\n";
	}
	//
	addElement(root, 3);
	addElement(root, 12);
	addElement(root, 8);
	addElement(root, 2);
	addElement(root, 3);
	addElement(root, 5);
	addElement(root, 16);
	addElement(root, 11);
	addElement(root, 26);

	printTree(root);

	cout << "\nобнуление элементов\n";

	reset_tree(root);
	printTree(root);
	cout << '\n';



	cout << "удаление дерева при помощи функции delete_tre(root)" << endl;
	delete_tre(root);
	printTree(root);


	




	return 0;
}

void addElement(BTNode*& root, int value)
{
	if (root == nullptr)
	{
		root = new BTNode(value);
		return;
	}
	BTNode* pCurrent = root;
	while (pCurrent != nullptr)
	{
		if (pCurrent->data == value) // дерево не содержит повторяющихся элементов
		{
			cout << value << " Exists alrady\n";
			//return; // или break
			break;
		}

		if (value > pCurrent->data)
		{
			if (pCurrent->pright != nullptr)
			{
				pCurrent = pCurrent->pright;
			}

			else
			{

				pCurrent->pright = new BTNode(value);
				return;
			}
		}



		else
		{
			if (pCurrent->pleft != nullptr)
			{
				pCurrent = pCurrent->pleft;
			}
			else
			{
				pCurrent->pleft = new BTNode(value);
				//return; // или break
				break;
			}
		}

	}
}

bool tree_search(BTNode*& root)
{
	bool is_in = false;
	int value{};
	cout << "\nEnter a value You want to search in the tree\n";
	cin >> value;

	if (root == nullptr)
	{
		is_in = false;
		cout << "tree is empty\n";
		
		
	}
	BTNode* pCurrent = root;
	while (pCurrent != nullptr)
	{
		if (value == pCurrent->data)
		{
			is_in = true;
			
			break;
		}
		if (value < pCurrent->data)
		{
			pCurrent = pCurrent->pleft;
		}
		else
		{
			pCurrent = pCurrent->pright;
		}
	}

	cout << "_____Is exist ?_____\n ";

	if (is_in == true)
	{
		cout << value << " is in the tree " << endl;
	}
	else
	{
		cout << value << " is't in the tree\n";
	}
	return is_in;
}

void printTree(BTNode* root)
{
	if (root != nullptr)
	{
		printTree(root->pleft);
		cout << root->data << "  ";
		printTree(root->pright);
	}
}

void reset_tree(BTNode* root)  // обнуляет все елементы
{
	if (root != nullptr)
	{

		reset_tree(root->pleft);
		root->data = 0;
		reset_tree(root->pright);
	}
}


void clearTree(BTNode*& root) // удаляет все BTNode кроме root
{
	if (root != nullptr)
	{
		clearTree(root->pleft);
		delete root->pleft;
		root->pleft = nullptr;
		clearTree(root->pright);
		delete root->pright;
		root->pright = nullptr;
	}
}

void delete_tre(BTNode*& root) // удаляет все BTNode вместе с root
{
	clearTree(root);
	delete[] root;
	root = nullptr;
	cout << "tree is empty\n";
}



