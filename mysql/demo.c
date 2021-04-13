/***************************************************************************************
 *   Copyright (C), 2006-2021, Legendsec Technology Co., Ltd.
 *
 *    Filename: demo.c
 * Description:
 *     Version: 1.0
 *     Created: ChaiYD   04/13/2021 07:40:10 PM
 *    Revision: none
 *
 *     History: <author>   <time>    <version >         <desc>
 *              ChaiYD   04/13/2021                  build this moudle
 ***************************************************************************************/
#include "demo.h"

void cyd_mysql_op()
{
	MYSQL mysql;

	mysql_init(&mysql);
	mysql_real_connect(&mysql, "127.0.0.1", "root", "123456",  NULL, 3355, NULL, 0);

	mysql_query(&mysql, "set names 'utf8'");
	mysql_query(&mysql, "drop database if exists tmpdb");
	mysql_query(&mysql, "create database tmpdb");
	mysql_query(&mysql, "use tmpdb");
	mysql_query(&mysql, "create table tmptab(c1 int, c2 varchar(20), c3 varchar(20))");
	mysql_query(&mysql,
				"insert into tmptab values(101, '姓名1', 'address1'), (102, '姓名2', 'address2'), (103, '姓名3', 'address3')");
	mysql_query(&mysql, "select * from tmptab");
	printf("--增加数据测试--\n");
	cyd_mysql_print(&mysql);
	mysql_query(&mysql, "delete from tmptab where c1 = 101");
	mysql_query(&mysql, "select * from tmptab");
	printf("--删除数据测试--\n");
	cyd_mysql_print(&mysql);
	mysql_query(&mysql, "update tmptab set c3 = 'address4' where c1 = 103");
	mysql_query(&mysql, "select * from tmptab");
	printf("--更新数据测试--\n");
	cyd_mysql_print(&mysql);
	mysql_query(&mysql, "delete from tmptab");
	mysql_query(&mysql, "select * from tmptab");
	printf("--清空数据测试--\n");
	cyd_mysql_print(&mysql);
	mysql_query(&mysql, "drop table tmptab");
	mysql_query(&mysql, "drop database tmpdb");
	mysql_close(&mysql);

	return;
}
void cyd_mysql_print(MYSQL *mysqlPrint)
{
	MYSQL_RES *result;
	int numFields = 0;
	int numRows = 0;
	MYSQL_FIELD *field;
	MYSQL_ROW row;
	int i = 0;
	result = mysql_store_result(mysqlPrint);//将查询的全部结果读取到客户端
	numFields = mysql_num_fields(result);//统计结果集中的字段数
	numRows = mysql_num_rows(result);//统计结果集的行数
	while (field = mysql_fetch_field(result)) { //返回结果集中的列信息(字段)
		printf("%s\t", field->name);
	}
	printf("\n");
	if (result) {
		while (row = mysql_fetch_row(result)) { //返回结果集中行的记录
			for (i = 0; i < numFields; i++) {
				printf("%s\t", row[i]);
			}
			printf("\n");
		}
	}
	mysql_free_result(result);//释放result空间，避免内存泄漏
	return;
}
