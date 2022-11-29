// For debugging
#include <iostream>
// For std::remove
#include <string>
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void fillWords(std::string in,const std::set<std::string>& dict, std::set<std::string>& words);
void fillit(std::string in, std::string floating, const std::set<std::string>& dict, std::set<std::string>& words);
// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    std::set<std::string> storage;
		fillit(in,floating,dict,storage);
		return storage;
		
    
        

}

void fillit(std::string in, std::string floating, const std::set<std::string>& dict, std::set<std::string>& words){
    if(floating.size() == 0){
			fillWords(in,dict,words);
			return;

			
		}

		else{
			for(int i = 0;i<in.size();i++){
				if(in[i] == '-'){
					std::string in2 = in;
					in2[i] = floating[0];
					fillit(in2,floating.substr(1,std::string::npos),dict,words);
				}
			}
		}
		
		
}
void fillWords(std::string in,const std::set<std::string>& dict, std::set<std::string>& words){
	if(in.find('-') == std::string::npos){
		if(dict.find(in) != dict.end()){
			words.insert(in);
		}
		return;
	}
	else{
		int i = in.find('-');
		for(int j = 0;j<26;j++){
			in[i] = char(j+97);
			fillWords(in,dict,words);
		}
	}
}


// Define any helper functions here
