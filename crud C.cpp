#include<stdio.h>

#include<stdlib.h>

#include<locale.h>

#include<string.h>

#include<conio.h>


#define MAX 50

#define QTD 10  //qtde max de clientes

int venda;


                                                        //Prototipos 

   

   

   void menuAtendente();

   int  menuProdutos();

   void compra();

   void menuCliente();

   void Clientes();

   void Produtos();

   void Vendas();

   void cadastroCliente();

   void mostrarCliente();

   void atualizarCliente();

   void deletarCliente();

   void cadastroProduto();

   void mostrarProduto();

   void atualizarProduto();

   void deletarProduto();

   void cadastroVenda();

   void mostrarVenda();

   void atualizarVenda();

   void deletarVenda();

   void login();

                                                        


                                                        // ESTRUTURAS


struct venda

{

        int cod_cli;

        char nome_cli;

        

}v_venda;


struct cliente

{

	char nome[50],sbnome[50];

	int dia,mes,ano;

	double cpf;

	char s[3];

	

} c_cliente;


struct produto

{

	int id,qtes;

	float preco;

	char nome_prod[20],editora[20],isbn[14];

}  p_produto;

                                                    //FUNCOES P/ FUNCIONARIOS

//Cadastrar Clientes	

void cadastroCliente(){

	char resp,r;

	c_cliente ;

	FILE*file;

	file = fopen("clientes.txt","ab");

	

	if(file == NULL){

		printf("Erro na abertura do arquivo.\n");

		exit(1);

	} else {

					do{

						system("cls");

						system("color F1");

						printf("\n-----------------CADASTRO-----------------\n");

						printf("#Insira o CPF:\n");

						scanf("%lf",&c_cliente.cpf);

						printf("#Nome do cliente:\n");

						scanf(" %s",&c_cliente.nome);					

						printf("#Sobrenome do cliente:\n");

						scanf(" %s",&c_cliente.sbnome);

					

						printf("#Insira a data de nascimento do cliente(dd/mm/aaaa):\n");

						scanf("%d/%d/%d",&c_cliente.dia, &c_cliente.mes, &c_cliente.ano);

							if(c_cliente.dia<0 || c_cliente.dia>31){

								printf("ERRO.Data inválida!\n");

								printf("Cadastre novamente.");

									return;

							}

								if(c_cliente.mes<1 || c_cliente.mes>12){

									printf("ERRO.Data inválida!\n");

									printf("Cadastre novamente.");

									return;

								}

									if(c_cliente.ano<1902 || c_cliente.ano>2022){

									printf("ERRO.Data inválida!\n");

									printf("Cadastre novamente.");

									return;

								}

						printf("#Insira o gênero (F - feminino, M - masculino, N - não desejo declarar):\n");

						scanf("%s",&c_cliente.s);

						fwrite(&c_cliente,sizeof(struct cliente),1,file);

						fflush(stdin);

						printf("Deseja realizar mais um cadastro?(s/n)\n");

						scanf(" %c", &resp);

					} while(resp!='n');

					printf("\nCadastro realizado com sucesso!");

						if(!fclose(file)){

								system("color F2");

								printf("\nFECHAR:Arquivo fechado com sucesso");

							} else{

								printf("\nErro ao fechar o arquivo\n");

							}

							printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

} 

//exit(0);

}// fim da funcao

	

//Listar Cliente

void mostrarCliente(){

	char r;

	c_cliente;

	FILE*file;

	file = fopen("clientes.txt","rb+");

	if(file==NULL)

	{

		printf("Erro na abertura do arquivo.\n");

		exit(1);

	} else {

			

			while(fread(&c_cliente,sizeof(struct cliente),1, file)==1){

				printf("color F1");

				printf("\n==================== CLIENTES REGISTRADOS ====================\n");

				printf("#Nome: %s\n",c_cliente.nome);			

				printf("#Sobrenome: %s\n",c_cliente.sbnome);

				printf("#CPF:%0.0lf\n",c_cliente.cpf);

				printf("#Data de Nascimento: %d/%d/%d\n",c_cliente.dia,c_cliente.mes,c_cliente.ano);

				printf("#Sexo: %s",c_cliente.s);

			}

}

	if(!fclose(file)){ //fechar arquivo

								system("color F2");

								printf("\n\nFECHAR:Arquivo fechado com sucesso");

							} else{

								printf("\nErro ao fechar o arquivo\n");

							}

							printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

								//exit(0);

}


