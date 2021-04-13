#include <iostream>
#include <hiredis/hiredis.h>
#include <cstring>

using namespace std;

class redis
{
public:
	redis(const char *ip = "127.0.0.1", int port = 6379)
	{
		ctx = redisConnect(ip, port);
		if (ctx == NULL || ctx->err) {
			if (ctx) {
				cout << "redisConnect failed: " << ctx->errstr << endl;
			}
			else {
				cout << "redisConnect failed: can't alloc redis context" << endl;
			}
		} // end if

		return;
	}

	~redis()
	{
		if (ctx) {
			redisFree(ctx);
			ctx = NULL;
		}

		return;
	}

public:
	string hget(const char *key, const char *hkey);
	int hset(const char *key, const char *hkey, const char *hvalue);
	int hset(const char *key, const char *hkey, const char *hvalue, size_t hvaluelen);

	int del(const char *key);
	int existsKey(const char *key);
public:
	redisContext *ctx;
};
