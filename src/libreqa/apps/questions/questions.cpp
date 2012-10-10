#include <apps/questions/questions.h>
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/cache_interface.h>
//#include <apps/blog/page.h>
//#include <apps/blog/post.h>
//#include <apps/blog/summary.h>

namespace apps {
	namespace questions {
		questions_master::questions_master(cppcms::service &s) : cppcms::application(s) {
		/*	attach(	new page(s),
				"page",
				"/page{1}",
				"/page((/.*)?)",1);

			attach(	new post(s),
				"post",
				"/post{1}",
				"/post((/.*)?)",1);

			attach(	new summary(s),
				"summary",
				"{1}",
				".*",0);*/
			dispatcher().assign("",&all,this);
			mapper().assign("");
		}
		questions_master::all() {
				if(user_.empty()) {
				response().make_error_response(cppcms::http::response::forbidden);
				return;
			}
			//prepare(id,true);
		}
	} // questions
} // apps