// atualizar cliente

void atualizarCliente(){

	c_cliente;

	char nome[MAX];

	char r;

	int i=1,cod;

	FILE*file;

	file = fopen("trabalho.txt","rb+");

	if(file ==NULL){

		printf("Erro.\n");

		exit(1);

	} else{

		system("cls");

		system("color F1");

		printf("########## ALTERAÇÃO DE CADASTROS ##########\n\n");

		printf("Cadastros já realizados:\n\n");

			while(fread(&c_cliente, sizeof(struct cliente),1,file)==1){

				printf("#Nome do Cliente:%s\n",c_cliente.nome);

				printf("#Sobrenome do Cliente: %s\n",c_cliente.sbnome);

				printf("#Aniversário: %d/%d/%d\n",c_cliente.dia,c_cliente.mes,c_cliente.ano);

				printf("#Gênero: %s\n",c_cliente.s);

				i++;

				printf("CODIGO: %d",i);

				printf("\n#########################################\n");

			}

		printf("Digite o codigo do cliente que deseja alterar:\n");

		scanf("%d",&cod);

		getchar();

		cod--;


			if(cod >= 0 and cod <= i - 1){ // se o cod for maior q 0 e menor que a qtde de cadastros

				printf("#Novo nome:");

				gets(c_cliente.nome);

				printf("#Nova data de aniversário:\n");

				scanf("%d %d %d",&c_cliente.dia,&c_cliente.mes,&c_cliente.ano);

				printf("#Novo genero:\n");

				scanf("%s",&c_cliente.s);

				printf("\nOperação concluída com sucesso!");

				fseek(file, nome[50] * sizeof(struct cliente), SEEK_SET);

				fwrite(&c_cliente, sizeof(struct cliente), 1, file);

				fclose(file);

				exit(0);

			} else {

				system("color F4");

				printf("Cliente não encontrado. Tente novamente.");

				if(!fclose(file)){ //fechar arquivo

								//system("color F2");

								printf("\n\nFECHAR:Arquivo fechado com sucesso");

							} else{

								system("color F4");

								printf("\nErro ao fechar o arquivo\n");

							}

								//exit(0);

			}

			printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

	}

}


//deletar cliente                 //funcao problematica

void deletarCliente(){

	c_cliente;

	char nome[MAX];

	char r;

	int i = 1,cod;

	//int flag = 0;

	FILE*file,*auxiliar;

	file = fopen("trabalho.txt","rb+");

	auxiliar = fopen("auxiliar.txt","wb+");

	if((file = fopen("trabalho.txt","rb+"))==NULL){

		printf("Erro. Arquivo inexistente ou com problema para abrir\n");

		exit(1);

	} else {  //Aqui começa a funcao de vdd

		system("cls");

		system("color F4");

		printf("\n-----------------DELETAR CADASTROS-----------------\n");

		printf("Cadastros já realizados:\n\n");

			while(fread(&c_cliente, sizeof(struct cliente),1,file)==1){

				printf("#Nome do Cliente:%s\n",c_cliente.nome);

				printf("# Sobrenome: %s\n",c_cliente.sbnome);

				printf("#Aniversário: %d/%d/%d\n",c_cliente.dia,c_cliente.mes,c_cliente.ano);

				printf("#Gênero: %s\n",c_cliente.s);

				i++;

				printf("CODIGO: %d",i);

				printf("\n#########################################\n");

			}

		printf("#Escreva o sobrenome e o código do cliente a ser deletado:\n");

		scanf("%s",&nome);

		scanf("%d",&cod);

		

			while(fread(&c_cliente, sizeof(struct cliente),1,file)==1){

				fflush(stdin);	

					if(strcmp(nome,c_cliente.sbnome) and i == cod )

				{

					fwrite(&c_cliente,sizeof(struct cliente),1,auxiliar);

				} //else {

				//	if((strcmp(nome,c_cliente.sbnome)and i == cod)==0){

					//	flag == 1;

				//	}

			//	}

			}

	} //fim do 1 else

	if(ferror(auxiliar)){

		printf("Erro.Tente novamente\n");

	} else{

		//if(flag ==0){

			printf("Operação realizada com sucesso!");

		//}

	}

	fclose(file);

	fclose(auxiliar);

	remove("trabalho.txt");

	rename("auxiliar.txt","trabalho.txt");

	printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

//	exit(0);


}


