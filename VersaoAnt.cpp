#include <iostream>
#include <ctime>

using namespace std;

struct Fila //Estrutura basica do jogo
{
	int cor;
	int rodada; // Usado para ter um valor com maior multação, pois assim a hash não dará tanto comflito.
	Fila* prox;
};

int Hash(int chave);
Fila busca_Hash(int* vetor, int chave);

int main()
{
	srand(time(NULL));
	int tam = 10;
	int i = 1;
	int indice;
	bool loop;
	char opc;


	Fila* inicio = NULL;
	Fila* fim = NULL;
	int* vetor = NULL;

	do
	{
		vetor = new (nothrow) int[tam];
		Fila* novo = new Fila(); // alocando
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
		indice = Hash(fim->rodada);
		cout << "Elemento na Tabela HASH :   " << vetor[indice] << endl;
		

			if(vetor[indice] == 0)		
			{
				vetor[indice] = fim->cor;
			}
			else
				if(fim->cor == vetor[indice]) 
				{
					tam*=2;
					cout << tam << endl;
				}




		cout << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Elemento na Tabela HASH :   " << vetor[indice] << endl;
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

int Hash(int chave)
{
	return chave % 7;
}
