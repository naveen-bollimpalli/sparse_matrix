#include"mat.h"
#include<stdio.h>
#include<stdlib.h>

/*..................................Initialises the row headers and column headers and turning all of them to null....................................................*/

void init_sparse(sparse *s)
{
	
	int i,j;
	for( i = 0; i<(s->row_sz); i++)
	{
		s->row[i] = NULL;
	}
	for( j = 0; j<(s->col_sz); j++)
        {
                s->col[j] = NULL;
        }

}

/*..................................To add a node to the sparse matrix list by dynamically allocating the memory to each of the node recieved.........................*/  
void insert_node(int r,int c,float key,sparse *s1)
{
	node *temp;				//temporary pointer to the strucure of type node is created
	temp = (node*)malloc(sizeof(node));	//memory is allocated dynamically to that temp pointer with the size of structure "node"
	temp->key = key;
	temp->row = r;
	temp->col = c;
	temp->rlink =0;
	temp->clink = 0;
	node *rr = s1->row[r];
	node *cc = s1->col[c];
	node *prevr = NULL;
	node *prevc = NULL;

	if(rr == NULL)				//checks wether the pointed row list is empty 
	{
		s1->row[r] = temp;		//if the row list is empty ..... the temp is assigned as 1st node in that row list
	}
	else if(rr -> col > temp -> col)
		{
			temp -> rlink = rr;
			s1->row[r] = temp;
		}

	 else                                    //comes here if pointed row list is not empty
        	{
                	while(rr)                //to get link of the last in the pointed row list
                	{
				printf("\ncheck0\n");
                        	prevr = rr;
                        	if(rr -> col < temp -> col)
                                	rr = rr->rlink;
                        	else
                                	break ;
                	}
                	if(rr == NULL)
                	{
                        	prevr->rlink = temp;
                        
                	}
                	else
                	{
                        	prevr-> rlink = temp;
                        	temp -> rlink = rr;
                        
                	}

        	}	

	
	if(cc == NULL)				//checks wether the pointed coloumn list is empty 
	{
        	s1->col[c] = temp;		//if the row list is empty ..... the temp is assigned as 1st node in that row list

        }
	else if(cc -> row > temp -> row)
	{
		temp -> clink = cc;
		s1->col[c] = temp;
	}

	else					//comes here if pointed row list is not empty

	{
		 while(cc)                //to get link of the last in the pointed row list

                {
			printf("\ncheck1\n");
                        prevc = cc ;
                        if(cc -> row < temp -> row)
                        {
                                cc= cc->clink;
                        }
                        else
                        {
                                break;
                        }
                }
                if(cc == NULL )
                {
                        prevc -> clink = temp;
                        
                }
                else
                {
                        prevc -> clink = temp;
                        temp -> clink = cc;
                        
                }


	}	
}
/*..................................................................................................................................................*/

/*.........................To display the elements present in the dynamically created sparse matrix list............................................*/
void display(sparse *s)

{
	int i,j,k,m,n;
	float z = 0;

	for(i = 0;i<(s->row_sz); ++i)						//To displaiy the elements of the matrix row wise

	{
		node * rr=s->row[i];
		node * p=s->row[i];

		if(rr == NULL)							//checks wether pointing row is null!!1
		{
			for(j = 0; j<(s->col_sz);++j)
			{
				printf("%f\t",z);					//if pointin row list is null then prints the whole row elements as zero
				
			}
		}

		else								//comes here if row list is not empty
		{
			int prev = 0;
			int count = 0;

			while(rr != NULL)					//to print zero and non zero row elements in original form
			{
				if((rr->col == 0)||(rr->col-p->col == 1))	//for 1st or consecutive non zero elements 
				{
					printf("%f\t",rr->key);			//prints either 1st element or consecutive elements in the pointed row
				}
				
				else if(count != 0)				//for zero elements between the previous and current node and for key of current node
				{
					for(k = 1;k<((rr->col)-prev);++k)
					{
						printf("%f\t",z);			//prints the zero elements between any 2 consecutive nodes "if present"
					}

					printf("%f\t",rr->key);			//prints the key of the current node 
				}

				 else 						//for the last element in the coloumn for the pointed row 
                                {
                                        for(n = 0;n< rr->col;++n)
                                        {
                                                printf("%f\t",z);			//prints the zero elements 
                                        }
                                        printf("%f\t",rr->key);			//prints the key of last element
                                }

				count++;
				p = rr;
				prev = rr->col;
				rr = rr->rlink;
			}

			if(p->col < ((s->col_sz)-1))				//for zero elements after the last node in the pointed row list if present
				{
					for(m = p->col ; m < (s->col_sz)-1 ; ++m)
					{
						printf("%f\t",z);			//prints zero elements
					}
				}
		}
		printf("\n");
		
	}

}


