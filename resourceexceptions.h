// resourceexceptions.h
// defines exceptions thrown by resources

#pragma once

// thrown when data is requested from a null resource
class nullresource : exception
{
public:
	nullresource() : exception( "Resource is not set to an instance of an object" ) {}
};