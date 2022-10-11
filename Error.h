﻿#pragma once
#define ERROR_THROW(id) Error::geterror(id);                 // throw ERROR_THROW(id)
#define ERROR_THROW_IN(id,l,c) Error::geterrorin(id,l,c);    // throw ERROR_THROW(id, строка, колонка)
#define ERROR_ENTRY(id,m) {id,m,{-1,-1}}                     // элемент таблицы ошибок
#define ERROR_MAXSIZE_MESSAGE 200                            // максимальная длина сообщения о ошибке
#define ERROR_ENTRY_NODEF(id) ERROR_ENTRY(-id,"Неопределённая ошибка") // 1 неопредлённый элемент таблицы ошибок
#define ERROR_ENTRY_NODEF10(id) ERROR_ENTRY_NODEF(id+0),ERROR_ENTRY_NODEF(id+1),ERROR_ENTRY_NODEF(id+2),\
								ERROR_ENTRY_NODEF(id+3),ERROR_ENTRY_NODEF(id+4),ERROR_ENTRY_NODEF(id+5),\
								ERROR_ENTRY_NODEF(id+6),ERROR_ENTRY_NODEF(id+7),ERROR_ENTRY_NODEF(id+8),ERROR_ENTRY_NODEF(id+9)
#define ERROR_ENTRY_NODEF100(id) ERROR_ENTRY_NODEF10(id+0),ERROR_ENTRY_NODEF10(id+10),ERROR_ENTRY_NODEF10(id+20),ERROR_ENTRY_NODEF10(id+30), \
								 ERROR_ENTRY_NODEF10(id+40),ERROR_ENTRY_NODEF10(id+50),ERROR_ENTRY_NODEF10(id+60),ERROR_ENTRY_NODEF10(id+70), \
								 ERROR_ENTRY_NODEF10(id+80),ERROR_ENTRY_NODEF10(id+90)
#define ERROR_MAX_ENTRY 1000                                  // количество элементов в таблице ошибок
namespace Error
{
	struct ERROR
	{
		int id;									// код ошибки
		char message[ERROR_MAXSIZE_MESSAGE];	// сообщение о ошибке
		struct IN								// расширение для ошибок при входных данных
		{
			short line;							// номер строки
			short col;							// номер позиции в строке
		} inext;
	};
	ERROR geterror(int id);
	ERROR geterrorin(int id, int line, int col);
};