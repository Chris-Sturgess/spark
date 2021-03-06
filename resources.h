// resources.h
// manages all in-game resources loaded from the hard disk
#include "resourceexceptions.h"

#pragma once

// namespace which manages all in-game resources
namespace resources
{
	// holds a resource and manages how many times that resource has been initialized
	template<typename T>
	class resource
	{
	public:
		// creates a new resource from the raw type
		resource( T* r ) : _resource(r), _counter(new int) { *_counter = 1; }
		
		// creates an uninitialized resource
		resource() : _resource(nullptr), _counter(nullptr) {}

		// destruction
		~resource( ) {
			destroy();
		}

		// checks if this resource is null
		bool null() const { return _resource == nullptr; }

		// gets the number of instances
		int instances() const { 
			throwIfNull();
			return *_counter; 
		}

		// gets the internal object
		T* get() const { throwIfNull(); return _resource; }
		T& operator*() { throwIfNull(); return *_resource; }
		T* operator->() { throwIfNull(); return _resource; }

		// copying
		resource( const resource<T>& rhs ) : _resource(rhs._resource), _counter(rhs._counter) { if( !null() ) (*_counter)++; }
		resource<T>& operator=( const resource<T>& rhs ) { 
			// check for self assignment
			if( this == &rhs ) return *this;

			// destroy us first
			destroy();

			// assign
			_counter = rhs._counter;
			_resource = rhs._resource;

			// increment
			if( !null() )
				(*_counter)++;

			return *this;
		}

	private:
		// throws a null resource exception if the resource is null
		void throwIfNull() const
		{
			if( null() ) throw nullresource();
		}

		// destroys this reference
		void destroy( ) {
			if( null() ) return;

			// decrease counter
			(*_counter)--;

			// check for total destruction
			if( *_counter == 0 ) {
				delete _counter;
				delete _resource;
				_counter = 0; _resource = 0;
			}
		}

		// resource instance
		T* _resource;

		// resource count
		int* _counter;
	};

	// loads an image from a file
	resource<sf::Image> loadImage( const string& file );

	// cleans the resource banks
	void clean( );
}

// image resource
typedef resources::resource<sf::Image> image;
