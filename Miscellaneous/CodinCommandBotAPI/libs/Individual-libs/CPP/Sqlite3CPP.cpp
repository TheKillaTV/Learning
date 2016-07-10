#include "Sqlite3CPP.h"

Sqlite3CPP::Sqlite3CPP() : m_ErrorCode(0), m_IsOpen(false)
{

}

Sqlite3CPP::~Sqlite3CPP()
{
	if (m_IsOpen)
	{
		sqlite3_finalize(m_statement);
		sqlite3_close(m_db);
		m_IsOpen = false;
	}
}

bool Sqlite3CPP::Open(const std::string & Filename)
{
	if (!m_IsOpen)
	{
		if (sqlite3_open(Filename.c_str(), &m_db) == SQLITE_OK)
		{
			m_IsOpen = true;
			return true;
		}

		else
		{
			m_ErrorMessage = sqlite3_errmsg(m_db);
			m_ErrorCode = sqlite3_errcode(m_db);
			sqlite3_close(m_db);
			return false;
		}
	}

	else
	{
		std::cout << "Call to  bool Sqlite3CPP::Open(const std::string & Filename) failed. Reason: Database is already open!" << std::endl;
		return false;
	}
}

void Sqlite3CPP::PrintLastError() const
{
	std::cout << "Sqlite3 Error Code: " << m_ErrorCode << std::endl;
	std::cout << "Sqlite3 Error Message: " << m_ErrorMessage << std::endl;
}

bool Sqlite3CPP::Query(const std::string & Query)
{
	if (m_IsOpen)
	{
		if (sqlite3_prepare_v2(m_db, Query.c_str(), -1, &m_statement, NULL) == SQLITE_OK)
		{
			return true;
		}

		else
		{
			m_ErrorMessage = sqlite3_errmsg(m_db);
			m_ErrorCode = sqlite3_errcode(m_db);
		}
	}

	else
	{
		std::cout << "Call to bool Sqlite3CPP::Query(const std::string & Query) failed, Reason: Database isn't open!" << std::endl;
	}

	return false;
}

bool Sqlite3CPP::Step()
{
	if (m_IsOpen)
	{
		if (sqlite3_step(m_statement) == SQLITE_ROW)
		{
			return true;
		}

		else
		{
			m_ErrorMessage = sqlite3_errmsg(m_db);
			m_ErrorCode = sqlite3_errcode(m_db);
		}
	}

	else
	{
		std::cout << "Call to bool Sqlite3CPP::Step() failed. Reason: Database isn't open!" << std::endl;
	}

	return false;
}

// standard kik. May have to edit this function for a modded kik
// x = 18 for message body.
// x = 16 for isuser
std::string Sqlite3CPP::GetColumnText(int x) const
{
	if (m_IsOpen)
	{
		// An extremly hackish way to get the first column. Will improve this.
		return (const char*)(sqlite3_column_text(m_statement, (sqlite3_column_count(m_statement) - sqlite3_column_count(m_statement)) + x));
	}

	else
	{
		return "NULL";
	}
}
