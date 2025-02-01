#include <iostream>
#include <cassert>
#include <fstream>
#include "p_4_header.hpp"

//string function 1
std::size_t length(char const *a){
    
    size_t size{}; 
    while (a[size] != '\0'){
        size++; 
    }

    return size; 

}

//string function 2
int compare (char const *str1, char const *str2){

    int size1 = length(str1); 
    int size2 = length(str2); 
    int size{}; 
    int k{}; 

    if (size1 > size2){
        size = size2; 
    }

    else{

        size = size1; 
    }


    while (k <= size){

        if (str1[k] == '\0' && str2[k] == '\0'){
            return 0; 

        }

        else if (str2[k] == '\0'){
            return 1; 
        }

        else if (str1[k] == '\0'){
            return -1; 
        }

        else if (str1[k] < str2[k]){
            return -1; 
        }

        else if (str1[k] > str2[k]){
            return 1; 
        }

        else {
            k++; 
        }

    }

}

//string function 3
void assign (char *str1, char const *str2){

    size_t size = length(str2); 
    int index{}; 


    while(str2[index]!='\0'){

        str1[index] = str2[index]; 
        index++; 

    }

    str1[index] = '\0'; 


}

//string function 4
unsigned int distance (char const *str1, char const *str2){
 
    
    if (str1[0] == '\0'){

        return length(str2); 
    }

    else if (str2[0] == '\0'){
        return length (str1); 
    }

    else if (str2[0] == str1[0]){

        return distance(str1+ 1, str2+1); 
    }

    else {

        int a = distance(str1 + 1, str2 + 1); 
        int b = distance (str1, str2 +1); 
        int c = distance(str1 + 1, str2); 

        int min = a; 

        if (b < min){
            min = b;  
        }

        if (c < min){

            min = c; 
        }
        
        return min + 1; 

    }

}

//array function 1
std::size_t is_sorted(char *array[], std::size_t capacity){

    bool check = true; 
    std::size_t count{0}; 

    for (int i = 0; i < capacity; i++){

        if (i != 0 ){

            if (compare(array[i], array[i-1]) > 0){

                count = i;
                continue; 
    
            }

             check = false; 
             break; 

        }

    }

    if (check)
        return capacity; 

    else 
        return count + 1; 


}

//array function 2
void insert(char *array[], std::size_t capacity){

    char value[21]; 
    assign(value, array[capacity-1]); 

    std::size_t k = capacity - 1;

    while (k > 0 && compare(array[k - 1], value) > 0){
        assign(array[k], array[k-1]); 
        --k; 

    }

    assign(array[k], value); 




}

//array function 3
void insertion_sort(char *array[], std::size_t capacity){

    for (std::size_t k{1}; k < capacity; ++k){

        insert(array, k+1);

    }

    assert(is_sorted(array, capacity) == capacity); 
}

//array function 4
std::size_t remove_duplicates (char *array[], std::size_t capacity){

    std::size_t number{}; 
    
    for (int i = 0; i < capacity; i++){

        bool unique = true;
        for (int k = 0; k < i; k++){

            if (*array[i] = *array[k]){

                unique = false; 
                break; 
            }

        }

        if (!unique){
            *array[i] = 0; 

        }
        
        else if (unique){
            int p = *array[number]; 
            int s = *array[i]; 
            *array[number] = s; 
            *array[i] = p; 
            number++;

        }
    }

}

//array function 5
std::size_t find(char *array[], std::size_t capacity, char const *str){

    int index{-1};
    std::size_t array2[capacity]{}; 
    
    for (int i = 0; i < capacity; i++){

        if (compare(array[i], str) == 0) {
             index = i; 

        }
    }

    if (index != -1)
        return(index); 

    else {

        for (int l = 0; l < capacity; l++){

            array2[l] = distance(array[l], str); 
        }
        
        index = 0;
        for (int k = 0; k < capacity; k++){

            if (array2[k] == 0){
                break; 
            }
            
            else if (array2[k] < array2[index]){

                index = k; 
            }
            
        }

        return index; 

    }
        


}

//deallocating memory
void free_word_array(char** word_array){

    delete [] word_array[0]; 
    delete [] word_array; 


}