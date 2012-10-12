#pragma once
#include <cppcms/application.h>
#include <cppcms/base_content.h>
#include <apps/basic_master.h>

namespace data { 
	namespace questions {
		struct master;
	}
}


namespace apps {

	namespace questions {

		class master : public basic_master {
		public:
			master(cppcms::service &s);
			~master();
			
			virtual void init();
			virtual void clear();
			void load_sidebar(data::questions::master &c);
		protected:
			void prepare(data::questions::master &c);
			std::string user_;
		};
	} // blog
} // apps
