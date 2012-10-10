#include <apps/captcha.h>
//#include <apps/config.h>
#include <apps/questions/questions.h>
//#include <apps/feed/feed.h>
//#include <apps/admin/admin.h>*/

#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppcms/application.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>

#include <iostream>


class libreqa : public cppcms::application{
public:
	libreqa(cppcms::service &s) : cppcms::application(s)
	{
		attach( new apps::captcha(s),
			"captcha",
			"/captcha{1}",
			"/captcha((/?.*))",1);
		
		attach( new apps::libreqa::libreqa_master(s),
			"questions",
			"{1}",
			"((/.*)?)",1);

		mapper().root(settings().get<std::string>("libreqa.root"));
	}
	virtual void main(std::string path)
	{
		cppcms::application::main(path);
	}
};


int main(int argc,char **argv)
{
	try {
		cppcms::service srv(argc,argv);
		srv.applications_pool().mount(cppcms::applications_factory<libreqa>());
		srv.run();
	}
	catch(std::exception const &e) {
		std::cerr << "Failed: " << e.what() << std::endl;
		std::cerr << booster::trace(e) << std::endl;
		return 1;
	}
	return 0;
}
