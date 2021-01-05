#include <iostream>
#include <string>
using namespace std; 

int main(int argc, char *argv[]) {
	string str1;
	getline(cin,str1);
	string str2;
	getline(cin,str2);
	int i,j;
	int count=0;
	for(i=1;i<=str1.length()-str2.length()+1;)
	{
		j=0;
		while(j<str2.length())
		{
			if(str2[j]!=str1[i+j-1])
			{
				break;
			}
			j++;
		}
			if(j==str2.length())
		{
			count++;
			i=i+str2.length();
		}
		else
		{
			i++;
		}

	}
	cout<<count;
	
	return 0;
}



