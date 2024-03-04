#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()
{ 
 // INICIO DA CRIA��O DE STRINGS/VARIAVEIS <3
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //FINAL DAS CRIA��O DE STRINGS/VARIAVEIS <3
  printf("Digite o CPF a ser cadastrado"); // COLETANDO INFORMA��O DE USUARIOS 
  scanf("%s" , cpf);// s se refere a strings criadas!!
   
  strcpy(arquivo, cpf); //Responsavel por copiar valores das string
  
  FILE *file;//cria o arquivo
  file = fopen(arquivo, "w");//cria o arquivo "w" Significa escrever
  fprintf(file,cpf);//salvo o valor da variavel
  fclose(file);//fecha o arquivo

  file = fopen(arquivo,"a"); // "a" pasta de arquivos
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: "); // Nome de usuario a ser cadastrado no sistemas
  scanf("%s",nome);
  
  fprintf(file,",");
  fprintf(file,nome); // Nome cadastrado!!
  fclose(file);
  
  file = fopen(arquivo,"a"); // Nome criado e colacado nos bancos de dados 
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado:");  // Sobrenome de usuario a ser cadastrado no sistemas
  scanf("%s",nome);
  scanf("%s",sobrenome);
  
  file = fopen(arquivo,"a"); // Sobrenome criado com sucesso!!
  fprintf(file,sobrenome);
  fclose(file);
  

  fprintf(file,","); // Virgula adiocionada no sistema !
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado:"); // Seu cargo esta sendo caolocado e adiocionado no banco de dados
  scanf("%s" ,cargo);
  
  file = fopen(arquivo,"a"); 
  fprintf(file,cargo); // CARGO ADIOCIONADO COM SUCESSO
  fclose(file);
  
  system("pause"); // Arquivo pausado !!
  
  
}
int consultar()
{ 

   setlocale(LC_ALL, "Portuguese");//defindo a linguagem
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF A ser consultado");
   scanf("%s",cpf);
   
   FILE*file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("N�o achamos seu arquivo\n");
    }
   
   while(fgets(conteudo, 200 ,file) != NULL )
   {
   
   	printf("\n Essas s�o suas informa��o");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
    system("pause");
}

int deletar()
{
    char cpf [40];
    printf("Digite o CPF do usuario ser deletado");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE*file;
    file = fopen(cpf,"r");
  
    if(file ==  NULL)
    {
     printf("O USUARIO N�O FOI ENCONTRADO NO SISTEMA!! TENTE NOVAMENTE!\n");
     system("pause");
     
	}
    
    
}	


int main()
{
	int opcao=0;//defindo as variaveis
	int laco=1;
	
  for(laco=1;laco=1;)
	{
	
  
     system("cls");
	setlocale(LC_ALL, "Portuguese");//defindo a linguagem
	
	printf("Cart�rio Do Banco Central\n\n");//inicio do menu
	printf("ESCOLHA A OP��O DESEJADA NO MENU!!\n\n");
	printf("\t1 - Qual o seu nome?\n");
	printf("\t2 - Registar seu nome\n");
	printf("\t3 - Deletar Nomes\n\n");
	printf("\t4 - Sair do Sistema");
	printf(" Op��o: \n\n");//fim do menu
	
	scanf("%d",&opcao);//armazenando a esolha do usuario
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1:
		 registro();
		 break;
		 
		case 2:
		consultar();
		break;
		
		case 3:	
		deletar();
        break;
        
        case 4:
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;
        
        default:
        printf("Essa op��o n�o � valida!\n ");
        system("pause");
        break;
    }
    
	
        
        
	}
	    
       
       


}






