/* 
 * File:   TextParser.h
 * Author: robertomaldonado
 *
 * Created on June 26, 2015, 3:08 PM
 */
#ifndef TEXTPARSER_H
#define	TEXTPARSER_H

class TextParser
{
public:
    //Methods for the class
    void LoadWordVector(std::string );
    void LoadWholeText(std::string);
    
    //Debugging (Mostrar datos en  consola) 
    double countTildes( std::vector<int> & v );
    void countSpaces(std::string);
    void printStr( std::string st );
    void printVectorStr( std::vector<std::string>& v );
    void printVectorInt( std::vector<int>& v );
    void printVectorCombined( std::vector<std::string>& v1 , std::vector<int> & v2 );
    void printVectorCombined( std::vector<std::string>& v1 , std::vector<double> & v2 );
    
    //Recursivo para almacenar palabras temporales
    
    //void generateUniques();
    //void generateUniquesCount();
    void generateGreetings();
    void generateMayusCharacters();
    void generateMinusCharacters();
    void generateNumericalCharacters();
    void generateCharacters(); //Genera caracteres de puntuacion 
    void generateAcuteChars(); //Caracteres tildados
    void generateMultipleChars(); //Caracteres multiples
    void generateKumarExpressions(); //Caracteres tildados
    
    void generateSyntacticExpr(); 
    
    
    int getParagraphs(std::string text);
    int getNumberWords();
    int getAvgWordLength();
    int getSentencesMessage();
    double getDotPerPar();
    double getCommaPerPar();
    double getColonPerPar();
    double getSemicolonPerPar();
    double getQosPerPar();
    double getMultipleQosPerPar();
    double getWordsPerPar();
    double getWordsPerSent();
    double getWsPerSent();
    double getSpaceBeforeCommaAvg();
    double getSpaceBeforeComma(std::string wrd );
    double getSpaceAfterComma(std::string wrd);
    void getAverages();
    double getWS(std::string text);
    double getBeginnigUCase(std::string text);
    double getBeginnigLCase(std::string text);
    double getSpaceAfterCommaAvg();
    
    void getTotals();

    void compareMayusCharsImproved(std::vector<std::string>& toCompare);
    void compareMinusCharsImproved(std::vector<std::string>& toCompare);
     
    void compareNumericalChars(std::vector<std::string>& toCompare);
    void compareChars(std::vector<std::string>& toCompare); //Compara los caracteres comunes 
    void compareAcuteChars(std::vector<std::string>& toCompare); //Compara los caracteres acentuados
    void compareMultipleChars(std::vector<std::string>& toCompare);
    void compareKumarExpressions(std::vector<std::string>& toCompare);
    void compareGreetings(std::vector<std::string>& toCompare);
    
    void addKumarAvg();
    
    void generateNumericalOutputChars();
    void generateOutputChars(); //Almacena nombres representativos para los graficos
    void generateAcuteOutputChars(); //Almacena nombres representativos para los graficos
    void generateMultipleOutputChars();
    void generateOutputAverageVector();
    void generateOutputMayusChars();
    void generateOutputMinusChars();
    void generateOutputGreetings();
    
    void generateLowerCases();
    void generateUpperCases();
    
    void generateOutputTotalsVector();
    
    void refineResults();
    
    void writeFilePlot2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name,  std::string ext); //Escribe al file para lectura
    void resetVariables();  //Utilizado para reiniciar variables, en manejo de archivos múlitples

    //Class variables
public:
    
    std::string wholeText;
    std::vector<std::string> wordsAndCharsVector; //Toda la lectura del archivo en vector
    std::vector<std::string> wordsVector;
    std::vector<std::string> spaceLower;
    std::vector<std::string> spaceUpper;
    
    std::vector<std::string> syntExpression;
    
    //std::vector<std::string> clonedVector;  //Vector temporal para ordenar los contenidos
    //std::vector<std::string> uniqueWordsVector; //Vector de palabras  o simbolos unicos
    //std::vector<int> uniqueWordsVectorCount; //Cuenta de palabras para cada uno de las palabras o simbolos
    
    
    std::vector<std::string> averagesVector; 
    
    std::vector<std::string> greetingExpression;
    std::vector<std::string> mayusChars;
    std::vector<std::string> minusChars;
    std::vector<std::string> numericalChars;
    std::vector<std::string> acuteChars; //Caracteres acentuados
    std::vector<std::string> commonChars; //Cualquier otro caracter. Puntuacion o matematico.
    std::vector<std::string> multipleChars; //Cualquier otro caracter. Puntuacion o matematico.
    std::vector<std::string> kumarExpressions;
    
    std::vector<std::string> outputGreeting;
    std::vector<std::string> outputMayus;
    std::vector<std::string> outputMinus;
    std::vector<std::string> outputNumericalChars; 
    std::vector<std::string> outputCommonChars; //Cualquier otro caracter. Puntuacion o matematico.
    std::vector<std::string> outputAcuteChars;
    std::vector<std::string> outputAverageVector;
    std::vector<std::string> outputTotalsVector;
    
    
    std::vector<int> commonCharsCount; //Cuenta de todos los caracteres asi sean 0.
    std::vector<int> acuteCharsCount; //Cuenta de todos los caracteres asi sean 0.
    std::vector<int> multipleCharsCount; //Cuenta de todos los caracteres asi sean 0.
    std::vector<int> kumarExpressionsCount;
  //  averageVectorCount
    std::vector<double>  farewellCountDec;
    std::vector<double>  greetingCountDec;
    std::vector<double>  mayusCountDec;
    std::vector<double> mayusCountDec2;
    std::vector<double>  minusCountDec;
    std::vector<double>  minusCountDec2;
    std::vector<double>  numericalCharsCountDec;
    std::vector<double> commonCharsCountDec; //Cuenta de todos los caracteres asi sean 0.
    std::vector<double> acuteCharsCountDec; //Cuenta de todos los caracteres asi sean 0.
    std::vector<double> multipleCharsCountDec; //Cuenta de todos los caracteres asi sean 0.
    std::vector<double> kumarExpressionsCountDec;
    std::vector<double> averageVectorCountDec;
    std::vector<double> totalsVectorCountDec;
    std::vector<double> mainVector;
    
};
#endif	/* TEXTPARSER_H */

