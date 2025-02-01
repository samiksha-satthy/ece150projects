#include <iostream>
#include <cassert>

void pattern(unsigned int n); 
unsigned int log10(unsigned int n); 
unsigned int count(unsigned int n, unsigned int bit); 
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1); 

int main() {

    //part 1
    unsigned int n; 
    std::cout<<"Enter a number: "; 
    std::cin>>n; 
    pattern(n); 

    //part 2
    unsigned int d; 
    std::cout<<"Enter a Number: "; 
    std::cin>>d; 
    std::cout<<"The largest exponent is: "<<log10(d)<<std::endl;
    std::cout<<std::endl;

    //part 3
    unsigned int n2; 
    unsigned int bit; 
    std::cout<<"Enter an integer: "; 
    std::cin>>n2; 
    std::cout<<"Enter a bit (0; 1): "; 
    std::cin>>bit; 
    std::cout<<count(n2, bit)<<std::endl;
    std::cout<<std::endl;

    //part 4

    unsigned int n3; 
    unsigned int b0; 
    unsigned int b1; 
    std::cout<<"Enter a number: ";
    std::cin>>n3; 
    std::cout<<"Enter first bit: "; 
    std::cin>>b0; 
    std::cout<<"Enter second bit: "; 
    std::cin>>b1; 

    std::cout<<swap_bytes(n3, b0, b1)<<std::endl; 


    return 0; 
}


void pattern (unsigned int n){

    

    int space = 0;  
    int current = 0; 
    int p = ((int)n*2)+1; 
    for (int x = p; x >= 1; x-=2){

            space += 2; 
            current = x;     

        
            for (int y = space/2; y > 1; y--){
                std::cout<<" "; 
                }
        

            for (int s = x; s > 0; s--){


                std::cout<<"*"; 
            }

            std::cout<<std::endl;  
            
    }

 
    for (int x = current + 2; x <= p; x+=2){

        
        space -= 2; 

        
        for (int y = space/2; y > 1; y--){
            std::cout<<" "; 
            }
        

        for (int s = x; s > 0; s--){

            std::cout<<"*"; 
        }


        std::cout<<std::endl; 

        

    }
}

unsigned int log10(unsigned int n){

    assert (n != 0); 

    unsigned int exp{0}; 

    while (n >= 10){
        n /= 10; 
        exp++; 
    }

    return exp; 

}

unsigned int count (unsigned int n, unsigned int bit){

    assert (bit == 0 || bit == 1); 
    unsigned int count{}; 

    for (int i = 31; i >= 0; --i) {
        // Shift bits to the right and mask with 1 to extract the i-th bit
        if (((n >> i) & 1) == bit){
            count++; 
        }
            
    }

    return count;  
}

unsigned int swap_bytes (unsigned int n, unsigned int b0, unsigned int b1){

    assert(0 <= b0 && b0 <= 3); 
    assert(0 <= b1 && b1 <= 3); 

    if (b0 == b1){
        return n; 
    } else{
 
        unsigned int m0= 0xFF<<(b0*8); 
        unsigned int m1= 0xFF<<(b1*8); 
        unsigned int by0= (n & m0)>>(b0*8); 
        unsigned int by1= (n & m1)>>(b1*8);

        n &=~m0; 
        n &=~m1; 

        n |= (by0 << (b1*8)); 
        n |= (by1 << (b0*8)); 


        return n; 


    }



}