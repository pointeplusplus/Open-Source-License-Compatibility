#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

#include "License.cpp"

using namespace std;

string CompareLicenses(License projectLicense, License exteralCode);

//this is for license names, permissions, and conditions
void readFileInfo(string fileName, vector<string> &licenses);

void getPairs(ifstream& in_str, License& thisOne, License& otherOne);

int main (int argc, char* argv[]){

	if(argc != 3){
	
		cout << "Please enter license of your project and license of project you would like to use code from.  See README for more information" << endl;
	}
	

	string thisProjectLicenseName = argv[1];
	string otherProjectLicenseName = argv[2];

	cout << thisProjectLicenseName << " " << otherProjectLicenseName << endl;

	vector<string> licenses;
	readFileInfo("LicenseNames.txt", licenses);
	
	
	License thisProjectLicense;
	License otherProjectLicense;
	
	for(int l = 0; l < licenses.size(); l++){
		if(licenses[l] == thisProjectLicenseName){
			thisProjectLicense = License(thisProjectLicenseName);
			cout << "found license 1" << endl;
		}
		if (licenses[l] == otherProjectLicenseName){
			otherProjectLicense = License(otherProjectLicenseName);
			cout << "found license 2" << endl;
		}
	}
	
	cout << thisProjectLicense.getName() << " " << otherProjectLicense.getName() << endl;

	vector<string> conditionNames;
	readFileInfo("Conditions.txt", conditionNames);
	vector<string> permissionNames;
	readFileInfo("Permissions.txt", permissionNames);
	
	return 1;
}


string CompareLicenses(License projectLicense, License externalCode){
	string whyLicenseIncompatible = "These licenses are incompatible because: \n";
	string howToFollowOtherLicense = "Take these actions to comply with the " + externalCode.getName();
	bool canUseSoFar = true;

	
}

void readFileInfo(string fileName, vector<string> &licenses){
	ifstream in_str(fileName);
	if(!in_str){
		cerr <<  "Problem reading the file " << fileName << endl;
	}
	string temp = "";
	while (!in_str.eof()) {
  		in_str >> temp;
  		licenses.push_back(temp);
  	}
}

void getPairs(ifstream& in_str, License& thisOne, License& otherOne){
	string licenseName;
	string infoType;
	string info;
	
	while(!in_str.eof()){
		in_str >> licenseName;
		in_str >> infoType;
		in_str >> info;
		
		if(licenseName == thisOne.getName()){
			if(infoType == "p"){
				thisOne.addPermission(info);
			}
			else if(infoType == "c"){
				thisOne.addCondition(info);
			}
			else{
				cerr << "Error in Pairs.txt file" << endl;
			}
		}
		
		else if(licenseName == otherOne.getName()){
			if(infoType == "p"){
				otherOne.addPermission(info);
			}
			else if(infoType == "c"){
				otherOne.addCondition(info);
			}
			else {
				cerr << "Error in Pairs.txt file" << endl;
			}
		}
	}
}


