#include "stdafx.h"
#include "Log.h"
#include "Parm.h"
#include "In.h"
#include <iostream>
#include <ctime>
namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		static std::ofstream stream(logfile);
		stream.seekp(0);
		LOG f;
		f.stream = &stream;
		wcscpy_s(f.logfile, logfile);
		f.stream->is_open();
		if (f.stream->fail())
		{
			throw ERROR_THROW(112);
		}
		return f;
	}
	void WriteLine(LOG log, char* c, ...)
	{
		log.stream->is_open();
		char** f;
		f = &c;
		char l[256] = "";
		while (*f != "")
		{
			strcat_s(l, *f);
			f = f + 1;
		}
		*(log.stream) << l;
	}
	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t** p = &c;
		char answ[100] = "", buf[100] = "";
		while (*p != L"")
		{
			wcstombs_s(0, buf, *p, 100);
			strcat_s(answ, buf);
			*(p)++;
		}
		*(log.stream) << answ;
	}
	void WriteLog(LOG log)
	{
		time_t rawtime;
		char buffer[80];
		time(&rawtime);
		struct tm timeinfo;
		localtime_s(&timeinfo, &rawtime);
		strftime(buffer, 80, "%d.%m.%Y %H:%M:%S", &timeinfo);
		if (log.stream->fail() == 0)
		{
			log.stream->write("---Протокол--- ", sizeof("---Протокол--- "));
			*(log.stream) << buffer << "----------" << std::endl;
		}
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		if (log.stream->fail() == 0)
		{
			char m[512] = "";
			log.stream->write("---Параметры---", sizeof("---Параметры---"));
			(*log.stream) << std::endl;
			wcstombs_s(0, m, parm.in, sizeof(parm.in));
			*(log.stream) << "-in: " << m << std::endl;
			wcstombs_s(0, m, parm.out, sizeof(parm.out));
			*(log.stream) << "-out: " << m << std::endl;
			wcstombs_s(0, m, parm.log, sizeof(parm.log));
			*(log.stream) << "-log: " << m << std::endl;
		}
		else
		{
			std::cout << "in: " << parm.in << std::endl;
			std::cout << "out:" << parm.out << std::endl;
			std::cout << "log: " << parm.log << std::endl;
		}
	}
	void WriteIn(LOG log, In::IN in)
	{
		if (log.stream->fail() == 0)
		{
			log.stream->write("---Исходные данные---", sizeof("---Исходные данные---"));
			(*log.stream) << std::endl;
			log.stream->write("Количество символов:", sizeof("Количество символов:"));
			*(log.stream) << in.size << std::endl;
			log.stream->write("Проигнорировано: ", sizeof("Проигнорировано: "));
			*(log.stream) << in.ignor << std::endl;
			log.stream->write("Количество строк: ", sizeof("Количество строк: "));
			*(log.stream) << in.lines << std::endl;
		}
		else
		{
			std::cout << "Количество символов: " << in.size << std::endl;
			std::cout << "Проигнорировано:" << in.ignor << std::endl;
			std::cout << "Количество строк: " << in.lines << std::endl;
		}
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		if (log.stream->fail() == 0)
		{
			*(log.stream) << error.id << " " << error.message << " строка " << error.inext.line << " позиция " << error.inext.col;
			*(log.stream) << std::endl;
		}
		else
		{
			std::cout << error.id << " " << error.message << " " << "строка" << error.inext.line << " позиция" << error.inext.col << std::endl;
		}
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
};