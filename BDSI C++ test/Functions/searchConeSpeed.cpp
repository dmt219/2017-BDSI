/*Duc Tran
*/
#include <dirent.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class searchConeSpeed {
public:
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
}

