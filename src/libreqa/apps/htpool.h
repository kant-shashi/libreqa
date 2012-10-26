#include <Common/Compat.h>
#include <Common/System.h>

#include <iostream>
#include <fstream>
#include "ThriftBroker/Client.h"
#include "ThriftBroker/gen-cpp/HqlService.h"
#include "ThriftBroker/ThriftHelper.h"
#include "ThriftBroker/SerializedCellsReader.h"

using namespace Hypertable;
using namespace Hypertable::ThriftGen;

pthread_mutex_t ht_mutex;

// These classes suffer from poor design but are coded
// for lack of time. Needs improvement.
// Simple Hypertable dbpool class
typedef struct HtClient {
	Thrift::Client* client;
	bool inUse;
	int id;
	
	HtClient(std::string, int, int);
	~HtClient();
}HtClient;
class HtPool {
	std::vector<HtClient*> clients_;
	int pool_size_;
	std::string host_;
	int port_;
	static HtPool* instance_;
	HtPool(int pool_size, std::string host, int port);
public:
	HtClient* getClientConnection();
	void releaseClientConnection(int id);
	static HtPool* getInstance(int pool_size, std::string host, int port);
};
