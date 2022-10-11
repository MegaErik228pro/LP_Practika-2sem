#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <iostream>
#include <fstream>
namespace In
{
	IN getin(wchar_t infile[])
	{
		IN f;
		unsigned char ch;
		static unsigned char l[1024] = "";
		int line = 1, position = 1, size = 0, ignor = 0, i = 0;
		std::ifstream in(infile);
		if (in.fail() == 0)
		{
			ch = in.get();
			while (!in.eof())
			{
				if (ch == ((unsigned char)'\n'))
				{
					line++;
					position = 0;
				}
				if (f.code[(int)ch] == IN::T)
				{
					position++;
					l[i] = ch;
					i++;
				}
				else if (f.code[(int)ch] == IN::F)
				{
					throw ERROR_THROW_IN(111, line, position);
				}
				else if (f.code[(int)ch] == IN::I)
				{
					ignor++;
				}
				else
				{
					l[i] = f.code[ch];
					i++;
				}
				ch = in.get();
			}
			in.close();
			f.size = i;
			f.text = l;
			f.lines = line;
			f.ignor = ignor;

		}
		else
		{
			throw ERROR_THROW(110);
		}
		return f;
	}
};