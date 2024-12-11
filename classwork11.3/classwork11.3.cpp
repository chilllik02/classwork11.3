#include <locale.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int size_arr = 5;
const int size_arr2 = 10;

void create_array(int* arr, int size_arr);
void combine_arrays(int* arr1, int* arr2, int size1,int size2, int* arr_combine);
void print_array(int* arr,int size);
int compare(const void* x1, const void* x2);


int main()
{
    setlocale(LC_ALL, "ru");
    /*srand(time(NULL));*/

    int array1[size_arr];
    int array2[size_arr2];

    create_array(array1, size_arr);
    create_array(array2, size_arr2);
    
    int array3[size_arr + size_arr2];
    combine_arrays(array1, array2, size_arr, size_arr2, array3);
    print_array(array3,size_arr+size_arr2);

    qsort(array3, 15, sizeof(int), compare);
    for (int i = 0; i < 15; i++)
    {
        cout << array3[i] << "\t";
    }
    
}

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

void create_array(int* arr, int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " \t";
    }
    cout << endl;
}
void combine_arrays(int* arr1, int* arr2, int size1, int size2,int* arr_combine)
{
    for (int i = 0; i < size1; i++)
    {
        arr_combine[i] = arr1[i];

    }
    for (int i = 0; i < size2; i++)
    {
        arr_combine[i + size1] = arr2[i];
    }

}

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";

    }
    cout << endl;
}

