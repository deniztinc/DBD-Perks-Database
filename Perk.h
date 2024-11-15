#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <fstream>

using namespace std;

class perk 
{
	public:
		string name;
		string type;
		int tier;
		perk() : name(" "), type(" "), tier(0) {}
};
