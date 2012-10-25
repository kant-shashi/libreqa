#include <apps/htpool.h>

static HtPool* HtPool::instance_ = NULL;

static HtPool* HtPool::getInstance(pool_size, std::string host, int port)
{
	if(!instance_)
	{
		instance_ = new HtPool(pool_size, host, port);
		return instance_;
	}
	retrun instance_;
}

HtPool::HtPool(int pool_size, std::string host, int port)
	:pool_size_(pool_size),host_(host),port_(port)
{
	for(int i=0; i<pool_size_; i++)
	{
		HtClient* ht = new HtClient(host_, port_, i);
		
		clients.push_back(ht);
	}
	pthread_mutex_init(&ht_mutex, NULL);
}

HtClient* HtPool::getClientConnection()
{
	pthread_mutex_lock(&ht_mutex);
	for(int i=0; i<pool_size; i++)
	{
		if(clients[i].inUse == false)
		{
			clients[i].inUse = true;
			pthread_mutex_unlock(&ht_mutex);
			return clients[i];
		}
	}
	
	HtClient* ht = new HtClient(host, port, clients.size()+1);
	
	clients.push_back(ht);
	pthread_mutex_unlock(&ht_mutex);
	return ht;
}

void HtPool::releaseClientConnection(int id)
{
	pthread_mutex_lock(&ht_mutex);
	if(id >= 10)
	{
		delete clients[id];
	}
	else
	{
		clients[id].inUse = false;
	}
	pthread_mutex_unlock(&ht_mutex);
}


HtClient::HtClient(std::string host, int port, int id)
{
	client = new Thrift::client(host, port);
	inUse = false;
	id = id;
}

HT::~HtClient()
{
	delete client;
}