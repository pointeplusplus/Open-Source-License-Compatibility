#include <iostream>
#include <array>

using namespace std;

int main (int argc, char* argv[]){

	if(argc != 3){
	
		cout << "Please enter license of your project and license of project you would like to use code from.  See README for more information" << endl;
	}
	
	cout << argv[1] << argv[2] << endl;


	return 1;
}
