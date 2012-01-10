// celldrawer.h
// is responsible for drawing a visual representation of a cell
#pragma once

#include "pch.h"
#include "celldrawer.h"

void visuals::celldrawer::renderCell( cell& theCell, sf::RenderTarget& target )
{
	auto f =  [&target](ents::pship sh) {
		image img = resources::loadImage(sh->imageName());
		b2Vec2 pos = sh->position();
		float32 angle = sh->rotation();

		sf::Vector2f scaledVector = sf::Vector2f(pos.x, pos.y);
		scaledVector *= 7.0f/1.0f;
		sf::Sprite sprite(*img, scaledVector, sf::Vector2f(1,1), angle * 180.0f / 3.14159265f);
		sprite.SetCenter( img->GetWidth()/2.0f, img->GetHeight()/2.0f );
		target.Draw(sprite);
	};
	theCell.foreachShip(f);
}
