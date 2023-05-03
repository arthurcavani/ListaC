#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX  4000


struct tipoElemento{
    char nome[50],rua[100],cidade[100],pais[35],num1[50],data[20],telefone[20],id[10],total[15];   
    };


typedef struct tipoElemento tElemento;


struct tipoLista{
    tElemento elem[MAX];
    int ultimo;
};
typedef struct tipoLista tLista;

int add=0,alterarl[50],cods[MAX],deleted[MAX],pos[MAX];
float tflex[MAX];
char nms[MAX][50];

FILE *arquivo;

void inicializar(tLista *lst);
void carregar(tLista *lst);
void salvar(tLista *lst);
void inserir(tLista *lst);
void remover(tLista *lst);
void alterar(tLista *lst);
void relcod(tLista *lst);
void pesquisarnome(tLista *lst);
void pesquisarcod(tLista *lst);
int lista_vazia(tLista *lst);
int lista_cheia(tLista *lst);
void formatar(tLista *lst);
void relnome(tLista *lst);
void reltotal(tLista *lst);
void selectionSort(float *data, int count);
void quickSort(int valor[], int esquerda, int direita);

void selectionSort(float *data, int count)
{
    int i, j, min,temp2;
	float temp;
	
	
	
	for (i = 0; i < count - 1; i++)
    {

        min = i;
        for (j = i+1; j < count; j++)
        {
            if (data[j] < data[min])
            {
                min = j;

            }
        }

        temp = data[i];
        temp2 = pos[i];
        data[i] = data[min];
        pos[i]  = pos[min];
        data[min] = temp;
        pos[min] = temp2;
    }
}


void reltotal(tLista *lst)
{
	 char bl[]="deleted";
	 int y=0,val=1;	
 for(int g=0;g<lst->ultimo;g++)
    tflex[g]=atof(lst->elem[g].total);
    
     for(int g=0;g<lst->ultimo;g++)
    pos[g]=g;
    
   selectionSort(tflex, lst->ultimo);    
     
  for(int x=0;x<lst->ultimo;x++){
  val=1;
     	if (stricmp(lst->elem[pos[x]].nome,bl) == 0){
		 			val = -1;
		 		}
		 			 
		  if (val==1){
		  
       	printf("\n--------------------------------");
         printf("\nNome : %s", lst->elem[pos[x]].nome);
         /* printf("\nId : %s", lst->elem[pos[x]].id);
      printf("\nRua : %s", lst->elem[pos[x]].rua);
         printf("\nCidade : %s", lst->elem[pos[x]].cidade);
         printf("\nPais : %s", lst->elem[pos[x]].pais);
         printf("\nNum1 : %s", lst->elem[pos[x]].num1);
         printf("\nData : %s", lst->elem[pos[x]].data);
         printf("\nTelefone : %s", lst->elem[pos[x]].telefone);*/
         printf("\nTotal : %s", lst->elem[pos[x]].total);        
     }
         
  
}
 for(int e=0;e<MAX+1;e++){
 tflex[e]=0;
}
      
    system("pause");
}

void relnome(tLista *lst)
{int i=0,valid = 1,d=-1;
char bl[]="deleted";
int chave;
     for(int g=0;g<lst->ultimo;g++)
     strcpy(nms[g],lst->elem[g].nome);
     
       for(int g=0;g<lst->ultimo;g++)
    pos[g]=g;
     
     for(int j=1; j<lst->ultimo; j++)
 	{char aux[50];
 	  int aux1;
 	  aux1=pos[j];
 	strcpy(aux,nms[j]);
 	i = j-1;
 	while(i >= 0 && stricmp(nms[i], aux) > 0)
 	{
 	pos[i+1]=pos[i];
 	strcpy(nms[i+1],nms[i]);
 	i--;
 	}
 	pos[i+1]=aux1;
 	strcpy(nms[i+1],aux);
 	} 

 int val=1;	
 
 for(int x=0;x<lst->ultimo;x++){
  val=1;
     	if (stricmp(lst->elem[pos[x]].nome,bl) == 0){
		 			val = -1;
		 		}
		 			 
		  if (val==1){
		  
       	printf("\n--------------------------------");
         printf("\nNome : %s", lst->elem[pos[x]].nome);
         printf("\nId : %s", lst->elem[pos[x]].id);
     /*  printf("\nRua : %s", lst->elem[pos[x]].rua);
         printf("\nCidade : %s", lst->elem[pos[x]].cidade);
         printf("\nPais : %s", lst->elem[pos[x]].pais);
         printf("\nNum1 : %s", lst->elem[pos[x]].num1);
         printf("\nData : %s", lst->elem[pos[x]].data);
         printf("\nTelefone : %s", lst->elem[pos[x]].telefone);
         printf("\nTotal : %s", lst->elem[pos[x]].total);        
     */}
         
  
}
 	
 	for(int g=0;g<MAX+1;g++){
 	 	strcpy(nms[g],"");
 		cods[g]=0;
 		pos[g]=0;
 	}
 	
 
 	system("pause");
 	
}


