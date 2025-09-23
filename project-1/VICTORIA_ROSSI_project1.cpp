#include "VICTORIA_ROSSI_project1.h"
#include "testing.h"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */



/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Brian Rosca
//   Mauricio Alvarez



/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    for(int i = 0; i< list.size(); i++){
        for(int j = 0; j<list.size()-i-1; j++){
            if(descending){
                if(list[j]<list[j+1]){
                    swap(list[j], list[j+1]);
                }
            }
            else{
                if(list[j]>list[j+1]){
                    swap(list[j], list[j+1]);
                }
            }
        }
    }
}














/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    // Your code here!   
    for (int i = 0; i < list.size(); i++){
        int min_index = i;
        for (int j = i+1; j < list.size(); j++){
            if (descending){
                if (list[j] > list[min_index]){
                    min_index = j;
                }
            }
            else{
                if (list[j] < list[min_index]){
                    min_index = j;
                }
            }
        }
        swap(list[i], list[min_index]);
    }
}















/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    for(int i = 1; i < list.size(); i++){
        T key = list[i];
        int j = i - 1;
        if(descending){
            while(j >= 0 && list[j] < key){
                list[j+1] = list[j];
                list[j] = key;
                j--;
            }
        } else {
            while(j >= 0 && list[j] > key){
                list[j+1] = list[j];
                list[j] = key;
                j--;
            }
        }
    }
}












/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void quicksort(vector<T> &list, bool descending) {
    // Your code here!
    quick_partition(list, descending);
}


/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */
template<typename T>
vector<T>& quick_partition(vector<T> &list, bool descending) {
    // Your code here!
    //
    // You can use the helper function 
    //      unsigned int get_rand_index(unsigned int len)
    if (list.size() <= 1) return list;

    // Choose a random pivot
    unsigned int pivotIndex = get_rand_index(list.size());
    T pivot = list[pivotIndex];

    vector<T> left, right;

    // This loop goes through all elements, adds the things smaller than the pivot to <left> and the others to <right>
    // O(n) runtime
    for (unsigned int i = 0; i < list.size(); i++){
        if (i == pivotIndex) continue;
        if ((descending && list[i] > pivot) || (!descending && list[i] < pivot)){
            left.push_back(list[i]);
        }
        else{
            right.push_back(list[i]);
        }
    }

    // We then wanna recursively partition the left and right halves (quicksort calls quick_partition)
    // O(log n) runtime
    quicksort(left, descending);
    quicksort(right, descending);

    list.clear();
    // Insert method takes 2 args (3 in this case bc iterators):
    // 1. Place to insert (right before)
    // In this case, we want to put it right before the end of the list (last element)
    // 2/3. Contents: in this case we're putting all the elements
    // that are less than the pivot first, then the elements greater than it
    list.insert(list.end(), left.begin(), left.end());
    // The pivot should go in between the things smaller and larger than it
    list.push_back(pivot); 
    list.insert(list.end(), right.begin(), right.end());

    return list;
}










