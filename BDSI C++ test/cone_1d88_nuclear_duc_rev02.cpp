/*Duc Tran
Main function 
*/

#include <dirent.h>
#include <stdlib.h>
#include <windows.h> 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
//#include "C:\Users\minhd\Desktop\BDSI C++\Functions\searchConeSpeed.h"

int main(){
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
	DIR *curdir = NULL;
	struct dirent *pent = NULL;

	curdir = opendir (".");
	if (curdir == NULL){
		cout<<"ERROR! Directory does not exist"<<endl;
		exit(1);
	}
	vector<string> M;
	M = aspcSearch_cone_speed2();
	int i;
	for (i=0;i<M.size();i++){
		vector<string> A;
		A = nuclearCells(M[i]);
	}
	int j;
	for(j=0;j<A.size();j++){
		forceFind forceFind1;
		//code in here
	}

}

vector<string> nuclearCells(string dir){
	vector <string> res;
	string cell = "cell";
	string Cell = "Cell";
	DIR *curdir = NULL;
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
       	if ((cell.compare((pent->d_name).substr(0,4)))||(Cell.compare((pent->d_name).substr(0,4)))){
       		if('n'.compare(endch)){
    			res.push_back(dir + pent->d_name + '\\');
    		}
    	}	
    }
}

vector<string> aspcSearch_cone_speed2(){
	vector <string> res;
	string aspc = "aspc";
	DIR *curdir = NULL;
	struct dirent *pent = NULL;
	curdir = opendir (".\\1d88 300");
	if (curdir == NULL){
		cout<<"ERROR! Directory does not exist"<<endl;
		exit(1);
	}
	while (pent = readdir (pdir)){
		if (pent == NULL){
        cout<< "ERROR!" <<endl;
        exit (3);
    	}
    	if (aspc.compare((pent->d_name).substr(0,4))){
    		res.push_back('C:\\Users\\minhd\\Desktop\\BDSI C++\\1d88 300\\' + pent->d_name + '\\');
    	}
	}
	chdir("..")		
}
