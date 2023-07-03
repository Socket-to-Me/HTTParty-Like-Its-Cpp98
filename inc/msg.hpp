#ifndef MSG_HEADER
#define MSG_HEADER

#include <string>
#include <vector>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	class msg {

		// -- friends ---------------------------------------------------------

		/* parser as friend */
		friend class parser;


		public:

			// -- public types -----------------------------------------------

			/* tags type */
			typedef std::vector<std::pair<std::string, std::string> > tags;

			/* source type */
			typedef std::string source;


			/* command type */
			typedef std::string command;

			/* params type */
			typedef std::vector<std::string> params;


			/* nick type */
			typedef std::string nick;

			/* user type */
			typedef std::string user;

			/* host type */
			typedef std::string host;


			// -- public constructors -----------------------------------------

			/* default constructor */
			msg(void);

			/* copy constructor */
			msg(const msg&);

			/* destructor */
			~msg(void);


			// -- public assignment operators ---------------------------------

			/* copy assignment operator */
			msg& operator=(const msg&);


			// -- public accessors --------------------------------------------

			/* have tags */
			bool have_tags(void) const;

			/* have source */
			bool have_source(void) const;

			/* have command */
			bool have_command(void) const;

			/* have params */
			bool have_params(void) const;

			/* have nick */
			bool have_nick(void) const;

			/* have user */
			bool have_user(void) const;

			/* have host */
			bool have_host(void) const;


			/* get tags */
			const tags& get_tags(void) const;

			/* get source */
			const source& get_source(void) const;

			/* get command */
			const command& get_command(void) const;

			/* get params */
			const params& get_params(void) const;

			/* get nick */
			const nick& get_nick(void) const;

			/* get user */
			const user& get_user(void) const;

			/* get host */
			const host& get_host(void) const;

			/* get original msg */
			const std::string& get_raw(void) const;


			// -- swap --------------------------------------------------------

			/* swap */
			void swap(msg&);


		private:

			// -- private members ---------------------------------------------

			/* tags */
			tags    _tags;

			/* source */
			source  _source;

			/* command */
			command _command;

			/* params */
			params  _params;

			/* nick */
			nick    _nick;

			/* user */
			user    _user;

			/* host */
			host    _host;

			/* raw */
			std::string _raw;

	};

}

#endif
