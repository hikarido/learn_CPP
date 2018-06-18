//
// Created by hikarido on 6/17/18.
//


#include "boost/log/trivial.hpp"
#include "boost/program_options.hpp"
#include <vector>
using namespace boost::log::trivial;
namespace po = boost::program_options;

int main(int argc, char *argv[])
{
	try{
		po::options_description desc("This prog");
		desc.add_options()
				("help", "Can I to help you")
				("compression", po::value<int>(), "set compression level");

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);

		if (vm.count("compression")) {
			BOOST_LOG_TRIVIAL(info) << "compression arg passed";
			return 1;
		} else if (vm.count("help")) {
			BOOST_LOG_TRIVIAL(info) << desc;
			return 2;
		}

		return 0;

	}
	catch(std::exception &e){
		BOOST_LOG_TRIVIAL(error) << "Error when parse cmb args: " << e.what();
		return -1;
	}
}
