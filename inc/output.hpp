#ifndef OUTPUT_HEADER
#define OUTPUT_HEADER


#include <iostream>
#include <string>


// -- N A M E S P A C E  I R C ------------------------------------------------

namespace irc {

	// -- O U T P U T ---------------------------------------------------------

	template <int n>
	struct out {
		template <class A>
		static void print(const A& msg) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B>
		static void print(const A& msg, const B& msg2) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B, class C>
		static void print(const A& msg, const B& msg2, const C& msg3) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2 << msg3;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B, class C, class D>
		static void print(const A& msg, const B& msg2, const C& msg3, const D& msg4) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2 << msg3 << msg4;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B, class C, class D, class E>
		static void print(const A& msg, const B& msg2, const C& msg3, const D& msg4, const E& msg5) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2 << msg3 << msg4 << msg5;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B, class C, class D, class E, class F>
		static void print(const A& msg, const B& msg2, const C& msg3, const D& msg4, const E& msg5, const F& msg6) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2 << msg3 << msg4 << msg5 << msg6;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B, class C, class D, class E, class F, class G>
		static void print(const A& msg, const B& msg2, const C& msg3, const D& msg4, const E& msg5, const F& msg6, const G& msg7) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2 << msg3 << msg4 << msg5 << msg6 << msg7;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
		template <class A, class B, class C, class D, class E, class F, class G, class H>
		static void print(const A& msg, const B& msg2, const C& msg3, const D& msg4, const E& msg5, const F& msg6, const G& msg7, const H& msg8) {
			static char color[5] = { 27, '[', '3', '0', 'm' };
			color[3] = '0' + n;
			std::cout.write(color, 5);
			std::cout << msg << msg2 << msg3 << msg4 << msg5 << msg6 << msg7 << msg8;
			std::cout.write("\x1b[0m", 4) << std::endl;
		}
	};




}

#endif
