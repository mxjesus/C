#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int menu(); //Menï¿½ de inicio
int make(); //Crea una matriz MxN con valores
int make2(); //Crea una matriz MxN secundaria con valores
int sola(); //Crea una matriz MxN con valores para uso singular
int impm(); //Imprime la matriz MxN
int impm2();
int suma(); //Suma de matrices
int mult(); //multiplicaciï¿½n de matrices
int trans(); //matriz transpuesta
int diag(); //Diagonal principal
int det(); //Determinante
int mati(); //Matriz inferior
int mats(); //Matriz superior
int r,i,j,k,d,f,c,f1,c1; /*fila=f,columna=c*/
int ar[100][100];
int ar2[100][100];
int sum[100][100];
int nue[100][100]; //Matriz utilizada para el determinante
char res;
int op1; //Condicional para matriz inferior
int op2; //Condicional para matriz superior
int op3; //Condicional para diagonal

int main()
{
	do 
	{
		menu();
		switch(r)
		{
			case 1: 
			suma();
			system("pause");
			break;		
			case 2: 
			mult();
			system("pause");
			break;
			case 3: 
			trans();
			break;
			case 4: 
			diag();
			system("pause");
			break;
			case 5: 
			det();	
			system("pause");
			break;
			case 6: 
			mati();	
			system("pause");
			break;
			case 7: 
			mats();
			system("pause");
			break;
			getch();
			system("pause");
		}
 	}while(r<8);
}
int menu()
{
	system("cls");
	printf("Elige/teclea la opcion a ejecutar \n");
	printf("\t 1:Suma de matrices \n");
	printf("\t 2:Multiplicacion de matrices \n");
	printf("\t 3:Matriz transpuesta \n");
	printf("\t 4:Diagonal principal \n");
	printf("\t 5:Determinantes (hasta matrices de 3x3) \n");
	printf("\t 6:Matriz inferior \n");
	printf("\t 7:Matriz superior\n");
	printf("\t 8:Salir \n");
	printf("\t Opcion: ");
	scanf("%i",&r);
	printf("%i",r);
	system("cls");
	return 0;
}
int sola()
{
	printf("Proporciona el numero de filas de la matriz\n");
    scanf("%d",&f);
    printf("Proporciona el numero de columnas de la matriz\n");
    scanf("%d",&c);	
	if ((c>0 && f>0)&&(c==f))
    {
    ar[0][0]=ar[f][c];      
    for(int i=0;i<f;i+=1)
	{
	   	for(int n=0;n<c;n+=1)
	{
	printf("Dame el valor de [%d][%d]\n",i,n);
    scanf("%d",&ar[i][n]);                   
	}                            
	}
    }
	return 0;
}
int make()
{
	printf("Proporciona el numero de filas de la primera matriz\n");
    scanf("%d",&f);
    printf("Proporciona el numero de columnas de la primera matriz\n");
    scanf("%d",&c);
    if (c>0 && f>0)
    {
    ar[0][0]=ar[f][c];      
	for(int i=0;i<f;i++)
	{
		for(int n=0;n<c;n++)
	{
		printf("Dame el valor de [%d][%d]\n",i,n);
	    scanf("%d",&ar[i][n]);                   
	}                            
}
}
}

int make2()
{
	if(c>0 && f>0){
	printf("Proporciona el numero de filas de la segunda matriz\n");
    scanf("%d",&f1);
    printf("Proporciona el numero de columnas de la segunda matriz\n");	
    scanf("%d",&c1);
    ar2[0][0]=ar2[f][c];      
    for(int i=0;i<f1;i++)
	{
	   	for(int n=0;n<c1;n++)
	{
 
	printf("Dame el valor de [%d][%d]\n",i,n);
    scanf("%d",&ar2[i][n]);                   
	}                            
}
}
}

int impm()
{
	printf("Los valores de la primera matriz son: \n\n");
    for(int i=0;i<f;i++) 
 		{
        	for(int n=0;n<c;n++)
 			{
                printf("[%d]",ar[i][n]);
            }
            printf("\n");
 		}
}
int impm2()
{
	printf("Los valores de la segunda matriz son: \n\n");
    for(int i=0;i<f1;i++) 
 		{
        	for(int n=0;n<c1;n++)
 			{
                printf("[%d]",ar2[i][n]);
            }
            printf("\n");
 		}
}

int suma()
{
	make();		
	make2();
	if (c>0 && f>0)
	{
	if ((c==c1 && f==f1)&&(c1>0 && f>0))
	{
	impm();
	impm2();
	printf("Los valores de las matrices sumadas: \n\n");
    for(int i=0;i<f;i++) 
	{
    	for(int n=0;n<c;n++)    	
		{
            printf("[%d]",ar[i][n]+ar2[i][n]);        
	}
		printf("\n");
	}
	}
	else
	{
		system("cls");
		printf("\nLas matrices no se pueden sumar\n");
	}
}
else
printf("\nError!\n");
}

