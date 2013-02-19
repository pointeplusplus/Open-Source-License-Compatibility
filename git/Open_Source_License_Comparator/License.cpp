#include <string>
#include <vector>
using namespace std;

class License{

private:
	string name;
	vector<string> permissions;
	
public:

	License(){
	}
	
	License(string l_name){
		name = l_name;
	}
	
	string getName(){
		return name;
	}

};
