#pragma once
#include <cppcms/application.h>
#include <apps/questions/master.h>
#include <cppcms/http_response.h>
namespace apps {
	namespace questions {
		class questions_master : public cppcms::application {
		public:
			questions_master(cppcms::service &srv);
			void all();
		};
	}
}
