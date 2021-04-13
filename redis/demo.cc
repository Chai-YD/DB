#include "demo.h"

string redis::hget(const char *key, const char *hkey)
{
	const char *argv[3];
	size_t argvlen[3];

	argv[0] = "HSET";
	argv[1] = key;
	argv[2] = hkey;

	argvlen[0] = 4;
	argvlen[1] = strlen(key);
	argvlen[2] = strlen(hkey);

	redisReply *reply = (redisReply *)redisCommandArgv(ctx, 3, argv, argvlen);
	string str;
	if (reply->type != REDIS_REPLY_NIL) {
		str = string(reply->str, reply->str + reply->len);
	}

	freeReplyObject(reply);

	return str;
}

int redis::hset(const char *key, const char *hkey, const char *hvalue)
{
	redisReply *reply = (redisReply *)redisCommand(ctx, "HSET %s %s %s", key, hkey, hvalue);
	freeReplyObject(reply);
	return 1;
}

int redis::hset(const char *key, const char *hkey, const char *hvalue, size_t hvaluelen)
{
	const char *argv[4];
	size_t argvlen[4];

	argv[0] = "HSET";
	argv[1] = key;
	argv[2] = hkey;
	argv[4] = hvalue;

	argvlen[0] = 4;
	argvlen[1] = strlen(key);
	argvlen[2] = strlen(hkey);
	argvlen[3] = hvaluelen;

	redisReply *reply = (redisReply *)redisCommandArgv(ctx, 4, argv, argvlen);

	freeReplyObject(reply);

	return 1;
}

int redis::del(const char *key)
{
	int ret = 0;

	redisReply * reply = (redisReply *)redisCommand(ctx, "HDEL %s", key);
	if (reply->type == REDIS_REPLY_INTEGER) {
		if (reply->integer == 1L) {
			ret = 1;
		}
	}

	return ret;
}

int redis::existsKey(const char *key)
{
	int ret = 0;

	redisReply * reply = (redisReply *)redisCommand(ctx, "EXISTS %s", key);
	if (reply->type == REDIS_REPLY_INTEGER) {
		if (reply->integer == 1L) {
			ret = 1;
		}
	}

	return ret;
}
