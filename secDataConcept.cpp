//Mitchell Stemm
//

#include <iostream>
#include <utility> 
#include <string>

//This is a structure for the values stored by CS2 
struct item{
		std::string field;
		int row;
		std::pair<int,int> location;
	};
	
	
//function definitions for printing
std::string printItem(item in);
void printEncrip(std::string str);
void printDecrip(std::string str);

int main(){
	
	std::cout <<"\nThis program is a proof of concept for an abstract database.\nEncryption will be represented by printing ascii values of the string\nWhile this system is all local it represents a Cloud system.\n\n";
	
	
	//creating 'databases'
	//the current length is arbitrary
	std::string CS1[20][20];
	item CS2[20][20];
	std::cout << "creating databases;\n\n";
	
	//process for adding to the data base
		//create refrence in CS2
		CS2[0][0].field="name";
		CS2[0][0].row=1;
		CS2[0][0].location=std::make_pair(0,0);
	
		//adding actual data to CS1
		CS1[CS2[0][0].location.first][CS2[0][0].location.second]="Mike";
	
	std::cout << "adding sample data to both CS1 and 2\n\n";
	
	
	//printing the current data, as the database would see:
			//CS2 sees:
		std::cout << "CS2 sees:\n";
		printEncrip(printItem(CS2[0][0]));
			//CS1 sees:
		std::cout << "\nCS1 sees:\n";
		printEncrip(CS1[0][0]);
	
	//Process for retrieving information
	
		std::cout<< "retrieving information\n\n";
	
		std::string temp =CS1[CS2[0][0].location.first][CS2[0][0].location.second];
	
		
		std::cout << "from CS2:\n";
		printDecrip(printItem(CS2[0][0]));
		
		std::cout << "from CS1:\n";
		printDecrip(temp);
		
	
	
}



//prints a string as ascii values, represents encryption
void printEncrip(std::string str){
	for(int i=0; i < str.length();i++)
		std::cout << (int)str[i];
	std::cout << std::endl;}

void printDecrip(std::string str){std::cout << str <<std::endl;}

std::string printItem(item in){
	std::string out = in.field + "\t";
	out+= in.row + "\t";
	out+= std::to_string(in.location.first) + ",";
	out+= std::to_string(in.location.second) + "\n";
	
	return out;
}