/*
	Michał Słomiany
	Rzeszów 2020
	github.com/MSlomiany
*/

#include<iostream>
#include<fstream>
#include<thread>
using namespace std;


/*
	Funkcja obliczająca średnią arytmetyczną
*/
void calcMean(int array[], int counter, int* result)
{
	*result = 0;
	unsigned long sum = 0;		//na wszelki wypadek
	for (int i = 0; i < counter; i++)
	{
		sum += array[i];
	}
	*result = sum / counter;	//można użyć liczby zmiennoprzecinkowej
}

/*
	Funkcja znajdująca medianę
	Sortowanie bąbelkowe :<
*/
void calcMedian(int array[], int counter, int* result)
{
	//Cześć sortująca
	int swap;
	do
	{
		int temp;
		swap = 0;
		for (int i = 0; i < counter - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap++;
			}
		}
	} while (swap != 0);
	//Część szukająca mediany
	int center;
	int median;
	if (counter % 2 == 0)
	{
		center = counter / 2;
		median = array[(counter / 2) - 1] + array[(counter / 2)];
		*result = median / 2;
	}
	else
	{
		*result = array[(counter % 2)];
	}
}

int main()
{
	/*
		Wczytywanie danych z pliku txt
	*/
	ifstream file("dane.txt");

	int counter = 0;
	int buffer;

	int valueArray[10000];

	while (file >> buffer)
	{
		valueArray[counter] = buffer;
		counter++;
	}

	/*
		tworzenie wątków obliczeniowych
	*/
	int mean;
	int median;

	thread firstThread(calcMean, valueArray, counter, &mean);
	thread secondThread(calcMedian, valueArray, counter, &median);

	//Synchronizacja wątków
	firstThread.join();
	secondThread.join();

	//Porównanie wartości
	cout << mean << endl;
	cout << median << endl;

	system("PAUSE");
	return 0;
}