/*........................................................................................................................................................*/

void create_mat(sparse *s1)
        {

		int z;
		FILE *file1;
                char fname[20];
                printf("\nenter the file name : ");
                scanf("%s",fname);
                file1 = fopen(fname,"r");                                       //opens the file present in read only mode

                while(file1==NULL)                                         //gives message if that file is not present
                {
                        printf("\nfile not found\n\n");
			printf("Enter \n\n1.To enter onather file name\n2.To exit\n\nCHOICE :: ");
			scanf("%d",&z);
			printf("\n");
			switch(z)
			{
				case 1: 
					printf("\nenter the file name : ");
                			scanf("%s",fname);
                			file1 = fopen(fname,"r");                                       //opens the file present in read only mode
					break;
				case 2:
					exit(0);
				default :
					 printf("\nEnter appropriate choice");
			}
                }
              	fscanf(file1,"%d",&s1->row_sz);
		fscanf(file1,"%d",&s1->col_sz);

                init_sparse(s1);

		
		int i = 0;
	        int r,c;
		float val;
		float ele = 0;
		
                while(!feof(file1))
                {
			
                        fscanf(file1,"%f",&ele);//error
			
                        if(i%3 == 0)
                        {
                                r = ele;
                        }
                        else if(i%3 == 1)
                        {
                                c = ele;
                        }
                        else if(i%3 == 2)
                        {
                                val = ele;
                                insert_node(r,c,val,s1);
			}
			++i;

		}
}

/*......................................................................................................................................................*/
void create_mat1(sparse *s1)
	{
		int z;
		FILE *file1;
        	char fname[20] = "gach.dat";
        	//printf("\nenter the file name : ");
        	//scanf("%s",fname);
        	file1 = fopen(fname,"r");                                       //opens the file present in read only mode
		 while(file1==NULL)                                         //gives message if that file is not present
                {
                        printf("\nfile not found\n\n");
                        printf("Enter \n\n1.To enter onather file name\n2.To exit\n\nCHOICE :: ");
                        scanf("%d",&z);
                        printf("\n");
                        switch(z)
                        {
                                case 1:
                                        printf("\nenter the file name : ");
                                        scanf("%s",fname);
                                        file1 = fopen(fname,"r");                                       //opens the file present in read only mode
                                        break;
                                case 2:
                                        exit(0);
                                default :
                                         printf("\nEnter appropriate choice");
                        }
                }
		


		//fscanf(file1,"%d",&s1->row_sz);
                //fscanf(file1,"%d",&s1->col_sz);
		s1->row_sz = 3;
		s1->col_sz = 4;
        	init_sparse(s1);

        	int i,j;
		float ele;

        	for(i = 0; i<s1->row_sz; ++i)                      //to create sparse matrix
        	{	
                	for(j = 0; j<s1->col_sz; j++)
                	{
                        	fscanf(file1,"%f",&ele);         //reading elements present in matrix file one by one 
                        	if(ele != 0)
                        	insert_node(i,j,ele,s1);       	//adds a node to the sparse matrix list
                		
			}
        	}

	}


/*......................................................................................................................................................*/
float getv(sparse *s1,int r,int c)
{
	if(s1->row[r] == NULL | s1->col[c] == NULL )
	{
		return 0;
	}
	else
	{
		node* rr = s1->row[r];
		float val;
		while(rr != NULL)
		{
			if(rr -> col == c)
			{
				val = rr->key;
				break;
			}
			else if(rr -> col > c)
			{
				val = 0;
				break;
			}
			else
			{
				rr = rr->rlink;
				if(rr == NULL)
				{
					val = 0;
				}
			}
		} 
		return(val);
	}
}


/*..................................................................................................................................................*/


