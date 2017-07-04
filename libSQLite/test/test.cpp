#include <stdio.h> 
#include <LibSQLite.h>

//static int callback(void *NotUsed, int argc, char **argv, char **azColName)
//{ 
//	int i; for(i=0; i<argc; i++)
//	{ 
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
//	} 
//	printf("\n"); 
//	return 0; 
//}

int main(int argc, char **argv)
{ 
	/*sqlite3 *db; 
	char *zErrMsg = 0; 
	int rc; 

	if( argc!=3 )
	{
		fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
		return(1);
	}
	rc = sqlite3_open(argv[1], &db); 
	if( rc )
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db)); 
		sqlite3_close(db);
		return(1); 
	} 
	rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg); 
	if( rc!=SQLITE_OK )
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} 
	sqlite3_close(db); 
	return 0;*/
	LibSQLite sql = LibSQLite();
	sql.sqlite_open(L"MyDataBase.db");
	/*sql.query_return_no_data(L"CREATE TABLE table1 (name TEXT, date INT);");
	sql.query_return_no_data(L"INSERT INTO table1 VALUES('jaewoong', 0704);");
	sql.query_return_no_data(L"INSERT INTO table1 VALUES('jiyong', 0705);");*/
	list<list<wstring>> retval = sql.query_return_data(L"SELECT * FROM table1;");
	sql.sqlite_close();
	
	/*for(list<wstring>::iterator iter = retval.begin();iter!=retval.end();iter++)
	{
		cout<<*iter<<endl;
	}*/
	return 0;
}