//MENU GERAL CLIENTES

void Clientes(){

int opcao;

char c_cliente[MAX] = ("trabalho.txt");


	system("cls");

	system("color F1");

	printf("--------------------------------------\n");

	printf("---------------CLIENTES---------------\n");

	printf("--------------------------------------\n");

	

	

	printf("\n1.CADASTRAR");

	printf("\n2.LISTAR Clientes");

	printf("\n3.ATUALZAR Registros");

	printf("\n4.EXCLUIR Registros");

	printf("\n5.SAIR");

	printf("\n\nOperação a ser realizada:\n");

	scanf("%d",&opcao);

		do{

			switch(opcao){

				case 1: cadastroCliente();

					break;

				case 2: mostrarCliente();

					break;

				case 3: atualizarCliente();

					break;

				case 4: deletarCliente();

					break;

				default: printf("Operação terminada.\n");

					exit(0);			

			}

		}while(opcao!=5);

	

}


//Cadastrar Produtos

void cadastroProduto(){

	setlocale(LC_ALL,"Portuguese");

	char resp,r;

	p_produto;

	FILE*filep;

	filep = fopen("produto.txt","ab");

	

	if(filep == NULL){

		printf("Erro na abertura do arquivo.\n");

		exit(1);

	} else {

					do{

						system("cls");

						system("color F5");

						printf("\n%%%%%%%%%%%% CADASTRO %%%%%%%%%%%%\n");

						printf("# Nome do Livro:\n");

						scanf(" %[^\n]s",&p_produto.nome_prod);

						printf("# Editora:\n");

						scanf(" %[^\n]s",&p_produto.editora);

						printf("# ISBN do Livro: (O ISBN tem 13 dígitos)\n");

						scanf(" %s",&p_produto.isbn);

						printf("# Código do produto:\n");

						scanf("%d",&p_produto.id);

						printf(" # Quantidade no ESTOQUE:\n");

						scanf("%d",&p_produto.qtes);

							int tam = strlen(p_produto.isbn);

							if(tam>13){

								printf("ERRO.ISBN inválido!\n");

								printf("Cadastre novamente.");

								exit(1);

								}

						printf("# Preço do Livro:\n");

						scanf(" %f",&p_produto.preco);

						fwrite(&p_produto,sizeof(struct produto),1,filep);

						fflush(stdin);

						printf("Deseja realizar mais um cadastro?(s/n)\n");

						scanf(" %c", &resp);

					} while(resp!='n');

					printf("\nCadastro realizado com sucesso!");

						if(!fclose(filep)){

								system("color F2");

								printf("\nFECHAR:Arquivo fechado com sucesso");

							} else{

								printf("\nErro ao fechar o arquivo\n");

							}

							printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}	

} 

exit(0);

}


