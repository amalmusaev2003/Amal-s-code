/*Вариант-6.
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть еще один элемент, равный ее максимальному элементу, 
упорядочить строки матрицы по невозрастанию количества простых чисел среди элементов строк.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;
void Read(int i, int j, int mas[100][100])
{ 
    for (int k = 0; k < i; k++)
    {
        for (int m = 0; m < j; m++)
        {
            mas[k][m] = rand() % 100 + 1;
           
        }
    }
}

void Write(int i, int j, int mas[100][100])
{
    ofstream out("out.txt");
    for (int k = 0; k < i; k++)
    {
        for (int m = 0; m < j; m++)
        {
            cout << mas[k][m] << " ";
            out << mas[k][m] << " ";

        }
        cout << endl;
        out << endl;
    }
    out.close();
}

int MAX(int& maxx,int i, int j, int mas[100][100])
{
    for (int k = 0; k < i; k++)
    {
        for (int m = 0; m < j; m++)
        {
            if (maxx < mas[k][m])
            {
                maxx = mas[k][m];
            }
        }
    }
    cout << "Максимальное - " << maxx << endl;
    return maxx;
}

bool KolMAX(int maxx, int i, int j, int mas[100][100])//количество максимальных чисел
{
    int count = 0;
    for (int k = 0; k < i; k++)
    {
        for (int m = 0; m < j; m++)
        {
            if (mas[k][m]== maxx)
            {
                count++;
            }
        }
    }
    cout << "Найдено " << count << " максимальных чисел" << endl;
    if (count > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Prostoe(int n)
{
    int x=0;//количество делителей
    if (n == 2 || n == 3)
    {
        return true;
    }
    for (int d = 2; d <= sqrt(n); d++)
    {
        if (n % d == 0)
        {
            x++;
        }
    }
    if (x > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int ProstvStr(int i, int j, int mas[100][100],int kolvo[100])//количество простых в строках
{
    int count=0;

    for (int k = 0; k < i; k++)
    {
        
        for (int m = 0; m < j; m++)
        {
            if (Prostoe(mas[k][m]))
            {
                count++;
            }
        }
        kolvo[k] = count;    
        cout << "В " << k+1 << " строке - " << count << " простых" << endl;
        count = 0;
    }
    return kolvo[100];
}

void Sort(int k, int m, int mas[100][100],int kolvo[100])
{
    int x;
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (kolvo[i] < kolvo[j])
            {  
                swap(kolvo[i], kolvo[j]);
                swap(mas[i], mas[j]);
            }
            else if (kolvo[i] == kolvo[j])
            {
                continue;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int i = rand() % 100 + 1;
    int j = rand() % 100 + 1;
    int s[100][100];
    int maxx=0;
    int kolvo[100];
    Read(i, j, s);
    MAX(maxx,i, j, s);
    if (KolMAX(maxx,i, j, s))
    {
        ProstvStr(i, j, s, kolvo);
        Sort(i, j, s, kolvo);
        Write(i, j, s);
    }
    else
    {
        cout << "Лишь один максимум: Не судьба" << endl;
    } 
}
