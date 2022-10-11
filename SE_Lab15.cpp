#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>

#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "Out.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	//      ���� ERROR
	//std::cout << "---- ���� Error::geterror ----" << std::endl << std::endl;
	//try
	//{
	//	throw ERROR_THROW(100);
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	//};

	//try
	//{
	//	throw ERROR_THROW_IN(111, 7, 7);
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "������ " << e.id << ": " << e.message
	//		<< ", ������ " << e.inext.line
	//		<< ", ������� " << e.inext.col << std::endl << std::endl;
	//};

	////      ���� PARM
	//std::cout << "---- ���� Parm::getparm ----" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	//};

	////      ���� IN 1
	//std::cout << "---- ���� In::getin 1 ----" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm.in);
	//	std::cout << in.text << std::endl;
	//	std::cout << "����� ��������: " << in.size << std::endl;
	//	std::cout << "����� �����: " << in.lines << std::endl;
	//	std::cout << "���������: " << in.ignor << std::endl << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	//};

	////      ���� IN 2
	//std::cout << "---- ���� In::getin 2 ----" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm.in);
	//	std::cout << in.text << std::endl;
	//	std::cout << "����� ��������: " << in.size << std::endl;
	//	std::cout << "����� �����: " << in.lines << std::endl;
	//	std::cout << "���������: " << in.ignor << std::endl << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
	//	std::cout << "������ " << e.inext.line << " ������� " << e.inext.col << std::endl << std::endl;
	//};

	//      ���� LOG
	std::cout << "---- ���� LOG::log  ----" << std::endl << std::endl;
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	Parm::PARM parm = Parm::getparm(argc, argv);
	try
	{
		log = Log::getlog(parm.log);
		out = Out::getOut(parm.out);
		Log::WriteLine(log, (char*)"����:", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����:", (wchar_t*)L" ��� ������ \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Out::WriteIn(out, in);
		Log::Close(log);
		Out::Close(out);
		
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		Out::WriteError(out, e);
	};
	system("pause");
	return 0;
}