//Listar Produtos

 void mostrarProduto(){

	p_produto;

	char r;

	FILE*filep;

	filep = fopen("produto.txt","rb+");

	if(filep==NULL)

	{

		printf("Erro na abertura do arquivo.\n");

		exit(1);

	} else {

			

			while(fread(&p_produto,sizeof(struct produto),1, filep)==1){

				printf("\n==================== PRODUTOS REGISTRADOS ====================\n");

				printf("# Título: %s\n",p_produto.nome_prod);

				printf("# Editora: %s\n",p_produto.editora);

				printf("# ISBN: %s\n",p_produto.isbn);

				printf("# Preço: %0.2f\n",p_produto.preco);

				printf(" # Quantidade no ESTOQUE: %d\n",p_produto.qtes);

			}

}

			if(!fclose(filep)){ //fechar arquivo

								system("color F2");

								printf("\n\nFECHAR:Arquivo fechado com sucesso");

							} else{

								printf("\nErro ao fechar o arquivo\n");

							}

							printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

								//exit(0);

}


//Atualizar Produtos

void atualizarProduto(){

	p_produto;

	char nomep[MAX];

	char r;

	int i=1,cod;

	FILE*filep;

	filep = fopen("produto.txt","rb+");

	if(filep ==NULL){

		printf("Erro.\n");

		exit(1);

	} else{

		system("cls");

		system("color F5");

		printf("########## ALTERAÇÃO DE CADASTROS ##########\n\n");

		printf("Cadastros já realizados:\n\n");

			while(fread(&p_produto, sizeof(struct produto),1,filep)==1){

				printf("# Título:%s\n",p_produto.nome_prod);

				printf("# Editora: %s\n",p_produto.editora);

				printf("# ISBN: %s\n",p_produto.isbn);

				printf("# Preço:%f\n",p_produto.preco);

				printf("# Quantidade no ESTOQUE: %d\n",p_produto.qtes);

				i++;

				printf("\nCODIGO: %d",i);

				printf("\n#########################################\n");

			}

		printf("Digite o codigo do produto que deseja alterar:\n");

		scanf("%d",&cod);

		getchar();

		cod--;


			if(cod >= 0 and cod < i - 1){ // se o cod for maior q 0 e menor que a qtde de cadastros

				printf("#Novo Título:");

				gets(p_produto.nome_prod);

				printf("#Nova editora:\n");

				gets(p_produto.editora);

				printf("#Novo ISBN:\n");

				gets(p_produto.isbn);

				printf("# Novo preço:\n");

				scanf("%f",&p_produto.preco);

				printf("\nOperação concluída com sucesso!");

				fseek(filep, nomep[MAX]* sizeof(struct produto), SEEK_SET);

				fwrite(&p_produto, sizeof(struct produto), 1, filep);

				fclose(filep);

				exit(0);

			} else {

				system("color F4");

				printf("Produto não encontrado. Tente novamente.");

				if(!fclose(filep)){ //fechar arquivo

								//system("color F2");

								printf("\n\nFECHAR:Arquivo fechado com sucesso");

							} else{

								system("color F4");

								printf("\nErro ao fechar o arquivo\n");

							}

							//	exit(0);

			}

			printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

	}

}


//Deletar Produtos

