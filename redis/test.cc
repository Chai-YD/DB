#include "demo.h"

using namespace std;

int demo_1(void)
{
	redisContext *ctx = redisConnect("127.0.0.1", 6379);
	if (ctx == NULL || ctx->err) {
		if (ctx) {
			cout << "redisConnect failed: " << ctx->errstr <<endl;
		}
		else {
			cout << "redisConnect failed: can't alloc redis context" << endl;
		}
	}

	/* 清理连接资源并释放连接 */
	redisFree(ctx);
	return 0;
}

void demo_2()
{
	int ret = -1;
	redis re("172.24.142.198", 6379);

	ret = re.hset("htest", "test_k", "test_v");
	if (ret != 1) {
		cout << "hset failed" <<endl; 
	}
	ret = re.hset("htest", "test_k1", "test_v", 4);
	if (ret != 1) {
		cout << "hset failed" <<endl; 
	}
	ret = re.existsKey("htest");
	if (ret != 1) {
		cout << "existsKey failed" <<endl; 
	}
	ret = re.del("htest");
	if (ret != 1) {
		cout << "del failed" <<endl; 
	}

	return;
}

int main(int argc, char *argv[])
{
	demo_2();
	return 0;
}
