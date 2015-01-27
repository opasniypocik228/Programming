//
//  main.cpp
//  Laba 5
//
//  Created by Nikita Barsukov on 28.12.14.
//  Copyright (c) 2014 Nikita Barsukov. All rights reserved.
//

/* ¬Ó ‚ıÓ‰ÌÓÏ ÚÂÍÒÚÓ‚ÓÏ Ù‡ÈÎÂ Ì‡ÈÚË Ò‡ÏÓÂ ‰ÎËÌÌÓÂ ÒÎÓ‚Ó Ë Ò‡ÏÓÂ ‰ÎËÌÌÓÂ ÔÂ‰ÎÓÊÂÌËÂ Ë ‚˚‚ÂÒÚË Ëı ‚ ‚˚ıÓ‰ÌÓÈ Ù‡ÈÎ. —ÎÓ‚ÓÏ Ò˜ËÚ‡Ú¸ Î˛·Û˛ ÔÓÒÎÂ‰Ó‚‡ÚÂÎ¸ÌÓÒÚ¸ ËÁ ·ÛÍ‚, ˆËÙ Ë ÒËÏ‚ÓÎÓ‚ -. œÂ‰ÎÓÊÂÌËÂÏ Ò˜ËÚ‡Ú¸ Î˛·Û˛ ÔÓÒÎÂ‰Ó‚‡ÚÂÎ¸ÌÓÒÚ¸ ÒËÏ‚ÓÎÓ‚ ÏÂÊ‰Û ÒÓÒÂ‰ÌËÏË ÒËÏ‚ÓÎ‡ÏË . ! ?
¬ıÓ‰ÌÓÈ Ë ‚˚ıÓ‰ÌÓÈ Ù‡ÈÎ Á‡‰‡‚‡Ú¸ Í‡Í ‡„ÛÏÂÌÚ˚ ÍÓÏ‡Ì‰ÌÓÈ ÒÚÓÍË. ¬ ÒÎÛ˜‡Â ÓÚÒÛÚÒÚ‚Ëˇ ‡„ÛÏÂÌÚÓ‚ ÍÓÏ‡Ì‰ÌÓÈ ÒÚÓÍË Ò˜ËÚ‡Ú¸, ˜ÚÓ Ëı ËÏÂÌ‡ ÒÓÓÚ‚ÂÚÒÚ‚ÂÌÌÓ in.txt Ë out.txt. */






#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <fstream>
#include <windows.h> 
using namespace std;
int razm();
void write(char *a, int count, int maxcount);
 
int main()
{	
	setlocale(LC_ALL, "Russian");
	ifstream in("in.txt");
	FILE * ptrFile = fopen("in.txt", "r");
	int s;
	s = razm();
	int count=0;
	int maxcount=0;
	int write1 = 0;
	

	
	char *text = new char(s);cout << s;
	fgets(text, 1024, ptrFile);

	fclose(ptrFile);
	
	 for (int i = 0; i < s; i++)
	{	
		count++;
		

		if (maxcount < count)
		{
			maxcount = count;

			write1 = i;
		}

		if (text[i] == ' ')
		{	
			count = 0;
		}
	}
	
	
	int ot=(write1-maxcount)+1;
	int qw = write1+1;
	
	write(text,ot,qw);
///////////////////////////////////œÂ‰ÎÓÊÂÌËÂ/////////////////////////////////////////
	 count = 0;
	 maxcount = 0;
	 write1 = 0;
	 ot = 0;
	 qw = 0;

	
	for (int i = 0; i < s; i++)
	{
		count++;
		if (maxcount < count)
		{
			write1 = i;
			maxcount = count;
		}
		if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			count = 0;
		}

	}

	cout << maxcount << endl << write1 << endl;

	ot = (write1 - maxcount) + 1;
    qw = write1 + 1;


	write(text, ot, qw);
	

	
	cout << "job done";
	system("pause");



}


int razm()
{
	ifstream in("in.txt");
	char szPeremen;
	unsigned int nN = 0;
	while ((szPeremen = in.get()) != EOF){
		nN++;
	}
		return nN;
}

void write(char *a, int count, int maxcount)
{
	ofstream out("out2.txt", ios::app);
	

	for (int i = count; i < maxcount; ++i)
	{
		//cout << a[i];
		out << a[i];
	}
	
}