void deletarProduto(){

	p_produto;

	char nomep[MAX];

	char r;

	int i = 1,cod;

	FILE*filep,*auxiliar;

	filep = fopen("produto.txt","rb+");

	auxiliar = fopen("auxiliar.txt","wb+");

	if((filep = fopen("produto.txt","rb+"))==NULL){

		printf("Erro. Arquivo inexistente ou com problema para abrir\n");

		exit(1);

	} else {  //Aqui começa a funcao de vdd

		system("cls");

		system("color F4");

		printf("\n-----------------DELETAR CADASTROS-----------------\n");

		printf("Cadastros já realizados:\n\n");

			while(fread(&p_produto, sizeof(struct produto),1,filep)==1){

				printf("# Título do livro:%s\n",p_produto.nome_prod);

				printf("# Editora: %s\n",p_produto.editora);

				printf("# ISBN: %s\n",p_produto.isbn);

				printf("# Preço: %.2f\n",p_produto.preco);

			//	printf("# Código do Produto: %d\n",p_produto.id);

				i++;

				printf("CODIGO: %d",i);

				printf("\n#########################################\n");

			}

		printf("#Escreva o código do livro a ser deletado:\n");

		//scanf("%s",&nome);

		scanf("%d",&cod);

		

			while(fread(&p_produto, sizeof(struct produto),1,filep)==1){

				fflush(stdin);	

					if( i == cod )

				{

					fwrite(&p_produto,sizeof(struct produto),1,auxiliar);

				} else {

						printf("\nNão foi possível realizar a operação.");

					}

			}//fim do while

	} //fim do 1 else

	if(ferror(auxiliar)){

		printf("Erro.Tente novamente\n");

	} else{

		//if(flag ==0){

			printf("Operação realizada com sucesso!");

		//}

	}

	fclose(filep);

	fclose(auxiliar);

	remove("trabalho.txt");

	rename("auxiliar.txt","trabalho.txt");

	printf("\nDeseja voltar ao MENU PRINCIPAL para Atendentes?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL ATENDENTES\n");

									menuAtendente();

								} else{

									exit(0);

								}

//	exit(0);


}

//MENU GERAL PRODUTOS

void Produtos(){

	int opcao;

	char p_produto[MAX] = ("produto.txt");


	system("cls");

	system("color F1");

	printf("--------------------------------------\n");

	printf("---------------LIVROS---------------\n");

	printf("--------------------------------------\n");

	

	

	printf("\n1.CADASTRAR LIVROS");

	printf("\n2.LISTAR LIVROS");

	printf("\n3.ATUALIZAR LIVROS");

	printf("\n4.EXCLUIR LIVROS");

	printf("\n5.SAIR");

	printf("\n\nOperação a ser realizada:\n");

	scanf("%d",&opcao);

		do{

			switch(opcao){

				case 1: cadastroProduto();

					break;

				case 2: mostrarProduto();

					break;

				case 3: atualizarProduto();

					break;

				case 4: deletarProduto();

					break;

				default: printf("Opção inválida.Operação terminada.\n");

					exit(0);			

			}

		}while(opcao!=5);

}


//Cadastro Venda                   // resolver amanha

