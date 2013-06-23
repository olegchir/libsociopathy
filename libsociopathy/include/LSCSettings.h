#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;
namespace BoostProgramOptions = boost::program_options;

class LSCSettings
{
public:
    static void writeSettings( std::string value );
    static void readSettings( BoostProgramOptions::options_description& desc, BoostProgramOptions::variables_map& vm );
    static string getSettingsFilePath();
};
