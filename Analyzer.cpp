
#define DEBUGMODEOFF


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include "Analyzer.h"
#include <algorithm>
#include <math.h>

using namespace std;

/**********************************************************/ 
/* BEGIN_1: Block of code related to ids and management of data*/
/**********************************************************/ 

void Analyzer::setId(int n){

    identifier = n;
}

int Analyzer::getId(){

    return identifier;
    
}
/**********************************************************/ 
/* END_1*/
/**********************************************************/ 

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/ 
/* BEGIN_2: Block of code used by many mathematical vector to sum final result*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/ 
double Analyzer::get_sum( std::vector<double>& v1 ){
    
    double value = 0;
    
    for(int i = 0; i < v1.size() ; i++)
    {
        value += v1[i] ;
    }    
    
    return value;

}

void Analyzer::printVectorCount(std::vector<double>& v){

    for(int i = 0 ; i < v.size() ;i++){ 
        
        cout << "Contenido: " << v[i]<<endl;
    }
}

//Set each of the temporal files to have the same length and avoid memory overflows
void Analyzer::initializeResults(std::vector<double>& p,  std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d ){

    for(int i = 0 ; i < d.size() ;i++){ 
        
        p.push_back(0);e.push_back(0);w.push_back(0); wx.push_back(0);
    }
    
}

//Erase content of each temporal holder, and leave vectors empty
void Analyzer::performClean( std::vector<double>& z, std::vector<double>& a,  std::vector<double>& b,std::vector<double>& c, std::vector<double>& d, std::vector<double>& e, std::vector<double>& p, std::vector<double>& ee,std::vector<double>& w, std::vector<double>& wx){
   
    a.clear(); b.clear();c.clear(); d.clear();e.clear();
    z.clear();p.clear();ee.clear();w.clear();wx.clear();  
    
}

//Assign memory space to temporal holders of data extracted from files 
void Analyzer::loadVectors( std::vector<double>& file0, std::vector<double>& file1, std::vector<double>& file2, std::vector<double>& file3,std::vector<double>& file4, std::vector<double>& file5, std::vector <std::vector<double> >& toAssign ){
     
    file0 = toAssign[0]; file1 = toAssign[1];file2 = toAssign[2];file3 = toAssign[3];file4 = toAssign[4];file5 = toAssign[5];
    
}

void Analyzer::performAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c, std::vector<double> d, std::vector<double> e){

    for(int i = 0 ; i < a.size() ;i++){ 
        
        v[i] = (a[i] + b[i] + c[i]+ d[i] + e[i])/(double)5 ;  
        //cout << "Average: "<<  v[i] <<endl;
    }
    
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/ 
/* END_2*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/ 

/*=====================================================================================*/  
/* BEGIN_WEIGTHEDMEAN: Section related to methods employed by Weighted Arithmetic Mean*/
/*=====================================================================================*/  

double Analyzer::applyWeightedArithmeticMeanDistance( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& equivalRef,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef,
                                         int extraAtribution){
     
    double returnScore = 0;
    
    loadVectors(file0, file1, file2, file3, file4, file5, toAssign); //Obligatorio
            
    initializeResults(promediosRef, equivalRef, vector_wRef, vector_xwRef, file0 ); //Obligatorio
    
    if(extraAtribution==0 || extraAtribution==1 ){
       performAverages(promediosRef, file1, file2, file3, file4, file5); 
    }
    else if(extraAtribution==2){
        performBinaryAverages(promediosRef, file1, file2, file3, file4, file5);
    }
    performEquival(promediosRef, equivalRef ,file0);
    performVectorW(promediosRef, vector_wRef ,file0);
    
    if(extraAtribution==0){
        performVectorXW(equivalRef, vector_wRef, vector_xwRef, file0);
    }else if(extraAtribution==1){
        performVectorXWNumerical(equivalRef, vector_wRef, vector_xwRef, file0);
    }else if(extraAtribution==2){
        performVectorXWGreeting(equivalRef, vector_wRef, vector_xwRef, file0);
    }
    
    if(get_sum(vector_xwRef)/get_sum(vector_wRef) <= 100){
        returnScore = get_sum(vector_xwRef)/get_sum(vector_wRef); 
    }else{
        returnScore = 100;
    }
    
    performClean( file0, file1, file2, file3, file4, file5, promediosRef, equivalRef,vector_wRef, vector_xwRef); //Obligatorio
    
    #ifndef DEBUGMODEOFF
         cout << "Weighted mean distance has been applied" <<endl; 
    #endif
    
    
    return returnScore; //Obligatorio
}

void Analyzer::performBinaryAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c, std::vector<double> d, std::vector<double> e){

    for(int i = 0 ; i < a.size() ;i++){ 
        
        v[i] = (a[i] + b[i] + c[i]+ d[i]+e[i])/(double)5 ;
        
        if( v[i] > 0 ){
            v[i] = 1;
        }
    }
    
}