void cadastroVenda(){

	setlocale(LC_ALL,"Portuguese");

	

	char resp, nomep[MAX],r;

	int qtde, i=0,id;

	float total;

	double cpf;

	p_produto;

	v_venda;

	c_cliente;

	FILE*filec;

	filec=fopen("clientes.txt","ab");

	FILE*filep;

	filep = fopen("produto.txt","rb+");

	FILE*filev;

	filev = fopen("venda.txt","ab");

	

	if(filev == NULL){

		printf("Erro na abertura do arquivo.\n");

		exit(1);

	} else {system("cls");

					do{

						

						system("color F5");

						printf("\n%%%%%%%%%%%% CADASTRAR VENDAS  %%%%%%%%%%%%\n");

						printf("# Nome do cliente:\n");

						scanf(" %s",&c_cliente.nome);

						printf("# Sobrenome do cliente:\n");

						scanf(" %s",&c_cliente.sbnome);

						printf("CPF do cliente\n");

						scanf("%lf",&c_cliente.cpf);

						while(fread(&p_produto,sizeof(struct produto),1, filep)==1 and i<=p_produto.id){

				printf("\n==================== PRODUTOS REGISTRADOS ====================\n");

				printf("# Título: %s\n",p_produto.nome_prod);

				printf("# Editora: %s\n",p_produto.editora);

				printf("# ISBN: %s\n",p_produto.isbn);

				printf("# Preço: %.2f\n",p_produto.preco);

				printf("# Quantidade no ESTOQUE: %d\n",p_produto.qtes);

				printf("# Código do Produto: %d\n",p_produto.id);

			

				i++;

			}

			printf("---------------------------------------\n");

			printf("-----------------CAIXA-----------------\n");

			printf("---------------------------------------\n");

			printf("\nBem Vindo! Qual o nome do livro você deseja comprar?\n");

			fflush(stdin);

			gets(nomep);

			printf("Codigo do livro:\n");

			scanf(" %d",&id);

			id--;

			fseek(filep, id* sizeof(struct produto), SEEK_SET);

			fread(&p_produto, sizeof(struct produto),1,filep);

	

			

				if(id>=0 && id<i){

					printf("\nQuantas unidades desse livro voce quer?");

					scanf("%d",&qtde);

					if(qtde<= p_produto.qtes){					

						total = p_produto.preco * qtde;						

						printf("Total da compra: = R$%.2f\n", total);

						fseek(filep,id* sizeof(struct produto),SEEK_SET);

						fseek(filec,cpf* sizeof(struct cliente),SEEK_SET);

						p_produto.qtes = p_produto.qtes - qtde;

						fwrite(&v_venda, sizeof(struct venda),1,filev);

						fwrite(&c_cliente, sizeof(struct cliente),1,filev);

						fwrite(&p_produto, sizeof(struct produto),1,filev);

						fwrite(&p_produto, sizeof(struct produto),1,filep);

						fclose(filep);

					

					} //fim do if de estoque

						else{

						system("color F3");					

						printf("Erro. Livro em falta no estoque. Escolha outro livro ou diminua a quantidade escolhida.");

						exit(1);

					}

			} // fim do if

			 else{

			 

				printf("Não temos o livro que você procura! Verifique se você digitou o índice correto ou contate um funcionáro\n");

				exit(0);

		}			

				printf("\nOperação realizada com sucesso!Volte logo!");

				printf("\nDeseja realizar mais um pedido? (s/n)");	

				 	scanf(" %c",&resp);

			}

						while(resp != 'n');

	

			fclose(filep);	

					 		

}		

			printf("\nDeseja voltar ao MENU ATENDENTES?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL\n");

									menuAtendente();

								} else{

									printf("\nOperação encerrada.");

									exit(0);

								}			

		

}

						


//Listar Venda

void mostrarVenda(){

	int i=0, x=0, id;

	double cpf;

	char resp,r;

	p_produto;

	c_cliente;

	v_venda;

	FILE*venda;

	venda=fopen("venda.txt","ab");

	system("cls");

	system("color F2");

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

	printf("-----------VENDAS CADASTRADAS-----------\n");

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");

	printf("Digite o Cpf do Cliente:\n");

	scanf("%lf",&cpf);

		fseek(venda, cpf* sizeof(struct cliente), SEEK_SET);

		fread(&c_cliente, sizeof(struct cliente),1,venda);

		if(cpf=c_cliente.cpf){

		

		

		while(fread(&c_cliente,sizeof(struct cliente),1, venda)==1 ){

	printf("#Nome do Cliente:\n%s\n",c_cliente.nome);

	printf("#CPF do Cliente:\n%0.0lf\n",c_cliente.cpf);

	printf("#Produtos comprados:\n");

	do{

		while(fread(&p_produto,sizeof(struct produto),1, venda)==1 and i<=p_produto.id){

				printf("\n==================== PRODUTOS ====================\n");

				printf("# Título: %s\n",p_produto.nome_prod);

				printf("# Código do Produto: %d\n",p_produto.id);

			

				i++;}	printf("\nDeseja voltar ao MENU PARA ATENDENTES?");				

				scanf(" %c",&resp);

				}		while(resp != 's');

					menuAtendente();

			fclose(venda);	

			}

		}

				

		else{

			printf("CPF não cadastrado");

		}		

		exit(0);	 		

		

}



//MENU VENDAS P/ CRUD