int mult()
{
	int f,c,f1,c2,i,j,k;
	int ar[100][100],ar2[100][100],C[100][100];
	printf("Proporciona el numero de filas de la primera matriz\n");
	scanf("%d",&f);
	printf("Proporciona el numero de columnas de la primera matriz\n");
	scanf("%d",&c);
	printf("\n---------------------------------------------------\n");
	printf("\nProporciona el numero de filas de la segunda matriz\n");
	scanf("%d",&f1);
	printf("Proporciona el numero de columnas de la segunda matriz\n");
	scanf("%d",&c2);
	printf("\n");
	if (c==f1)
	{
		printf("\n---------------------------------------------------\n");
		//PEDIR LAS MATRICES
		for (i=1;i<=f;i++)
			for (j=1;j<=c;j++)
			{ 
				printf("Dame el valor [%d][%d]= ",i,j);
				scanf ("%i",&ar[i][j]);
			}
		printf("\n");
		printf("\n---------------------------------------------------\n");	
		for (i=1;i<=f1;i++)	
			for (j=1;j<=c2;j++)	
			{ 
				printf("Dame el valor [%d][%d]= ",i,j);
				scanf ("%i",&ar2[i][j]);	
			}
	//OPERACION DE MULTIPLICACION
	for (i=1;i<=f;i++)
	{
		for (j=1;j<=c2;j++)
		{ 
			C[i][j]=0;
			for (k=1;k<=c;k++)
	  		{
				C[i][j]=C[i][j]+ar[i][k]*ar2[k][j];
			}	
		}	
	}	
	printf("\n---------------------------------------------------\n");
	printf("\n La multiplicacion de matrices:\n\n");
	//IMPRESION
	for (i=1;i<=f;i++)
	{
		for (j=1;j<=c2;j++)
		{
			printf("%i  ",C[i][j]);
		}
		printf("\n");
	}
	}
	else
	{
		printf("\n_________________________________________\n");
		printf("Estas matrices no se pueden multiplicar debido a que son de diferente orden \n");
	}
	printf("\n");
}
 
 
 int trans()
 {	
	make();                           
	if (c>0 && f>0)
	{ 	
 	/*Matriz original*/ 		
	impm();
	/*Matriz transpuesta*/  		
    printf("Los valores en la matriz transpuesta \n\n");
    for(int n=0;n<c;n++) 
	 	{
	    	for(int i=0;i<f;i++)
		 	{
		    	printf("[%d]",ar[i][n]);
		    }
	   		printf("\n");
 		} 	
 }
else{
system("cls");
printf("\nError\n"); 
 system("pause");
}
}
 
 int diag()
 {
	sola();
	if ((c>0 && f>0) && (c==f))
	{
	printf("Los valores de la matriz son: \n\n");	 
	for(int i=0;i<f;i++) 
	{
	    for(int n=0;n<c;n++)	        	
	 	{
	 		if (i==n)
	 		{
	            printf("[%d]",ar[i][n]);
	        }
	        else
	        {
	            printf("   ");
	        }
	        
	 		}
	printf("\n");
	}	
	}
else
{
system("cls");
printf("\nError\n");	
}

 }
 

 int det()
 {
	printf("Proporciona el numero de filas y columnas de la matriz\n");
    scanf("%d",&f);
    c=f;
    if((c>0) && (c<=3))
    {
    ar[1][1]=ar[f][c];      
    for(int i=1;i<=f;i++)
	{
	   	for(int n=1;n<=c;n++)
	{
	printf("Dame el valor de [%d][%d]: ",i,n);
    scanf("%d",&ar[i][n]);                   
	}    
	}	
	d=ar[1][1]; 
	int resultado;
	if(c == 1){
		printf("\nEl valor del determinante es: %d\n", ar[1][1]); 
	}
	if(c == 2){
		printf("%i %i %i %i ", ar[1][1],ar[2][2],ar[1][2],ar[2][1]);
		resultado = (ar[1][1] * ar [2][2]) - (ar[1][2]* ar[2][1]);
		printf("\nEl valor del determinante es: %d\n", resultado); 
	}
	if (c == 3){
		printf("%i %i %i %i ", ar[1][1],ar[2][2],ar[1][2],ar[2][1]);
		resultado = ar[1][1] * (ar [2][2] * ar [3][3] - ar [2][3] * ar [3][2]) - ar[1][2] * (ar[2][1]*ar[3][3]-ar[2][3]*ar[3][1]) + ar[1][3]*(ar[2][1]*ar[3][2] - ar[2][2]*ar[3][1]);
		printf("\nEl valor del determinante es: %d\n", resultado);
	}
	}
	else{
	system("cls");
	printf("\nError\n\n Debe dar un valor entre 1 y 2"); 
	}
}
  
 
 
 int mati()
  { 		
	 sola();  
	if ((c>0 && f>0) && (c==f))
	{               
		 printf("Los valores de la matriz son: \n\n");	 
		for(int i=0;i<f;i++) 
		{
		    for(int n=0;n<c;n++)	        	
		 	{
		 		if (i>=n)
		 		{
		            printf("[%d]",ar[i][n]);
		        }
		        else
		        {
		            printf(" ");
		        }
		        
		 		}
		printf("\n");
		}
	}
	else
	{
	system("cls");
	printf("\nError\n\n El valor de número de filas y columnas deben ser el mismo");	
	}
	
}
 
 
 int mats()
 {	
 	sola();   
 	if ((c>0 && f>0) && (c==f))
	{               
	 printf("Los valores de la matriz son: \n\n");	 
	for(int i=0;i<f;i++) 
	{
	    for(int n=0;n<c;n++)	        	
	 	{
	 		if (i<=n)
	 		{
	            printf("[%d]",ar[i][n]);
	        }
	        else
	        {
	            printf("   ");
	        }
	        
	 		}
		printf("\n");
		}
	}
	else
	{
	system("cls");
	printf("\nError\n\n El valor de número de filas y columnas deben ser el mismo");	
	}
}
