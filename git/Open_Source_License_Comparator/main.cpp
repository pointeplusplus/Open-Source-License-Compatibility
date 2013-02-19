#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

#include "License.cpp"

using namespace std;

string CompareLicenses(License projectLicense, License exteralCode);
void readLicenseNames(ifstream& in_str, vector<string> &licenses);

int main (int argc, char* argv[]){

	if(argc != 3){
	
		cout << "Please enter license of your project and license of project you would like to use code from.  See README for more information" << endl;
	}
	
	cout << argv[1] << argv[2] << endl;

	ifstream in_str("LicenseNames.txt");
	if(!in_str){
		cerr <<  "Problem reading the file LicenseNames.txt" << endl;
	}
	vector<string> licenses;
	readLicenseNames(in_str, licenses);

	return 1;
}


string CompareLicenses(License projectLicense, License externalCode){
	string whyLicenseIncompatible = "These licenses are incompatible because: \n";
	string howToFollowOtherLicense = "Take these actions to comply with the " + externalCode.getName();
	bool canUseSoFar = true;

	
}

void readLicenseNames(ifstream& in_str, vector<string> &licenses){
	string temp = "";
	while (!in_str.eof()) {
  		in_str >> temp;
  		licenses.push_back(temp);
  	}
}


