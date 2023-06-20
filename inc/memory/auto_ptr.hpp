#ifndef AUTO_PTR_HEADER
#define AUTO_PTR_HEADER

#include <cstddef>


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- U N I Q U E  P O I N T E R  C L A S S -------------------------------

	template <class T>
	class auto_ptr {

		public:

			// -- P U B L I C  A L I A S E S ----------------------------------

			/* value type */
			typedef T value_type;

			/* self type */
			typedef auto_ptr<value_type> self;

			/* reference type */
			typedef value_type& reference;

			/* pointer type */
			typedef value_type* mutable_pointer;

			/* const reference type */
			typedef const value_type& const_reference;

			/* const pointer type */
			typedef const value_type* const_pointer;


			// -- P U B L I C  C O N S T R U C T O R S ------------------------

			/* default constructor */
			auto_ptr(void) : _data(NULL) { }

			/* pointer constructor */
			auto_ptr(const T* data) : _data(data) { }
			
			/* pointer constructor */
			template <class U>
			auto_ptr(U* data) : _data(data) { }

			/* copy constructor */
			auto_ptr(const self& other)
			: _data(other._data) {
				// behavior like move constructor
				other._data = NULL;
			}

			/* copy assignment operator */
			self& operator=(const self& other) {
				// check pointer validity
				if (_data != NULL) {
					// deallocate memory
					delete _data; }
				// set pointer
				_data = other._data;
				// behavior like move assignment operator
				other._data = NULL;
				// return self reference
				return *this;
			}


			/* destructor */
			~auto_ptr(void) {
				// check pointer validity
				if (_data != NULL) {
					// deallocate memory
					delete _data;
				}
			}


			// -- P U B L I C  A S S I G N M E N T ----------------------------

			/* pointer assignment */
			self& assign(const_pointer data) {
				// check pointer validity
				if (_data != NULL) {
					// deallocate memory
					delete _data; }
				// set pointer
				_data = data;
				// return self reference
				return *this;
			}


			// -- P U B L I C  A S S I G N M E N T  O P E R A T O R S ---------

			/* pointer assignment operator */
			self& operator=(const_pointer data) {
				// assign pointer
				return assign(data);
			}


			// -- P U B L I C  A C C E S S O R S  O P E R A T O R S -----------

			/* dereference operator */
			reference operator*(void) {
				// return reference
				return *_data;
			}

			/* const dereference operator */
			const_reference operator*(void) const {
				// return const reference
				return *_data;
			}

			/* arrow operator */
			mutable_pointer operator->(void) {
				// return pointer
				return _data;
			}

			/* const arrow operator */
			const_pointer operator->(void) const {
				// return const pointer
				return _data;
			}


			// -- B O O L E A N  O P E R A T O R S ----------------------------

			/* boolean operator */
			operator bool(void) const {
				// return pointer validity
				return _data != NULL;
			}

			/* not operator */
			bool operator!(void) const {
				// return pointer invalidity
				return _data == NULL;
			}


			// -- P U B L I C  C O M P A R I S O N  O P E R A T O R S ---------

			/* equality operator */
			bool operator==(const self& other) const {
				// return pointer equality
				return _data == other._data;
			}

			/* inequality operator */
			bool operator!=(const self& other) const {
				// return pointer inequality
				return _data != other._data;
			}


			// -- P U B L I C  M E T H O D S ----------------------------------

			/* reset pointer */
			void reset(void) {
				// check pointer validity
				if (_data != NULL) {
					// deallocate memory
					delete _data;
					// invalidate pointer
					_data = NULL;
				}
			}


		private:

			// -- P R I V A T E  M E M B E R S --------------------------------

			/* data */
			mutable mutable_pointer _data;


			// -- N O N  C O P Y A B L E  C L A S S --------------------------


	};

}

#endif
