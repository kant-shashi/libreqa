#pragma once
#include <cppcms/application.h>
#include <apps/questions/master.h>
#include <cppcms/http_response.h>
#include <data/questions/master.h>
namespace apps {
	namespace home {
		class home_master : public cppcms::application {
		public:
			home_master(cppcms::service &srv);
			void all();
		};
	}
}