char *replace(char *s, char old, char ne)
{
    char *p = s;

    while(*p)
    {
        if(*p == old)
            *p = ne;

        ++p;
    }

    return s;
}

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
 
    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}


void formatar(tLista *lst){
	tElemento aux;
	for(int u=0;u<lst->ultimo;u++){
		aux = lst->elem[u];
		strcpy(aux.total,replace(aux.total, ',', '.'));
	lst->elem[u] = aux;	
	}
}


void relcod(tLista *lst){
	 char bl[]="deleted";
	 int chave=0,achou=-1,m=0,y=0,val=1,j=0,z=0;	
 for(int g=0;g<lst->ultimo;g++)
    cods[g]=atoi(lst->elem[g].id);
    
    quickSort(cods,0,lst->ultimo-1);
  

     int h=0;
     	for(h=0;h < lst->ultimo;h++){  
		     val=1;
		     for(int w=0;w<lst->ultimo;w++){
		     	if(atoi(lst->elem[w].id)==cods[h]){
		     		chave=w;
		     	}
		     }
		 		if (stricmp(lst->elem[chave].nome,bl) == 0){
		 			val = -1;
		 		}
		 			 
		  if (val==1){
		  
    	printf("\n--------------------------------");
         printf("\nNome : %s", lst->elem[chave].nome);
         printf("\nId : %s", lst->elem[chave].id);
      /* printf("\nRua : %s", lst->elem[chave].rua);
         printf("\nCidade : %s", lst->elem[chave].cidade);
         printf("\nPais : %s", lst->elem[chave].pais);
         printf("\nNum1 : %s", lst->elem[chave].num1);
         printf("\nData : %s", lst->elem[chave].data);
         printf("\nTelefone : %s", lst->elem[chave].telefone);
         printf("\nTotal : %s", lst->elem[chave].total);*/        
     }
         
   }
    
 for(int e=0;e<MAX+1;e++){
  cods[e]=0;
}
    
    system("pause");
}


void salvar(tLista *lst){
arquivo = fopen("clientes.csv","w");	

 int u=0,valid = 1;
 char linha[300],comma[]=";";
    for( u=lst->ultimo; u > 0; u--){
       strcpy(linha,lst->elem[u-1].id);
       strcat(linha,comma);
     
       strcat(linha,lst->elem[u-1].nome);
       strcat(linha,comma);
      
       strcat(linha,lst->elem[u-1].rua);
       strcat(linha,comma);
     
       strcat(linha,lst->elem[u-1].cidade);
       strcat(linha,comma);
    
       strcat(linha,lst->elem[u-1].pais);
       strcat(linha,comma);
   
       strcat(linha,lst->elem[u-1].num1);
       strcat(linha,comma);
    
       strcat(linha,lst->elem[u-1].data);
       strcat(linha,comma);
   
       strcat(linha,lst->elem[u-1].telefone);
       strcat(linha,comma);
  
      strcat(linha,lst->elem[u-1].total);
      
     
      fputs (linha,arquivo);
      valid=1;
      for(int r=0;r<51;r++){
      	if (atoi(lst->elem[u-1].id)==alterarl[r]){
      	      	putc('\n',arquivo);
      	      	r=52;
      	      }
      	      else
      	      if (valid==1){
      	        if(u<add+1){      
      putc('\n',arquivo);
      valid = -1;
  }
      	      
    }  
	}
      
      
    }
    fclose(arquivo);
    add=0;
     for(int r=0;r<51;r++)
     alterarl[r]=0;    	
     
}