void Analyzer::performEquival(std::vector<double>& p, std::vector<double>& e, std::vector<double> d){

    for(int i = 0 ; i < d.size() ;i++){ 
        
        if(p[i]!=0){
                e[i] = (100 * d[i])/ p[i] ;
        }else{
                e[i] = 0;
        }
        
        if(e[i] > 100 && e[i] < 200){
           e[i] = abs(e[i] - 200);
        }else if(e[i] >= 200){
           e[i] = 0;
        }
       
    }
}

//
void Analyzer::performVectorW(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d){
    
    double sum = 0;
    //promedios, vector_w ,arch0
    
    for(int i = 0; i < p.size() ; i++)
    {
        sum += p[i] ;
    }    
   
    for(int i = 0 ; i < d.size() ;i++){ 
        
        if( sum!=0 ){
                vw[i] =  ((p[i])/sum) ;
        }else{
               vw[i] = 0;
        }
    }

}

//Method used by Weighted Mean Distance
//Perform the product given by the weights in the vector and the percentage of similarity. No additional similarities given by existence of parameter
void Analyzer::performVectorXW(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d){
    
    //equival, vector_w, vector_xw, arch0
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
    }
    
}

//Method used by Weighted Mean Distance
//Perform the product given by the weights in the vector and the percentage of similarity, specifically for numbers
void Analyzer::performVectorXWNumerical(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d){
    
    double items = e.size();
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
                if(d[i] > 0){
                    wx[i] += 100/items; //Verify
                      //  break;
                }
    }
  
}

//Method used by Weighted Mean Distance
//Perform the product given by the weights in the vector and the percentage of similarity, specifically for greeting and farewell expressions
void Analyzer::performVectorXWGreeting(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d){
    
    //equival, vector_w, vector_xw, arch0
    double items = e.size();
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
                if(d[i] > 0)
                        wx[i] += 25 ; //Verify
    
    }
    
}
/*=====================================================================================*/  
/*END_WEIGTHEDMEAN*/
/*=====================================================================================*/  

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
/*BEGIN_MINKOWSKI: Methods used by the Minkowski Distance*/ 
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
double Analyzer::applyMinkowskiDistance( std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5,
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& minkowskiDistance,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef,
                                         double exp){
     
    double returnScore = 0; //Obligatorio
    
       loadVectors(file0, file1, file2, file3, file4, file5, toAssign); //Obligatorio
        
       initializeResults(promediosRef, minkowskiDistance, vector_wRef, vector_xwRef, file0 ); //Obligatorio
    
       performAverages(promediosRef, file1, file2, file3, file4, file5); //Obligatorio
       
       performMinkowski(promediosRef, minkowskiDistance ,file0, exp);
       
       returnScore = performMinEquival(promediosRef, minkowskiDistance, exp ); 
    
       performClean( file0, file1, file2, file3, file4, file5, promediosRef, minkowskiDistance,vector_wRef, vector_xwRef); //Obligatorio
        
#ifndef DEBUGMODEOFF
        cout << "Minkowski distance has been applied" <<endl;
#endif
    
    return returnScore; //Obligatorio
}

void Analyzer::performMinkowski(std::vector<double>& p, std::vector<double>& e, std::vector<double>& d, double exp){

    for(int i = 0 ; i < d.size() ;i++){ 
   
         e[i] = abs(p[i] - d[i])/p[i];
         
        if(e[i] > p[i] ){
            e[i]=0;
        }
        
        e[i] =  std::pow(e[i],exp);
        
    }
    
    for(int i = 0 ; i < d.size() ;i++){ 
        
        p[i] = abs( std::pow(p[i],exp));
        
    }
 
}

