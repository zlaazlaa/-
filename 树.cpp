#include<bits/stdc++.h> 

int left,right,value,number,x,father;
struct relate {
	int left;
	int right;
	int value;
	int father;
} A[10000];

void change(int x) {
	int k = A[x].left;
	A[x].left = A[x].right;
	A[x].right = k;
}

void ergodic(int x) {
	printf("%d ",A[x].value); //Output every value
	if(A[x].left)	ergodic(A[x].left);
	if(A[x].right)	ergodic(A[x].right);
}

int main() {
	left = right = value = number = x = father = 1;

	while(scanf("%d",&number) != 0 && number != 0) {   //Build the tree(没闹懂用户需求，建树先按孩子建的)
		scanf("%d%d%d",&value,&left,&right);
		A[number].value = value;
		A[number].left = left;
		A[number].right = right;
		A[left].father = number;
		A[right].father = number;
	}
	
	while(scanf("%d",&number) != 0 && number != 0) {   //Enlarge the tree(没闹懂用户需求，扩大先按父亲扩的)
		scanf("%d%d",&value,&father);
		A[number].value = value;
		A[number].father = father;
	}

	ergodic(1);  //Ergodic and output every value(前序遍历输出)
	
	while(scanf("%d",&x)) {  //Change childen
		if(x == 0)	break;
		change(x);
	}
	
	return 0;
}
