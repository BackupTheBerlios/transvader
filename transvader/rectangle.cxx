/******************************************************************************
 *  rectangle.cxx
 *
 *  Implements rectangles.
 *
 *  Author: Michael Prinzinger, Leslie Polzer, Mark Roesel
 *  Created: 2004-??-?? / Last updated: 2004-06-26
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/

#include <iostream>

#include "rectangle.hxx"


namespace TV
{


Rectangle::Rectangle()
	:
	p(0,0),
	w(0),
	h(0)
{
	return;
}


Rectangle::~Rectangle()
{
	return;
}


Rectangle::Rectangle ( Point new_p, int new_w, int new_h )
	:
	p(new_p),
	w(new_w),
	h(new_h)
{
	return;
}


Rectangle::Rectangle ( Rectangle& rect )
	:
	p(rect.getP()),
	w(rect.getW()),
	h(rect.getH())
{
	return;
}


Rectangle::Rectangle ( Rectangle* rect )
	:
	p(rect->getP()),
	w(rect->getW()),
	h(rect->getH())
{
	return;
}


/* 
 * compares two rectangles and returs if they are equal or not 
 */
bool Rectangle::operator == ( const Rectangle& rect )
{
	return ( this->p == rect.getP()
		  && this->w == rect.getW()
		  && this->h == rect.getH() );
}


/* 
 * assigns the values of one rectangle to another 
 */
Rectangle& Rectangle::operator = ( Rectangle& rect )
{
	this->p = rect.getP();
	this->w = rect.getW();
	this->h = rect.getH();

	return ( *this );
}


bool Rectangle::intersects ( Rectangle& rect )
{
	if (*this == rect)
	   return(true);

	else if ( (this->p.y + this->h) > (rect.getP().y) )
	     return( ( (this->p.y + this->h) > (rect.getP().y) ) && ( (this->p.x + this->w) > (rect.getP().x) )
        	  || ( (this->p.y + this->h) > (rect.getP().y) ) && ( (this->p.x )          > (rect.getP().x) ) ) ;

	else if ( this->p.y < (rect.getP().y + rect.getH()) )
	     return( ( (this->p.y + this->h) > (rect.getP().y) ) && ( (this->p.x + this->w) > (rect.getP().x) )
        	  || ( (this->p.y + this->h) > (rect.getP().y) ) && ( (this->p.x )          > (rect.getP().x) ) );

	return(false);
}


bool Rectangle::intersects ( Point& point )
{
	return ( false ); //edit me!!!!!!!!!!! Na los, Michael!! ;-P
}


/* 
 * combines two rectangles to one 
 */
Rectangle& Rectangle::operator + ( Rectangle& rect)
{
	if(this->p.x < rect.getP().x)
                rect.getP().x = this->p.x;

	if(this->p.y < rect.getP().y)
                rect.getP().y = this->p.y;

        if( (this->p.y + this->h) < (rect.getP().y + rect.getH()) )
                rect.setH( (rect.getP().y + rect.getH()) - this->p.y);
        else if ( (this->p.y + this->h) > (rect.getP().y + rect.getH()) )
                rect.setH( (this->p.y + this->h)  + rect.getP().y);

        if( (this->p.x + this->w) < (rect.getP().x + rect.getW()) )
                rect.setW( (rect.getP().x + rect.getW()) - this->p.x);
        else if ( (this->p.x + this->w) > (rect.getP().x + rect.getW()) )
                rect.setW( (this->p.x + this->w) + rect.getP().x);

        return(rect);

}

Rectangle& Rectangle::operator += ( int pixel)
{
        this->h = this->h + pixel;
        this->w = this->w + pixel;
        
        return( *this );
}

Rectangle& Rectangle::operator -= ( int pixel)
{
        if ( ( (this->h - pixel) > 0) && ( (this->w - pixel) > 0) )
        {
           this->h = this->h - pixel;
           this->w = this->w - pixel;
        }

        return( *this );
}

/*
 * calculates the amount of pixels both rectangles share with each other 
 */

int Rectangle::commonPixels ( Rectangle& rect )
{
    rect = commonRectangle ( rect);
    return ( rect.getH() * rect.getW() );

}

/* 
 * returns the Rectangle two traversing Rectangles share 
 */

Rectangle& Rectangle::commonRectangle ( Rectangle& rect)
{
    int common_x = 0, common_y = 0, common_h = 0, common_w = 0;

    if( (this->p.y + this->h) < (rect.getP().y + rect.getH()) )
    {
        common_h = rect.getH()  - ( (rect.getP().y + rect.getH()) - (this->p.y + this->h) );
        common_y = rect.getP().y;
    }
    else if ( (this->p.y + this->h) > (rect.getP().y + rect.getH()) )
    {
        common_h = this->h - ( (this->p.y + this->h) - (rect.getP().y + rect.getH()) );
        common_y = this->p.y;
    }
    else
    {
        common_h = this->h;
        common_y = this->p.y;
    }

    if( (this->p.x + this->w) < (rect.getP().x + rect.getW()) )
    {
        common_w = rect.getW()  - ( (rect.getP().x + rect.getW()) - (this->p.x + this->w) );
        common_x = rect.getP().x;
    }
    else if ( (this->p.x + this->w) > (rect.getP().x + rect.getW()) )
    {
        common_w = this->w - ( (this->p.x + this->w) - (rect.getP().x + rect.getW()) );
        common_x = this->p.x;
    }
    else
    {
        common_w = this->w;
        common_x = this->p.x;
    }
    this->p.x = common_x;
    this->p.y = common_y;
    this->h = common_w;
    this->w = common_h;
    return( *this );
}

/* 
 * get coordinates of the rectangle 
 */

Point Rectangle::getP() const
{
	return ( this->p );
}

int Rectangle::getW() const
{
	return ( this->w );
}

int Rectangle::getH() const
{
	return ( this->h );
}

/* 
 * set coordinates of the rectangle 
 */

void Rectangle::setP(Point new_p)
{
	this->p = new_p;	
}

void Rectangle::setW(int new_w)
{
	this->w = new_w;
}

void Rectangle::setH(int new_h)
{
	this->h = new_h;
}


/* 
 * sets coordinates of the rectangle
 */

void Rectangle::setCoordinates (Point new_p, int new_h, int new_w)
{
        this->p = new_p;
        this->h = new_h;
        this->w = new_w;
}

std::ostream& operator << ( std::ostream& out, const Rectangle& r )
{
	out << "[" << r.p << " / " << r.w << "x" << r.h << "]";

	return out;
}

} // namespace TV
