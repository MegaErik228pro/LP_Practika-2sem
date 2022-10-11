#include "stdafx.h"
#include "Parm.h"
#include "Error.h"
namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		bool bin = 0, bout = 0, blog = 0;
		PARM f;
		for (int l = 0; l < argc; l++)
		{
			if (wcsstr(argv[l], PARM_IN))
			{
				bin = 1;
			}
			if (wcsstr(argv[l], PARM_OUT))
			{
				bout = 1;
			}
			if (wcsstr(argv[l], PARM_LOG))
			{
				blog = 1;
			}
		}
		if (bin == 0)
		{
			throw ERROR_THROW(100)
		}
		for (int i = 0; i < argc; i++)
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);
			if (wcsstr(argv[i], PARM_IN))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.in, h);
			}
			if (wcsstr(argv[i], PARM_OUT))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.out, h);
			}
			if (wcsstr(argv[i], PARM_LOG))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.log, h);
			}
		}
		if (bout == 0)
		{
			wcscpy_s(f.out, f.in);
			wcscat_s(f.out, PARM_OUT_DEFAULT_EXT);
		}
		if (blog == 0)
		{
			wcscpy_s(f.log, f.in);
			wcscat_s(f.log, PARM_LOG_DEFAULT_EXT);
		}
		return f;
	}
};