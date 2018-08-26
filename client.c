#include<stdio.h>
#include<stdlib.h>
#include"mat.h"

int main()
{	
	//for(;;)
	//{
		sparse s1;
		int *A;
		//printf("\n----------------MENU----------------------\n\n");
		//printf("1.To Solve a system of equatons using guassian elemination\n");
		//printf("2.To exit\n\n");
		//int ch ;
		//printf("Enter your choice :: ");	
		//scanf("%d",&ch);
		//printf("\n");
		//switch(ch)
		//{
			//case 1:
			//repeat :
				//printf("\n\n.................................Enter Input Type..................................\n\n");
				//printf("1.File containing only non zero tupule inputs\n");
				//printf("2.File containing complete matrix\n");
				//printf("3.To exit\n");
				//int x;
				//printf("\n\nEnter ur choice :: ");
				//scanf("%d",&x);
				//switch(x)
				//{
					//case 1:
						//printf("\n\nEnter the details of augumented matrix :: \n\n");
						create_mat1(&s1);
						//guass (&s1);
						display(&s1);
						g_e(&s1);
						//int i,j;
						//for(i=0;i<3;++i)
						//{
						//for(j=0;j<4;++j)
						//{
						//printf("\n\n%f",getv(&s1,i,j));
						//delete_node(2,3,&s1);
						//printf("\n%f\n",getv(&s1,2,2));
						//gelim(&s1);
						//guass (&s1);
						//printf("\n\n");
						display(&s1);
						//}}
						//break;
					/*case 2:
						printf("\n\nEnter the details of augumented matrix :: \n\n");
                                                create_mat1(&s1);
						display(&s1);
                                                //gelim(s1);
						break;*/
					/*case 3:
						printf("\n\nEnter the details of augumented matrix :: \n\n");
                      	                        A = create_mat2();
                                                gelim1(A);
						break;

					case 4:
						printf("\n\nEnter the details of augumented matrix :: \n\n");
                                                A = create_mat3();
                                                gelim1(A);
                                                break;*/
					/* case 5:
						exit(0);
					default:
						printf("\n\nEntered input is invalid and enter an valid input");
						goto repeat;

				}
				break;
			case 2:
				exit(0);
			default:
				printf("\n\n\nEntered input is invalid and enter an valid input\n");
			
			
		}
	}				
	return 0;*/
	
}
