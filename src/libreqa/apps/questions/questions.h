#pragma once
#include <cppcms/application.h>
namespace apps {
	namespace questions {
		class questions_master : public cppcms::application {
		public:
			questions_master(cppcms::service &srv);
		};
	}
}
