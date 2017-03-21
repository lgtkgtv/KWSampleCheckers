#include <stdio.h>
#include <memory.h>

int main() 
{ 
	int *p1[10]; 
	int i[10];
	int *p2; 

	p1[0] = NULL; //check this as first trigger
	i[0] = NULL;
	p2 = NULL; 

	memset(i, 0, sizeof(i));
	memset(p1[0], 0, sizeof(int)); // Klocwork cannot detect NPD here 
	memset(p2, 0, sizeof(int)); // Klocwork report NPD here 

	return 0; 
}
