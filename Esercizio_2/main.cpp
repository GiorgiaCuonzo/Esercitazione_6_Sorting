#include <chrono>
#include <iostream>
#include <unistd.h>
#include <numeric>
#include <algorithm>
#include <vector>
#include "SortingAlgorithm.hpp"
#include <iomanip>

using namespace std;

template<typename T>
double TimeBubble(vector<T>& v)
{
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    SortLibrary::BubbleSort(v);
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

    double timeElapsed = chrono::duration_cast<chrono::nanoseconds>(t_end-t_begin).count();
    return timeElapsed;
}

template<typename T>
double TimeMerge(vector<T>& v)
{
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    SortLibrary::MergeSort(v);
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

    double timeElapsed = chrono::duration_cast<chrono::nanoseconds>(t_end-t_begin).count();
    return timeElapsed;
}


int main(int argc, char ** argv)
{
    int n = 0;
    size_t dimv = stoi(argv[1]);
    unsigned int iters = 100;
    vector<int> v(dimv);
    double time_Bubble = 0;
    double time_Merge = 0;

    cout << scientific << setprecision(4);
    // Vector of random integers in range 0-987
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        for (unsigned int i=0; i<dimv; i++){
            v[i] = rand() % 987;
        }
        vector<int> v_copia = v;

        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v = time_Bubble/iters;
    double time_MergeSort_v = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a random integers vector" << endl
         << "Bubblesort: " << time_BubbleSort_v << endl
         << "MergeSort : " << time_MergeSort_v << endl << endl;


    // Vector of random doubles in range 0-1
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    vector<double> w(dimv);
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        for (unsigned int i=0; i<dimv; i++){
            w[i] = rand();
        }
        vector<double> w_copia = w;

        time_Bubble += TimeBubble(w);
        time_Merge += TimeMerge(w_copia);
    }
    double time_BubbleSort_w = time_Bubble/iters;
    double time_MergeSort_w = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a random doubles vector" << endl
         << "Bubblesort: " << time_BubbleSort_w << endl
         << "MergeSort : " << time_MergeSort_w << endl << endl;


    // Vector of ascending ordered integers
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    generate(v.begin(),v.end(),[&n] () {return n++;});
    vector<int> v_copia = v;
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v3 = time_Bubble/iters;
    double time_MergeSort_v3 = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a ordered integers vector" << endl
         << "Bubblesort: " << time_BubbleSort_v3 << endl
         << "MergeSort : " << time_MergeSort_v3 << endl << endl;


    unsigned int half_dim = dimv/2;
    // Vector of ordered integers with the fist half perturbed
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    generate(v.begin(),v.end(),[&n] () {return n++;});
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        for (unsigned int i=0; i<half_dim; i++){
            v[i] = rand() % half_dim;
        }
        vector<int> v_copia = v;

        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v1 = time_Bubble/iters;
    double time_MergeSort_v1 = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a integers vector with the fist half of elements perturbed" << endl
         << "Bubblesort: " << time_BubbleSort_v1 << endl
         << "MergeSort : " << time_MergeSort_v1 << endl << endl;


    // Vector of ordered integers with the second half perturbed
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    generate(v.begin(),v.end(),[&n] () {return n++;});
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        for (unsigned int i=half_dim; i<dimv; i++){
            v[i] = rand() % dimv + half_dim;
        }
        vector<int> v_copia = v;

        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v2 = time_Bubble/iters;
    double time_MergeSort_v2 = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a integers vector with the second half of elements perturbed" << endl
         << "Bubblesort: " << time_BubbleSort_v2 << endl
         << "MergeSort : " << time_MergeSort_v2 << endl << endl;


    // Vector of ordered integers which elements have been switched in pairs
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    generate(v.begin(),v.end(),[&n] () {return n++;});
    int dimv_floor = (dimv/2)*2;
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        for (unsigned int i=0; i<dimv_floor-1; i+=2){
            int chang = v[i];
            v[i] = v[i+1];
            v[i+1] = chang;
        }
        vector<int> v_copia = v;

        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v4 = time_Bubble/iters;
    double time_MergeSort_v4 = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a integers vector with elements switched in pairs" << endl
         << "Bubblesort: " << time_BubbleSort_v4 << endl
         << "MergeSort : " << time_MergeSort_v4 << endl << endl;


    // Vector of ordered integers where the last element has been popped in the front
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    generate(v.begin(),v.end(),[&n] () {return n++;});
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        int new_first = v[dimv-1];
        for (unsigned int i=dimv-1; i>0; i--){
            v[i] = v[i-1];
        }
        v[0] = new_first;
        vector<int> v_copia = v;

        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v5 = time_Bubble/iters;
    double time_MergeSort_v5 = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a ordered integers vector with the last element popped in the front" << endl
         << "Bubblesort: " << time_BubbleSort_v5 << endl
         << "MergeSort : " << time_MergeSort_v5 << endl << endl;


    // Vector or ordered integers which first and second half have been switched
    time_Bubble = 0;
    time_Merge = 0;
    n = 0;
    for (unsigned int num_iter = 0; num_iter < iters; num_iter++){
        for (unsigned int i=n; i<dimv; i++){
            v[i] = (i + half_dim)%dimv;
        }
        vector<int> v_copia = v;

        time_Bubble += TimeBubble(v);
        time_Merge += TimeMerge(v_copia);
    }
    double time_BubbleSort_v6 = time_Bubble/iters;
    double time_MergeSort_v6 = time_Merge/iters;
    cout << "Time in nanoseconds needed for sorting a ordered integers vector with the first and second halfs switched" << endl
         << "Bubblesort: " << time_BubbleSort_v6 << endl
         << "MergeSort : " << time_MergeSort_v6 << endl << endl;


    return 0;
}

