#include "parse.hpp"

using namespace std;

namespace argparse {

	int sCount(string str, char chr) {
		return count(str.begin(), str.end(), chr);
	}

	vector<string> split(string splitting, string delimiter) {
		vector<string> splitstring = {};
		
		size_t pos = 0;
		while ( ( pos = splitting.find( delimiter ) ) != string::npos ) {
			splitstring.push_back( splitting.substr( 0, pos ) );
			splitting.erase( 0, pos + delimiter.length() );
		} // ^ from cplusplus.com

		splitstring.push_back( splitting );

		return splitstring;
	}

	vector<string> parseArgs(string arguments) {
		if (arguments == "") {
			return {""};
		} else if ((sCount(arguments, '"') + sCount(arguments, '\'')) % 2) {
			throw std::invalid_argument("Found beginning quote but no end quote!");
		}
		vector<string> parsedargs = {};
		string curarg = "";
		bool multiarg = false;

		for ( auto& arg : split( arguments ) ) {
			if ( 
				!( 
					( 
						arg.find( "\"" ) == (arg.size() - 1) // " at beginning
						||
						arg.find( "\"" ) == 0 // ' at beginning
					)
					|| 
					(
						arg.find( "'" ) == (arg.size() - 1) // ' at end 
						||
						arg.find( "'" ) == 0 // ' at end
					) 
				) 
				&& !( multiarg ) // not in multi-word argument
				)
			{
				// Not in multi-word argument, add to output vector
				parsedargs.push_back( arg );
			} else if ( 
				( 
					arg.find( "\"" ) == (arg.size() - 1) // " at end
					|| 
					arg.find( "'" ) == (arg.size() - 1) // ' at end
				) 
				&& ( multiarg ) // in multi-word argumuent
				) {
				// End multi-word argument, add multi-word argument to vector, with the 
				arg.erase( arg.size() - 1 );
				multiarg = false;
				curarg += " " + arg;
				parsedargs.push_back( curarg );
			} else if ( multiarg ) { 
				// In multi-word argument, add arg to multi-word argument
				curarg += " " + arg;	
			} else { 
				// Begin multi-word argument, set multi-word argument to arg
				multiarg = true;
				curarg = arg.substr( 1, (arg.size() - 1) ); 
			}
		}

		return parsedargs;
	}

}