void Vendas(){

	int opcao;

	char v_venda[MAX] = ("venda.txt");


	system("cls");

	system("color F2");

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

	printf("---------------VENDAS---------------\n");

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

	printf("\n1.CADASTRAR VENDAS");

	printf("\n2.LISTAR VENDAS");

	printf("\n3.ATUALIZAR VENDAS");

	printf("\n4.EXCLUIR VENDAS");

	printf("\n5.SAIR");

	printf("\n\nOperação a ser realizada:\n");

	scanf("%d",&opcao);

		do{

			switch(opcao){

				case 1: cadastroVenda();

					break;

				case 2: mostrarVenda();

					break;

			//	case 3: atualizarVenda();

				//	break;

			//	case 4: deletarVenda();

				//	break;

				default: printf("Opção inválida.Operação terminada.\n");

					exit(0);			

			}

		}while(opcao!=5);	

}


//MENU ATENDENTE GERAL

void menuAtendente()

{

	int opcao;

	system("cls");

	printf("==================MENU===================\n");

	printf("----------------Atendente-----------------\n");

	printf("Instruções de uso:\n\n 1-Cadastre os livros para torná-los disponíveis para venda.");

	printf("\n 2-Lembre-se de cadastrar os Clientes!\n ");

	

	printf("\n1.CLIENTES");

	printf("\n2.LIVROS");

	printf("\n3.VENDAS");

	printf("\n4.SAIR\n");

	

	printf("Selecione uma opção para navegar:\n");

	scanf("%d",&opcao);

		do{

			switch(opcao){

				case 1: Clientes();

				break;

				case 2: Produtos();

				break;

				case 3: Vendas();

				break;

				default: printf("Opção inválida.Operação encerrada");

					exit(0);

			}

		}while(opcao!=4);

	

}



                                        //Codigo relativo aos Clientes --Tudo certo aqui!

//Menu para os clientes

 int menuProdutos()

{

	char r;

	p_produto;

	system("cls");

	printf("\t-----------------LivrariaDaTravessa---------------------\n");

	printf("\t-----------------------Classicos-------------------------\n");

	printf("\t-----------------------Catálogo-------------------------\n");

	mostrarProduto(); // vai pegar os produtos cadastrados e mostrar

	printf("\nVoce deseja realizar uma compra?\n");

	scanf("%c",&r);

		switch(r){

			case 's': compra();

			break;

			case 'n':

				printf("\nOperação encerrada");

				 exit(0);

			break;	

			default: printf("\nVoce escolheu sair");

				return 0;

		}

	return 0;

		

}


void compra()  

{

	char resp,r;

	char nomep[MAX];

	int qtde, id,i=0;

	float preco,total;

	p_produto;

	FILE*filep;

	filep = fopen("produto.txt","rb+");

		if(filep == NULL){

			printf("Erro ao abrir o arquivo!");

		} 

		else{	

		system("cls");

			do{

				while(fread(&p_produto,sizeof(struct produto),1, filep)==1 and i<=p_produto.id){

				printf("\n==================== PRODUTOS REGISTRADOS ====================\n");

				printf("# Título: %s\n",p_produto.nome_prod);

				printf("# Editora: %s\n",p_produto.editora);

				printf("# ISBN: %s\n",p_produto.isbn);

				printf("# Preço: %.2f\n",p_produto.preco);

				printf("# Quantidade no ESTOQUE: %d\n",p_produto.qtes);

				printf("# Código do Produto: %d\n",p_produto.id);

			

				i++;

			}

			printf("---------------------------------------\n");

			printf("-----------------CAIXA-----------------\n");

			printf("---------------------------------------\n");

			printf("\nBem Vindo! Qual o nome do livro você deseja comprar?\n");

			fflush(stdin);

			gets(nomep);

			printf("Codigo do livro:\n");

			scanf(" %d",&id);

			id--;

			fseek(filep, id* sizeof(struct produto), SEEK_SET);

			fread(&p_produto, sizeof(struct produto),1,filep);

	

			

				if(id>=0 && id<i){

					printf("\nQuantas unidades desse livro voce quer?");

					scanf("%d",&qtde);

					if(qtde<= p_produto.qtes){					

						total = p_produto.preco * qtde;						

						printf("Total da compra: = R$%.2f\n", total);

						fseek(filep,id* sizeof(struct produto),SEEK_SET);

						p_produto.qtes = p_produto.qtes - qtde;

						fwrite(&p_produto, sizeof(struct produto),1,filep);

						fclose(filep);

					

					} //fim do if de estoque

						else{

						system("color F3");					

						printf("Erro. Livro em falta no estoque. Escolha outro livro ou diminua a quantidade escolhida.");

						exit(1);

					}

			} // fim do if

			 else{

			 

				printf("Não temos o livro que você procura! Verifique se você digitou o índice correto ou contate um funcionáro\n");

				exit(0);

		}			

				printf("\nOperação realizada com sucesso!Volte logo!");

				printf("\nDeseja realizar mais um pedido? (s/n)");	

				 	scanf(" %c",&resp);

			}

						while(resp != 'n');

	

			fclose(filep);	

					 		

}		

			printf("\nDeseja voltar ao MENU PRINCIPAL CLIENTES?");

							scanf(" %c",&r);

								if(r == 's' or r == 'S'){

									printf("Você será redirecionado para o MENU PRINCIPAL\n");

									menuCliente();

								} else{

									printf("\nOperação encerrada.");

									exit(0);

								}			

		

}

		

