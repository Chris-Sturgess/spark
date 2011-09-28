// sprite.h
// sprite wrapper class

#pragma once

// wraps around the graphics library and provides an implementation
// to draw, translate, and rotate images
class sprite
{
public:
	// constructs the sprite
	sprite(void);

	// frees system resources
	~sprite(void);

	// loads an image from a file
	void load( const string& file );

	// copying
	sprite( const sprite& );
	sprite& operator= (const sprite&);
private:
	// image data
	sf::Image _image;
};

