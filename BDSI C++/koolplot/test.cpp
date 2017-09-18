#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <koolplot.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include<cmath>
using namespace std;


bool myComparison(const pair<double,double> &a,const pair<double,double> &b){
       return a.first<b.first;
}

void findInflectionPoint(vector<double> YA, vector<double> XA);

vector <double> smooth(vector<double> foo);
void findMaxima(vector<double>foo, vector<int>* container);
//vector<int> findMinima(vector<double>foo);
double findMean (int begin, int end, vector<double> foo);

int main () {
    vector<double> X;
    vector<double> Y;
    double yCo;
    double xCo;
    string line;
    ifstream xFile ("X.txt");
    if (xFile.is_open()){
        getline (xFile,line);
        char * writable = new char[line.size() + 1];
        copy(line.begin(), line.end(), writable);
        writable[line.size()] = '\0';
        char * pch;
        pch = strtok (writable," ");
        while (pch != NULL){
            xCo = atof(pch);
            X.push_back(xCo);
            pch = strtok (NULL, " ");
    }
        delete[] writable;
        xFile.close();
    }

    ifstream yFile("Y.txt");
    if (yFile.is_open()){
        getline (yFile,line);
        char * writable = new char[line.size() + 1];
        copy(line.begin(), line.end(), writable);
        writable[line.size()] = '\0';
        char * pch;
        pch = strtok (writable," ");
        while (pch != NULL){
            yCo = atof(pch);
            Y.push_back(yCo);
            pch = strtok (NULL, " ");
    }
        delete[] writable;
        yFile.close();
    }
    else cout << "Unable to open file";

    int i;
    vector< pair<double,double > > v;
    for(i=0; i<X.size();i++){
        pair<double,double> t;
        t.first=X[i];
        t.second=Y[i];
        v.push_back(t);
    }
    sort(v.begin(),v.end(),myComparison);

    vector<double> X_sorted;
    vector<double> Y_sorted;
    for(i=0;i<v.size();i++){
        X_sorted.push_back(v[i].first);
        Y_sorted.push_back(v[i].second);

    }

    findInflectionPoint(Y_sorted,X_sorted);


    //plotdata x(xAfterInflection[0],xAfterInflection[xAfterInflection.size()-1]);
    //plotdata x(-6.0, 6.0);
    //plotdata y = sin(x) + x/5;
    //plot(x, y);
    //for(i=0;i<xAfterInflection.size();i++){
    //    addMark(x, y, xAfterInflection[i], yAfterInflection[i]);
    //}



    return 0;
}

void findInflectionPoint(vector<double> YA, vector<double> XA){
		const double pi  =3.141592653589793238463;
		double thetathresh = 20*pi/180;

    	int i;
    	vector<double>YAsmooth = smooth(YA);
    	vector<double>XAsmooth = smooth(XA);
    	vector<double>YAsmooth2 = smooth(YAsmooth);
    	double translation =*max_element(YAsmooth2.begin(), YAsmooth2.end());
    	for (i=0;i<YAsmooth2.size();i++){
    		YAsmooth2[i]= YAsmooth2[i]-translation;
    	}


    	//vector<int> localMax  = findMaxima(YAsmooth2);

    	//vector<int> localMin = findMinima(YAsmooth2);


        vector<int> container;
    	findMaxima(YAsmooth2, &container);

        int lastLocalMaxIndex;
        lastLocalMaxIndex = container[container.size() - 1];


    	vector<double> yAfterInflection;
    	vector<double> xAfterInflection;

    	for(i=lastLocalMaxIndex;i<YAsmooth2.size();i++){
            yAfterInflection.push_back(YAsmooth2[i]);
            xAfterInflection.push_back(XA[i]);
    	}

    	double yMean;
    	double xMean;
    	double xSquareMean;
    	double Sxx;
    	double Sxy;
    	double Sxxsq;
    	double Sxsqxsq;
    	double Sxsqy;

    	for(i=0;i<yAfterInflection.size();i++){
            yMean+=yAfterInflection[i];
            xMean+=xAfterInflection[i];
            xSquareMean += (xAfterInflection[i])*(xAfterInflection[i]);
    	}
    	yMean = yMean / yAfterInflection.size();
    	xMean = xMean/ xAfterInflection.size();
    	xSquareMean = xSquareMean/xAfterInflection.size();

    	for(i=0;i<yAfterInflection.size();i++){
            Sxx += pow((xAfterInflection[i]- xMean),2.0);
            Sxy += (xAfterInflection[i]-xMean)*(yAfterInflection[i]-yMean);
            Sxxsq += (xAfterInflection[i]-xMean)*(pow(xAfterInflection[i],2.0)-pow(xMean,2.0));
            Sxsqxsq+= pow ( (pow(xAfterInflection[i],2.0) - pow(xMean,2.0))   ,2.0);
            Sxsqy += (pow(xAfterInflection[i],2.0)- pow(xMean,2.0)) * (yAfterInflection[i]-yMean);
    	}

    	Sxx = Sxx / yAfterInflection.size();
    	Sxy = Sxy / yAfterInflection.size();
    	Sxxsq = Sxxsq / yAfterInflection.size();
    	Sxsqxsq = Sxsqxsq / yAfterInflection.size();
    	Sxsqy = Sxsqy / yAfterInflection.size();

    	double C;
    	C = (Sxsqy * Sxx - Sxy * Sxxsq)  / (Sxx*Sxsqxsq - pow(Sxxsq,2.0));
    	plotdata x(xAfterInflection[0],xAfterInflection[xAfterInflection.size()-1]);
    	plotdata y = C*pow(x,2);
    	plot(x,y);
    	for(i=0;i<XA.size();i++){
            addMark(x, y, XA[i], YA[i]);
    	}




}

vector <double> smooth(vector<double> foo){ //smooth data using a 200 points moving average
		vector<double>res;
		int i;
		for(i=0;i<foo.size()-199;i++){
			res.push_back(findMean(i,i+199,foo));
		}
		return res;
}

double findMean (int begin, int end, vector<double> foo){ //find the mean of the 200 points
		double res;
		int i;
		for(i=begin;i<=end;i++){
			res += foo[i];
		}
		return res/200;
}

void findMaxima(vector<double>foo, vector<int>* localMax){
		int direction;
		int i;
		//vector<int> localMax;
		if(foo[0]<foo[1]){ //positive slope
			direction=1;
		}
		else{
			direction =0; //negative slope
		}

		for(i=1;i<foo.size()-1;i++){
			if(direction==1){
				if(foo[i]<foo[i+1]){
					direction =1;
				}
				else{
					localMax->push_back(i);
					direction=0;
				}
			}
			else{
				if(foo[i]>foo[i+1]){
					direction =0;
				}
				else{
					direction=1;
				}
			}
		}

}

vector<int> findMinima(vector<double>foo){
		int direction;
		int i;
		vector<int> localMin;
		if(foo[0]<foo[1]){ //positive slope
			direction=1;
		}
		else{
			direction =0; //negative slope
		}

		for(i=1;i<foo.size()-1;i++){
			if(direction==1){
				if(foo[i]<foo[i+1]){
					direction =1;
				}
				else{
					direction=0;
				}
			}
			else{
				if(foo[i]>foo[i+1]){
					direction =0;
				}
				else{
					localMin.push_back(i);
					direction=1;
				}
			}
		}
		return localMin;
}




