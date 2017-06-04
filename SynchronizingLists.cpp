# include <iostream>
# include <iomanip>
using namespace std;

struct node 
{
public:
	int n;
	node *next;
};

struct set 
{
public:
	int n;
	node *firstListHead;
	node *secondListHead;
	set *next;
};

int main()
{
	set *headSet = NULL, *tempSet;
	node *tempNode = NULL;
	int x = -1, y = 0, temp = 0;

	while (x != 0) 
	{
		cin >> x;
		if(x != 0)
		{
			set *newSet = new set();
			newSet -> n = x;
			newSet -> next = NULL;
			newSet -> firstListHead = NULL;
			newSet -> secondListHead = NULL;
			if(headSet == NULL)
			{
				headSet = newSet;
			}
			else 
			{
				tempSet -> next = newSet;
			}
			tempSet = newSet;
			for(int i = 0; i < x; i++) 
			{
				cin >> y;
				node *newNode = new node();
				newNode -> n = y;
				newNode -> next = NULL;
				if(newSet -> firstListHead == NULL) {
					newSet -> firstListHead = newNode;
				}
				else {
					tempNode -> next = newNode;
				}
				tempNode = newNode;
			}
			for(int i = 0; i < x; i++) 
			{
				cin >> y;
				node *newNode = new node();
				newNode -> n = y;
				newNode -> next = NULL;
				if(newSet -> secondListHead == NULL) {
					newSet -> secondListHead = newNode;
				}
				else {
					tempNode -> next = newNode;
				}
				tempNode = newNode;	
			}
		}
	}

	tempSet = headSet;
	x = -1;

	while(tempSet != NULL)
	{
		int matrix[2][tempSet -> n];
		tempNode = tempSet -> firstListHead;
		int i = 0, j = 0;
		while(tempNode != NULL) 
		{
			matrix[0][i] = tempNode -> n;
			i++;
			tempNode = tempNode -> next; 
		}

		tempNode = tempSet-> secondListHead;
		i = 0;
		while(tempNode != NULL) 
		{
			matrix[1][i] = tempNode -> n;
			i++;
			tempNode = tempNode -> next; 
		}
		for(int x = 0; x < 2; x++) 
		{
			for(i = 0; i < tempSet -> n; i++)
			{
				for(j = i+1; j < tempSet -> n; j++)
				{
					if(matrix[x][i] < matrix[x][j]) 
					{
						temp = matrix[x][i];
						matrix[x][i] = matrix[x][j];
						matrix[x][j] = temp;
					}
				}
			}
		}
		tempNode = tempSet -> firstListHead;
		while(tempNode != NULL) 
		{
			temp = tempNode -> n;
			for(i = 0; i < tempSet -> n; i++)
			{
				if(matrix[0][i] == temp)
					break;
			}
			cout << matrix[1][i] << "\n";
			tempNode = tempNode -> next;
		}
		if(tempSet->next != NULL)
			cout << "\n";
		tempSet = tempSet -> next;

	}
	
	return 0;

}