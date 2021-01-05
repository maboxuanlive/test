#include <iostream>
#include <string>
using namespace std; 

int main(int argc, char *argv[]) {
	string str1;
	getline(cin,str1);
	string str2;
	getline(cin,str2);
	int i,j;
	for(i=0;i<=str1.length()-str2.length();i++)
	{
		j=0;
		while(j<str2.length())
		{
			if(str2[j]!=str1[i+j])
			{
				break;
			}
			j++;
		}
			if(j==str2.length())
		{
			cout<<"        "<<i+1;
			return 0;
		}

	}
	cout<<"0";
	
	return 0;
}



