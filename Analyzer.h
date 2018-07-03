/* 
 * File:   Analyzer.h
 * Author: robertomaldonado
 *
 * Created on July 15, 2015, 10:15 AM
 */

#ifndef ANALYZER_H
#define	ANALYZER_H


class Analyzer{
    
    public:
        void setId(int n);
        int getId();
        

        double get_sum( std::vector<double>& v1 );
        
        void printVectorCount(std::vector<double>& v);
        
        void loadVectors( std::vector<double>& file0, std::vector<double>& file1, std::vector<double>& file2, std::vector<double>& file3,std::vector<double>& file4, std::vector<double>& file5, std::vector <std::vector<double> >& toAssign );
        
        
        double applyRegularMeanDistance( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& equivalRef,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef);
      
        double applyWeightedArithmeticMeanDistance( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& equivalRef,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef,
                                         int extraAtribution);
        
        double applyMinkowskiDistance( std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& minkowskiDistance,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef,
                                         double exp);
        
        double applyChebyshevDistance( std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& chebyshevDistance,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef);
       double applyNewCustomizedMethod( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& equivalRef,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef);
       
        void performNuevoMetodo(std::vector<double>& promedios, std::vector<double>& auxiliar1 , std::vector<double>& resultadosDeOtroAutor);
        double devolverResultado(std::vector<double>& promedios, std::vector<double>& r);
       
        
        void performMeanWeigths(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d);
     
        void performMeanEquival(std::vector<double>& p, std::vector<double>& e, std::vector<double> d);
        
        void initializeResults(std::vector<double>& p,  std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d );
        void performAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c, std::vector<double> d, std::vector<double> e);
        void performEquival(std::vector<double>& p, std::vector<double>& e, std::vector<double> d);
        void performVectorW(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d);
        void performVectorXW(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d);
        void performBinaryAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c, std::vector<double> d, std::vector<double> e);
      
        void performVectorXWNumerical(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d);
        //void performCompare();
        void performVectorXWGreeting(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d);
        
        void performClean( std::vector<double>& z, std::vector<double>& a,  std::vector<double>& b,std::vector<double>& c, std::vector<double>& d, std::vector<double>& e, std::vector<double>& p, std::vector<double>& ee,std::vector<double>& w, std::vector<double>& wx);
        
        void performMinkowski(std::vector<double>& p, std::vector<double>& e, std::vector<double>& d, double exp);
        double performMinEquival(std::vector<double>& a, std::vector<double>& b, double exp);
        
        void performChebyshev(std::vector<double>& p, std::vector<double>& e, std::vector<double>& d);
        double performChevEquival(std::vector<double>& a, std::vector<double>& b);
public:
        int identifier;
        std::vector<double> featuresCountVector(); 
};
#endif	/* ANALYZER_H */

