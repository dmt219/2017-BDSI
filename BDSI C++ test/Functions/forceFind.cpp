/*Duc Tran
*/
#include <dirent.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <array>
#include <algorithm>
//#include "C:\Users\minhd\Desktop\BDSI C++\Functions\inflectionPoint.h"

class forceFind{
	public:
	int z=0;
	int counter =1;
	int errorCounter =1;
	int WEcounter = 1;
	long spring=.0092495;
   	long slope=5.96617e-8;
   	int IPcounter = 1;
	int DataCounter=1;
	int TPcounter = 1;
	int TP = 0;
	int IP = 0;
	int FittedE=0;
	int Indent=0;
	int Force=0;
	int points = 0;
	string ScanName = 'starter';
	int k =1;
	int type;

		AveLR,AveE,B,AveMax,AveOffset,AveUnCorrMax,AveIndentDist,...
    AveForce,AveEFit,MSE,counter,...
    FittedE,E_Fitted,Indent,Force,ScanName,points,IP,IPcounter,TP,TPcounter

    InflectionPoint;
    type;

	void forceAndSpeed(string dir,int k,int DataCounter,int FittedE,int Indent, int Force, string ScanName,int points, int IP,int IPcounter,int TP, int TPcounter){
		DIR *curdir = NULL;
		vector<D> B;
		struct dirent *pent = NULL;
		curdir = opendir (dir);
		if (curdir == NULL){
			cout<<"ERROR! Directory does not exist"<<endl;
			exit(1);
		}
		while (pent = readdir (pdir)){
			if (pent == NULL){
	        	cout<< "ERROR!" <<endl;
	        	exit (3);
	        }
	        char endch = pent->d_name.back();
	       	if ("Force".compare((pent->d_name).substr(0,5))){
	       		if('A'.compare(endch)){
	       			string name = dir+ pent->d_name +'\\';
	    			B.push_back(IBWread(name));
	    		}

	    	}	
	    }
	    int j;
	    for(j=0;j<B.size()-1;j++){
	    	if(j%2==1){
	    		vector<long> XA;
	    		XA = B[j+1].y;
	    		vector<long> YA;
	    		YA = B[j].y;
	    		string bname;
	    		bname=B[j].bname;
	    		int minLength = min(XA.size(),YA.size());
	    		if(YA.size()<100){
	    			int t;
	    			for(t=0;t<YA.size();t++){
	    				YA[t]=0;
	    			}
	    			int p;
	    			for(p=0;p<XA,size();p++){
	    				XA[p]=0;
	    			}
        			minLength=10000;
	    		}
	    		else{   			
	    		}

	    		findInflectionPoint (YA,XA,minlength,IP,IPcounter,TP,TPcounter);  
	    	}
	    }
	    


	}

	void findInflectionPoint(vector<long> YA, vector<long> XA, int minLength,int IP, int IPcounter, int TP, int TPcounter){
		const double pi  =3.141592653589793238463;
		double thetathresh = 20*pi/180;

		std::sort(YA.begin(), YA.end(), [&XA](size_t i, size_t j){
        	return XA[i] < XA[j];
        });
    	std::sort(XA.begin(), XA.end(),
        std::less<long>());

    	type =1;

    	int i;
    	vector<long>YAsmooth = smooth(YA);
    	vector<long>XAsmooth = smooth(XA);
    	vector<long>YAsmooth2 = smooth(YAsmooth);
    	long translation =*max_element(YAsmooth2.begin(), YAsmooth2.end());
    	for (i=0;i<YAsmooth2.size();i++){
    		YAsmooth2[i]= YAsmooth2[i]-translation;
    	}
    	vector<int> localMax  = findMaxima(YAsmooth2);
    	vector<int> localMin = findMinima(YAsmooth2);

    	chdir("C:\\Users\\minhd\\Desktop\\BDSI C++");	

    	

	}

	vector <long> smooth(vector<long> foo){ //smooth data using a 200 points moving average
		vector<long>res;
		int i;
		for(i=0;i<foo.size()-199;i++){
			res[i]=findMean(i,i+199,foo);
		}
		return res;
	}

	long findMean (int begin, int end, vector<long> foo){ //find the mean of the 200 points
		long res;
		int i;
		for(i=begin;i<=end;i++){
			res += foo[i];
		}
		return res/200;
	}

	vector<int> findMaxima(vector<long>foo){ //find local maxima
		int direction;
		int i;
		vector<int> localMax;
		//vector<int> localMin;
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
					localMax.push_back[i];
					direction=0;
				}
			}
			else{
				if(foo[i]>foo[i+1]){
					direction =0;
				}
				else{
					//localMin.push_back[i];
					direction=1;
				}
			}
		}
		return localMax;

vector<int> findMinima(vector<long>foo){ //find local minima
		int direction;
		int i;
		//vector<int> localMax;
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
					//localMax.push_back[i];
					direction=0;
				}
			}
			else{
				if(foo[i]>foo[i+1]){
					direction =0;
				}
				else{
					localMin.push_back[i];
					direction=1;
				}
			}
		}
		return localMin;
	}


	
}