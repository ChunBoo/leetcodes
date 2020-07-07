#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
// using unsigned char=uchar;
typedef unsigned char uchar;
int findSmallestNumber(int iarray[])
{


}
int dec2hexChars(int decNum, char s[4])
{
		int b, idx = 0,temp;
		for (temp=0; temp < 4; temp++)
		{
			s[temp] = '0';
		}
		while (decNum > 0)
		{
			b = decNum % 16;
			if (b > 9) 
				s[idx] = b - 10 + 'A';
			else	
				s[idx] = b + '0';
			decNum /= 16;
			idx++;
		}
		return idx;
}
//------------------------------------------------------------------------
// Convert 1 hex character to binary.
//
short ToHex(uchar ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 0x37;
	else if ((ch >= 'a') && (ch <= 'f'))   //convert to 
		return ch - 0x57;
		
	else if ((ch >= 'A') && (ch <= 'Z'))
		return ch - 0x41;
	else
		return 0;
}
 

int main()
{
    int decVal=23*32;
    string sval="";
    char arrLastPageHexValue[4];
    uchar arrayTargetPageValue[2];
    int bitsCnt = dec2hexChars(decVal,arrLastPageHexValue);
    arrayTargetPageValue[0] = (ToHex(arrLastPageHexValue[1])<<4)| ToHex(arrLastPageHexValue[0]);   //LOW Address
	arrayTargetPageValue[1] = (ToHex(arrLastPageHexValue[3]) << 4) | ToHex(arrLastPageHexValue[2]);	//High address
    for(int i=0;i<4;i++)
        cout<<i<<"  "<<arrLastPageHexValue[i]<<endl;

    // system("pause");
     cout<<"converted value"<<endl;
    // cout<<"%x"<<arrayTargetPageValue[0]<<"%x"<<arrayTargetPageValue[1]<<endl;
    // printf("%X,%X",arrayTargetPageValue[0],arrayTargetPageValue[1]);
      printf("%d,%X",arrLastPageHexValue[1]<<4,ToHex(arrLastPageHexValue[1])<<4);

}