void carregar(tLista *lst){

    tElemento novo;
    int posicao=0;

  
       arquivo = fopen("clientes.csv","r");
char linha[300]; 
char * pch;

 while (fgets(linha, sizeof linha, arquivo) != NULL) 
    {
     int c;
     c=1;
     pch = strtok (linha,";");
     strcpy(novo.id,pch);
     
     
  while (pch != NULL)
  {c++;
  
     
  pch = strtok (NULL, ";");
    if (c==2)
		strcpy(novo.nome,pch);		 
		if (c==3)

		{
		strcpy(novo.rua,pch);	
		}		
		
	if (c==4)
		{
		strcpy(novo.cidade,pch);	
	}
	
		if (c==5)
		{
		strcpy(novo.pais,pch);	
	}
	
		if (c==6)
		{strcpy(novo.num1,pch);
				
				}
				if (c==7)
		{strcpy(novo.data,pch);
				
				}
					if (c==8)
		{strcpy(novo.telefone,pch);
				
				}
				if (c==9)
		{strcpy(novo.total,pch);
				
				}
				}
				
 if ( posicao >= 0 && posicao < MAX){

             
                if ( posicao > lst->ultimo){
                    posicao = lst->ultimo;
                }

             
                int i;
                for ( i = lst->ultimo; i > posicao; i--){
                    lst->elem[i] = lst->elem[i-1];
                }

            
                lst->elem[i] = novo;
                lst->ultimo++;
                
               
                
                       }	   
}
    

 fclose(arquivo);      
}




void inicializar(tLista *lst){
    lst->ultimo=0;
}


void alterar(tLista *lst){

    int posicao,p;
    tElemento aux;

    printf("ID : ");
    scanf("%d",&p);
    
    for(int l=0;l<lst->ultimo;l++){
    if (atoi(lst->elem[l].id)==p)
    posicao=l;
    }
    
    if (posicao >=0 && posicao < MAX){
        
       fflush(stdin);
        printf("Nome : ");
        gets(aux.nome);
        
        fflush(stdin);
        printf("Rua : ");
        gets(aux.rua);
        
        fflush(stdin);
        printf("Cidade : ");
        gets(aux.cidade);
        
        fflush(stdin);
        printf("Pais : ");
        gets(aux.pais);
        
        fflush(stdin);
        printf("Num1 : ");
        gets(aux.num1);
        
        fflush(stdin);
        printf("Data : ");
        gets(aux.data);
        
        fflush(stdin);
        printf("Telefone : ");
        gets(aux.telefone);
        
        fflush(stdin);
        printf("Total : ");
        gets(aux.total);
        
        itoa(p,aux.id,10);
        
        lst->elem[posicao] = aux;
        int y=0,m=0;
        while(m==0){
        	if(alterarl[y]==0){
        		alterarl[y]=p;
				m=1;     		
        	}
        y++;}
        
        printf("\n\nOperacao realizada com sucesso!\n\n");
    }else{
        printf("\n\nPosicao invalida!\n\n");
    }
}


void inserir(tLista *lst){

    tElemento novo;
    int posicao;
    
  
    if ( lista_cheia(lst) == 0){

        
        fflush(stdin);
        printf("Nome : ");
        gets(novo.nome);
        
        fflush(stdin);
        printf("Rua : ");
        gets(novo.rua);
        
        fflush(stdin);
        printf("Cidade : ");
        gets(novo.cidade);
        
        fflush(stdin);
        printf("Pais : ");
        gets(novo.pais);
        
        fflush(stdin);
        printf("Num1 : ");
        gets(novo.num1);
        
        fflush(stdin);
        printf("Data : ");
        gets(novo.data);
        
        fflush(stdin);
        printf("Telefone : ");
        gets(novo.telefone);
        
        fflush(stdin);
        printf("Total : ");
        gets(novo.total);
        
		sprintf(novo.id,"%d",lst->ultimo+1);
		posicao=0;
       
        if ( posicao >= 0 && posicao < MAX){

              
                if ( posicao > lst->ultimo){
                    posicao = lst->ultimo;
                }

            
                int i;
                for ( i = lst->ultimo; i > posicao; i--){
                    lst->elem[i] = lst->elem[i-1];
                }

           
                lst->elem[i] = novo;
                lst->ultimo++;
                add++;
                printf("\n\nOperacao realizada com sucesso!\n\n");

        }else{
            printf("\n\nPosicao invalida!\n\n");
        }

    }else{
        printf("\n\nLISTA CHEIA!\n\n");
    }
system("pause");
}


