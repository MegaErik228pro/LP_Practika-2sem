#include "stdafx.h"
#include "Log.h"
#include "Out.h"
#include "Parm.h"
#include "In.h"
#include <iostream>
#include <ctime>
namespace Out
{
	OUT getOut(wchar_t outfile[])
	{
		static std::ofstream stream(outfile);
		stream.seekp(0);
		OUT f;
		f.stream = &stream;
		wcscpy_s(f.outfile, outfile);
		f.stream->is_open();
		if (f.stream->fail())
		{
			throw ERROR_THROW(112);
		}
		return f;
	}
	void WriteIn(OUT out, In::IN in)
	{
		*out.stream << in.text;
	}
	void WriteError(OUT out, Error::ERROR error)
	{
		if (out.stream->fail() == 0)
		{
			*(out.stream) << error.id << " " << error.message << " строка " << error.inext.line << " позиция " << error.inext.col;
			*(out.stream) << std::endl;
		}
	}
	void Close(OUT out)
	{
		out.stream->close();
	}
};