/*void gelim(sparse * s1)
{
	
	int i,j,k,n,pivotrow;
	n = s1->row_sz;
	for(i = 0 ; i<n-2 ; ++i)
	{
		pivotrow = i;
		for(j = 0 ; j < n-1 ; ++j)
		{
			if(getv(s1,j,i) > getv(s1,pivotrow,k))
			{
				pivotrow = j;
			}
		}
		for(k = 0 ; k < n ; ++k)
		{
			swap(s1,i,k,getv(s1,i,j),pivotrow,k,getv(s1,pivotrow,k));
		}
		for(j = i+1 ; j < n-1 ; ++j)
		{
			float x;
			x = (getv(s1,j,i)/getv(s1,i,i));
			for(k = i ; k < n ; ++k)
			{
				delete_node(j,k,s1);
				float var;
				var = getv(s1,j,k)-(getv(s1,i,k)*x);
				if(var != 0)
				{
					insert_node(j,k,var,s1);
				}
			}
		}
	}
	

}*/	
/*.................................................................................................................................................*/

void swap(sparse *s1,int r1 ,int c1 ,float val1,int r2,int c2,float val2)
{
	if(val1 != 0 & val2 == 0)
	{
		delete_node(r1,c1,s1);
		insert_node(r2,c2,val1,s1);
	}
	else if(val1 == 0 & val2 != 0)
        {
                delete_node(r2,c2,s1);
                insert_node(r1,c1,val2,s1);
        }
	else if(val1 != 0 & val2 != 0)
        {
                delete_node(r1,c1,s1);
		delete_node(r2,c2,s1);
                insert_node(r1,c1,val2,s1);
		insert_node(r2,c2,val1,s1);
        }

}

/*..................................................................................................................................................*/


int delete_node(int r , int c , sparse *s1)
{
	node *rr;
	node *cc;
	node *prev;
	rr = s1 -> row[r];
	cc = s1 -> col[c];
	if(rr == NULL | cc == NULL)
	{
		return 0;
	}
	else
	{ 
		if(rr->col == c)
		{
			s1 -> row[r] = rr -> rlink;
		
		}
		else
		{
			while(rr)
			{
				
				if(rr->col < c)
				{	
					prev = rr;
					rr = rr->rlink;
				}
				else if(rr -> col == c)
				{
					break;
				}
				else
				{
					return 0;
				}
			
			}
			if(rr != NULL)
			{
				prev -> rlink = rr -> rlink;
				free(rr);
			}
			else
			{
				return 0;
			}
		
		}

        	if(cc->row == r)
        	{
                	s1 -> col[c] = cc -> clink;

        	}
        	else
        	{
             
             		while(cc)
                	{
                        		
                        	if(cc->row < r)
                        	{
                                	prev = cc;
					cc = cc->clink;
                        	}
                        	else if(cc -> row == r)
                        	{
                                	break;
                        	}
                        	else
                        	{
                                	return 0;
                        	}

                	}
                	if(cc != NULL)
                	{
                        	prev -> clink = cc -> clink;
				free(cc);
                	}
                	else
                	{
                        	return 0;
                	}
  
        	}
			
	}

}
/*..................................................................................................................................................*/
/*void guass (sparse *s1) 
{

      //  forwardSubstitution(s1);
printf("\n\n");	
//display(s1);       
 reverseElimination(s1);
	
printf("\n\n");
        display(s1);

}
void forwardSubstitution(sparse *s1)
{

        int i, j, k, max;
        int n = s1->row_sz;

        float t;

        for (i = 0; i < n; ++i) 
	{

                max = i;

                for (j = i + 1; j < n; ++j)

                        if (getv(s1,j,i) > getv(s1,max,i))

                                max = j;



                for (j = 0; j < n + 1; ++j)
                {
                        swap(s1,max,j,getv(s1,max,j),i,j,getv(s1,i,j));
                        //t = getv(s1,max,j);

                        //a[max][j] = a[i][j];

                        //a[i][j] = t;

                }
                                                                                                                       
 for (j = n; j >= i; --j)

                        for (k = i + 1; k < n; ++k)
                        {

                                float m = (getv(s1,k,j))-(getv(s1,k,i)/getv(s1,i,i))*getv(s1,i,j);
				delete_node(k,j,s1);
				insert_node(k,j,m,s1);
                        }


/*              for (k = 0; k < n; ++k) {

                        for (j = 0; j < n + 1; ++j)

                                printf("%.2f\t", a[k][j]);

                        printf("\n");

                }*/

  /*      }

}

void reverseElimination(sparse *s1)
{

        int i, j;
	int n = s1->row_sz;
        for (i = n - 1; i >= 0; --i)
	{

                delete_node(i,j,s1);
                insert_node(i,j,(getv(s1,i,n)/getv(s1,i,i)),s1);
                delete_node(i,i,s1);
                insert_node(i,i,1,s1);

                for (j = i-1 ; j >= 0 ; --j)
                {
                        delete_node(j,n,s1);
                        insert_node(j,n,(getv(s1,j,n)-getv(s1,j,i)*getv(s1,i,n)),s1);
                        delete_node(j,i,s1);
                        //a[j][i] = 0;

                }

        }

}*/
/*..................................................................................................................................................*/
/*void guassian_elemination(sparse *s1)
{
	int n,m,i,j,k;
	n = s1->col_sz;
	m = s1->row_sz;
	for(i = 0;i<(n-2);++i)
	{
		for(j = i+1 ; j < m ; ++j)
		{printf("hi\n");
			for(k = i; k < n ; ++k)
			{printf("hik");
				float x = (getv(s1,j,k)-(getv(s1,i,k)*(getv(s1,j,i)/getv(s1,i,i))));
				delete_node(j,k,s1);
				printf("\n\n");
				//display(s1);
				if(x != 0)
				{
					insert_node(j,k,x,s1);
				}
			}
		}
	}
}*/
/*void guassian_elemination1(sparse *s1)
{
	int i,j,k,pivotrow;
	int n = s1-> col_sz;
	for(i = 0; i < n-1;++i)
	{
		pivotrow = i;
		for(j = i;j<n+1;++j)
		{
			if(getv(s1,j,i)>getv(s1,pivotrow,i))
				pivotrow = j;
		}
		for(k=i;k<n+1;++k)
		{
			float a,b;
			a = getv(s1,i,k);
			b = getv(s1,pivotrow,k);
			delete_node(i,k,s1);
			delete_node(pivotrow,k,s1);
			if(a != 0)
			{
				insert_node(i,k,b,s1);
			}
			if(b != 0)
			{
				insert_node(pivotrow,k,a,s1);
			}
		}
		for(j=i+1;j<n;++j)
		{
			float temp = getv(s1,j,i)/getv(s1,i,i);
			for(k = i; k < n+1 ; ++k)
			{
				float x = getv(s1,j,k)-getv(s1,i,k)*temp;
				delete_node(j,k,s1);
                                if(x != 0)
                                {
                                        insert_node(j,k,x,s1);
                                }

			}
		}
	}
}*/


