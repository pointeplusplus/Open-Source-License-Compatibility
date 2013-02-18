#include <string>
#include <vector>

class License{

private:
	LicenseType name;
	vector<LicenseAttributes> attributes;
	string whyLicenseIncompatible;
	string howToFollowOtherLicense;
	bool canUseSoFar;
	
	public License(){
		canUseSoFar = true;
	}
	
	public License(int nameOrdinal){
		canUseSoFar = true;
	}
	
	public License(LicenseType name){
		canUseSoFar = true;
		this.name = name;
	}

};