double Analyzer::performMinEquival(std::vector<double>& a, std::vector<double>& b, double exp){
    
    double returnVal;
    double maxAwayDist = get_sum(a);
    double root = 1/exp;
    double sumMaxAwayDist = std::pow(maxAwayDist,root);
    
    double var = get_sum(b);
    double totalMin = std::pow(var,root);
    
#ifndef DEBUGMODEOFF
    cout <<" returning" << abs(((totalMin/sumMaxAwayDist)*100))  <<endl;
    cout << totalMin/sumMaxAwayDist << endl;
 #endif

    returnVal = (1 - (totalMin/sumMaxAwayDist));
    
    if(returnVal < 1 && returnVal > -1 )
        returnVal = abs(returnVal)*100;
    else
        returnVal = 0;
   
    #ifndef DEBUGMODEOFF
    cout << "Minkowski result: "<< returnVal <<endl;
    #endif
    return returnVal;
    
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*END_MINKOWSKI*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
 
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/   
/*BEGIN_CHEBYSHEV: Methods used by the Minkowski Distance*/ 
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/ 

void Analyzer::performChebyshev(std::vector<double>& p, std::vector<double>& e, std::vector<double>& d){

     for(int i = 0 ; i < d.size() ;i++){ 
        
        e[i] = abs(p[i] - d[i])/p[i];
        
        if(e[i] > p[i] ){
            e[i]=0;
        }
     
        
     #ifndef DEBUGMODEOFF
        
     cout << "Average: " << p[i] << " vs: Autor B: "<< d[i] << " with distance: " << abs(p[i] - d[i]) <<endl;
     
    #endif
     
    
    }
    
}
       
 double Analyzer::performChevEquival(std::vector<double>& a, std::vector<double>& b ){
     
     double reference =  *max_element(a.begin(), a.end()); //Valor maximo que puede tomar el parametro
     
     double remoteness = *max_element(b.begin(), b.end()); //Valor de alejamiento estimado
     
     double closeness = (abs(abs(remoteness)-abs(reference))/reference)*100; //Valor de acercamiento estimado
     
     
     #ifndef DEBUGMODEOFF
        
     cout << "Tu maximo es: " << remoteness <<endl;
     cout << "con referencia: " << reference <<endl;
     cout << "con equivalencia: " << remoteness/reference <<endl;
     
    #endif
     
     
     return closeness;
      
 }

double Analyzer::applyChebyshevDistance( std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& chebyshevDistance,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef){
     
    double returnScore = 0; //Obligatorio
    
       loadVectors(file0, file1, file2, file3, file4, file5, toAssign); //Obligatorio
    
       initializeResults(promediosRef, chebyshevDistance, vector_wRef, vector_xwRef, file0 ); //Obligatorio
    
       performAverages(promediosRef, file1, file2, file3, file4, file5); //Obligatorio
       
       performChebyshev(promediosRef, chebyshevDistance ,file0); //Personalizacion
       
       returnScore = performChevEquival(promediosRef, chebyshevDistance); //Personalizacion
    
       performClean( file0, file1, file2, file3, file4, file5, promediosRef, chebyshevDistance,vector_wRef, vector_xwRef); //Obligatorio
        
#ifndef DEBUGMODEOFF
        cout << "Chebyshev distance has been applied" <<endl;
#endif
        
    return returnScore; //Obligatorio
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/   
/*END_CHEBYSHEV*/ 
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/ 


/*=====================================================================================*/  
/* BEGIN_MEAN: Section related to methods employed by regular and equitative Distance*/
/*=====================================================================================*/  

double Analyzer::applyRegularMeanDistance( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& equivalRef,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef){
     
    double returnScore = 0;
    
    loadVectors(file0, file1, file2, file3, file4, file5, toAssign); //Obligatorio
    initializeResults(promediosRef, equivalRef, vector_wRef, vector_xwRef, file0 ); //Obligatorio
    performAverages(promediosRef, file1, file2, file3, file4, file5); //Obligatorio
    
    performMeanEquival(promediosRef, equivalRef ,file0); 
    
    performMeanWeigths(promediosRef, vector_wRef ,file0);
    
    performVectorXW(equivalRef, vector_wRef, vector_xwRef, file0);
    
    if(get_sum(vector_xwRef) <= 100){
        returnScore = get_sum(vector_xwRef); 
    }else{
        returnScore = 100; 
    }
    
    performClean( file0, file1, file2, file3, file4, file5, promediosRef, equivalRef,vector_wRef, vector_xwRef); //Obligatorio
    
    #ifndef DEBUGMODEOFF
         cout << "Weighted mean distance has been applied" <<endl; 
    #endif
    
    
    return returnScore;
}

void Analyzer::performMeanWeigths(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d){
    
    double sum = 0;
    //promedios, vector_w ,arch0
    
    for(int i = 0; i < p.size() ; i++)
    {
        sum++ ;
    }    
   
    for(int i = 0 ; i < d.size() ;i++){ 
        
                vw[i] =  (1/sum) ;
    }

}

void Analyzer::performMeanEquival(std::vector<double>& p, std::vector<double>& e, std::vector<double> d){

    for(int i = 0 ; i < d.size() ;i++){ 
        
        
         e[i] = abs(p[i] - d[i])/p[i];
        
        if(e[i] > p[i] ){
            e[i]=0;
        }
        
         e[i]=(1-e[i])*100;
       
    }
}
/*=====================================================================================*/  
/*END_WEIGTHEDMEAN*/
/*=====================================================================================*/ 


/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/  
/* BEGIN_CUSTOMIZED_METHOD: */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/  

double Analyzer::applyNewCustomizedMethod( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& vectorOne,
                                         std::vector<double>& vectorTwo,
                                         std::vector<double>& vectorThree){
     
    double returnScore; //Obligatorio
    
    loadVectors(file0, file1, file2, file3, file4, file5, toAssign); //Obligatorio
    initializeResults(promediosRef, vectorOne, vectorTwo, vectorThree, file0 ); //Obligatorio
    performAverages(promediosRef, file1, file2, file3, file4, file5); //Obligatorio. Saca promedios.
    
     performNuevoMetodo(promediosRef, vectorOne ,file0);
     
    returnScore = devolverResultado(promediosRef, vectorOne); //Personalizacion
 
    performClean( file0, file1, file2, file3, file4, file5, promediosRef, vectorOne,vectorTwo, vectorThree); //Obligatorio
    
    return returnScore; //Obligatorio
}


void Analyzer::performNuevoMetodo(std::vector<double>& promedios, std::vector<double>& auxiliar1 , std::vector<double>& resultadosDeOtroAutor){

    
}

double Analyzer::devolverResultado(std::vector<double>& promedios, std::vector<double>& r){
 
    return 0;
    
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/  
/*END_CUSTOMIZED_METHOD*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/ 
