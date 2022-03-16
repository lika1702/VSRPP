
// SnopokLR_5_2Set.h: интерфейс класса CSnopokLR_5_2Set
//


#pragma once

// создаваемый код 30 октября 2021 г., 0:59

class CSnopokLR_5_2SetAccessor
{
public:
	LONG m_index;
	TCHAR m_login[256];
	TCHAR m_password[256];
	LONG m_day;
	LONG m_month;
	LONG m_year;
	LONG m_hour;
	LONG m_minute;
	LONG m_duration;

	// Следующие создаваемые мастером члены данных содержат значения 
	// состояния для соответствующих полей в сопоставлении столбцов. 
	// Эти значение можно использовать для сохранения значений NULL, возвращаемых
	// базой данных, или для сохранения сведений об ошибках, когда компилятор 
	// возвращает ошибки. См. описание членов данных состояния полей в создаваемых 
	// мастером методах доступа в документации Visual C++ 
	// и сведения об использовании полей.
	// Примечание. Перед заданием или вставкой данных эти поля необходимо инициализировать!

	DBSTATUS m_dwcolumn0Status;
	DBSTATUS m_dwcolumn1Status;
	DBSTATUS m_dwcolumn2Status;
	DBSTATUS m_dwcolumn3Status;
	DBSTATUS m_dwcolumn4Status;
	DBSTATUS m_dwcolumn5Status;
	DBSTATUS m_dwcolumn6Status;
	DBSTATUS m_dwcolumn7Status;
	DBSTATUS m_dwcolumn8Status;

	// Следующие создаваемые мастером члены данных содержат значения 
	// длины для соответствующих полей в сопоставлении столбцов. 
	// Примечание. Для столбцов с переменной длиной значений необходимо
	//      инициализировать эти поля перед заданием или вставкой данных!

	DBLENGTH m_dwcolumn0Length;
	DBLENGTH m_dwcolumn1Length;
	DBLENGTH m_dwcolumn2Length;
	DBLENGTH m_dwcolumn3Length;
	DBLENGTH m_dwcolumn4Length;
	DBLENGTH m_dwcolumn5Length;
	DBLENGTH m_dwcolumn6Length;
	DBLENGTH m_dwcolumn7Length;
	DBLENGTH m_dwcolumn8Length;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_IRowsetChange, true);
		pPropSet->AddProperty(DBPROP_IRowsetScroll, true);
		pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);

	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error Проблема безопасности: строка подключения может содержать пароль 
// Следующая строка подключения может содержать незашифрованные пароли или 
// другую конфиденциальную информацию. Удалите #error после просмотра строки подключения 
// в целях безопасности. Возможно, 
// потребуется сохранить пароль в другом виде или использовать другую аутентификацию.
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Mode=ReadWrite;Extended Properties=\"DSN=MS Access Database;DBQ=D:\\\x0412\x0421\x0420\x041f\x041f\\DB_for_4.accdb;DefaultDir=D:\\\x0412\x0421\x0420\x041f\x041f;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;\"");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	BEGIN_COLUMN_MAP(CSnopokLR_5_2SetAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_index, m_dwcolumn0Length, m_dwcolumn0Status)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_login, m_dwcolumn1Length, m_dwcolumn1Status)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_password, m_dwcolumn2Length, m_dwcolumn2Status)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_day, m_dwcolumn3Length, m_dwcolumn3Status)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_month, m_dwcolumn4Length, m_dwcolumn4Status)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_year, m_dwcolumn5Length, m_dwcolumn5Status)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_hour, m_dwcolumn6Length, m_dwcolumn6Status)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_minute, m_dwcolumn7Length, m_dwcolumn7Status)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_duration, m_dwcolumn8Length, m_dwcolumn8Status)
	END_COLUMN_MAP()
};

class CSnopokLR_5_2Set : public CCommand<CAccessor<CSnopokLR_5_2SetAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT ReOpen(CString where_str = L"", CString order_str = L"")
	{
		CDBPropSet propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetLocate, true);
		GetRowsetProperties(&propset);
		CString select_str;
		if (where_str.IsEmpty())
			select_str.Format(L"select * from [User] order by %s", order_str);
		else
			select_str.Format(L"select * from [User] where %s order by %s", where_str, order_str);
		Close();
		HRESULT hr = Open(m_session, select_str, &propset);
#ifdef _DEBUG
		if (FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}


	HRESULT AddRecord(TCHAR* login, TCHAR* password, LONG day, LONG month, LONG year, LONG hour, LONG minute, LONG duration) {
		CDBPropSet propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetLocate, true);
		GetRowsetProperties(&propset);
		CString execute_str;
		execute_str.Format(
			L"INSERT INTO [User] ([Логин], [Пароль], [День], [Месяц], [Год], [Часы], [Минуты], [Длительность сессии]) VALUES ('%s', '%s', '%d', '%d', '%d', '%d', '%d', '%d')",
			login, password, day, month, year, hour, minute, duration);
		Close();
		HRESULT hr = Open(m_session, execute_str, &propset, 0, DBGUID_DEFAULT, false);
		Close();
		hr = Open(m_session, L"select * from [User] order by [Код]", &propset);
#ifdef _DEBUG
		if (FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	HRESULT EditRecord(CString str) {
		CDBPropSet propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetLocate, true);
		GetRowsetProperties(&propset);
		Close();
		HRESULT hr = Open(m_session, str, &propset, 0, DBGUID_DEFAULT, false);
		Close();
		hr = Open(m_session, L"select * from [User]  order by [Код]", &propset);
#ifdef _DEBUG
		if (FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, L"select * from [User]  order by [Код]", pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		CloseDataSource();
	}
};

