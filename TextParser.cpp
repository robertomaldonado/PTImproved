/*
 TextParser

 En la clase se presentan varias formas de abrir el archivo y cargar los datos a un vector.
 Los métodos son los siguientes:
 ReadParagraphs()
 ReadLines()
 ReadWords()
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "TextParser.h"
#include <algorithm>  //Libreria requerida por linux
#include <clocale>

using namespace std;

void TextParser::LoadWholeText(string fileName) //trabajando en esto
{
  std::string tempLine = ""; //String almacenalinea de texto de forma temporal
  
  ifstream inputFile (fileName);

  if (inputFile.is_open()) {
      
    while (std::getline(inputFile, tempLine)){  //Seguir tomando el siguiente caracter del archivo de texto\
          
        wholeText = wholeText + tempLine + "\n"; //Concatenar palabra y nueva linea.
             // cout << "Leido " + tempLine << endl;    // Debug          
          }//end else
  }else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else

}

void TextParser::LoadWordVector(string fileName) //trabajando en esto
{
  string word = ""; //String almacenalinea de texto de forma temporal
  
  ifstream inputFile (fileName);

  if (inputFile.is_open()) {
      
    while ( inputFile >> word ){  //Seguir tomando el siguiente caracter del archivo de texto
              wordsVector.push_back(word); //insertar palabra
          }//end else

  }else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else

}

 double TextParser::countTildes(std::vector<int> & v){
     double tildes = 0 ; 
     
     for (int i = 0; i < v.size(); i++)
        {
          tildes = tildes + v[i];
        }
     return tildes; 
 }

void TextParser::countSpaces(std::string fileName){
   
    
   ifstream inputFile (fileName);
   
   int whiteSpacesCount = 0;
   string line = ""; 
   
  if (inputFile.is_open()) {
      
    while (getline(inputFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ' )
                whiteSpacesCount++;
        }
    }

  }
    else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else; 
 }
  

//Funcion imprime los valores de un vector del tipo string
void TextParser::printStr( std::string st){

    //Desplegar contenido del vector de lineas
    cout << "Contenido completo del archivo: "  << endl;
    cout << st ;

    cout << endl << "Fin de contenido del archivo." << endl;

}

//Funcion imprime los valores de un vector del tipo string
void TextParser::printVectorStr( std::vector<std::string>& v  ){

    //Desplegar contenido del vector de lineas
    cout << "Contenido del archivo: " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl << endl;
    }//end for

    cout << endl << "Fin de contenido del archivo." << endl;

    cout << "Informacion: ";
    cout << v.size() << endl;

}

//Funcion imprime los valores de un vector del tipo int
void TextParser::printVectorInt( std::vector<int> & v ){

    //Desplegar contenido del vector de lineas
    cout << "Contenido del archivo: " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout <<  v[i] << endl << endl;

    }//end for

    cout << endl << "Fin de contenido del archivo." << endl;

    cout << "Informacion: ";
    cout << v.size() << endl;

}

//Impresion a consola del vector combinado de palabras unicas y su conteo
void TextParser::printVectorCombined( std::vector<std::string>& v1 , std::vector<int> & v2 ){

    //Desplegar contenido del vector de lineas
    cout << "Contenido del archivo: " << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ": " << v2[i]<< endl << endl;
    }//end for

}

//Almacenar en CommonChars los caracteres existentes (31)
void TextParser::generateCharacters(){
    
    //Puntuacion
    commonChars.push_back("."); //
    commonChars.push_back(":"); //
    commonChars.push_back(","); //
    commonChars.push_back(";"); //
    
    //Exclam y Pregunta
    commonChars.push_back("¡");  //
    commonChars.push_back("!"); //
    commonChars.push_back("¿"); //
    commonChars.push_back("?"); //
    
    //Operador Matematico
    commonChars.push_back("+"); //
    commonChars.push_back("-"); //
    commonChars.push_back("*"); //
    commonChars.push_back("%"); //
    commonChars.push_back("="); //
    commonChars.push_back(">"); //
    commonChars.push_back("<"); //
    commonChars.push_back("/"); //
    
    //Operador agrupacion
    commonChars.push_back("("); //
    commonChars.push_back(")"); //
    commonChars.push_back("{"); //
    commonChars.push_back("}"); //
    commonChars.push_back("["); //
    commonChars.push_back("]"); //
    
    //Signos altos
    commonChars.push_back("\""); //

    //Otros
    commonChars.push_back("@"); //
    commonChars.push_back("#"); //
    commonChars.push_back("$"); //
    commonChars.push_back("^"); //
    commonChars.push_back("&"); //
    commonChars.push_back("|"); //
    commonChars.push_back("'"); //
    commonChars.push_back("_"); //
    
    
    for (int i = 0; i < commonChars.size() ; i++){
        commonCharsCount.push_back(0);  //Inicializar todo a cero
        commonCharsCountDec.push_back(0); 
    }
    
}

void TextParser::generateLowerCases(){
    
    //Minus case letter
    spaceLower.push_back(". a");
    spaceLower.push_back(". b");
    spaceLower.push_back(". c");
    spaceLower.push_back(". d");
    spaceLower.push_back(". e");
    spaceLower.push_back(". f");
    spaceLower.push_back(". g");
    spaceLower.push_back(". h");
    spaceLower.push_back(". i");
    spaceLower.push_back(". j");
    spaceLower.push_back(". k");
    spaceLower.push_back(". l");
    spaceLower.push_back(". m");
    spaceLower.push_back(". n");
    spaceLower.push_back(". o");
    spaceLower.push_back(". p");
    spaceLower.push_back(". q");
    spaceLower.push_back(". r");
    spaceLower.push_back(". s");
    spaceLower.push_back(". t");
    spaceLower.push_back(". u");
    spaceLower.push_back(". v");
    spaceLower.push_back(". w");
    spaceLower.push_back(". x");
    spaceLower.push_back(". y");
    spaceLower.push_back(". z");
    
}

void TextParser::generateUpperCases(){
    
    //Minus case letter
    spaceUpper.push_back(". A");
    spaceUpper.push_back(". B");
    spaceUpper.push_back(". C");
    spaceUpper.push_back(". D");
    spaceUpper.push_back(". E");
    spaceUpper.push_back(". F");
    spaceUpper.push_back(". G");
    spaceUpper.push_back(". H");
    spaceUpper.push_back(". I");
    spaceUpper.push_back(". J");
    spaceUpper.push_back(". K");
    spaceUpper.push_back(". L");
    spaceUpper.push_back(". M");
    spaceUpper.push_back(". N");
    spaceUpper.push_back(". O");
    spaceUpper.push_back(". P");
    spaceUpper.push_back(". Q");
    spaceUpper.push_back(". R");
    spaceUpper.push_back(". S");
    spaceUpper.push_back(". T");
    spaceUpper.push_back(". U");
    spaceUpper.push_back(". V");
    spaceUpper.push_back(". W");
    spaceUpper.push_back(". X");
    spaceUpper.push_back(". Y");
    spaceUpper.push_back(". Z");
    
}

void TextParser::generateAcuteChars(){
    
    //Mayus
    acuteChars.push_back("Á"); //
    acuteChars.push_back("É"); //
    acuteChars.push_back("Í"); //
    acuteChars.push_back("Ó"); //
    acuteChars.push_back("Ú");  //
    
    //Minus
    acuteChars.push_back("á");  //
    acuteChars.push_back("é"); //
    acuteChars.push_back("í"); //
    acuteChars.push_back("ó"); //
    acuteChars.push_back("ú");  //
    
   for (int i = 0; i < acuteChars.size() ; i++){     
        acuteCharsCount.push_back(0);  //Inicializar todo a cero
        acuteCharsCountDec.push_back(0);
    }
    
}

void TextParser::generateSyntacticExpr(){
    
    syntExpression.push_back("a");
    syntExpression.push_back("de");

//    for (int i = 0; i < acuteChars.size() ; i++){     
//        acuteCharsCount.push_back(0);  //Inicializar todo a cero
//        acuteCharsCountDec.push_back(0);
//    }
}

void TextParser::generateMultipleChars(){ 
    //Mayus
    multipleChars.push_back("Tilde");
    multipleChars.push_back("Whitespace");
    multipleChars.push_back("???"); //
    multipleChars.push_back("!!!"); //
    multipleChars.push_back("..."); //

   for (int i = 0; i < multipleChars.size() ; i++){     
        multipleCharsCount.push_back(0);  //Inicializar todo a cero
        multipleCharsCountDec.push_back(0);
   }
}
void TextParser::generateKumarExpressions(){

    kumarExpressions.push_back("Bueno");
    kumarExpressions.push_back("Sin embargo");
    kumarExpressions.push_back("Basicamente");

   for (int i = 0; i < kumarExpressions.size() ; i++){     
        kumarExpressionsCount.push_back(0);  //Inicializar todo a cero
        kumarExpressionsCountDec.push_back(0);
   }
}

void TextParser::generateNumericalCharacters(){
    
    numericalChars.push_back("0");
    numericalChars.push_back("1");
    numericalChars.push_back("2");
    numericalChars.push_back("3");
    numericalChars.push_back("4");
    numericalChars.push_back("5");
    numericalChars.push_back("6");
    numericalChars.push_back("7");
    numericalChars.push_back("8");
    numericalChars.push_back("9");

    for (int i = 0; i < numericalChars.size() ; i++){    
        
        numericalCharsCountDec.push_back(0);
   }
}

void TextParser::generateMayusCharacters(){
    
    mayusChars.push_back("A");
    mayusChars.push_back("B");
    mayusChars.push_back("C");
    mayusChars.push_back("D");
    mayusChars.push_back("E");
    mayusChars.push_back("F");
    mayusChars.push_back("G");
    mayusChars.push_back("H");
    mayusChars.push_back("I");
    mayusChars.push_back("J");
    mayusChars.push_back("K");
    mayusChars.push_back("L");
    mayusChars.push_back("M");
    mayusChars.push_back("N");
    mayusChars.push_back("O");
    mayusChars.push_back("P");
    mayusChars.push_back("Q");
    mayusChars.push_back("R");
    mayusChars.push_back("S");
    mayusChars.push_back("T");
    mayusChars.push_back("U");
    mayusChars.push_back("V");
    mayusChars.push_back("W");
    mayusChars.push_back("X");
    mayusChars.push_back("Y");
    mayusChars.push_back("Z");

    for (int i = 0; i < mayusChars.size() ; i++){    
        
        mayusCountDec.push_back(0); 
        mayusCountDec2.push_back(0); 
   }
}

void TextParser::generateMinusCharacters(){
    
    minusChars.push_back("a");
    minusChars.push_back("b");
    minusChars.push_back("c");
    minusChars.push_back("d");
    minusChars.push_back("e");
    minusChars.push_back("f");
    minusChars.push_back("g");
    minusChars.push_back("h");
    minusChars.push_back("i");
    minusChars.push_back("j");
    minusChars.push_back("k");
    minusChars.push_back("l");
    minusChars.push_back("m");
    minusChars.push_back("n");
    minusChars.push_back("o");
    minusChars.push_back("p");
    minusChars.push_back("q");
    minusChars.push_back("r");
    minusChars.push_back("s");
    minusChars.push_back("t");
    minusChars.push_back("u");
    minusChars.push_back("v");
    minusChars.push_back("w");
    minusChars.push_back("x");
    minusChars.push_back("y");
    minusChars.push_back("z");

    for (int i = 0; i < minusChars.size() ; i++){    
        
        minusCountDec.push_back(0);  
        minusCountDec2.push_back(0); 
   }

}

void TextParser::generateGreetings(){
    
    greetingExpression.push_back("Hola");
    greetingExpression.push_back("Buen Día");
    greetingExpression.push_back("Estimado");
    greetingExpression.push_back("Estimada");
    greetingExpression.push_back("Buenos");
    greetingExpression.push_back("Buenas");
    greetingExpression.push_back("Gracias");
    greetingExpression.push_back("Atentamente");
    greetingExpression.push_back("Cordialmente");
    greetingExpression.push_back("Suerte");
    greetingExpression.push_back("Saludos");
    
    for (int i = 0; i < greetingExpression.size() ; i++){    
         
        greetingCountDec.push_back(0); 
   }
}


void TextParser::compareGreetings(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    for (int i = 0; i < toCompare.size() ; i++)
    {
        
        for(int j=0; j < greetingExpression.size() ; j++){
                std::size_t found = toCompare[i].find(greetingExpression[j]);
                if (found!=std::string::npos)
                {
                greetingCountDec[j] =  greetingCountDec[j]+1;
               // found = 0;
                }        
      }
    } 
}

void TextParser::compareChars(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    for (int i = 0; i < toCompare.size() ; i++)
    {
        
        for(int j=0; j < commonChars.size() ; j++){
                std::size_t found = toCompare[i].find(commonChars[j]);
                if (found!=std::string::npos)
                {
                commonCharsCount[j] =  commonCharsCount[j]+1;
                found = 0;
                }        
      }
    } 
}

void TextParser::compareMultipleChars(std::vector<std::string>& toCompare){
       
    for(int i = 0 ; i < acuteCharsCount.size() ; i++){
        multipleCharsCount[0] += acuteCharsCount[i];
    }
      // multipleCharsCount[1] = 9 ; //Correguir
        
    for (int i = 0; i < toCompare.size() ; i++){
        for (int k=0; k < multipleChars.size() ; k++){
                std::size_t pos = toCompare[i].find(multipleChars[k]);
                if (pos!=std::string::npos)
                {
                multipleCharsCount[k] =  multipleCharsCount[k]+1;
                }
        }
    }
 
}
void TextParser::compareKumarExpressions(std::vector<std::string>& toCompare){
       
    for(int i = 0 ; i < acuteCharsCount.size() ; i++){
        multipleCharsCount[0] += acuteCharsCount[i];
    }
       // multipleCharsCount[1] = 9 ; //Correguir
        
    for (int i = 0; i < toCompare.size() ; i++){
        
        for (int k=0; k < kumarExpressions.size() ; k++){
                std::size_t pos = toCompare[i].find(kumarExpressions[k]);
                if (pos!=std::string::npos)
                {
                    kumarExpressionsCount[k] =  kumarExpressionsCount[k]+1;
                }
        }
    }
       // cout << "PARRAFOS: " << getParagraphs() <<endl;
 
}

void TextParser::addKumarAvg(){
    
        kumarExpressionsCount.push_back(kumarExpressionsCount[0]/wordsVector.size());
        kumarExpressionsCount.push_back(kumarExpressionsCount[1]/wordsVector.size());
        kumarExpressionsCount.push_back(kumarExpressionsCount[2]/wordsVector.size());

}

int TextParser::getParagraphs(std::string text){
    
    int number_of_p = 0;
    string comp = "";
    
     for(unsigned int i=0; i < text.length(); i++){
       //     cout << "Text: "<<text[i] << endl;
         
           if ( text[i]== '\n')
                        number_of_p++;
         }
    
    return number_of_p;
}

int TextParser::getNumberWords(){
    return wordsVector.size();
}

int TextParser::getAvgWordLength(){
    int sum = 0;
    int avg = 0;
    
    for (unsigned int i=0; i < wordsVector.size(); i++){
        
        sum += wordsVector[i].size();
    }
    avg = sum/wordsVector.size(); 
    
    return avg;
}

int TextParser::getSentencesMessage(){
    int sentences = commonCharsCount[0] + commonCharsCount[5] + commonCharsCount[7] ;
    return sentences;
}

double TextParser::getDotPerPar(){
    double dotsPP = commonCharsCount[0] / (double)getParagraphs(wholeText) ;
    return dotsPP;
}

double TextParser::getCommaPerPar(){
    double commaPP = commonCharsCount[2] / (double)getParagraphs(wholeText) ;
    return commaPP;
}

double TextParser::getColonPerPar(){
    double colonPP = commonCharsCount[1] / (double)getParagraphs(wholeText) ;
    return colonPP;
}

double TextParser::getSemicolonPerPar(){
    double semicolonPP = commonCharsCount[3] / (double)getParagraphs(wholeText) ;
    return semicolonPP;
}
double TextParser::getQosPerPar(){
    double qosPP = commonCharsCount[3] / (double)getParagraphs(wholeText) ;
    return qosPP;
}
double TextParser::getMultipleQosPerPar(){
    double mqosPP = commonCharsCount[7] / (double)getParagraphs(wholeText) ;
    return mqosPP;
}
double TextParser::getWordsPerPar(){
    double wordsPS = wordsVector.size() / (double)getParagraphs(wholeText) ;
    return wordsPS;
}
double TextParser::getWordsPerSent(){
    double wordsPS = wordsVector.size() / (double)getSentencesMessage() ;
    return wordsPS;
}
double TextParser::getWsPerSent(){
    double wsPS = wordsVector.size() / (double)getSentencesMessage() ;
    return wsPS;
}
double TextParser::getSpaceBeforeComma(std::string wrd){
    
    double cBs = 0;
    for(int i =0 ; i < wrd.size()-2; i++){
    
        string tmp = wrd.substr(i,2);
        
        if( tmp.compare(" ,") == 0 ){
           cBs +=1;  
        }
        
    }
    return cBs;
    
}
double TextParser::getSpaceAfterComma(std::string wrd){
    
    double sAc = 0;
    
    for(int i =0 ; i < wrd.size()-2; i++){
    
        string tmp = wrd.substr(i,2);
        
        if( tmp.compare(", ") == 0 ){
           sAc +=1;  
        }
        
    }
    return sAc;
    
}
double TextParser::getSpaceBeforeCommaAvg(){
    
    return getSpaceBeforeComma(wholeText) / (double) wordsVector.size() ;
    
}

double TextParser::getSpaceAfterCommaAvg(){
    
    return getSpaceAfterComma(wholeText) / (double) wordsVector.size() ;
    
}

double TextParser::getWS(std::string text){ 
    
    int number_of_ws = 0;
     for(unsigned int i=0; i < text.length(); i++){
           if ( text[i]==' ')
                        number_of_ws++;
         }
    return number_of_ws;
    
}
double TextParser::getBeginnigUCase(std::string text){
    double uc =  0; 
    
    for(int j =0 ; j < text.size()-3; j++){
        string tmp = text.substr(j,3);
        for(int k =0 ; k < spaceUpper.size() ; k++){
                if( tmp.compare(spaceUpper[k]) == 0 ){
                   uc +=1;  
                 }
        }
    }
    
    return uc;
}

double TextParser::getBeginnigLCase(std::string text){
    double lc =  0; 
    
    for(int j =0 ; j < text.size()-3; j++){
        string tmp = text.substr(j,3);
        for(int k =0 ; k < spaceLower.size() ; k++){
            
                if( tmp.compare(spaceLower[k]) == 0 ){
                lc +=1;  
                 }
        }
    }
    
    return lc;
}

void TextParser::getAverages(){
    
    averageVectorCountDec.push_back( getAvgWordLength() );
    averageVectorCountDec.push_back( getWordsPerSent() );
    averageVectorCountDec.push_back( getWordsPerPar() );
    averageVectorCountDec.push_back( getDotPerPar() );
    averageVectorCountDec.push_back( getCommaPerPar()  );
    averageVectorCountDec.push_back( getColonPerPar() );
    averageVectorCountDec.push_back( getSemicolonPerPar()  );
    averageVectorCountDec.push_back( getQosPerPar() );
    averageVectorCountDec.push_back( getMultipleQosPerPar() );
    averageVectorCountDec.push_back( getWS(wholeText)/(double)wordsVector.size() );
    averageVectorCountDec.push_back( kumarExpressionsCount[0]/(double)wordsVector.size() );    
    averageVectorCountDec.push_back( kumarExpressionsCount[1]/(double)wordsVector.size() );
    averageVectorCountDec.push_back( kumarExpressionsCount[2]/(double)wordsVector.size() );
    averageVectorCountDec.push_back( commonCharsCount[0]/(double)wordsVector.size() );
    averageVectorCountDec.push_back( getSpaceAfterCommaAvg() );
    averageVectorCountDec.push_back( getSpaceBeforeCommaAvg() ); 
    
}
void TextParser::getTotals(){
    
        totalsVectorCountDec.push_back( getBeginnigUCase(wholeText) ); //Sentences begin w/ UpperC
        totalsVectorCountDec.push_back( getBeginnigLCase(wholeText) ); //Sentences begin w/ LowerC
        totalsVectorCountDec.push_back( getNumberWords() );
        totalsVectorCountDec.push_back( getSentencesMessage() );
        totalsVectorCountDec.push_back( getParagraphs(wholeText) );
        totalsVectorCountDec.push_back( countTildes(acuteCharsCount) );
        totalsVectorCountDec.push_back( wordsVector.size() );
        totalsVectorCountDec.push_back( multipleCharsCount[2] );
        totalsVectorCountDec.push_back( multipleCharsCount[3] );
        totalsVectorCountDec.push_back( multipleCharsCount[4] );
        totalsVectorCountDec.push_back( getWS(wholeText) ); 
        totalsVectorCountDec.push_back( (double)kumarExpressionsCount[0] );
        totalsVectorCountDec.push_back((double)kumarExpressionsCount[1]);
        totalsVectorCountDec.push_back((double)kumarExpressionsCount[2]);
        totalsVectorCountDec.push_back( getSpaceAfterComma(wholeText) );
        totalsVectorCountDec.push_back( getSpaceBeforeComma(wholeText) );

}

void TextParser::compareAcuteChars(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    for (int i = 0; i < toCompare.size() ; i++){
        
         //std::cout << " Iterando en metodo" <<endl;//Debug
         
        for(int j= 0; j < acuteChars.size() ; j++){
            
               // std::cout << "          Dentro de metodo" <<endl;//Debug
                
                  std::size_t found = toCompare[i].find(acuteChars[j]);
                        if (found!=std::string::npos)
                        {
                 //       std::cout <<acuteChars[j]<< " es un match con " << wordsAndCharsVector[i] <<endl;//Debug
                        acuteCharsCount[j] =  acuteCharsCount[j]+1;
                        //break;
                        }
        }
    }

}

void TextParser::compareNumericalChars(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    int zero = 0, one = 0, two = 0 , three= 0, four= 0, five= 0, six= 0, seven= 0, eight= 0, nine= 0 ;
    int total = 0;
    
    for (int i = 0; i < toCompare.size() ; i++){
                
         zero += count(toCompare[i].begin(), toCompare[i].end(), '0');
         one += count(toCompare[i].begin(), toCompare[i].end(), '1');
         two += count(toCompare[i].begin(), toCompare[i].end(), '2');
         three += count(toCompare[i].begin(), toCompare[i].end(), '3');
         four += count(toCompare[i].begin(), toCompare[i].end(), '4');
         five += count(toCompare[i].begin(), toCompare[i].end(), '5');
         six += count(toCompare[i].begin(), toCompare[i].end(), '6');
         seven += count(toCompare[i].begin(), toCompare[i].end(),'7');
         eight += count(toCompare[i].begin(), toCompare[i].end(), '8');
         nine += count(toCompare[i].begin(), toCompare[i].end(), '9');
         //break;
        // cout << "Contando carateres 0.." << c <<endl;

    }
    
    total = zero + one + two + three + four + five + six + seven + eight + nine;
   // cout << "Total de numericos son: " << total <<endl;
    
    numericalCharsCountDec[0]= zero;
    numericalCharsCountDec[1]= one;
    numericalCharsCountDec[2]= two;
    numericalCharsCountDec[3]= three;
    numericalCharsCountDec[4]= four;
    numericalCharsCountDec[5]= five;
    numericalCharsCountDec[6]= six;
    numericalCharsCountDec[7]= seven;
    numericalCharsCountDec[8]= eight;
    numericalCharsCountDec[9]= nine;
    
    //numericalCharsCountDec.push_back(total);
}

void TextParser::compareMayusCharsImproved(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    int a = 0, b = 0, c = 0 , d= 0, e= 0, f= 0, g= 0, h= 0, i= 0, j= 0, k=0 , l=0, m=0 ;
    int n = 0, o = 0, p = 0 , q= 0, r= 0,  s=0, t= 0, u= 0, v= 0, w= 0, x=0 , y=0, z=0 ;
    int total = 0;
    
    for (int op = 0; op < toCompare.size() ; op++){
                
         a += count(toCompare[i].begin(), toCompare[i].end(), 'A');
         b += count(toCompare[i].begin(), toCompare[i].end(), 'B');
         c += count(toCompare[i].begin(), toCompare[i].end(), 'C');
         d += count(toCompare[i].begin(), toCompare[i].end(), 'D');
         e += count(toCompare[i].begin(), toCompare[i].end(), 'E');
         f += count(toCompare[i].begin(), toCompare[i].end(), 'F');
         g += count(toCompare[i].begin(), toCompare[i].end(), 'G');
         h += count(toCompare[i].begin(), toCompare[i].end(),'H');
         i += count(toCompare[i].begin(), toCompare[i].end(), 'I');
         j += count(toCompare[i].begin(), toCompare[i].end(), 'J');
         k += count(toCompare[i].begin(), toCompare[i].end(), 'K');
         l += count(toCompare[i].begin(), toCompare[i].end(), 'L');
         m += count(toCompare[i].begin(), toCompare[i].end(), 'M');
         n += count(toCompare[i].begin(), toCompare[i].end(), 'N');
         o += count(toCompare[i].begin(), toCompare[i].end(), 'O');
         p += count(toCompare[i].begin(), toCompare[i].end(), 'P');
         q += count(toCompare[i].begin(), toCompare[i].end(), 'Q');
         r += count(toCompare[i].begin(), toCompare[i].end(), 'R');
         s += count(toCompare[i].begin(), toCompare[i].end(),'S');
         t += count(toCompare[i].begin(), toCompare[i].end(), 'T');
         u += count(toCompare[i].begin(), toCompare[i].end(), 'U');
         v += count(toCompare[i].begin(), toCompare[i].end(), 'V');
         w += count(toCompare[i].begin(), toCompare[i].end(), 'W');
         x += count(toCompare[i].begin(), toCompare[i].end(), 'X');
         y += count(toCompare[i].begin(), toCompare[i].end(), 'Y');
         z += count(toCompare[i].begin(), toCompare[i].end(), 'Z');
         //break;
         // << "Contando carateres mayus.." << a <<endl;

    }
    
    for (int i = 0; i < toCompare.size() ; i++)
    {
        
        for(int j=0; j < mayusChars.size() ; j++){
                std::size_t found = toCompare[i].find(mayusChars[j]);
                if (found!=std::string::npos)
                {
                mayusCountDec2[j] =  mayusCountDec2[j]+1;
                found = 0;
                }        
      }
    } 
      
    total = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    
    mayusCountDec[0]= a;
    mayusCountDec[1]= b;
    mayusCountDec[2]= c;
    mayusCountDec[3]= d;
    mayusCountDec[4]= e;
    mayusCountDec[5]= f;
    mayusCountDec[6]= g;
    mayusCountDec[7]= h;
    mayusCountDec[8]= i;
    mayusCountDec[9]= j;
    mayusCountDec[10]= k;
    mayusCountDec[11]= l;
    mayusCountDec[12]= m;
    mayusCountDec[13]= n;
    mayusCountDec[14]= o;
    mayusCountDec[15]= p;
    mayusCountDec[16]= q;
    mayusCountDec[17]= r;
    mayusCountDec[18]= s;
    mayusCountDec[19]= t;
    mayusCountDec[20]= u;
    mayusCountDec[21]= v;
    mayusCountDec[22]= w;
    mayusCountDec[23]= x;
    mayusCountDec[24]= y;
    mayusCountDec[25]= z;
    
}

void TextParser::compareMinusCharsImproved(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    int a = 0, b = 0, c = 0 , d= 0, e= 0, f= 0, g= 0, h= 0, i= 0, j= 0, k=0 , l=0, m=0 ;
    int n = 0, o = 0, p = 0 , q= 0, r= 0,  s=0, t= 0, u= 0, v= 0, w= 0, x=0 , y=0, z=0 ;
    int total = 0;
    
    for (int op = 0; op < toCompare.size() ; op++){
                
         a += count(toCompare[i].begin(), toCompare[i].end(), 'a');
         b += count(toCompare[i].begin(), toCompare[i].end(), 'b');
         c += count(toCompare[i].begin(), toCompare[i].end(), 'c');
         d += count(toCompare[i].begin(), toCompare[i].end(), 'd');
         e += count(toCompare[i].begin(), toCompare[i].end(), 'e');
         f += count(toCompare[i].begin(), toCompare[i].end(), 'f');
         g += count(toCompare[i].begin(), toCompare[i].end(), 'g');
         h += count(toCompare[i].begin(), toCompare[i].end(),'h');
         i += count(toCompare[i].begin(), toCompare[i].end(), 'i');
         j += count(toCompare[i].begin(), toCompare[i].end(), 'j');
         k += count(toCompare[i].begin(), toCompare[i].end(), 'k');
         l += count(toCompare[i].begin(), toCompare[i].end(), 'l');
         m += count(toCompare[i].begin(), toCompare[i].end(), 'm');
         n += count(toCompare[i].begin(), toCompare[i].end(), 'n');
         o += count(toCompare[i].begin(), toCompare[i].end(), 'o');
         p += count(toCompare[i].begin(), toCompare[i].end(), 'p');
         q += count(toCompare[i].begin(), toCompare[i].end(), 'q');
         r += count(toCompare[i].begin(), toCompare[i].end(), 'r');
         s += count(toCompare[i].begin(), toCompare[i].end(),'s');
         t += count(toCompare[i].begin(), toCompare[i].end(), 't');
         u += count(toCompare[i].begin(), toCompare[i].end(), 'u');
         v += count(toCompare[i].begin(), toCompare[i].end(), 'v');
         w += count(toCompare[i].begin(), toCompare[i].end(), 'w');
         x += count(toCompare[i].begin(), toCompare[i].end(), 'x');
         y += count(toCompare[i].begin(), toCompare[i].end(), 'y');
         z += count(toCompare[i].begin(), toCompare[i].end(), 'z');

    }
   
    
    for (int i = 0; i < toCompare.size() ; i++)
    {
        
        for(int j=0; j < minusChars.size() ; j++){
                std::size_t found = toCompare[i].find(minusChars[j]);
                if (found!=std::string::npos)
                {
                minusCountDec2[j] =  minusCountDec2[j]+1;
                found = 0;
                }        
      }
    } 
    
    minusCountDec[0]= a;
    minusCountDec[1]= b;
    minusCountDec[2]= c;
    minusCountDec[3]= d;
    minusCountDec[4]= e;
    minusCountDec[5]= f;
    minusCountDec[6]= g;
    minusCountDec[7]= h;
    minusCountDec[8]= i;
    minusCountDec[9]= j;
    minusCountDec[10]= k;
    minusCountDec[11]= l;
    minusCountDec[12]= m;
    minusCountDec[13]= n;
    minusCountDec[14]= o;
    minusCountDec[15]= p;
    minusCountDec[16]= q;
    minusCountDec[17]= r;
    minusCountDec[18]= s;
    minusCountDec[19]= t;
    minusCountDec[20]= u;
    minusCountDec[21]= v;
    minusCountDec[22]= w;
    minusCountDec[23]= x;
    minusCountDec[24]= y;
    minusCountDec[25]= z;
    
}

void TextParser::generateNumericalOutputChars(){
    
    outputNumericalChars.push_back("ZERO");
    outputNumericalChars.push_back("ONE");
    outputNumericalChars.push_back("TWO");
    outputNumericalChars.push_back("THREE");
    outputNumericalChars.push_back("FOUR");
    outputNumericalChars.push_back("FIVE");
    outputNumericalChars.push_back("SIX");
    outputNumericalChars.push_back("SEVEN");
    outputNumericalChars.push_back("EIGHT");
    outputNumericalChars.push_back("NINE");
    
}

void TextParser::generateOutputGreetings(){
    
    outputGreeting.push_back("G1");
    outputGreeting.push_back("G2");
    outputGreeting.push_back("G3");
    outputGreeting.push_back("G4");
    outputGreeting.push_back("G5");
    outputGreeting.push_back("G6");
    outputGreeting.push_back("F1");
    outputGreeting.push_back("F2");
    outputGreeting.push_back("F3");
    outputGreeting.push_back("F4");
    outputGreeting.push_back("F5");
    
}

//Dar formato al archivo de plot. Notacion reconocible por programas del shellScripting
void TextParser::generateOutputChars(){
    
    //Puntuacion
    outputCommonChars.push_back("PPD"); //
    outputCommonChars.push_back("PCN"); //
    outputCommonChars.push_back("PCA"); //
    outputCommonChars.push_back("PCS"); //
    
    //Exclam y Pregunta
    outputCommonChars.push_back("EEO");  //
    outputCommonChars.push_back("EEC"); //
    outputCommonChars.push_back("EQO"); //
    outputCommonChars.push_back("EQC"); //
    
    //Operador Matematico
    outputCommonChars.push_back("MPS"); //
    outputCommonChars.push_back("MMS"); //
    outputCommonChars.push_back("MTS"); //
    outputCommonChars.push_back("MMO"); //
    outputCommonChars.push_back("MEQ"); //
    outputCommonChars.push_back("MGR"); //
    outputCommonChars.push_back("MLR"); //
    outputCommonChars.push_back("MDN"); //
    
    //Operador agrupacion
    outputCommonChars.push_back("GPO"); //
    outputCommonChars.push_back("GPC"); //
    outputCommonChars.push_back("GCO"); //
    outputCommonChars.push_back("GCC"); //
    outputCommonChars.push_back("GBO"); //
    outputCommonChars.push_back("GBC"); //
    
    //Signos altos
    outputCommonChars.push_back("OBS"); //
    
    //Otros
    outputCommonChars.push_back("OAA"); //
    outputCommonChars.push_back("ONS"); //
    outputCommonChars.push_back("ODS"); //
    outputCommonChars.push_back("OHO"); //
    outputCommonChars.push_back("ONP"); //
    outputCommonChars.push_back("OVD"); //
    outputCommonChars.push_back("OPS"); //
    outputCommonChars.push_back("OUS"); //
}

//Dar formato al archivo de plot. Notacion reconocible por programas del shellScripting
void TextParser::generateAcuteOutputChars(){
    
    //Puntuacion
    outputAcuteChars.push_back("MAA"); //
    outputAcuteChars.push_back("MAE");
    outputAcuteChars.push_back("MAI");
    outputAcuteChars.push_back("MAO");
    outputAcuteChars.push_back("MAU");
    
    outputAcuteChars.push_back("MIA");
    outputAcuteChars.push_back("MIE");
    outputAcuteChars.push_back("MII");
    outputAcuteChars.push_back("MIO");
    outputAcuteChars.push_back("MIU");

}

void TextParser::generateMultipleOutputChars(){
    
    //Puntuacion
    outputAcuteChars.push_back("TLD"); // Tildes
    outputAcuteChars.push_back("WSM"); // Whitespaces in message
    outputAcuteChars.push_back("MQM"); // Multiple Question
    outputAcuteChars.push_back("MQM"); // Multiple Exclamation
    outputAcuteChars.push_back("MEL"); // Multiple Dots ...

}

void TextParser::generateOutputAverageVector(){

    outputAverageVector.push_back( "AWL");
    outputAverageVector.push_back("AWPS");
    outputAverageVector.push_back("AWPP");
    outputAverageVector.push_back("ADPP");
    outputAverageVector.push_back("ACPP");
    outputAverageVector.push_back("ACOPP");
    outputAverageVector.push_back("ASCPP");
    outputAverageVector.push_back("AQPP");
    outputAverageVector.push_back("AMQPP");
    outputAverageVector.push_back("AWSPS");
    outputAverageVector.push_back("AK1");
    outputAverageVector.push_back("AK2");
    outputAverageVector.push_back("AK3");
    outputAverageVector.push_back("AWS");
    outputAverageVector.push_back("ACAS");
    outputAverageVector.push_back("ACBS");

}

void TextParser::generateOutputTotalsVector(){
    
        outputTotalsVector.push_back("TUS");
        outputTotalsVector.push_back("TLS");
        outputTotalsVector.push_back("TNW");
        outputTotalsVector.push_back("TNS");
        outputTotalsVector.push_back("TNP");
        outputTotalsVector.push_back("TNT");
        outputTotalsVector.push_back("TNWS");
        
        outputTotalsVector.push_back("TNMQ");
        outputTotalsVector.push_back("TNME");
        outputTotalsVector.push_back("TNE");
        outputTotalsVector.push_back("TNWAP");
        outputTotalsVector.push_back("TNK1");
        outputTotalsVector.push_back("TNK2");
        outputTotalsVector.push_back("TNK3");
        outputTotalsVector.push_back("TNCBS");
        outputTotalsVector.push_back("TNCAS");

}

void TextParser::generateOutputMayusChars(){
    
        outputMayus.push_back("A");
        outputMayus.push_back("B");
        outputMayus.push_back("C");
        outputMayus.push_back("D");
        outputMayus.push_back("E");
        outputMayus.push_back("F");
        outputMayus.push_back("G");
        outputMayus.push_back("H");
        outputMayus.push_back("I");
        outputMayus.push_back("J");
        outputMayus.push_back("K");
        outputMayus.push_back("L");
        outputMayus.push_back("M");
        outputMayus.push_back("N");
        outputMayus.push_back("O");
        outputMayus.push_back("P");
        outputMayus.push_back("Q");
        outputMayus.push_back("R");
        outputMayus.push_back("S");
        outputMayus.push_back("T");
        outputMayus.push_back("U");
        outputMayus.push_back("V");
        outputMayus.push_back("W");
        outputMayus.push_back("X");
        outputMayus.push_back("Y");
        outputMayus.push_back("Z");

}

void TextParser::generateOutputMinusChars(){
    
        outputMinus.push_back("a");
        outputMinus.push_back("b");
        outputMinus.push_back("c");
        outputMinus.push_back("d");
        outputMinus.push_back("e");
        outputMinus.push_back("f");
        outputMinus.push_back("g");
        outputMinus.push_back("h");
        outputMinus.push_back("i");
        outputMinus.push_back("j");
        outputMinus.push_back("k");
        outputMinus.push_back("l");
        outputMinus.push_back("m");
        outputMinus.push_back("n");
        outputMinus.push_back("o");
        outputMinus.push_back("p");
        outputMinus.push_back("q");
        outputMinus.push_back("r");
        outputMinus.push_back("s");
        outputMinus.push_back("t");
        outputMinus.push_back("u");
        outputMinus.push_back("v");
        outputMinus.push_back("w");
        outputMinus.push_back("x");
        outputMinus.push_back("y");
        outputMinus.push_back("z");

}

void TextParser::refineResults(){
  
     for (int i = 0; i < acuteCharsCount.size() ; i++)
     {
         acuteCharsCountDec[i] = (acuteCharsCount[i]/(double)wordsVector.size())*100;
         //cout << "Se ha dividido para: " << wordsVector.size() << endl;
     }
     
     for (int j = 0; j < commonCharsCount.size() ; j++)
     {
         commonCharsCountDec[j] = (commonCharsCount[j]/(double)wordsVector.size())*100;
     }
     
     for (int k = 0; k < multipleCharsCount.size() ; k++)
     {
         multipleCharsCountDec[k] = (multipleCharsCount[k]/(double)wordsVector.size())*100;
     }
     
     for (int m = 0; m < kumarExpressions.size() ; m++)
     {
         kumarExpressionsCountDec[m] = (kumarExpressionsCount[m]/(double)wordsVector.size())*100;
     }
     
     for (int n = 0; n < numericalCharsCountDec.size() ; n++)
     {
         numericalCharsCountDec[n] = (numericalCharsCountDec[n]/(double)wordsVector.size())*100;
     }
     
     for (int o = 0; o < mayusCountDec.size() ; o++)
     {
         mayusCountDec[o] = (mayusCountDec[o]/(double)wordsVector.size())*100;
     }
     
     for (int o = 0; o < mayusCountDec2.size() ; o++)
     {
         mayusCountDec2[o] = (mayusCountDec2[o]/(double)wordsVector.size())*100;
     }
     
      for (int p = 0; p < minusCountDec.size() ; p++)
     {
         minusCountDec[p] = (minusCountDec[p]/(double)wordsVector.size())*100;
     }
     
     for (int p = 0; p < minusCountDec.size() ; p++)
     {
         minusCountDec2[p] = (minusCountDec2[p]/(double)wordsVector.size())*100;
     }
     
//     for (int p = 0; p < greetingCountDec.size() ; p++)
//     {
//         greetingCountDec[p] = (greetingCountDec[p]/(double)wordsVector.size())*100;
//     }
     
    
}


void TextParser::writeFilePlot2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name, std::string ext){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append(ext);
    
    //Abrir el archivo
    myfile.open(outputName);
    
    //Escribir en el archivo
    myfile << "##### CATEGORIA SIMBOLOS GLOBALES ####" << endl;
    
    myfile << "PPD: Punctuation Period\nPCN: Punctuation Colon\nPCA: Punctuation Comma\nPSC: Punctuation Semicolon\n"
            "  EEO: Expression Exclamation Open\nEEC: Expression Exclamation Close\nEQO: Expression Question Open\nEQC: Expression Question Close\n"
            "  MPS: Mathematical Plus\nMMS: Mathematical Minus\nMTS: Mathematical Times\nMMO: Mathematical Modulus\nMEQ: Mathematical Equals\nMGR: Mathematical Greater\nMLR: Mathematical Lesser\nMDN: Mathematical Division\n"
            "  GPO: Grouping Parenthesis Open\nGPC: Grouping Parenthesis Close\nGCO: Grouping Curly Bracket Open\nGCC: Grouping XCurly Bracket Close\nGBO: Grouping Bracket Open\nGBC: Grouping Bracket Close\n"
            "  OBS: Other Back Slash\nOAA: Other Arroba\nONS: Other Number Symbol\nODS: Other Dollar Sign\nOHO: Other Carret\nONP: Other Ampersand\nOVD: Other Pipe\n\n" << endl;
    
    myfile << "FILE " << name <<" ";
    for (int i = 0; i < v2.size(); i++) //Iterara sobre todas las palabras
    {
        myfile << v1[i] << " " << v2[i]<< " ";
    }//end for
    
    //Cerrar el archivo saliente
    myfile.close();   
}

void TextParser::resetVariables(){
    
    cout << endl << "Cleared Variables... Ready for next text..." << endl;
    wordsVector.clear();
    wholeText = "";
    
   // uniqueWordsVector.clear();
    //uniqueWordsVectorCount.clear();
    //clonedVector.clear();
    
    commonCharsCount.clear();commonCharsCountDec.clear();commonChars.clear();averageVectorCountDec.clear();
    
    acuteCharsCount.clear();acuteCharsCountDec.clear();acuteChars.clear();
    
    multipleCharsCount.clear();multipleChars.clear();multipleCharsCountDec.clear();
    
    outputCommonChars.clear();
    outputAcuteChars.clear();
    outputAverageVector.clear();
    outputTotalsVector.clear();
    
    kumarExpressions.clear();kumarExpressionsCount.clear();kumarExpressionsCountDec.clear();
    
    totalsVectorCountDec.clear();
    
    mainVector.clear();
    
    numericalCharsCountDec.clear();numericalChars.clear();outputNumericalChars.clear();
    
    outputMayus.clear();mayusCountDec.clear();mayusChars.clear();mayusCountDec2.clear();
    
    outputMinus.clear();minusCountDec.clear();minusChars.clear();minusCountDec2.clear();
    
    greetingExpression.clear();
    outputGreeting.clear();
    greetingCountDec.clear();
    
    spaceLower.clear();spaceUpper.clear();

    syntExpression.clear();
}