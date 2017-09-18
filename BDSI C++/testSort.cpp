#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


bool myComparison(const pair<double,double> &a,const pair<double,double> &b)
{
       return a.second<b.second;
}
int main(){
    vector<double> predictions;
    predictions.push_back(1.22);
    predictions.push_back(3.22);
    predictions.push_back(2.22);
    predictions.push_back(4.22);
    vector<double> indices;
    indices.push_back(1.0);
    indices.push_back(3.0);
    indices.push_back(2.0);
    indices.push_back(4.0);


    int i;
    vector< pair<double,double > > v;
    for(i=0; i<predictions.size();i++){
        pair<double,double> t;
        t.first=predictions[i];
        t.second=indices[i];
        v.push_back(t);
    }
    sort(v.begin(),v.end(),myComparison);

    vector<double> predictions2;
    vector<double>indices2;
    for(i=0;i<v.size();i++){
            predictions2.push_back(v[i].first);
            indices2.push_back(v[i].second);

    }

    for(i=0;i<predictions2.size();i++){
        cout<<predictions2[i]<<"\n";
        cout<<indices2[i]<<"\n";
    }

}