void remover(tLista *lst){
  int posicao,p=0,y=0,valid=1,conf=1;
  char bl[]="deleted",zero[]="0.00";
    tElemento aux;
    while(p==0){
    	system("cls");
        printf("ID : ");
    scanf("%d",&p);
}
   
   
    
    
      for(y=0;y<lst->ultimo;y++){
   	if (stricmp(lst->elem[y].nome,bl) == 0){
	   	for(int q=0;q<MAX+1;q++){
	   		if (deleted[q]==0){	   		   			
	   			deleted[q]=atoi(lst->elem[y].id);
	   			q=MAX+1;
	   	  
	   		}
	   	}
    } 
 }
    
    for(int ju=0;ju<lst->ultimo;ju++){
    	 if (ju==0){
    	  if(p<1 || p>lst->ultimo){
    	printf("\n\nItem nao encontrado!\n\n");
    		valid=-1;	
    }
}
    	if (p==deleted[ju]){
    		printf("\n\nItem nao encontrado!\n\n");
    		valid=-1;
    	}
    }
    
    for(int l=0;l<lst->ultimo;l++){
    if (atoi(lst->elem[l].id)==p)
    posicao=l;
    }
       
    if (valid==1){
        
    if (posicao >=0 && posicao < MAX){
       
        strcpy(aux.nome,bl);              
      strcpy(aux.rua,bl);         
       strcpy(aux.cidade,bl); ;
        strcpy(aux.pais,bl); 
        strcpy(aux.num1,bl); 
        strcpy(aux.data,bl); 
        strcpy(aux.telefone,bl); 
        strcpy(aux.total,zero); 
        
        itoa(p,aux.id,10);
        
        lst->elem[posicao] = aux;
        int y=0,m=0;
        while(m==0){
        	if(alterarl[y]==0){
        		alterarl[y]=p;
				m=1;     		
        	}
        y++;}
        
        printf("\n\nOperacao realizada com sucesso!\n\n");
    }else{
        printf("\n\nPosicao invalida!\n\n");
    }
}
for(int e=0;e<MAX+1;e++){
  cods[e]=0;
  deleted[e]=0;
}
system("pause");
}




void pesquisarnome(tLista *lst){

    char nome[50];
    char bl[]="deleted";
    int i = 0;
    int achou = -1;
    fflush(stdin);
    printf("Nome: ");
    gets(nome);

    while ( i < lst->ultimo && achou == -1){
        if (stricmp(lst->elem[i].nome,nome) == 0){
            achou = 1;
        }else{
            i++;
        }
    }

    if ( achou != -1){
    		if (stricmp(lst->elem[i].rua,bl) == 0){
    		printf("\nO elemento nao foi encontrado!\n\n");
    	}else{
        printf("\nNome : %s", lst->elem[i].nome);
         printf("\nId : %s", lst->elem[i].id);
         printf("\nRua : %s", lst->elem[i].rua);
         printf("\nCidade : %s", lst->elem[i].cidade);
         printf("\nPais : %s", lst->elem[i].pais);
         printf("\nNum1 : %s", lst->elem[i].num1);
         printf("\nData : %s", lst->elem[i].data);
         printf("\nTelefone : %s", lst->elem[i].telefone);
         printf("\nTotal : %s", lst->elem[i].total);
        printf("\n");}
    }else{
        printf("\nO elemento nao foi encontrado!\n\n");
    }
system("pause");
}

void pesquisarcod(tLista *lst){

    char cod[10];
    int i = 0;
    int achou = -1;
char bl[]="deleted";
    fflush(stdin);
    printf("Codigo: ");
    gets(cod);

    while ( i < lst->ultimo && achou == -1){
        if (stricmp(lst->elem[i].id,cod) == 0){
            achou = 1;
        }else{
            i++;
        }
    }

    if ( achou != -1){
    	if (stricmp(lst->elem[i].rua,bl) == 0){
    		printf("\nO elemento nao foi encontrado!\n\n");
    	}else{
    	
        printf("\nNome : %s", lst->elem[i].nome);
         printf("\nId : %s", lst->elem[i].id);
         printf("\nRua : %s", lst->elem[i].rua);
         printf("\nCidade : %s", lst->elem[i].cidade);
         printf("\nPais : %s", lst->elem[i].pais);
         printf("\nNum1 : %s", lst->elem[i].num1);
         printf("\nData : %s", lst->elem[i].data);
         printf("\nTelefone : %s", lst->elem[i].telefone);
         printf("\nTotal : %s", lst->elem[i].total);
        printf("\n");}
    }else{
        printf("\nO elemento nao foi encontrado!\n\n");
    }
system("pause");
}




int lista_cheia(tLista *lst){

    if ( lst->ultimo >= MAX){
        return 1;  
    }else{
        return 0;   
    }

}


int lista_vazia(tLista *lst){

    if ( lst->ultimo == 0){
        return 1;  
    }else{
        return 0;   
    }
}






