#include <iostream>
#include <cstring>
#include <string>
#include "md5.h"

using namespace std;

int main() 
{
	string Hash = "I1JjSUzgQ5rPId/BCVAiJ.";
	string pass = "aaaaaa"; 
	// "fmfokk";
	string salt = "4fTghp6q"; 
	string magicID = "$1$"
	bool found = false;
	
	while(password != "zzzzz" && !found) 
	{
		unsigned char* maybe_pass = MD5(pass + salt + password).digest;
		string t = "";
		for(unsigned int i = 0; i < 6; i++) 
		{
			t.push_back(maybe_pass[i]);
		}

		unsigned char* maybe_pass2 = MD5(pass + magicID + salt + t  + pass[0] + '\0' + '\0').digest;
		for(unsigned int j = 0; j < 1000; j++) 
		{
			
			string temp = "";

			for(unsigned int k = 0; k < 16; k++) 
			{
				temp.push_back(maybe_pass2[k]);
			}

			string str = "";

			if(j % 2 == 0) 
			{
				str += temp;
			}
			if(j % 2 == 1) 
			{
				str += pass;
			}
			if(!(j % 3 == 0)) 
			{
				str += salt;
			}
			if(!(j % 7 == 0)) 
			{
				str += pass;
			}
			if(j % 2 == 0) 
			{
				str += pass;
			}
			if(j % 2 == 1) 
			{
				str += temp;
			}

			maybe_pass2 = MD5(str).digest;
		}

		cout << magic + salt + "$";

		string crypto64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		unsigned char fin[16];
		fin[0] = maybe_pass2[11];
		fin[1] = maybe_pass2[4];
		fin[2] = maybe_pass2[10];
		fin[3] = maybe_pass2[5];
		fin[4] = maybe_pass2[3];
		fin[5] = maybe_pass2[9];
		fin[6] = maybe_pass2[15];
		fin[7] = maybe_pass2[2];
		fin[8] = maybe_pass2[8];
		fin[9] = maybe_pass2[14];
		fin[10] = maybe_pass2[1];
		fin[11] = maybe_pass2[7];
		fin[12] = maybe_pass2[13];
		fin[13] = maybe_pass2[0];
		fin[14] = maybe_pass2[6];
		fin[15] = maybe_pass2[12];	

		unsigned long long A = (0 | fin[13] << 16) | (fin[14] << 8) | fin[15];
		unsigned long long B = (0 | fin[10] << 16) | (fin[11] << 8) | fin[12];
		unsigned long long C = (0 | fin[7] << 16) | (fin[8] << 8) | fin[9];
		unsigned long long D = (0 | fin[4] << 16) | (fin[5] << 8) | fin[6];
		unsigned long long E = (0 | fin[1] << 16) | (fin[2] << 8) | fin[3];
		unsigned long long F = 0 | fin[0];
		string result = "";
		int x = 0;

		while(A != 0) 
		{
			x = A & 0x3F;
			result += crypto64[x];
			A = A >> 6;
		}

		while(B != 0) 
		{
			x = B & 0x3F;
			result += crypto64[x];
			B = B >> 6;
		}

		while(C != 0) 
		{
			x = C & 0x3F;
			result += crypto64[x];
			C = C >> 6;
		}

		while(D != 0) 
		{
			x = D & 0x3F;
			result += crypto64[x];
			D = D >> 6;
		}

		while(E != 0) 
		{
			x = E & 0x3F;
			result += crypto64[x];
			E = E >> 6;
		}

		while(F != 0) 
		{
			x = F & 0x3F;
			result += crypto64[x];
			F = F >> 6;
		}

		cout << result << endl;

		if(result == Hash) 
		{
			cout << "Your password is: " << password << endl;
			found = true;
		}
		
		if(pass[5] == 'z') 
		{
			if(pass[4] == 'z') 
			{
				if(pass[3] == 'z') 
				{
					if(pass[2] == 'z') 
					{
						if(pass[1] == 'z')
						{
							pass[0]++;
							pass[1] = 'a';
							pass[2] = 'a';
							pass[3] = 'a';
							pass[4] = 'a';
							pass[5] = 'a';
						} 
						else 
						{
							pass[1]++;
							pass[2] = 'a';
							pass[3] = 'a';
							pass[4] = 'a';
							pass[5] = 'a';
						}
					} 
					else 
					{
						pass[2]++;
						pass[3] = 'a';
						pass[4] = 'a';
						pass[5] = 'a';
					}
				} 
				else 
				{
					pass[3]++;
					pass[4] = 'a';
					pass[5] = 'a';
				}
			} 
			else 
			{
				pass[4]++;
				pass[5] = 'a';
			}
		} 
		else 
		{
			pass[5]++;
		}
	}
	
	return 0;
}
