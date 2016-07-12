#include "WqtAnimation.h"

WqtAnimation::WqtAnimation()
{

}

WqtAnimation::WqtAnimation(SpriteInfo* infos)
	: SpriteAnimation("AlliedCharacters.png", infos, LOOPING, 1)
{

}

WqtAnimation::~WqtAnimation()
{
}
