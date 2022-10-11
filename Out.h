#pragma once
#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"
namespace Out     // Работа с протоколом
{
	struct OUT	  // протокол
	{
		wchar_t outfile[PARM_MAX_SIZE]; // имя файла протокола
		std::ofstream* stream;			// выходной поток протокола
	};
	static const OUT INITOUT = { L"",NULL }; // структура для начальной инициализации OUT
	OUT getOut(wchar_t Outfile[]);			 // сформировать структуру OUT
	void WriteIn(OUT out, In::IN in);        // вывести в протокол информацию о входном потоке
	void WriteError(OUT out, Error::ERROR error); // вывести в протокол информацию об ошибке
	void Close(OUT out);
};