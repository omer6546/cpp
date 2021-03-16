#include "snowman.hpp"
#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel{
string snowman(int snowdata) {
	const int ten = 10;
	int dig = countDigit(snowdata);
	const int exp_length = 8;
	if (dig > exp_length) {throw length_error{"number is to long, can't create snowman :("};};
	if (dig < exp_length) {throw length_error{"number is to short, can't create snowman :("};};
	string ans;
	array<int, exp_length> arr {};
	const int five = 5;
	const int six = 6;
	const int seven = 7;
	for (int j=seven ; j>-1 ; j--){
		int tmp = 0;
		if (j!=0){
			tmp = snowdata% ten;
			snowdata = snowdata/ten;
		}
		else {tmp = snowdata% ten;};
		if (tmp>4 || tmp<1) {throw out_of_range{"one or more number is not between 0-4, can't create snowman :("};};
		arr.at(j) = tmp;
		}
	switch (arr.at(0)){
		case 1:
			ans.append(" _===_\n");
			break;
		case 2:
			ans.append("  ___ \n ..... \n");
			break;
		case 3:
			ans.append("   _  \n  /_\\ \n");
			break;
		case 4:
			ans.append("  ___ \n (_*_)\n");
			break;
	}
	string flag = " ";
	if (arr.at(4) == 2) {flag = "\\";};
	//face:
	string N = " ";
	switch (arr.at(1)){
		case 1:
			N = ",";
			break;
		case 2:
			N = ".";
			break;
		case 3:
			N = "_";
			break;
	}
	string L = " ";
	switch (arr.at(2)){
		case 1:
			L = ".";
			break;
		case 2:
			L = "o";
			break;
		case 3:
			L = "O";
			break;
		case 4:
			L = "-";
			break;
	}
	string R = " ";
	switch (arr.at(3)){
		case 1:
			R = ".";
			break;
		case 2:
			R = "o";
			break;
		case 3:
			R = "O";
			break;
		case 4:
			R = "-";
			break;
	}
	ans.append(flag + "(" + L + N + R);
	if (arr.at(five) == 2){
		ans.append(")/\n");
	} 
	else {
		ans.append(")\n");
	}
	//left arm
	string X = " ";
	switch (arr.at(4)){
		case 1:
			X = "<";
			break;
		case 3:
			X = "/";
			break;
	}
	//right arm
	string Y = " ";
	switch (arr.at(five)){
		case 1:
			Y = ">";
			break;
		case 3:
			Y = "\\";
			break;
	}
	//torso:
	switch (arr.at(six)){
		case 1:
			ans.append(X + "( : )" + Y + "\n");
			break;
		case 2:
			ans.append(X + "(] [)" + Y + "\n");
			break;
		case 3:
			ans.append(X + "(> <)" + Y + "\n");
			break;
		case 4:
			ans.append(X + "(   )" + Y + "\n");
			break;
	}
	//base:
	if (arr.at(seven) == 1){
		ans.append(" ( : )\n");
	}
	if (arr.at(seven) == 2){
		ans.append(" (\" \")\n");
	}
	if (arr.at(seven) == 3){
		ans.append(" (___)\n");
	}
	if (arr.at(seven) == 4){
		ans.append(" (   )\n");
	}
	
	return ans ;
}


int countDigit(int n)
{
    const int ten2 = 10;
	if (n == 0){return 0;};
    return 1 + countDigit(n / ten2);
}
};

