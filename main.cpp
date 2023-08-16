#include <iostream>

void merge_sort(int* arr, int size)
{
    int left_size = size / 2;
    int right_size;

    if (size % 2 == 1)
    {
        right_size = (size / 2) + 1;
    }
    else
    {
        right_size = size / 2;
    }

    int* left_arr = new int[left_size];
    int* right_arr = new int[right_size];
    int* sort_arr = new int[size];

    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[(size / 2) + i];
    }

    for (int i = 0; i < left_size; i++)
        for (int j = 0; j < left_size - 1; j++)
        {
            if (left_arr[j] > left_arr[j + 1]) 
            { 
                std::swap(left_arr[j], left_arr[j + 1]); 
            }
        }

    for (int i = 0; i < right_size; i++)
        for (int j = 0; j < right_size - 1; j++)
        {
            if (right_arr[j] > right_arr[j + 1]) 
            {
                std::swap(right_arr[j], right_arr[j + 1]); 
            }
        }

    int count_la = 0;
    int count_ra = 0;

    for (int count_sa = 0; count_sa < size; count_sa++)
    {
        if (count_la >= left_size)
        {
            sort_arr[count_sa] = right_arr[count_ra];
            count_ra++;
        }
        else if (count_ra >= right_size)
        {
            sort_arr[count_sa] = left_arr[count_la];
            count_la++;
        }
        else
        {
            if (left_arr[count_la] <= right_arr[count_ra])
            {
                sort_arr[count_sa] = left_arr[count_la];
                count_la++;
            }
            else
            {
                sort_arr[count_sa] = right_arr[count_ra];
                count_ra++;
            }
        }
    }

    std::cout << "Отсортированный массив: ";
    
    for (int i = 0; i < size; i++)
    {
        std::cout << sort_arr[i] << " ";
    }

    std::cout << "\n";
    delete[] sort_arr;
    delete[] left_arr;
    delete[] right_arr;
}

void print_arr(int* arr, int size)
{
    std::cout << "\nИсходный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int first_arr[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int second_arr[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int third_arr[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    print_arr(first_arr, sizeof(first_arr) / sizeof(int));
    merge_sort(first_arr, sizeof(first_arr) / sizeof(int));
    print_arr(second_arr, sizeof(second_arr) / sizeof(int));
    merge_sort(second_arr, sizeof(second_arr) / sizeof(int));
    print_arr(third_arr, sizeof(third_arr) / sizeof(int));
    merge_sort(third_arr, sizeof(third_arr) / sizeof(int));
}