/*...............................................................................................................................................*/
void guassian_elemination(sparse *s1)	
{
	
	int i,j,k;
	int r,c;
	r = s1->row_sz;
	c = s1->col_sz;
	float x,temp;
	for(i=0;i<(c-2);++i)
	{
		for(j=i+1;j<r;++j)
		{
			temp = getv(s1,j,i)/getv(s1,i,i);
			 printf("\nchk-5\n");
			for(k = i;k < c;++k)
			{
				 printf("\nchk-4\n");
				x = getv(s1,j,k)-(getv(s1,i,k)*temp);
				 printf("\nchk-3\n");
				delete_node(j,k,s1);
				 printf("\nchk-2\n");
				if(x != 0)
				{
					printf("\nchk-1\n");
					insert_node(j,k,x,s1);
					printf("\nchk0\n");
				}
				printf("\nchk1\n");
				display(s1);
				
			}
			printf("chk2");
		}
		printf("chk3");
	}
	printf("\n\n\n");
	display(s1);
}
/*................................................................................................................................................*/
void g_e(sparse *s1)
{
	int r = s1->row_sz;
	int c = s1->col_sz;
	int i,j,k,pivot_r;
	float temp,x;

	for(i = 0;i<c-2;++i)
	{
		pivot_r = i;
		for(j = i+1 ; j<r ; ++j)
		{
			if(getv(s1,j,i)>getv(s1,pivot_r,i))
			{
				pivot_r = j;
			}
		}
		for(k = i ; k < c ; ++k)
		{
			float ik,pk;
			ik = getv(s1,i,k);
			pk = getv(s1,pivot_r,k);
			delete_node(i,k,s1);
			delete_node(pivot_r,k,s1);
			if(ik != 0)
			{
				printf("\nch1\n");
				insert_node(pivot_r,k,ik,s1);
				printf("\nch2\n") ;
			}
			if(pk != 0)
			{	
				printf("%d \t%d" , i , k) ;
				insert_node(i,k,pk,s1);
				
			}
			
		}
		for(j = i+1 ; j < r ; ++j)
		{
			temp = getv(s1,j,i)/getv(s1,i,i);
			for(k = 0;k< c ; ++k)
			{
				x = getv(s1,j,k)-(getv(s1,i,k)*temp);
				delete_node(j,k,s1);
				if(x != 0)
				{
					insert_node(j,k,x,s1);
				}
			}
		}
	}
}
