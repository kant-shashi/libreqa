#include <apps/htpool.h>

HtPool* HtPool::instance_ = NULL;

HtPool* HtPool::getInstance(int pool_size, std::string host, int port)
{
	if(!instance_)
	{
		instance_ = new HtPool(pool_size, host, port);
		return instance_;
	}
	return instance_;
}

HtPool::HtPool(int pool_size, std::string host, int port)
	:pool_size_(pool_size),host_(host),port_(port)
{
	for(int i=0; i<pool_size_; i++)
	{
		HtClient* ht = new HtClient(host_, port_, i);
		
		clients_.push_back(ht);
	}
	pthread_mutex_init(&ht_mutex, NULL);
}

HtClient* HtPool::getClientConnection()
{
	pthread_mutex_lock(&ht_mutex);
	for(int i=0; i<pool_size_; i++)
	{
		if(clients_[i]->inUse == false)
		{
			clients_[i]->inUse = true;
			pthread_mutex_unlock(&ht_mutex);
			return clients_[i];
		}
	}
	
	HtClient* ht = new HtClient(host_, port_, clients_.size()+1);
	
	clients_.push_back(ht);
	pthread_mutex_unlock(&ht_mutex);
	return ht;
}

void HtPool::releaseClientConnection(int id)
{
	pthread_mutex_lock(&ht_mutex);
	if(id >= 10)
	{
		delete clients_[id];
	}
	else
	{
		clients_[id]->inUse = false;
	}
	pthread_mutex_unlock(&ht_mutex);
}


HtClient::HtClient(std::string host, int port, int id)
{
	Thrift::Client* client = new Thrift::Client(host, port);
	this->inUse = false;
	this->id = id;
}

HtClient::~HtClient()
{
	delete client;
}
