#pragma once

// A small wrapper class for sqlite3 specifically for the kik bot . Will make future kik bot projects easier.

#include "Global.h"
#include <sqlite3.h>

#ifndef SQLITE3CPP_H
#define SQLITE3CPP_H

class Sqlite3CPP
{
public:
	Sqlite3CPP();
	~Sqlite3CPP();
	bool Open(const std::string & Filename);
	bool Query(const std::string & Query);
	bool Step();
	void PrintLastError() const;
	std::string GetColumnText(int x) const;
	

private:
	bool m_IsOpen;
	sqlite3 * m_db;
	sqlite3_stmt * m_statement;
	std::string m_ErrorMessage;
	int m_ErrorCode;

};

#endif