/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort(vector<T> &list, bool decending) {
    if (list.size() <= 1) return;

    int mid = list.size() / 2;

    // divide
    vector<T> left(list.begin(), list.begin() + mid);
    vector<T> right(list.begin() + mid, list.end());

    merge_sort(left, decending);
    merge_sort(right, decending);

    // merge
    int i = 0, j = 0, k = 0;
    while(i < left.size() && j < right.size()){
        if(decending){
            if(left[i] > right[j]){
                list[k] = left[i];
                i++;
            } else {
                list[k] = right[j];
                j++;
            }
        } else {
            if(left[i] < right[j]){
                list[k] = left[i];
                i++;
            } else {
                list[k] = right[j];
                j++;
            }
        }
        k++;
    }

    // add leftover elements
    while(i < left.size()){
        list[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size()){
        list[k] = right[j];
        j++;
        k++;    
    }
}



/* Merge Lists
 *
 * Helper function for Bucket Merge Sort. This function will merge the buckets into the list.
 *
 */
template<typename T>
void merge_lists(vector<vector<T>> &buckets, vector<T> &list, bool descending){

    int n = buckets.size();

    while(n > 1){
        int k = 0;
        for(int i = 0; i < n; i += 2){
            int j = 0, l = 0;

            // merge buckets[i] and buckets[i+1] elem by elem
            while(j < buckets[i].size() && (i + 1 < n) && l < buckets[i+1].size()){
                if(descending){
                    if(buckets[i][j] > buckets[i+1][l]){
                        list.push_back(buckets[i][j]);
                        j++;
                    } else {
                        list.push_back(buckets[i+1][l]);
                        l++;
                    }
                } else {
                    if(buckets[i][j] < buckets[i+1][l]){
                        list.push_back(buckets[i][j]);
                        j++;
                    } else {
                        list.push_back(buckets[i+1][l]);
                        l++;
                    }
                }
            }

            // add leftover elements
            while(j < buckets[i].size()){
                list.push_back(buckets[i][j]);
                j++;
            } 

            while((i + 1 < n) && l < buckets[i+1].size()){
                list.push_back(buckets[i+1][l]);
                l++;    
            }

            // after merging, save merged bucket back into buckets[k] for next pass
            // eg: after first pass buckets[0] = merge(buckets[0], buckets[1])
            //     after second pass buckets[1] = merge(buckets[2], buckets[3])
            //     etc.
            buckets[k] = vector<T>(list.end() - (j + l), list.end());
            k++;
        }
        n = k; // update number of buckets
        list.clear(); // clear list for next merge pass
    }

    // by the time we finish, all buckets will be merged into buckets[0] bc of line 390
    if(n == 1){
        list = buckets[0];
    }
}






/* Bucket Merge Sort
 *
 * 20 points
 * 
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending) {
    const int BUCKET_SIZE = 32; 

    // divide list into buckets
    vector<vector<T>> buckets;
    for(int i = 0; i < list.size(); i += BUCKET_SIZE){
        // create bucket of size BUCKET_SIZE or the remaining elements of list
        // vector from idx of first elem in bucket to idx of last elem in bucket
        vector<T> bucket(list.begin() + i, list.begin() + min(i + BUCKET_SIZE, (int)list.size()));
        buckets.push_back(bucket);
    }

    // sort each bucket using fast algorithm (i.e. insertion)
    for (int i = 0; i < buckets.size(); i++){
        insertion_sort(buckets[i], descending);
    }

    // merge neighbouring buckets together
    list.clear();
    merge_lists(buckets, list, descending);
}




/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Your code here!
}


/* Your Hybrid Sort
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    // Your code here!
    // I'm implementing introsort because I'm BORED - Mauricio
    int max_recursion_depth = 2 * log2(list.size());
    intro_sort(list, 0, list.size() -1, max_recursion_depth, descending);
}

template<typename T>
// Inputs: List with ranges, descending flag
// Makes two partitions in place within the list
// Return: index of partition
int _partition(vector<T>& list, int low, int high, bool descending) {
    // Choose a random pivot index in [low, high]
    int pivotIndex = low + get_rand_index(high - low + 1);
    T pivot = list[pivotIndex];
    swap(list[pivotIndex], list[high]); // To not swap the pivot
    
    int i = low; // place for the next element that belongs to the "left" side
    for (int j = low; j < high; j++) {
        if ((descending && list[j] > pivot) || (!descending && list[j] < pivot)) {
            swap(list[i], list[j]);
            i++;
        }
    }
    // Place pivot (list[high])in its final position
    swap(list[i], list[high]);
    return i; // pivot index
}

template<typename T>
void insertion_sort_w_range(vector<T> &list, int low, int high, bool descending) {
    for (int i = low + 1; i <= high; i++) {
        int j = i;
        if (descending) {
            while (j > low && list[j - 1] < list[j]) {
                swap(list[j - 1], list[j]);
                j--;
            }
        } else {
            while (j > low && list[j - 1] > list[j]) {
                swap(list[j - 1], list[j]);
                j--;
            }
        }
    }
}

template<typename T>
void intro_sort(vector<T> &list, int low, int high, int max_depth, bool descending){
    // Important business to start with: do we have a sorted list? "Sort" it!
    if (high - low <= 1) return;
    // No. Is it insertion sortable? Insertion-sort it!
    if (high - low + 1 <= 32) {
        insertion_sort_w_range(list, low, high, descending);
        return;
    }
    // No. Have we recursed too many times? Heap-sort it!
    // O(n log n)
    if (max_depth <= 0) heap_sort(list, low, high,  descending);

    // We proceed using quicksort as normal otherwise
    int partitionIndex = _partition(list, low, high, descending);
    // Now everything left of  <partitionIndex> is smaller than it
    // And everything right of it is larger
    // We can recurse
    intro_sort(list, low, partitionIndex - 1, max_depth - 1, descending);
    intro_sort(list, partitionIndex + 1, high, max_depth - 1, descending);
}

template<typename T>
void heap_sort(vector<T> &list, int low, int high, bool descending){
    auto first = list.begin() + low;
    auto last = list.begin() + high + 1;
    // make_heap() + sort_heap() heapifies a vector with the front/first element being the largest
    if (descending) {
        make_heap(first, last);
        sort_heap(first, last);
    }
    // If we want it in ascending order, we add a <T> comparator
    else {
        make_heap(first, last, greater<T>());
        sort_heap(first, last, greater<T>());
    }
    return;
}



/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
}


/*
---------------------
TESTING FUNCTIONS
---------------------
*/

enum test_types {BUBBLE, SELECTION, INSERTION, QUICK, MERGE, BUCKET_MERGE, BINARY_RADIX, HYBRID, RADIX};

void sorting_test(int test_name, bool descending=false) {
    vector<int> test_list_1 = gen_unique_list(100);
    vector<int> test_list_2 = gen_random_list(100);
    vector<int> test_list_3 = gen_descending_list(100);
    vector<int> test_list_4 = gen_ascending_list(100);
    vector<int> test_list_5 = gen_all_equal_list(100);
    vector<int> test_list_6 = gen_many_dupes_list(100);
    vector<int> test_list_7 = gen_one_percent_rand_list(100);

    string function_name = "";

    switch(test_name){
        case test_types::BUBBLE:
            bubble_sort(test_list_1, descending);
            bubble_sort(test_list_2, descending);
            bubble_sort(test_list_3, descending);
            bubble_sort(test_list_4, descending);
            bubble_sort(test_list_5, descending);
            bubble_sort(test_list_6, descending);
            bubble_sort(test_list_7, descending);
            function_name = "BUBBLE SORT";
            break;
        case test_types::SELECTION:
            selection_sort(test_list_1, descending);
            selection_sort(test_list_2, descending);
            selection_sort(test_list_3, descending);
            selection_sort(test_list_4, descending);
            selection_sort(test_list_5, descending);
            selection_sort(test_list_6, descending);
            selection_sort(test_list_7, descending);
            function_name = "SELECTION SORT";
            break;
        case test_types::INSERTION:
            insertion_sort(test_list_1, descending);
            insertion_sort(test_list_2, descending);
            insertion_sort(test_list_3, descending);
            insertion_sort(test_list_4, descending);
            insertion_sort(test_list_5, descending);
            insertion_sort(test_list_6, descending);
            insertion_sort(test_list_7, descending);
            function_name = "INSERTION SORT";
            break;
        case test_types::QUICK:
            quicksort(test_list_1, descending);
            quicksort(test_list_2, descending);
            quicksort(test_list_3, descending);
            quicksort(test_list_4, descending);
            quicksort(test_list_5, descending);
            quicksort(test_list_6, descending);
            quicksort(test_list_7, descending);
            function_name = "QUICK SORT";
            break;
        case test_types::MERGE:
            merge_sort(test_list_1, descending);
            merge_sort(test_list_2, descending);
            merge_sort(test_list_3, descending);
            merge_sort(test_list_4, descending);
            merge_sort(test_list_5, descending);
            merge_sort(test_list_6, descending);
            merge_sort(test_list_7, descending);
            function_name = "MERGE SORT";
            break;
        case test_types::BUCKET_MERGE:
            bucket_merge_sort(test_list_1, descending);
            bucket_merge_sort(test_list_2, descending);
            bucket_merge_sort(test_list_3, descending);
            bucket_merge_sort(test_list_4, descending);
            bucket_merge_sort(test_list_5, descending);
            bucket_merge_sort(test_list_6, descending);
            bucket_merge_sort(test_list_7, descending);
            function_name = "BUCKET MERGE SORT";
            break;
        case test_types::HYBRID:
            my_hybrid_sort(test_list_1, descending);
            my_hybrid_sort(test_list_2, descending);
            my_hybrid_sort(test_list_3, descending);
            my_hybrid_sort(test_list_4, descending);
            my_hybrid_sort(test_list_5, descending);
            my_hybrid_sort(test_list_6, descending);
            my_hybrid_sort(test_list_7, descending);
            function_name = "INTRO SORT";
            break;
        default:
            cout << "RUNNING MERGE SORT TESTS" << endl;
    }

    if(is_list_sorted(test_list_1, descending)){
        cout <<  function_name + " UNIQUE LIST PASSED" << endl;
    } else {
        cout << function_name + " UNIQUE LIST FAILED" << endl;
        cout << "LIST CONTENTS: " << endl;
        for (const auto& item : test_list_1){
            cout << item << endl;
        }
    }
    
    if(is_list_sorted(test_list_2, descending)){
        cout <<  function_name +  " RANDOM LIST PASSED" << endl;
    } else {
        cout << function_name + " RANDOM LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_3, descending)){
        cout <<  function_name + " DESCENDING LIST PASSED" << endl;
    } else {
        cout << function_name + " DESCENDING LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_4, descending)){
        cout <<  function_name + " ASCENDING LIST PASSED" << endl;
    } else {
        cout << function_name + " ASCENDING LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_5, descending)){
        cout <<  function_name + " ALL EQUAL PASSED" << endl;
    } else {
        cout << function_name + " ALL EQUAL LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_6, descending)){
        cout <<  function_name + " MANY DUPLES LIST PASSED" << endl;
    } else {
        cout << function_name + " MANY DUPLES LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_7, descending)){
        cout << function_name + " ONE PERCENT RAND LIST PASSED" << endl;
    } else {
        cout << function_name + " ONE PERCENT RAND LIST FAILED" << endl;
    }
}




int main() {
    /**** STUDENT CODE HERE ****/ 


    sorting_test(test_types::BUBBLE, true);

    cout << "-----------------" << endl;

    sorting_test(test_types::SELECTION, true);

    cout << "-----------------" << endl;

    sorting_test(test_types::INSERTION, true);

    cout << "-----------------" << endl;
    
    sorting_test(test_types::QUICK, true);
    
    cout << "-----------------" << endl;

    sorting_test(test_types::MERGE, true);
    
    cout << "-----------------" << endl;

    sorting_test(test_types::BUCKET_MERGE, true);
    
    cout << "-----------------" << endl;

    sorting_test(test_types::HYBRID, true);
    // vector<int> test_list = gen_unique_list(70);
    // print_list_group(test_list);
    // bucket_merge_sort(test_list, false);
    // print_list_group(test_list);



    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    // vector<int> test_list {1, 2, 3, 4, 5};
    //bubble_sort(test_list);
    //selection_sort(test_list);
    //insertion_sort(test_list);
    //quicksort(test_list);
    //merge_sort(test_list);
    //bucket_merge_sort(test_list);
    //binary_radix_sort(test_list);
    //my_hybrid_sort(test_list);
    //radix_sort(test_list);
}