#ifndef LOGO_HEADER
#define LOGO_HEADER


#include <string>


// -- N A M E S P A C E  I R C ------------------------------------------------

namespace irc {


	class logo {

		private:

			/* init logo */
			static std::string init_logo(void);

			static const std::string _logo;

		public:

			static const std::string& get(void);


	};


}


#endif
