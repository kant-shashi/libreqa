#pragma once
#include <cppcms/application.h>

namespace data {
	struct basic_master;
}
namespace apps {
	class basic_master : public cppcms::application {
	public:
		basic_master(cppcms::service &s);
		~basic_master();
	protected:
		std::string host_;
		void prepare(data::basic_master &);
	private:
		std::string media_;
		std::string cookie_;
	};
	
	void init_tex_filer(cppcms::json::value const &s);
}

