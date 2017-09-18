/*Duc Tran
*/
#include <dirent.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

/*Cell case sensitive*/
class searchNuclearCells{
public:
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
}	
