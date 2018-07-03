#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "FileHandler.h"
#include <algorithm>

using namespace std;

//Se puede pedir el nombre del autor principal que se analiza
int FileHandler::getPubNumber(){
    int numberPubs = 1;
    cout << "Textos previos del mismo autor: ";
    cin >> numberPubs;
    return numberPubs; //Pedir ingreso al usuario
}

string FileHandler::makeName(int textosPrevios){
    string titulo = "files/default";
    titulo.append("_");
    string t = to_string(textosPrevios);
    titulo.append(t);
    titulo.append(".txt");
    return titulo;
}

void FileHandler::welcomeUser(){
    
    cout << endl;
    cout << "#####################################################" << endl;
    cout << "##                                                 ## " << endl;
    cout << "##            BIENVENIDO AL PROGRAMA               ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##              PATTERN RECOGNITION                ## " << endl;
    cout << "##                     TOOL                        ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##            TUTOR: MAURICIO ITURRALDE            ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##            AUTOR: ROBERTO MALDONADO             ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##################################################### " << endl;

}

int FileHandler::askDebug(){
    
    int dMode = 0;
    cout << endl;
    cout << "Mode de debugging. (0)off (1)on: ";
    cin >> dMode;
    return dMode;
    
}

int FileHandler::askMethod(){
    
    int dMode = 0;
    cout << endl;
    cout << "Method. (1)Regular Mean Dist. (2)Weighted Mean Dist. (3)Minkowski Dist. (4)Chebyshev Dist. ";
    cin >> dMode;
    return dMode;
    
}

int FileHandler::askMode(){

    int mode = 0;
    cout << endl;
    cout << "Percentaje mode. (0)off (1)on: ";
    cin >> mode;
    return mode;
    
}

bool FileHandler::askEnable(){

    int choice = 0;
    
    cout << "Enable?. (0)off (1)on: ";
    cin >> choice;
     
    if(choice == 1)
        return true;
    else
        return false;
    
}

void FileHandler::printResults(double highScore, double lowScore) {
    
    cout << endl << "######     ######      ######      ######      ######      ######      ######      ###### " <<endl;
    cout << endl << "High value score: " << highScore <<"% over 100%"<<endl;
    cout << endl << "Low  value score: " << lowScore <<"% over 100%"<<endl;
    cout << endl << "######     ######      ######      ######      ######      ######      ######      ###### " <<endl;
    
}

void FileHandler::calculateVectorResultsAndPrint( std::vector<double>& results ){
    
    double count = 0, totalEstimado = 0, totalGlobal = 0; 
    
    cout << "ATRIBUTO:  CARACTERES.  PROMEDIOS.  TOTALES.    TILDES.   NUMEROS.   MAYUSC.   MINUSC.   SALUDO" << endl;
    cout << "PORCENTAJE: ";
        
    for(int i = 0 ; i < results.size(); i ++){
        std::cout <<results[i] <<"     ";
        if(results[i] > 1){
                count += 1; 
        }    
    }
    cout << endl;
    
    for(int i = 0 ; i < results.size(); i ++){
        
      totalEstimado +=  results[i]/count;
      totalGlobal +=  results[i]/results.size();
      
    }
    
    printResults( totalEstimado, totalGlobal);

}