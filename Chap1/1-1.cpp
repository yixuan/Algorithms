//==========================================================================
// Name        : 1-1.cpp
// Author      : Yixuan Qiu
// Version     : 2012-02-21
// Description : Data Structure and Algorithm Analysis in C
//               Mark Allen weiss and Yue Chen
//               Exercise 1.1
//               Selection problem
// Build       : g++ -Wall 1-1.cpp -o 1-1.out
//==========================================================================


#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;


// Generate simulated data for sorting and selection
void generate_data(double array[], size_t array_len,
                   int upper_bound = 100);
// Print the elements in an array
void print_array(double array[], size_t array_len);
// Simple bubble sorting (decreasing)
void bubble_sort_desc(double src_array[], size_t array_len,
                      double array_sort[]);

// Bubble selection
double bubble_selection(double array[], size_t array_len,
                        size_t k);
// Replace selection
double replace_selection(double array[], size_t array_len,
                         size_t k);




void generate_data(double array[], size_t array_len,
                   int upper_bound)
{
    size_t i;
    // Set seed to 1
    srand(1);
    // Generate random numbers between 0 and upper_bound
    for(i = 0; i < array_len; i++)
    {
        array[i] = rand() % upper_bound;
    }
}

void print_array(double array[], size_t array_len)
{
    size_t i;
    for(i = 0; i < array_len; i++)
    {
        cout << setw(4) << array[i];
        if(i % 15 == 14) cout << endl;
    }
    cout << endl;
}


void bubble_sort_desc(double src_array[], size_t array_len,
                      double array_sort[])
{
    size_t i, j;
    double tmp;
    // Copy array src_array to array_sort
    for(i = 0; i < array_len; i++)
    {
        array_sort[i] = src_array[i];
    }
    // Bubble sorting
    for(i = 0; i < array_len - 1; i++)
    {
        for(j = i + 1; j < array_len; j++)
        {
            if(array_sort[j] > array_sort[i])
            {
                tmp = array_sort[j];
                array_sort[j] = array_sort[i];
                array_sort[i] = tmp;
            }
        }
    }
}

double bubble_selection(double array[], size_t array_len,
                        size_t k)
{
    // Copy array src_array to array_sort
    size_t i, j;
    double tmp, result;
    double *array_sort = new double[array_len];
    for(i = 0; i < array_len; i++)
    {
        array_sort[i] = array[i];
    }
    // Partial bubble sorting
    for(i = 0; i < k; i++)
    {
        for(j = i + 1; j < array_len; j++)
        {
            if(array_sort[j] > array_sort[i])
            {
                tmp = array_sort[j];
                array_sort[j] = array_sort[i];
                array_sort[i] = tmp;
            }
        }
    }
    result = array_sort[k - 1];
    delete [] array_sort;
    
    return result;
}

double replace_selection(double array[], size_t array_len,
                         size_t k)
{
    double *array_k = new double[k];
    double *array_ptr, *array_ptr2;
    double result;
    size_t i;
    // Copy the first k elements of array to array_k
    for(i = 0; i < k; i++)
    {
        array_k[i] = array[i];
    }
    // Sort array_k
    bubble_sort_desc(array_k, k, array_k);
    // Insert remaining elements in array into array_k at
    // appropriate positions
    for(i = k; i < array_len; i++)
    {
        if(array[i] > array_k[k - 1])
        {
            for(array_ptr = array_k; array_ptr < &array_k[k]; array_ptr++)
            {
                if(array[i] > *array_ptr) break;
            }
            for(array_ptr2 = &array_k[k - 1]; array_ptr2 > array_ptr; array_ptr2--)
            {
                *array_ptr2 = *(array_ptr2 - 1);
            }
            *array_ptr = array[i];
        }
    }
    result = array_k[k - 1];
    delete [] array_k;
    
    return result;
}



int main()
{
    // Length of array
    const int N = 100;
    // The order of the kth largest number
    int k = N / 2;
    
    double array[N];
    double array_sort[N];
    
    
    generate_data(array, N, 100);
    cout << "Original array is:" << endl;
    print_array(array, 100);
    bubble_sort_desc(array, 100, array_sort);
    cout << "Array after sorting is:" << endl;
    print_array(array_sort, 100);
    cout << "The " << k << "th largest number is (bubble selection):\n";
    cout << bubble_selection(array, N, k) << endl;
    cout << "The " << k << "th largest number is (replace selection):\n";
    cout << replace_selection(array, N, k) << endl;
    
    return 0;
}
