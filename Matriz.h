#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>
using std::string;



class Matriz{
	private:
		string nombre;
		int** matriz;
		int det;
		int size;
	public:
		Matriz();
		Matriz(string, int**, int);
		void determinante();
		Matriz operator|(Matriz);
		int** getMatriz();
		void setMatriz(int**);
		//~Matriz();
	
};
#endif