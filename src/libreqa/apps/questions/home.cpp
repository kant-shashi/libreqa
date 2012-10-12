#include <apps/questions/home.h>
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/cache_interface.h>
#include <data/questions/home.h>


namespace apps {
	namespace home {
		home_master::home_master(cppcms::service &s) : cppcms::application(s) {
			dispatcher().assign("",&home_master::all,this);
			mapper().assign("");
		}
		void home_master::all() {
 			data::questions::home c;
			render("green", "home", c);
			//prepare(id,true);
		}
	} // questions
} // apps
