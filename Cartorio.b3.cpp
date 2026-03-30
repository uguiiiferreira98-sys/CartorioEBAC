#include <stdio.h> //biblioteca de comunicaçãop com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar dos strings


int registro()//Função responsavel por casastrar usuários do sistema


{
	//inicio da criação de variáveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criação de variáveis/string
   
   printf("Digite o CPF a ser cadastrado ");
   scanf("%s", cpf);//%s refere-se a string
   
   strcpy(arquivo, cpf);// Responsável por copiar valores das string
   
   FILE *file;// cria o arquivo
   file = fopen(arquivo, "w");// cria a pasta e o 'w" significa escrever
   fprintf(file,cpf);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   printf("Digire o sobrenome a ser cadastrado ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo ,"a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
}


int consulta()


{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);

	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPf do usuário a ser excluido: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
    {
    	printf("CPF não encontrado! \n");
    }
    	system("pause");
    	
    	
}

int main()
{   

	int opcao=0;//Definido variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		
	  printf("###Cartório da EBAC###\n\n");//inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Resgistrar nome\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("Opção: ");//fim do menu
	
      scanf("%d", &opcao);// armazenado a escolha do usuário
    
	 
	  system("cls");// responsável por limpar a tela
	  
	  
	  
	  switch(opcao)// inicio da seleção do menu
	  { 
	     case 1:
	     registro();// chamada de funções
	     break;
	         
	     case 2:
	     consulta();
         break;
         
         case 3:
         deletar();
		 break;
		 
		 	
		 default:
		 printf("Essa opcao não está disponivel\n");
		 system("pause");
		 break;
	  } //fim da seleção
	
	 
	  
    }
    
}
	
	
	  

	  


