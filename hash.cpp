#include <iostream>
#include <ctime>

#define N 128

using namespace std;

struct Fila //Estrutura basica do jogo
{
	int cor;
	int rodada; // Usado para ter um valor com maior multação, pois assim a hash não dará tanto comflito.
	Fila* prox;
};

int has(int chave);
Fila busca_Hash(int* vetor, int chave);

int main()
{
	srand(time(NULL));
	int tam = 10;
	int i = 1;
	int indice;
	bool loop;
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
		
		
		
			cout << "Cor ---- " << fim->cor << endl;
			cout << "Rodada-- " << fim->rodada << endl;
			indice = has(fim->rodada);
			cout << "indice :   " << indice << endl;
			cout << "Elemento na Tabela HASH :   " << Hash[indice] << endl;
		

//			indice = has(fim->rodada);
			fila = Hash[indice];
			while(Hash[indice] != NULL)
			{
				if(fila->cor == fim->cor)
					break;
				fila = fila->prox;
			}
			if (fila == NULL)
			{
				
				outro->cor = fim->cor;
				outro->prox = Hash[indice];
				Hash[indice] = fila;
			}

					cout << endl;
					cout << "---------------------------------------------" << endl;
					cout << "Elemento na Tabela HASH :   " << Hash[indice] << endl;
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

	return 0;
} 

int has(int chave)
{
	return chave % 7;
}