//Menu principal para os Clientes


void menuCliente(){

	int opcao;

	system("cls");

	printf("\t\t\t\t\tBem Vindo(a) ao Menu dos Clientes!\n");

	printf("\t\t\t\t--------------------------------------------\n");

	printf("\t\t\t\t\t\tVocê deseja:\n");

	printf("\t\t\t\t--------------------------------------------\n");

	printf("\t\t\t\t1. Ver produtos \n");

	printf("\t\t\t\t2. Comprar \n");

	printf("\t\t\t\t3. Sair\n");

	printf("\t\t\t\t--------------------------------------------\n");

	printf("Opção:\n");

	scanf("%d",&opcao);

		do{

			switch(opcao){

			case 1: 

				menuProdutos();

			break;

			case 2: 

				compra();

			break;

			case 3:

				exit(0);

			break;	

			default: printf("Escolha uma das opções acima!");

		}

		} while(opcao!=3);

}

                                                                     //MAIN


main(){

	int opcao,qtde,total,resp,cond,operacao;

	cliente c[MAX];

	setlocale(LC_ALL,"Portuguese");

	

	system("color F0");

	printf("\t\t\t\t\tBem vindo à Livraria Travessa!\n");

	printf("\t\t\t\t--------------------------------------------\n");

	printf("\t\t\t\t\t\tVocê é:\n");

	printf("\t\t\t\t--------------------------------------------\n");

	printf("\t\t\t\t1. Cliente \n");

	printf("\t\t\t\t2. Atendente \n");

	printf("\t\t\t\t3. Sair\n");

	printf("\t\t\t\t--------------------------------------------\n");

	scanf("%d",&cond);

		do{

		switch(cond){

			case 1:

			system("cls");

			system("color F1");

			login();

			break;

			case 2: 

			system("cls");

			system("color F1");

			fflush(stdin);

			menuAtendente();

			printf("Digite o número da operação a ser realizada:\n");

			scanf(" %d",&operacao);

			break;

		}

	} while (cond !=3);

}

void login(){

	FILE*login;

	login = fopen("clientes.txt","ab");

	c_cliente:

	char cpf,resp;	

	fseek(login, cpf* sizeof(struct cliente), SEEK_SET);

			fread(&c_cliente, sizeof(struct cliente),1,login);

		if(login==NULL){

			printf("Erro ao acessar Banco de dados");

		}

	

		else{

			system("cls");

			do{ 

			printf("Digite seu CPF( sem pontos):\n");

			scanf("%lf",&cpf);

		

				if(cpf==c_cliente.cpf){

					menuCliente();

					

				}

				else{

					printf("Nome incorreto. Deseja tentar novamente?");

					scanf("%c",&resp);

				

				}

			}

			

			while(resp!='s');

		

	exit(0);

}
}

