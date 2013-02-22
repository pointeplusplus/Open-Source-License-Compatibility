#include <string>
#include <vector>
using namespace std;

class License{

private:
	string name;
	vector<string> permissions;
	vector<string> conditions;
	
public:

	License(){
		name = "error";
	}
	
	License(string l_name){
		name = l_name;
	}
	
	const string& getName() const{
		return name;
	}

};
