#ifndef PARSER_HEADER
#define PARSER_HEADER

#include "lexer.hpp"
#include "msg.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {



    class parser {

        public:

			// -- public static methods ---------------------------------------

			/* parse */
            static irc::msg parse(const std::string&);


        private:

			// -- private constructors ----------------------------------------

			/* default constructor */
            parser(void);

			/* copy constructor */
			parser(const parser&);

			/* destructor */
			~parser(void);

    };
}

#endif
