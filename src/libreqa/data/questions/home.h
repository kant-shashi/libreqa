#pragma once

namespace data {
namespace questions {
	struct home : public master {
		std::string category_name;
		int id;
		int prev_page;
		int page;
		int next_page;

		home() : 
			id(0) ,
			prev_page(0),
			next_page(0)
		{
		}
	};

}
}
