#include "VICTORIA_ROSSI_project1.h"
#include "testing.h"

#include <iostream>
#include <algorithm>
#include <chrono>

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
                    T temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }
            }
            else{
                if(list[j]>list[j+1]){
                    T temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
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
    // Your code here!
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


void merge_sort_test(){
    vector<int> test_list_1 = gen_unique_list(100);
    vector<int> test_list_2 = gen_random_list(100);
    vector<int> test_list_3 = gen_descending_list(100);
    vector<int> test_list_4 = gen_ascending_list(100);
    vector<int> test_list_5 = gen_all_equal_list(100);
    vector<int> test_list_6 = gen_many_dupes_list(100);
    vector<int> test_list_7 = gen_one_percent_rand_list(100);

    merge_sort(test_list_1);
    merge_sort(test_list_2);
    merge_sort(test_list_3);
    merge_sort(test_list_4);
    merge_sort(test_list_5);
    merge_sort(test_list_6);
    merge_sort(test_list_7);

    if(is_list_sorted(test_list_1)){
        cout <<  "MERGE SORT UNIQUE LIST PASSED" << endl;
    } else {
        cout << "MERGE SORT UNIQUE LIST FAILED" << endl;
    }
    
    if(is_list_sorted(test_list_2)){
        cout <<  "MERGE SORT RANDOM LIST PASSED" << endl;
    } else {
        cout << "MERGE SORT RANDOM LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_3)){
        cout <<  "MERGE SORT DESCENDING LIST PASSED" << endl;
    } else {
        cout << "MERGE SORT DESCENDING LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_4)){
        cout <<  "MERGE SORT ASCENDING LIST PASSED" << endl;
    } else {
        cout << "MERGE SORT ASCENDING LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_5)){
        cout <<  "MERGE SORT ALL EQUAL PASSED" << endl;
    } else {
        cout << "MERGE SORT ALL EQUAL LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_6)){
        cout <<  "MERGE SORT MANY DUPLES LIST PASSED" << endl;
    } else {
        cout << "MERGE SORT MANY DUPLES LIST FAILED" << endl;
    }

    if(is_list_sorted(test_list_7)){
        cout << "MERGE SORT ONE PERCENT RAND LIST PASSED" << endl;
    } else {
        cout << "MERGE SORT ONE PERCENT RAND LIST FAILED" << endl;
    }
}




int main() {
    /**** STUDENT CODE HERE ****/ 






    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    //vector<int> test_list {1, 2, 3, 4, 5};
    //bubble_sort(test_list);
    //selection_sort(test_list);
    //insertion_sort(test_list);
    //quicksort(test_list);
    //merge_sort(test_list);
    //bucket_merge_sort(test_list);
    //binary_radix_sort(test_list);
    //my_hybrid_sort(test_list);
    //radix_sort(test_list);

    merge_sort_test();
    
}
