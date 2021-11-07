#include <iostream>
#include <string>
#include <cstdlib>
void clear()
{
	system("clear");
}
void getInput(long long int(&Numero)[1000], int& Cantidad)
{
	std::cout << "Escribe los numeros (Escribe \"done\" antes de \nNumero):\n";
	long long int temp;
	for (int count{ 0 }; ; count++)
	{
		std::cin >> temp;
		if (std::cin.fail())
		{
			break;
		}
		else
		{
			Numero[count] = temp;
		}
		Cantidad++;
	}
}
void Numeros(long long int(&Numero)[1000], const int& Cantidad)
{
	long long int temp;
	int count{ Cantidad - 1 };
	for (int adj{ 0 }; adj < (count + 1); adj++)
	{
		for (int adj2{ 0 }; adj2 < count; adj2++)
		{
			if (Numero[adj2] > Numero[adj2 + 1])
			{
				temp = Numero[adj2];
				Numero[adj2] = Numero[adj2 + 1];
				Numero[adj2 + 1] = temp;
			}
		}
	}
}
void printpromedio(const long long int(&Numero)[1000], const int& Cantidad, long long int& vpromedio)
{
	for (int count{ 0 }; count < Cantidad; count++)
	{
		vpromedio += Numero[count];
	}
	vpromedio /= Cantidad;
	std::cout << "Promedio: " << vpromedio << '\n';
}
void printMediana(const long long int(&Numero)[1000], const int& Cantidad, long long int& vmediana)
{
	int count{ Cantidad / 2 };
	if (Cantidad % 2 == 0)
	{
		std::cout << "Mediana:	Entre " << Numero[count - 1] << " & " << Numero[count] << '\n';
	}
	else
	{
		vmediana = Numero[count];
		std::cout << "Mediana: " << vmediana << '\n';
	}
}
void Moda(long long int(&Numero)[1000], int(&count)[1000], const int& Cantidad)
{
	for (int count1{ 0 }; count1 < Cantidad; count1++)
	{
		count[count1] = 0;
	}
	for (int count2{ 0 }; count2 < Cantidad; count2++)
	{
		for (int count3{ 0 }; count3 < Cantidad; count3++)
		{
			if (Numero[count2] == Numero[count3])
			{
				count[count2]++;
			}
		}
	}
	long long int temp;
	int count_{ Cantidad - 1 };
	for (int adj{ 0 }; adj < (count_ + 1); adj++)
	{
		for (int adj2{ 0 }; adj2 < count_; adj2++)
		{
			if (count[adj2] > count[adj2 + 1])
			{
				temp = count[adj2];
				count[adj2] = count[adj + 1];
				count[adj + 1] = temp;
				temp = Numero[adj2];
				Numero[adj2] = Numero[adj2 + 1];
				Numero[adj2 + 1] = temp;
			}
		}
	}
}
void printModa(long long int(&Numero)[1000], int(&count)[1000], const int& Cantidad, long long int& mode)
{
	mode = Numero[Cantidad - 1];
	std::cout << "Moda: " << mode << '\n';
}
void printRango(const long long int(&Numero)[1000], const int& Cantidad, long long int& range)
{
	range = Numero[Cantidad - 1] - Numero[0];
	std::cout << "Rango: " << range << '\n';
}
int main()
{
	long long int Numero[1000];
	int count[1000];
	int Cantidad{ 0 };
	long long int average{ 0 }, mediana, moda, rango;
	{
		getInput(Numero, Cantidad);
		Numeros(Numero, Cantidad);
		printpromedio(Numero, Cantidad, average);
		printMediana(Numero, Cantidad, mediana);
		printRango(Numero, Cantidad, rango);
		Moda(Numero, count, Cantidad);
		printModa(Numero, count, Cantidad, moda);
	} 
}
