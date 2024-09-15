#include<stdio.h>


//function for acepting elements for a matrix
void accept(int arr[20][20],int m,int n) {
    	for(int i=0;i<m;i++) {
    		for(int j=0;j<n;j++){
        		printf("enter element %d,%d: ",i,j);
        		scanf("%d",&arr[i][j]);
        	}
    }
}


//function for diplaying the matrix
void display(int arr[20][20],int m,int n) {
    	for(int i=0;i<m;i++) {
    		for(int j=0;j<n;j++){
    			printf(" %d ",arr[i][j]);
    		}
    		printf("\n");
    	}
}


//function for converting sparse matrix to triplet form
int conversion(int b[20][20],int arr[20][20],int m, int n){
	int k =1;
	b[0][0] = m;
	b[0][1] = n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) {
			if (arr[i][j] != 0){
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = arr[i][j];
				k++;
			}
		}
	}
	b[0][2] = k-1;
	return k;
}


//function for simple transpose
void simpleTranspose(int b[20][20],int a[20][20], int m, int n){
	for(int i=0;i<m;i++){
		b[i][2] = a[i][2];
		b[i][0] = a[i][1];
		b[i][1] = a[i][0];
	}
}


//function for fast transpose
void fastTranspose(){
	
}


int main() {
	//taking the input of array size
	int m,n;
	printf("enter the number of rows for array: ");
	scanf("%d",&m);
	printf("enter the number of rows for array: ");
	scanf("%d",&n);
	int mat[20][20];
	
	//calling the elements accepting function
	accept(mat,m,n);
	
	//displaying the sparse matrix
	printf("the normal sparse matrix is: \n");
	display(mat,m,n);
	printf("\n");
	
	int cptmat[20][20];     // declaring the matrix for triplet form
	
	//converting sparse matrix into triplet form and then displaying it
	int value = conversion(cptmat,mat,m,n);
	printf("the compact matrix is: \n");
	display(cptmat,value,3);
	
	//simple transposing the compact matrix and then displaying it 
	int stmat[20][20];
	simpleTranspose(stmat,cptmat,value,3);
	printf("the simple transpose of compact matrix is: \n");
	display(stmat,value,3);
	
	//fast transposing the compact matrix and then displaying it 
	int ftmat[20][20];
	fastTranspose(ftmat,cptmat,value,3)
	
return 0;
}



