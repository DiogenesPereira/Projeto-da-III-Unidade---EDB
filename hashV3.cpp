#include <iostream>
#include <ctime>

#define N 13

using namespace std;

struct Fila //Estrutura basica do jogo
{
	int cor;
	int rodada; // Usado para ter um valor com maior multação, pois assim a hash não dará tanto comflito.
	Fila* prox;
};

int has(int chave);
Fila busca_Hash(int* vetor, int chave);
int has2(int chave);
void print(Fila* vetor, int tam);

int main()
{
	srand(time(NULL));
	int tam = 10;
	int i = 0;
	int ind;
	int indice;
	bool loop;
	int laco = 0;
	char opc;
	Fila* Hash[N];//-------------------->> Vetor do tipo Fila

	Fila* inicio = NULL;
	Fila* fim = NULL;
	Fila* fila = NULL;

	do
	{
		Fila* novo = new Fila(); // alocando
		Fila* outro = new Fila(); // alocando
		novo->cor = rand() % 4+1;
		if (inicio == NULL)
		{
			inicio = novo;
			fim = novo;
			inicio->rodada = i; 
		}
		else
		{
			fim->prox = novo;
			fim = novo;
			fim->rodada = i;
		}
		
		
			cout << "----------------------------" << endl;
			cout << "| Cor ---- " << fim->cor << endl;
			cout << "| Rodada-- " << fim->rodada << endl;
			indice = has(fim->rodada);
			cout << "| indice :   " << indice << endl;
			//cout << "Elemento na Tabela HASH :   " << Hash[indice] << endl;
			cout << "---------------------------" << endl;
		

			
			if (i > 10)
			{
				if (Hash[indice]->cor == fim->cor)
				{
					outro = fim;
					outro->prox = Hash[indice];
					Hash[indice] = outro;

				}
				else
				{
					cout << "COR DIFERENTE" << endl;
					ind = has2(indice);
					
					while(laco != 1)
					{	
						if(fim->cor == Hash[ind]->cor)
						{
								outro = fim;
								outro->prox = Hash[ind];
								Hash[ind] = outro;
								laco = 1;
								cout << "----------------------------" << endl;
								cout << "Opa, e igual: " << ind << endl;
								cout << "----------------------------" << endl;
						}
						else
							if (Hash[ind]->cor != 1 and Hash[ind]->cor != 2 and Hash[ind]->cor != 3 and Hash[ind]->cor != 4)
							{
								Hash[ind] = fim;
								laco = 1;
							}else 
							if(Hash[ind]->cor != fim->cor)
							{
								ind = has2(ind);
								cout << "----------------------------" << endl;
								cout << "Novo Indice: " << ind << endl;
								cout << "----------------------------" << endl;
							}
					}
					cout << endl;
					cout << "---------------------------------------------" << endl;
					cout << "Elemento na Tabela HASH :   " << Hash[ind]->cor << endl;
					cout << "---------------------------------------------" << endl;
				}
			}
			else
				Hash[indice] = fim;
					

					cout << endl;
					cout << "---------------------------------------------" << endl;
					cout << "Elemento na Tabela HASH :   " << Hash[indice]->cor << endl;
					cout << "---------------------------------------------" << endl;


					i++;
					cout << "Dejesa inserir mais um elemento ?? (s/n)? " << endl;
              	
	            	cin >> opc;
	   				opc = tolower(opc);
					while(opc != 'n' and opc !='s')
					{
						cout << "Opção INVALIDA!!" << endl << "Dejesa continuar (s/n)? " << endl;
				        cin >> opc;
				        opc = tolower(opc);
			    	}
			    	if(opc=='n')
				        loop = false;
				    else
				    if(opc=='s')
		       		loop =  true;	       
	}while (loop != false);


	for (i = 0; i < N; ++i) //Função Print do vetor"!!!!!
	{
		fim = Hash[i];
		while(fim->prox != NULL){
			cout << "vetor na posição: " << indice << endl; 
			cout << Hash[i]->cor << endl;
			cout << Hash[i]->rodada << endl;
			fim = fim->prox;	
		}
		indice++;
	}

	return 0;
} 

int has(int chave)
{
	return chave % 11;
}
int has2(int chave)
{
	return chave % 11 + 1;
}

void print(Fila* vetor, int tam)
{
	while(tam != 0)
	{
		
	}
}
