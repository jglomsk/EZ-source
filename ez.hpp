/* Welcome to the EZ language!
 * Documentation is in the ReadMe.txt
 * This file will be commented out as much as possible.
 * The purpose of the comments is to help the CREATORS of the program. Not you.
 * Just kidding, if you want to follow along you can.
 * It may be hard at times, but we can get through it.
 * Just know this:
 * I can explain it to you, but I can't understand it for you.
 * P.S. the line above this one is a sticker on my laptop.
 */
#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include "mere.hpp"
#ifdef _WIN32
	#define PLATFORM 1
#else
	#define PLATFORM 2
#endif
class Main {
public:
	std::vector<std::string> funcs; // need this for function keeping and file deleting at the end
	bool tof;
	int flush = 0;
	void end_n_del(std::vector<std::string> vals);
	float pemdas(std::string thing);
	void translate(const char* file, // the file itself
							 	std::vector<std::string>& vars, // the variables that are global
							 	std::vector<std::string>& vals, // the values to those variables
							 	std::vector<std::vector<var> >& baskets,
							 	int& co, int wya = 0, bool in_func = false, int nested = 0);
	void while_loop_guts(float beg, float end, int newlinesnum, std::vector<std::string>& variables,
								std::vector<std::string>& values, std::vector<std::vector<var> >& baskets,
								int k, int i, int& count, int problem, std::string im_this,
								std::vector<std::string> entire_file, std::string thing, int comment_limit = 0);
};
// does the while loop keyword
void Main::while_loop_guts(float beg, float end, int newlinesnum, std::vector<std::string>& variables, std::vector<std::string>& values, std::vector<std::vector<var> >& baskets, int k, int i, int& count, int problem, std::string im_this, std::vector<std::string> entire_file, std::string thing, int comment_limit)
{
	int nest = 0;
	std::ofstream do_me_hard;
	do_me_hard.open("conditional" + std::to_string(problem));
	for (int j = k + 1;; j++) {
		if ((entire_file[i].find("while", j - 1) != std::string::npos && entire_file[i].find("while", j - 1) < comment_limit) ||
						(entire_file[i].find("if", j - 1) != std::string::npos && entire_file[i].find("if", j - 1) < comment_limit) ||
						(entire_file[i].find("else", j - 1) != std::string::npos && entire_file[i].find("else", j - 1) < comment_limit) ||
						(entire_file[i].find("make", j - 1) != std::string::npos && entire_file[i].find("make", j - 1) < comment_limit)) nest++;
		else if (entire_file[i].find("done") != std::string::npos && nest > 0 &&
						 entire_file[i].find("done") < comment_limit &&
						 entire_file[i].find("done") < entire_file[i].find("show") &&
						 entire_file[i].find("done") < entire_file[i].find("set") &&
						 entire_file[i].find("done") < entire_file[i].find("if") &&
						 entire_file[i].find("done") < entire_file[i].find("else") &&
						 entire_file[i].find("done") < entire_file[i].find("push") &&
						 entire_file[i].find("done") < entire_file[i].find("make") &&
						 entire_file[i].find("done") < entire_file[i].find("with") &&
						 entire_file[i].find("done") < entire_file[i].find("while") &&
						 entire_file[i].find("done") < entire_file[i].find("call")) {
			nest--;
			do_me_hard << "done\n";
		}
		else if (entire_file[i].find("done") < comment_limit &&
						 entire_file[i].find("done") < entire_file[i].find("show") &&
						 entire_file[i].find("done") < entire_file[i].find("set") &&
						 entire_file[i].find("done") < entire_file[i].find("if") &&
						 entire_file[i].find("done") < entire_file[i].find("else") &&
						 entire_file[i].find("done") < entire_file[i].find("push") &&
						 entire_file[i].find("done") < entire_file[i].find("make") &&
						 entire_file[i].find("done") < entire_file[i].find("with") &&
						 entire_file[i].find("done") < entire_file[i].find("while") &&
						 entire_file[i].find("done") < entire_file[i].find("call") && nest <= 0) break;
		else if (i == newlinesnum) {
			std::cout << "Your conditional did not have a \"done\" statement before the end of the file.\n";
			std::cout << "The failed conditional started on line " << problem << ". The program will now exit.\n";
			std::cout << "Error code: 60n3\n";
			end_n_del(funcs);
			endp(603, flush);
		}
		else if (j > entire_file[i].size()) {
			i++;
			j = 0;
			do_me_hard << '\n';
		}
		char put_me_in_coach = entire_file[i][j - 1];
		do_me_hard << put_me_in_coach;
	}
	do_me_hard.close();
	if (beg > end) while (beg > end) {
		for (int p = 0; p < variables.size(); p++) {
			if (im_this[3] == '1' && variables[p] == thing) { // x > 8
				values[p] = std::to_string(beg--);
				if (beg > end) translate(std::string("conditional" + std::to_string(problem)).c_str(), variables, values, baskets, count, i);
				break;
			}
			else if (im_this == "var2") { // 8 < x
				beg--;
				if (beg > end) translate(std::string("conditional" + std::to_string(problem)).c_str(), variables, values, baskets, count, i);
			}
		}
	}
	else if (beg < end) while (beg < end) {
		for (int p = 0; p < variables.size(); p++) {
			if (im_this[3] == '1' && variables[p] == thing) { // x < 8
				values[p] = std::to_string(beg++);
				if (beg < end) translate(std::string("conditional" + std::to_string(problem)).c_str(), variables, values, baskets, count, i);
				break;
			}
			else if (im_this == "var2") { // 8 < x
				beg++;
				if (beg < end) translate(std::string("conditional" + std::to_string(problem)).c_str(), variables, values, baskets, count, i);
			}
		}
	}
}
// deletes the function files
void Main::end_n_del(std::vector<std::string> values)
{
	for (int i = 0; i < funcs.size(); i++) {
		remove(values[i].c_str());
	}
}
// turns a string equation into a real float
float Main::pemdas(std::string thing)
{
	std::string new_string = "";
	std::string wo_spaces = "";
	std::string wo_comments = "";
	int p = 0;
	int paren_loc_beg = 0;
	int paren_loc_end = 0;
	int expo_loc = 0;
	int mult_loc = 0;
	int div_loc = 0;
	int plus_loc = 0;
	int min_loc = 0;
	int stuck = 0;
	while (thing[p] != '\0') {
		if (thing[p] != ' ') { // get rid of spaces in the whole thing
			wo_spaces += thing[p];
		}
		p++;
	}
	if (wo_spaces.find('(') == std::string::npos &&
		wo_spaces.find('^') == std::string::npos &&
		wo_spaces.find('*') == std::string::npos &&
		wo_spaces.find('/') == std::string::npos &&
		wo_spaces.find('+') == std::string::npos &&
		wo_spaces.find('-') == std::string::npos) {
		return ::atof(wo_spaces.c_str()); // return the number if no equation symbol was given
	}
	thing = wo_spaces;
	/* WARNING: DO NOT, and I repeat, DO NOT delete ANY of this section!!
	 * It is perfect and bug free. You do not need to understand it AT ALL.
	 * Just know it works. Good luck trying to understand it if you wish to read it.
	 * Sometimes I don't even know how to debug this section...
	 * begin confusion
	 */
	while (true) {
		if (thing.find('(', paren_loc_beg) != std::string::npos) {
			int j = thing.find('(', paren_loc_beg) + paren_loc_beg;
			paren_loc_beg += j + 1;
			for (; j < thing.size() && thing[j] != ')'; ++j) {
				new_string += thing[j];
			}
			new_string += ')';
			paren_loc_end = j;
		}
		else if (thing.find('^', expo_loc + stuck) != std::string::npos && (thing.find('^', expo_loc) + stuck < paren_loc_beg ||
			thing.find('^', expo_loc) + stuck > paren_loc_end)) {
			int j = thing.find('^', expo_loc + stuck);
			if (j < paren_loc_beg) {
				for (; j > -1; j--) {
					if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '^') != false) {
						new_string += thing[j];
					}
				}
				j++;
				while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '^' || thing[j] == '.')) j++;
			}
			else {
				if (j >= paren_loc_beg - 1) {
					j++;
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '^') != true || j <= 0) {
							break;
						}
					}
					if (thing.find('(') != std::string::npos) j++;
					else if (thing[j] != '^' && !isdigit(thing[j])) j++;
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '.' || thing[j] == '^')) {
						new_string += thing[j];
						j++;
					}
				}
				else {
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '^') != false) {
							new_string += thing[j];
						}
						if (j <= 0) break;
					}
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '^' || thing[j] == '.')) j++;
				}
			}
			expo_loc = j + 1;
		}
		else if (thing.find('*', mult_loc + stuck) != std::string::npos && (thing.find('*', mult_loc) + stuck < paren_loc_beg || 
																																				thing.find('*', mult_loc) + stuck > paren_loc_end)) {
			int j = thing.find('*', mult_loc + stuck);
			if (j < paren_loc_beg) {
				for (; j > -1; j--) {
					if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] =='*') != false) {
						new_string += thing[j];
					}
				}
				j++;
				while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '*' || thing[j] == '.')) j++;
			}
			else {
				if (j >= paren_loc_beg - 1) {
					j++;
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '*') != true || j <= 0) {
							break;
						}
					}
					if (thing.find('(') != std::string::npos) j++;
					else if (thing[j] != '*' && !isdigit(thing[j])) j++;
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '.' || thing[j] == '*')) {
						new_string += thing[j];
						j++;
					}
				}
				else {
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '*') != false) {
							new_string += thing[j];
						}
						if (j <= 0) break;
					}
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '*' || thing[j] == '.')) j++;
				}
			}
			mult_loc = j + 1;
		}
		else if (thing.find('/', div_loc + stuck) != std::string::npos && (thing.find('/', div_loc) + stuck < paren_loc_beg ||
			thing.find('/', div_loc) + stuck > paren_loc_end)) {
			int j = thing.find('/', div_loc + stuck);
			if (j < paren_loc_beg) {
				for (; j > -1; j--) {
					if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '/') != false) {
						new_string += thing[j];
					}
				}
				j++;
				while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '/' || thing[j] == '.')) j++;
			}
			else {
				if (j >= paren_loc_beg - 1) {
					j++;
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '/') != true || j <= 0) {
							break;
						}
					}
					if (thing.find('(') != std::string::npos) j++;
					else if (thing[j] != '/' && !isdigit(thing[j])) j++;
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '.' || thing[j] == '/')) {
						new_string += thing[j];
						j++;
					}
				}
				else {
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '/') != false) {
							new_string += thing[j];
						}
						if (j <= 0) break;
					}
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '/' || thing[j] == '.')) j++;
				}
			}
			div_loc = j + 1;
		}
		else if (thing.find('+', plus_loc + stuck) != std::string::npos && (thing.find('+', plus_loc) + stuck < paren_loc_beg ||
			thing.find('+', plus_loc) + stuck > paren_loc_end)) {
			int j = thing.find('+', plus_loc + stuck);
			if (j < paren_loc_beg) {
				for (; j > -1; j--) {
					if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '+') != false) {
						new_string += thing[j];
					}
				}
				j++;
				while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '+' || thing[j] == '.')) j++;
			}
			else {
				if (j >= paren_loc_beg - 1) {
					j++;
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '+') != true || j <= 0) {
							break;
						}
					}
					if (thing.find('(') != std::string::npos) j++;
					else if (thing[j] != '+' && !isdigit(thing[j])) j++;
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '.' || thing[j] == '+')) {
						new_string += thing[j];
						j++;
					}
				}
				else {
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '+') != false) {
							new_string += thing[j];
						}
						if (j <= 0) break;
					}
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '+' || thing[j] == '.')) j++;
				}
			}
			plus_loc = j + 1;
		}
		else if (thing.find('-', min_loc + stuck) != std::string::npos && (thing.find('-', min_loc) + stuck < paren_loc_beg ||
			thing.find('-', min_loc) + stuck > paren_loc_end)) {
			int j = thing.find('-', min_loc + stuck);
			if (j < paren_loc_beg) {
				for (; j > -1; j--) {
					if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '-') != false) {
						new_string += thing[j];
					}
				}
				j++;
				while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '-' || thing[j] == '.')) j++;
			}
			else {
				if (j >= paren_loc_beg - 1) {
					j++;
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '-') != true || j <= 0) {
							break;
						}
					}
					if (thing.find('(') != std::string::npos) j++;
					else if (thing[j] != '-' && !isdigit(thing[j])) j++;
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '.' || thing[j] == '-')) {
						new_string += thing[j];
						j++;
					}
				}
				else {
					for (;; j--) {
						if ((isdigit(thing[j]) || thing[j] == '.' || thing[j] == '-') != false) {
							new_string += thing[j];
						}
						if (j <= 0) break;
					}
					while (j < thing.size() && (isdigit(thing[j]) || thing[j] == '-' || thing[j] == '.')) j++;
				}
			}
			min_loc = j + 1;
		}
		else if (wo_spaces.size() == new_string.size()) break;
		else if (thing.find(';') != std::string::npos) {
			int stop_here = thing.find(';');
			for (int i = 0; i < stop_here; i++) wo_comments += thing[i];
			break;
		}
		else {
			stuck++;
		}
	}
	// end confusion
	if (wo_comments == "") {
		for (int i = 0; i < new_string.size(); i++) {
			wo_comments += new_string[i];
		}
	}
	// hard code here
	// turn the ints inside the string into actual ints
	// don't forget: parentheses need to be treated as an entirely different number
	float curr_ans = 0;
	std::string x = "";
	std::string y = "";
	bool now_switch = false;
	bool in_parens = false;
	char sign = '\0';
	for (int i = 0;; i++) {
		if ((isdigit(wo_comments[i]) || wo_comments[i] == '.') && now_switch == false) {
			x += wo_comments[i];
		}
		else if (wo_comments[i] == '^' ||
			wo_comments[i] == '*' ||
			wo_comments[i] == '+' ||
			wo_comments[i] == '/' ||
			wo_comments[i] == '-') {
			if (curr_ans && y != "") {
				curr_ans = Math::calc(curr_ans, sign, ::atof(y.c_str()));
			}
			else if (x != "" && y != "" && sign != '\0') {
				curr_ans = Math::calc(::atof(x.c_str()), sign, ::atof(y.c_str()));
			}
			sign = wo_comments[i];
			now_switch = true;
			y = "";
		}
		else if (now_switch && (isdigit(wo_comments[i]) || wo_comments[i] == '.')) {
			if (wo_comments[i] == '\0') {
				curr_ans = Math::calc(curr_ans, sign, ::atof(y.c_str()));
				break;
			}
			else {
				y += wo_comments[i];
			}
		}
		else if (wo_comments[i] == '(') {
			in_parens = true;
		}
		else if (wo_comments[i] == ')' && in_parens) {
			curr_ans = Math::calc(::atof(x.c_str()), sign, ::atof(y.c_str()));
			x = "";
			y = "";
			in_parens = false;
			now_switch = false;
		}
		else if (wo_comments[i] == '\0' && curr_ans) {
			if (y != "") {
				curr_ans = Math::calc(curr_ans, sign, ::atof(y.c_str()));
			}
			break;
		}
		else if (wo_comments[i] == '\0') {
			if (curr_ans == 0) {
				curr_ans = Math::calc(::atof(x.c_str()), sign, ::atof(y.c_str()));
			}
			break;
		}
	}
	return curr_ans;
}
// the head honcho of the program
void Main::translate(const char* file, // the file itself
							 std::vector<std::string>& variables, // the variables that are global
							 std::vector<std::string>& values, // the values to those variables
							 std::vector<std::vector<var> >& baskets,
							 int& count, int wya, bool in_func, int nested) // co = count of variables, wya = where is the program
{
	std::ifstream fp(file);
	std::vector<std::string> entire_file;
	int newlinesnum = 0;
	int problem = 0;
	int nest = nested;
	// reading in file into entire_file
	while (!fp.eof()) {
		std::string curr = "";
		std::getline(fp, curr);
		newlinesnum++;
		entire_file.push_back(curr);
	}
	// limit for entire program
	for (int p = 0; p < entire_file.size(); p++) {
		if (entire_file[p] == "\0") newlinesnum--;
	}
	fp.close();
	// begin big loop
	for (int i = 0; i < newlinesnum; i++) {
		if (in_func) problem = abs(wya - (newlinesnum - i));
		else problem = i + 1;
		int comment_limit = 0;
		if (entire_file[i].find(';') != std::string::npos) comment_limit = entire_file[i].find(';');
		else comment_limit = entire_file[i].size();
		// keyword with
		if (entire_file[i].find("with") != std::string::npos && entire_file[i].find("with") < comment_limit &&
			 	entire_file[i].find("with") < entire_file[i].find("show") &&
			 	entire_file[i].find("with") < entire_file[i].find("set") &&
			 	entire_file[i].find("with") < entire_file[i].find("if") &&
			 	entire_file[i].find("with") < entire_file[i].find("else") &&
			 	entire_file[i].find("with") < entire_file[i].find("push") &&
			 	entire_file[i].find("with") < entire_file[i].find("make") &&
			 	entire_file[i].find("with") < entire_file[i].find("while") &&
			 	entire_file[i].find("with") < entire_file[i].find("call")) {
			int k = entire_file[i].find("with") + 4;
			while (entire_file[i][k] == ' ') k++;
			std::string fp_add = "";
			for (; k < comment_limit && entire_file[i][k] != ' '; k++) {
				fp_add += entire_file[i][k];
			}
			try {
				std::ifstream fp_test(fp_add.c_str());
				if (fp_test) translate(fp_add.c_str(), variables, values, baskets, count);
				else throw 107;
			} catch (...) {
				try {
					std::string fp_copy = "";
					if (PLATFORM == 1) {
						fp_copy = std::string("\"C:\\Program Files\\EZ\\") + fp_add + std::string("\"");
					}
					else if (PLATFORM == 2) {
						fp_copy = std::string("/usr/share/ez/") + fp_add;
					}
					std::ifstream fp_test(fp_copy.c_str());
					if (fp_test) translate(fp_copy.c_str(), variables, values, baskets, count);
					else throw 107;
				} catch (...) {
					std::cout << "Import Error.\nCheck your import file and make sure you typed the correct file name.\n";
					end_n_del(funcs);
					endp(107, flush);
				}
			}
		}
		// keyword if
		else if (entire_file[i].find("if") != std::string::npos && entire_file[i].find("if") < comment_limit &&
			  entire_file[i].find("if") < entire_file[i].find("show") &&
			 	entire_file[i].find("if") < entire_file[i].find("set") &&
			 	entire_file[i].find("if") < entire_file[i].find("else") &&
			 	entire_file[i].find("if") < entire_file[i].find("push") &&
			 	entire_file[i].find("if") < entire_file[i].find("while") &&
			 	entire_file[i].find("if") < entire_file[i].find("call") &&
			 	entire_file[i].find("if") < entire_file[i].find("make") &&
			 	entire_file[i].find("if") < entire_file[i].find("with")) {
			int k = entire_file[i].find("if") + 2;
			while (entire_file[i][k] == ' ') k++;
			std::string condition1 = "";
			for (; entire_file[i][k] != ' '; k++) {
				condition1 += entire_file[i][k];
			}
			while (entire_file[i][k] == ' ') k++;
			std::string condition2 = "";
			char cond_sign = entire_file[i][k];
			k++;
			while (entire_file[i][k] == ' ') k++;
			for (; entire_file[i][k] != '\0' && entire_file[i][k] != ' ' && k < comment_limit; k++) {
				condition2 += entire_file[i][k];
			}
			if (cond_sign == '>' ||
					cond_sign == '<' ||
					cond_sign == '=' ||
					cond_sign == '!') {
				if (isdigit(condition1[0]) && isdigit(condition2[0])) {
					if (cond_sign == '>') tof = (std::atoi(condition1.c_str()) > std::atoi(condition2.c_str()));
					else if (cond_sign == '<') tof = (std::atoi(condition1.c_str()) < std::atoi(condition2.c_str()));
					else if (cond_sign == '=') tof = (std::atoi(condition1.c_str()) == std::atoi(condition2.c_str()));
					else if (cond_sign == '!') tof = (std::atoi(condition1.c_str()) != std::atoi(condition2.c_str()));
				}
				else if (!isdigit(condition1[0]) && !isdigit(condition2[0])) {
					int a = 0;
					while (a < variables.size()) {
						if (variables[a] == condition1) break;
						else a++;
					}
					int b = 0;
					while (b < variables.size()) {
						if (variables[b] == condition2) break;
						else b++;
					}
					if (a > variables.size() || b > variables.size()) {
						std::cout << "You failed to specify valid variables in the conditional on line " << problem << ".\n";
						std::cout << "The program will now exit.\nError code: g3n4rg\n";
						end_n_del(funcs);
						endp(34, flush);
					}
					else {
						if (cond_sign == '>') tof = (std::atoi(values[a].c_str()) > std::atoi(values[b].c_str()));
						else if (cond_sign == '<') tof = (std::atoi(values[a].c_str()) < std::atoi(values[b].c_str()));
						else if (cond_sign == '=') tof = (atof(values[a].c_str()) == atof(values[b].c_str()));
						else if (cond_sign == '!') tof = (atof(values[a].c_str()) != atof(values[b].c_str()));
					}
				}
				else if (isdigit(condition2.c_str()[0])) {
					int j = 0;
 					while (j < variables.size()) {
						if (variables[j] == condition1) break;
						else j++;
					}
					if (j > variables.size()) {
						std::cout << "You failed to specify a valid variable for the first half of the conditional on line " << problem << ".\n";
						std::cout << "The program will now exit.\nError code: 14rg\n";
						end_n_del(funcs);
						endp(14, flush);
					}
					else {
						if (cond_sign == '>') tof = (std::atoi(values[j].c_str()) > std::atoi(condition2.c_str()));
						else if (cond_sign == '<') tof = (std::atoi(values[j].c_str()) < std::atoi(condition2.c_str()));
						else if (cond_sign == '=') tof = (std::atoi(values[j].c_str()) == std::atoi(condition2.c_str()));
						else if (cond_sign == '!') tof = (std::atoi(values[j].c_str()) != std::atoi(condition2.c_str()));
					}
				}
				else if (isdigit(condition1[0])) {
					int j = 0;
					while (j < variables.size() + 1) {
						if (variables[j] == condition2) break;
						else j++;
					}
					if (j == variables.size()) {
						std::cout << "You failed to specify a valid variable for the second half of the conditional on line " << problem << ".\n";
						std::cout << "The program will now exit.\nError code: 24rg\n";
						end_n_del(funcs);
						endp(24, flush);
					}
					else {
						if (cond_sign == '>') tof = (std::atoi(values[j].c_str()) < std::atoi(condition1.c_str()));
						else if (cond_sign == '<') tof = (std::atoi(values[j].c_str()) > std::atoi(condition1.c_str()));
						else if (cond_sign == '=') tof = (std::atoi(values[j].c_str()) == std::atoi(condition1.c_str()));
						else if (cond_sign == '!') tof = (std::atoi(values[j].c_str()) != std::atoi(condition1.c_str()));
					}
				}
				if (tof) {
					std::ofstream do_me_hard;
					do_me_hard.open("conditional" + std::to_string(problem));
					for (int j = k + 1;; j++) {
						if (i == newlinesnum) {
							std::cout << "Your conditional did not have a \"done\" statement before the end of the file.\n";
							std::cout << "The failed conditional started on line " << problem << ". The program will now exit.\n";
							std::cout << "Error code: 60n3\n";
							end_n_del(funcs);
							endp(603, flush);
						}
						else if (j > entire_file[i].size()) {
							i++;
							j = 0;
							do_me_hard << '\n';
						}
						else if ((entire_file[i].find("while", j - 1) != std::string::npos && entire_file[i].find("while", j - 1) < comment_limit) ||
										 (entire_file[i].find("if", j - 1) != std::string::npos && entire_file[i].find("if", j - 1) < comment_limit) ||
										 (entire_file[i].find("else", j - 1) != std::string::npos && entire_file[i].find("else", j - 1) < comment_limit) ||
										 (entire_file[i].find("make", j - 1) != std::string::npos && entire_file[i].find("make", j - 1) < comment_limit)) nest++;
						else if (entire_file[i].find("done") != std::string::npos && nest > 0 &&
										 entire_file[i].find("done") < comment_limit &&
										 entire_file[i].find("done") < entire_file[i].find("show") &&
										 entire_file[i].find("done") < entire_file[i].find("set") &&
										 entire_file[i].find("done") < entire_file[i].find("if") &&
										 entire_file[i].find("done") < entire_file[i].find("else") &&
										 entire_file[i].find("done") < entire_file[i].find("push") &&
										 entire_file[i].find("done") < entire_file[i].find("make") &&
										 entire_file[i].find("done") < entire_file[i].find("with") &&
										 entire_file[i].find("done") < entire_file[i].find("while") &&
										 entire_file[i].find("done") < entire_file[i].find("call")) {
							nest--;
							do_me_hard << "done\n";
						}
						else if (entire_file[i].find("done") < comment_limit &&
										 entire_file[i].find("done") < entire_file[i].find("show") &&
										 entire_file[i].find("done") < entire_file[i].find("set") &&
										 entire_file[i].find("done") < entire_file[i].find("if") &&
										 entire_file[i].find("done") < entire_file[i].find("else") &&
										 entire_file[i].find("done") < entire_file[i].find("push") &&
										 entire_file[i].find("done") < entire_file[i].find("make") &&
										 entire_file[i].find("done") < entire_file[i].find("with") &&
										 entire_file[i].find("done") < entire_file[i].find("while") &&
										 entire_file[i].find("done") < entire_file[i].find("call")) break;
						char put_me_in_coach = entire_file[i][j - 1];
						do_me_hard << put_me_in_coach;
					}
					do_me_hard.close();
					translate(std::string("conditional" + std::to_string(problem)).c_str(), variables, values, baskets, count, i, false, nest);
					remove(std::string("conditional" + std::to_string(problem)).c_str());
				}
				else {
					while (entire_file[i].find("done") == std::string::npos) i++;
				}
			}
			else {
				std::cout << "You did not specify a conditional character on line " << problem << ".\nThe program will now exit.";
				std::cout << "Error code: c0n651gn\n";
				end_n_del(funcs);
				endp(651, flush);
			}
		}
		// keyword else
		else if (entire_file[i].find("else") != std::string::npos && entire_file[i].find("else") < comment_limit &&
						entire_file[i].find("else") < entire_file[i].find("show") &&
						entire_file[i].find("else") < entire_file[i].find("set") &&
						entire_file[i].find("else") < entire_file[i].find("if") &&
						entire_file[i].find("else") < entire_file[i].find("push") &&
						entire_file[i].find("else") < entire_file[i].find("while") &&
						entire_file[i].find("else") < entire_file[i].find("call") &&
						entire_file[i].find("else") < entire_file[i].find("make") &&
						entire_file[i].find("else") < entire_file[i].find("with")) {
			if (!tof) {
				int k = entire_file[i].find("else") + 4;
				std::ofstream else_file;
				const char* else_f = std::string("else" + std::to_string(problem)).c_str();
				else_file.open(else_f);
				for (int j = k + 1;; j++) {
					if (j > entire_file[i].size()) {
						i++;
						j = 0;
						else_file << '\n';
					}
					else if ((entire_file[i].find("while", j - 1) != std::string::npos && entire_file[i].find("while", j - 1) < comment_limit) ||
									(entire_file[i].find("if", j - 1) != std::string::npos && entire_file[i].find("if", j - 1) < comment_limit) ||
									(entire_file[i].find("else", j - 1) != std::string::npos && entire_file[i].find("else", j - 1) < comment_limit) ||
									(entire_file[i].find("make", j - 1) != std::string::npos && entire_file[i].find("make", j - 1) < comment_limit)) nest++;
					else if (entire_file[i].find("done") != std::string::npos && nest > 0 &&
									 entire_file[i].find("done") < comment_limit &&
									 entire_file[i].find("done") < entire_file[i].find("show") &&
									 entire_file[i].find("done") < entire_file[i].find("set") &&
									 entire_file[i].find("done") < entire_file[i].find("if") &&
									 entire_file[i].find("done") < entire_file[i].find("else") &&
									 entire_file[i].find("done") < entire_file[i].find("push") &&
									 entire_file[i].find("done") < entire_file[i].find("make") &&
									 entire_file[i].find("done") < entire_file[i].find("with") &&
									 entire_file[i].find("done") < entire_file[i].find("while") &&
									 entire_file[i].find("done") < entire_file[i].find("call")) {
						nest--;
						else_file << "done\n";
					}
					else if (entire_file[i].find("done") < comment_limit &&
									 entire_file[i].find("done") < entire_file[i].find("show") &&
									 entire_file[i].find("done") < entire_file[i].find("set") &&
									 entire_file[i].find("done") < entire_file[i].find("if") &&
									 entire_file[i].find("done") < entire_file[i].find("else") &&
									 entire_file[i].find("done") < entire_file[i].find("push") &&
									 entire_file[i].find("done") < entire_file[i].find("make") &&
									 entire_file[i].find("done") < entire_file[i].find("with") &&
									 entire_file[i].find("done") < entire_file[i].find("while") &&
									 entire_file[i].find("done") < entire_file[i].find("call")) break;
					char put_me_in_coach = entire_file[i][j - 1];
					else_file << put_me_in_coach;
				}
				else_file.close();
				translate(else_f, variables, values, baskets, count, i);
				remove(else_f);
			}
			else {
				while (entire_file[i].find("done") == std::string::npos) i++;
			}
		}
		// keyword push
		else if (entire_file[i].find("push") != std::string::npos && entire_file[i].find("push") < comment_limit &&
						entire_file[i].find("push") < entire_file[i].find("show") &&
						entire_file[i].find("push") < entire_file[i].find("set") &&
						entire_file[i].find("push") < entire_file[i].find("if") &&
						entire_file[i].find("push") < entire_file[i].find("else") &&
						entire_file[i].find("push") < entire_file[i].find("while") &&
						entire_file[i].find("push") < entire_file[i].find("call") &&
						entire_file[i].find("push") < entire_file[i].find("make") &&
						entire_file[i].find("push") < entire_file[i].find("with")) {
			int k = entire_file[i].find("push") + 4;
			while (entire_file[i][k] == ' ') k++;
			std::string thing = "";
			std::string basket_im_adding_to = "";
			for (; entire_file[i][k] != ' ' && k < comment_limit; k++) {
				thing += entire_file[i][k];
			}
			while (entire_file[i][k] == ' ') k++;
			if (entire_file[i].find("into") != std::string::npos && entire_file[i].find("into") < comment_limit) k += 4;
			else {
				std::cout << "You did not include the keyword \"into\" in your push statement on line " << problem << ".\n";
				std::cout << "The program will now exit.\n";
				std::cout << "Error code: 1n70\n";
				end_n_del(funcs);
				endp(170, flush);
			}
			while (entire_file[i][k] == ' ') k++;
			for (; entire_file[i][k] != ' ' && entire_file[i][k] != '\0' && k < comment_limit; k++) {
				basket_im_adding_to += entire_file[i][k];
			}
			for (int e = 0;; e++) {
				if (!baskets.empty() == true) {
					if (basket_im_adding_to == baskets[e][0].getsdata()) {
						if (isdigit(thing.c_str()[0])) baskets[e].push_back(var(std::atoi(thing.c_str())));
						else {
							for (int y = 0;; y++) {
								if (thing == variables[y]) {
									baskets[e].push_back(values[y].c_str());
									break;
								}
								else if (y == variables.size() - 1) {
									baskets[e].push_back(thing.c_str());
									break;
								}
							}
						}
						break;
					}
					else if (e == baskets.size()) {
						std::cout << "You failed to push something into the basket on line " << problem << ".\n";
						break;
					}
				}
			}
		}
		// keyword while
		else if (entire_file[i].find("while") != std::string::npos && entire_file[i].find("while") < comment_limit &&
						entire_file[i].find("while") < entire_file[i].find("show") &&
						entire_file[i].find("while") < entire_file[i].find("set") &&
						entire_file[i].find("while") < entire_file[i].find("if") &&
						entire_file[i].find("while") < entire_file[i].find("else") &&
						entire_file[i].find("while") < entire_file[i].find("push") &&
						entire_file[i].find("while") < entire_file[i].find("call") &&
						entire_file[i].find("while") < entire_file[i].find("make") &&
						entire_file[i].find("while") < entire_file[i].find("with")) {
			int k = entire_file[i].find("while") + 5;
			std::string thing = "";
			int beg = 0;
			int end = 0;
			while (entire_file[i][k] == ' ') k++;
			std::string condition1 = "";
			std::string im_this = "";
			for (; entire_file[i][k] != ' ' && k < comment_limit; k++) {
				condition1 += entire_file[i][k];
			}
			while (entire_file[i][k] == ' ') k++;
			std::string condition2 = "";
			char cond_sign = entire_file[i][k];
			k++;
			while (entire_file[i][k] == ' ') k++;
			for (; entire_file[i][k] != '\0' && entire_file[i][k] != ' ' && k < comment_limit; k++) {
				condition2 += entire_file[i][k];
			}
			if (cond_sign == '>' ||
					cond_sign == '<' ||
					cond_sign == '=' ||
					cond_sign == '!') {
				if (isdigit(condition1[0]) && isdigit(condition2[0])) {
					if (cond_sign == '>') tof = (std::atoi(condition1.c_str()) > std::atoi(condition2.c_str()));
					else if (cond_sign == '<') tof = (std::atoi(condition1.c_str()) < std::atoi(condition2.c_str()));
					else if (cond_sign == '=') tof = (std::atoi(condition1.c_str()) == std::atoi(condition2.c_str()));
					else if (cond_sign == '!') tof = (std::atoi(condition1.c_str()) != std::atoi(condition2.c_str()));
					beg = std::atoi(condition1.c_str());
					end = std::atoi(condition2.c_str());
					im_this = "2num";
				}
				else if (!isdigit(condition1[0]) && !isdigit(condition2[0])) {
					int a = 0;
					while (a < variables.size()) {
						if (variables[a] == condition1) break;
						else a++;
					}
					int b = 0;
					while (b < variables.size()) {
						if (variables[b] == condition2) break;
						else b++;
					}
					if (a > variables.size() || b > variables.size()) {
						std::cout << "You failed to specify valid variables in the conditional on line " << problem << ".\n";
						std::cout << "The program will now exit.\nError code: g3n4rg\n";
						end_n_del(funcs);
						endp(34, flush);
					}
					else {
						if (cond_sign == '>') tof = (std::atoi(values[a].c_str()) > std::atoi(values[b].c_str()));
						else if (cond_sign == '<') tof = (std::atoi(values[a].c_str()) < std::atoi(values[b].c_str()));
						else if (cond_sign == '=') tof = (std::atoi(values[a].c_str()) == std::atoi(values[b].c_str()));
						else if (cond_sign == '!') tof = (std::atoi(values[a].c_str()) != std::atoi(values[b].c_str()));
						beg = std::atoi(values[a].c_str());
						end = std::atoi(values[b].c_str());
						im_this = "2var";
					}
				}
				else if (isdigit(condition2.c_str()[0])) {
					int j = 0;
					while (j < variables.size()) {
						if (variables[j] == condition1) break;
						else j++;
					}
					if (j > variables.size()) {
						std::cout << "You failed to specify a valid variable for the first half of the conditional on line " << problem << ".\n";
						std::cout << "The program will now exit.\nError code: 14rg\n";
						end_n_del(funcs);
						endp(14, flush);
					}
					else {
						if (cond_sign == '>') tof = (std::atoi(values[j].c_str()) > std::atoi(condition2.c_str()));
						else if (cond_sign == '<') tof = (std::atoi(values[j].c_str()) < std::atoi(condition2.c_str()));
						else if (cond_sign == '=') tof = (std::atoi(values[j].c_str()) == std::atoi(condition2.c_str()));
						else if (cond_sign == '!') tof = (std::atoi(values[j].c_str()) != std::atoi(condition2.c_str()));
						beg = std::atoi(values[j].c_str());
						end = std::atoi(condition2.c_str());
						im_this = "var1";
						thing = variables[j];
					}
				}
				else if (isdigit(condition1[0])) {
					int j = 0;
					while (j < variables.size() + 1) {
						if (variables[j] == condition2) break;
						else j++;
					}
					if (j == variables.size()) {
						std::cout << "You failed to specify a valid variable for the second half of the conditional on line " << problem << ".\n";
						std::cout << "The program will now exit.\nError code: 24rg\n";
						end_n_del(funcs);
						endp(24, flush);
					}
					else {
						if (cond_sign == '>') tof = (std::atoi(values[j].c_str()) < std::atoi(condition1.c_str()));
						else if (cond_sign == '<') tof = (std::atoi(values[j].c_str()) > std::atoi(condition1.c_str()));
						else if (cond_sign == '=') tof = (std::atoi(values[j].c_str()) == std::atoi(condition1.c_str()));
						else if (cond_sign == '!') tof = (std::atoi(values[j].c_str()) != std::atoi(condition1.c_str()));
						beg = std::atoi(condition1.c_str());
						end = std::atoi(values[j].c_str());
						im_this = "var2";
						thing = variables[j];
					}
				}
			}
			if (tof) {
				while_loop_guts(beg, end, newlinesnum, variables, values, baskets, k, i, count, problem, im_this, entire_file, thing, comment_limit);
				remove(std::string("conditional" + std::to_string(problem)).c_str());
			}
		}
		// keyword make
		else if (entire_file[i].find("make") != std::string::npos && entire_file[i].find("make") < comment_limit &&
						entire_file[i].find("make") < entire_file[i].find("show") &&
						entire_file[i].find("make") < entire_file[i].find("set") &&
						entire_file[i].find("make") < entire_file[i].find("if") &&
						entire_file[i].find("make") < entire_file[i].find("else") &&
						entire_file[i].find("make") < entire_file[i].find("push") &&
						entire_file[i].find("make") < entire_file[i].find("while") &&
						entire_file[i].find("make") < entire_file[i].find("call") &&
						entire_file[i].find("make") < entire_file[i].find("with")) {
			int k = entire_file[i].find("make") + 4;
			while (entire_file[i][k] == ' ') k++;
			std::string func_name = "";
			for (; entire_file[i][k] != ' ' && entire_file[i][k] != '\0'; k++) {
				func_name += entire_file[i].at(k);
			}
			std::ofstream func_file;
			func_file.open(func_name);
			funcs.push_back(func_name);
			if (entire_file[i][k] == '\0') i++;
			else while (entire_file[i][k] == ' ' || entire_file[i][k] == 'd' || entire_file[i][k] == 'o') k++;
			for (int j = k + 1;; j++) {
				if (i == newlinesnum) {
					std::cout << "Your function did not have a \"done\" statement before the end of the file.\n";
					std::cout << "The failed function started on line " << problem << ". The program will now exit.\n";
					std::cout << "Error code: 60n3\n";
					end_n_del(funcs);
					endp(603, flush);
				}
				else if (entire_file[i].find("call " + func_name) != std::string::npos) {
					std::cout << "You called a function before you finished making it on line " << problem << ".\n";
					std::cout << "The program will now exit.\n";
					std::cout << "Error code: c411d0n3\n";
					end_n_del(funcs);
					endp(41103, flush);
				}
				else if (j > entire_file[i].size()) {
					i++;
					j = 0;
					func_file << '\n';
				}
				else if ((entire_file[i].find("while", j - 1) != std::string::npos && entire_file[i].find("while", j - 1) < comment_limit) ||
								(entire_file[i].find("if", j - 1) != std::string::npos && entire_file[i].find("if", j - 1) < comment_limit) ||
								(entire_file[i].find("else", j - 1) != std::string::npos && entire_file[i].find("else", j - 1) < comment_limit) ||
								(entire_file[i].find("make", j - 1) != std::string::npos && entire_file[i].find("make", j - 1) < comment_limit)) nest++;
				else if (entire_file[i].find("done") != std::string::npos && nest > 0 &&
								 entire_file[i].find("done") < comment_limit &&
								 entire_file[i].find("done") < entire_file[i].find("show") &&
								 entire_file[i].find("done") < entire_file[i].find("set") &&
								 entire_file[i].find("done") < entire_file[i].find("if") &&
								 entire_file[i].find("done") < entire_file[i].find("else") &&
								 entire_file[i].find("done") < entire_file[i].find("push") &&
								 entire_file[i].find("done") < entire_file[i].find("make") &&
								 entire_file[i].find("done") < entire_file[i].find("with") &&
								 entire_file[i].find("done") < entire_file[i].find("while") &&
								 entire_file[i].find("done") < entire_file[i].find("call")) {
					nest--;
					func_file << "done\n";
				}
				else if (entire_file[i].find("done") < comment_limit &&
								 entire_file[i].find("done") < entire_file[i].find("show") &&
								 entire_file[i].find("done") < entire_file[i].find("set") &&
								 entire_file[i].find("done") < entire_file[i].find("if") &&
								 entire_file[i].find("done") < entire_file[i].find("else") &&
								 entire_file[i].find("done") < entire_file[i].find("push") &&
								 entire_file[i].find("done") < entire_file[i].find("make") &&
								 entire_file[i].find("done") < entire_file[i].find("with") &&
								 entire_file[i].find("done") < entire_file[i].find("while") &&
								 entire_file[i].find("done") < entire_file[i].find("call")) break;
				char put_me_in_coach = entire_file[i][j - 1];
				func_file << put_me_in_coach;
			}
			func_file.close();
		}
		// keyword call
		else if (entire_file[i].find("call") != std::string::npos && entire_file[i].find("call") < comment_limit &&
						entire_file[i].find("call") < entire_file[i].find("show") &&
						entire_file[i].find("call") < entire_file[i].find("set") &&
						entire_file[i].find("call") < entire_file[i].find("if") &&
						entire_file[i].find("call") < entire_file[i].find("else") &&
						entire_file[i].find("call") < entire_file[i].find("push") &&
						entire_file[i].find("call") < entire_file[i].find("make") &&
						entire_file[i].find("call") < entire_file[i].find("while") &&
						entire_file[i].find("call") < entire_file[i].find("with")) {
			int k = entire_file[i].find("call") + 4;
			int stop_here = 0;
			if (entire_file[i].find(';') != std::string::npos) stop_here = entire_file[i].find(';');
			else stop_here = entire_file[i].size();
			while (entire_file[i][k] == ' ') k++;
			std::string call_name = "";
			for (; k < stop_here && entire_file[i][k] != ' ' && entire_file[i][k] != '\0'; k++) {
				call_name += entire_file[i][k];
			}
			for (int j = 0; j < funcs.size(); j++) {
				if (call_name == "") {
					std::cout << "You failed to call a specific function on line " << problem << ". The program will now exit.\n";
					std::cout << "Error code: c411614nk\n";
					end_n_del(funcs);
					endp(411614, flush);
				}
				if (funcs[j] == call_name) {
					std::vector<std::string> varTemp = variables;
					std::vector<std::string> valTemp = values;
					translate(funcs[j].c_str(), varTemp, valTemp, baskets, count, i, true);
				}
			}
		}
		// keyword show
		else if (entire_file[i].find("show") != std::string::npos && entire_file[i].find("show") < comment_limit &&
						entire_file[i].find("show") < entire_file[i].find("set") &&
						entire_file[i].find("show") < entire_file[i].find("if") &&
						entire_file[i].find("show") < entire_file[i].find("else") &&
						entire_file[i].find("show") < entire_file[i].find("push") &&
						entire_file[i].find("show") < entire_file[i].find("call") &&
						entire_file[i].find("show") < entire_file[i].find("make") &&
						entire_file[i].find("show") < entire_file[i].find("while") &&
						entire_file[i].find("show") < entire_file[i].find("with")) {
			int k = entire_file[i].find("show") + 4;
			int stop_here = 0;
			if (entire_file[i].find(';') != std::string::npos) stop_here = entire_file[i].find(';');
			else stop_here = entire_file[i].size();
			while (entire_file[i][k] == ' ') k++;
			while (entire_file[i][k] != '\n') {
				if (isdigit(entire_file[i][k])) {
					std::string thing = "";
					for (int a = k; a < stop_here; a++) {
						thing += entire_file[i][a];
					}
					std::cout << pemdas(thing) << '\n';
				}
				else if (count < 1) {
					for (int b = k; b < stop_here; b++) {
						std::cout << entire_file[i][b];
					}
					std::cout << '\n';
				}
				else {
					for (int p = 0;; p++) {
						if (entire_file[i][k] == variables[p][0] || count == p) {
							std::string thing = "";
							bool not_done = false;
							int here = 0;
							for (int e = k; e < stop_here && entire_file[i][e] != ' '; e++) {
								thing += entire_file[i][e];
								here = e + 1;
							}
							if (entire_file[i].find_first_of("1234567890-=qwertyuiop\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?", here + 1) < stop_here &&
							entire_file[i].find_first_of("1234567890-=qwertyuiop\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?", here + 1) != std::string::npos) not_done = true;
							if (thing == variables[p] && !not_done) {
								std::cout << values[p];
								std::cout << '\n';
								break;
							}
							else if (!not_done && !baskets.empty()) {
								for (int y = 0; y < baskets.size(); y++) {
									if (thing == baskets[y][0].getsdata() && thing.find('[') == std::string::npos) {
										for (int m = 1; m < baskets[y].size(); m++) std::cout << (m - 1) << ": " << baskets[y][m] << '\n';
										break;
										break;
										break;
									}
									else if (thing.find('[') != std::string::npos) {
										std::string u = "";
										std::string new_thing = "";
										for (int j = 0; thing[j] != '['; j++) {
											new_thing += thing[j];
										}
										for (int m = thing.find('[') + 1; m < thing.size() && thing[m] != ']'; m++) {
											u += thing[m];
										}
										if (new_thing == baskets[y][0].getsdata()) {
											std::cout << baskets[y][std::atoi(u.c_str()) + 1] << '\n';
										}
									}
								}
							}
							else if (not_done || p == count) {
								for (int b = k; b < stop_here; b++) {
									std::cout << entire_file[i][b];
								}
								std::cout << '\n';
								break;
							}
						}
						else if (p < count - 1) {}
						else if (p >= count) {
							break;
							break;
						}
					}
				}
				k++;
				break;
			}
		}
		// keyword set
		else if (entire_file[i].find("set") != std::string::npos && entire_file[i].find("set") < comment_limit &&
						entire_file[i].find("set") < entire_file[i].find("show") &&
						entire_file[i].find("set") < entire_file[i].find("if") &&
						entire_file[i].find("set") < entire_file[i].find("else") &&
						entire_file[i].find("set") < entire_file[i].find("push") &&
						entire_file[i].find("set") < entire_file[i].find("call") &&
						entire_file[i].find("set") < entire_file[i].find("make") &&
						entire_file[i].find("set") < entire_file[i].find("while") &&
						entire_file[i].find("set") < entire_file[i].find("with")) {
			try {
				int k = entire_file[i].find("set") + 3;
				int stop_here = 0;
				std::string variable = "";
				if (entire_file[i].find(';') != std::string::npos) stop_here = entire_file[i].find(';');
				else stop_here = entire_file[i].size();
				if (entire_file[i].at(k) == ' ') {
					while (entire_file[i].at(k) == ' ') k++;
				}
				while (entire_file[i].at(k) != ' ') {
					variable += entire_file[i].at(k);
					k++;
				}
				while (entire_file[i].at(k) == ' ') k++;
				if (entire_file[i][k] == 't' && entire_file[i][k + 1] == 'o') {
					k += 3;
					while (entire_file[i].at(k) == ' ') k++;
				} else throw 70;
				int copy_k = k;
				for (int j = 0;; j++) {
					if (variables[j] == variable) {
						if (isdigit(entire_file[i].at(copy_k))) {
							std::string thing = "";
							for (int a = copy_k; a < stop_here; a++) {
								thing += entire_file[i][a];
							}
							values[j] = std::to_string(pemdas(thing));
						}
						else {
							if (copy_k < stop_here) {
								values[j] = "";
								while (copy_k < stop_here && entire_file[i][copy_k] != ' ') {
									values[j] += (entire_file[i].at(copy_k));
									copy_k++;
								}
								if (values[j] == "input") {
									values[j] = "";
									std::cin >> values[j];
									flush++;
								}
							} else throw 5709;
						}
						copy_k = k;
					}
					else if (j >= variables.size() - 1) {
						variables[count] = variable;
						if (isdigit(entire_file[i].at(copy_k))) {
							std::string thing = "";
							for (int a = copy_k; a < stop_here; a++) {
								thing += entire_file[i][a];
							}
							values[count] = std::to_string(pemdas(thing));
						}
						else {
							if (copy_k < stop_here) {
								while (copy_k < stop_here && entire_file[i][copy_k] != ' ') {
									values[count].push_back(entire_file[i].at(copy_k));
									copy_k++;
								}
								if (values[count] == "input") {
									values[count] = "";
									std::cin >> values[count];
									flush++;
								}
								else if (values[count] == "basket") {
									std::vector<var> push_me;
									push_me.push_back(variables[count].c_str());
									values[count] = "";
									variables[count] = "";
									baskets.push_back(push_me);
								}
							} else throw 537;
						}
						copy_k = k;
						count++;
						break;
					}
				}
			}
			catch (int& e) { // catch from keyword set
				std::cout << "Your variable failed on line " << problem << ". Did you set a value to it?\n";
				std::cout << "The program will now exit.\n";
				std::cout << "Error code: " << e << std::endl;
				end_n_del(funcs);
				endp(e, flush);
			}
		}
	}
}
