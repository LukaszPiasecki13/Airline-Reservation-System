#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class File_Services
{

private:
	string c_patch;

public:
	File_Services(string patch);
	map<int, string> Read_File();
	void Write_File(map<int, string> tekst );
};