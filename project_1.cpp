#include <iostream>
#include <cmath> 

int main(){

    //variables
    double fmax{-1}; 
    double mmax{-1}; 
    double p1max{-1}; 
    double p2max{-1}; 
    double p3max{-1}; 
    double p4max{-1}; 
    double p5max{-1}; 
    double final{-1}; 
    double midterm{-1}; 
    double project1{-1}; 
    double project2{-1}; 
    double project3{-1}; 
    double project4{-1}; 
    double project5{-1}; 
    double examtotal{0}; 
    double projtotal{0}; 
    double total{0}; 

    //final examination
    while (fmax <= 0 || fmax!=std::round(fmax)){

        std::cout<<"Enter Final Max: "; 
        std::cin>>fmax; 

    }


    while (final < 0|| final > fmax){

        std::cout<<"Enter Final Examination: "; 
        std::cin>>final; 


    }
    

    //midterm 
    while (mmax <= 0 || mmax!=std::round(mmax)){

        std::cout<<"Enter Midterm Max: "; 
        std::cin>>mmax; 

    }


    while (midterm < 0|| midterm > mmax){


        std::cout<<"Enter Midterm Examination: ";
        std::cin>>midterm;


    }
    

    //project 1
    while (p1max <= 0 || p1max!=std::round(p1max)){

        std::cout<<"Enter Project 1 Max: "; 
        std::cin>>p1max; 

    }


    while (project1 < 0|| project1 > p1max){


        std::cout<<"Enter Project 1 Mark: ";
        std::cin>>project1;

    }

    //project 2
    while (p2max <= 0 || p2max!=std::round(p2max)){

        std::cout<<"Enter Project 2 Max: "; 
        std::cin>>p2max; 

    }

    while (project2 < 0|| project2 > p2max){


        std::cout<<"Enter Project 2 Mark: ";
        std::cin>>project2;
    }

    //project 3
    while (p3max <= 0 || p3max!=std::round(p3max)){

        std::cout<<"Enter Project 3 Max: "; 
        std::cin>>p3max; 

    }

    while (project3 < 0|| project3 > p3max){

        std::cout<<"Enter Project 3 Mark: ";
        std::cin>>project3;

    }

    //project 4
    while (p4max <= 0 || p4max!=std::round(p4max)){


        std::cout<<"Enter Project 4 Max: "; 
        std::cin>>p4max; 
    

    }

    while (project4 < 0|| project4 > p4max){

        std::cout<<"Enter Project 4 Mark: ";
        std::cin>>project4;

    }

    //project 5
    while (p5max <= 0 || p5max!=std::round(p5max)){

        std::cout<<"Enter Project 5 Max: "; 
        std::cin>>p5max; 

    }

    while (project5 < 0|| project5 > p5max){

        std::cout<<"Enter Project 5 Mark: ";
        std::cin>>project5;
    }

    final = (final/fmax)*100.00; 
    midterm = (midterm/mmax)*100.00;
    project1 = (project1/p1max)*100.00;  
    project2 = (project2/p2max)*100.00; 
    project3 = (project3/p3max)*100.00; 
    project4 = (project4/p4max)*100.00;
    project5 = (project5/p5max)*100.00; 

    if (final > midterm)
        midterm = final; 
        

    if (final > project1)
        project1 = final;
        

    if (final > project2)
        project2 = final; 

    if (final > project3)
        project3 = final; 
        

    if (final > project4)
        project4 = final; 
        

    if (final > project5)
        project5 = final; 
        
    examtotal = (0.75 * final)+(0.25*midterm);

    projtotal = ((project1+project2+project3+project4+project5)/5); 

   
    if (examtotal <= 40 || projtotal == 0){

            total = examtotal; 
        }

    else if (examtotal >= 60){

 
            total = ((2.0/3.0) * examtotal) + ((1.0/3.0) * projtotal);
            
    
        }

    else {

            total = ((-1.0/60.0) * examtotal * examtotal) + ((5.0/3.0)*examtotal) + ((1.0/60.0)*projtotal*examtotal) - ((2.0/3.0)*projtotal); 
    }

   std::cout<<"Final Mark: "<< round( total + 1e-2 ) << std::endl; 
    
   return 0; 
  


}