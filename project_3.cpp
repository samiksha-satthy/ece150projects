#include <iostream>
#include <cassert>

int main();
// double *geometric(double a, double ratio, std::size_t cap); 
// double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);  
// std::size_t shift_duplicates(int array[], std::size_t capacity); 
// void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0); 

double *geometric(double a, double ratio, std::size_t cap){

    double *array1 = new double[cap]{}; 

    if (cap == 0){
        return array1; 
    }


    else {

        array1[0] = a; 

        for (int i = 1; i < cap; i++){
        
        array1[i] = array1[i-1] * ratio; 

        }

        return array1; 


    }


}


double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){

    assert(cap0 + cap1>= 1);  
    std::size_t size = cap0 + cap1 - 1; 
    double *array_new = {new double[size]{}}; 



    for (int i = 0; i < cap0; i++){

        for (int j = 0; j < cap1; j++){

            array_new[i+j] += array0[i] * array1[j]; 
        }
    }


    return array_new; 

}

std::size_t shift_duplicates(int array[], std::size_t capacity){

    std::size_t count{}; 
    

    for (int i = 0; i < capacity; i++){
        bool unique = true; 
        for (int j = 0; j < i; j++){

            if (array[i] == array[j] ){
                unique = false; 
                break; 

            } 
        }

        if (unique){
            int p= array[count];
            array[count] = array[i];
            array[i]=p;
            count++; 
        }
            
       
    }


    return count; 


}

void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0){

    
    
    if (is_array){

        for (int i = 0; i < capacity; i++){

            ptr[i] = 0.0; 

        }

        delete [] ptr; 
        ptr = nullptr; 
    }


    else {

        // *ptr = 0.0; 
        delete ptr; 
        ptr = nullptr; 
    }



}



