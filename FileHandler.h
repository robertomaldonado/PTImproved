/* 
 * File:   FileHandler.h
 * Author: robertomaldonado
 *
 * Created on June 29, 2015, 12:15 PM
 */

#ifndef FILEHANDLER_H
#define	FILEHANDLER_H

class FileHandler
{

public:
    //Methods for the class
void welcomeUser();
int askDebug();
int askMethod();
int getPubNumber();
std::string makeName(int textosPrevios);
int askMode();
bool askEnable();
void printResults(double highScore, double lowScore);
void calculateVectorResultsAndPrint( std::vector<double>& results );

};

#endif	/* FILEHANDLER_H */

