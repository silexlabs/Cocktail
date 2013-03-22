#include <hxcpp.h>

#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace neash{
namespace geom{

Void Rectangle_obj::__construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{
HX_STACK_PUSH("Rectangle::new","neash/geom/Rectangle.hx",44);
{
	HX_STACK_LINE(45)
	this->x = (  (((inX == null()))) ? Dynamic((int)0) : Dynamic(inX) );
	HX_STACK_LINE(46)
	this->y = (  (((inY == null()))) ? Dynamic((int)0) : Dynamic(inY) );
	HX_STACK_LINE(47)
	this->width = (  (((inWidth == null()))) ? Dynamic((int)0) : Dynamic(inWidth) );
	HX_STACK_LINE(48)
	this->height = (  (((inHeight == null()))) ? Dynamic((int)0) : Dynamic(inHeight) );
}
;
	return null();
}

Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hx::ObjectPtr< Rectangle_obj > Rectangle_obj::__new(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inX,inY,inWidth,inHeight);
	return result;}

Dynamic Rectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::neash::geom::Point Rectangle_obj::nmeSetTopLeft( ::neash::geom::Point p){
	HX_STACK_PUSH("Rectangle::nmeSetTopLeft","neash/geom/Rectangle.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(231)
	this->x = p->x;
	HX_STACK_LINE(231)
	this->y = p->y;
	HX_STACK_LINE(231)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetTopLeft,return )

::neash::geom::Point Rectangle_obj::nmeGetTopLeft( ){
	HX_STACK_PUSH("Rectangle::nmeGetTopLeft","neash/geom/Rectangle.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_LINE(230)
	return ::neash::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetTopLeft,return )

Float Rectangle_obj::nmeSetTop( Float t){
	HX_STACK_PUSH("Rectangle::nmeSetTop","neash/geom/Rectangle.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(229)
	hx::SubEq(this->height,(t - this->y));
	HX_STACK_LINE(229)
	this->y = t;
	HX_STACK_LINE(229)
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetTop,return )

Float Rectangle_obj::nmeGetTop( ){
	HX_STACK_PUSH("Rectangle::nmeGetTop","neash/geom/Rectangle.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_LINE(228)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetTop,return )

::neash::geom::Point Rectangle_obj::nmeSetSize( ::neash::geom::Point p){
	HX_STACK_PUSH("Rectangle::nmeSetSize","neash/geom/Rectangle.hx",227);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(227)
	this->width = p->x;
	HX_STACK_LINE(227)
	this->height = p->y;
	HX_STACK_LINE(227)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetSize,return )

::neash::geom::Point Rectangle_obj::nmeGetSize( ){
	HX_STACK_PUSH("Rectangle::nmeGetSize","neash/geom/Rectangle.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_LINE(226)
	return ::neash::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetSize,return )

Float Rectangle_obj::nmeSetRight( Float r){
	HX_STACK_PUSH("Rectangle::nmeSetRight","neash/geom/Rectangle.hx",225);
	HX_STACK_THIS(this);
	HX_STACK_ARG(r,"r");
	HX_STACK_LINE(225)
	this->width = (r - this->x);
	HX_STACK_LINE(225)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetRight,return )

Float Rectangle_obj::nmeGetRight( ){
	HX_STACK_PUSH("Rectangle::nmeGetRight","neash/geom/Rectangle.hx",224);
	HX_STACK_THIS(this);
	HX_STACK_LINE(224)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetRight,return )

Float Rectangle_obj::nmeSetLeft( Float l){
	HX_STACK_PUSH("Rectangle::nmeSetLeft","neash/geom/Rectangle.hx",223);
	HX_STACK_THIS(this);
	HX_STACK_ARG(l,"l");
	HX_STACK_LINE(223)
	hx::SubEq(this->width,(l - this->x));
	HX_STACK_LINE(223)
	this->x = l;
	HX_STACK_LINE(223)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetLeft,return )

Float Rectangle_obj::nmeGetLeft( ){
	HX_STACK_PUSH("Rectangle::nmeGetLeft","neash/geom/Rectangle.hx",222);
	HX_STACK_THIS(this);
	HX_STACK_LINE(222)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetLeft,return )

::neash::geom::Point Rectangle_obj::nmeSetBottomRight( ::neash::geom::Point p){
	HX_STACK_PUSH("Rectangle::nmeSetBottomRight","neash/geom/Rectangle.hx",221);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(221)
	this->width = (p->x - this->x);
	HX_STACK_LINE(221)
	this->height = (p->y - this->y);
	HX_STACK_LINE(221)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetBottomRight,return )

::neash::geom::Point Rectangle_obj::nmeGetBottomRight( ){
	HX_STACK_PUSH("Rectangle::nmeGetBottomRight","neash/geom/Rectangle.hx",220);
	HX_STACK_THIS(this);
	HX_STACK_LINE(220)
	return ::neash::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetBottomRight,return )

Float Rectangle_obj::nmeSetBottom( Float b){
	HX_STACK_PUSH("Rectangle::nmeSetBottom","neash/geom/Rectangle.hx",219);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(219)
	this->height = (b - this->y);
	HX_STACK_LINE(219)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,nmeSetBottom,return )

Float Rectangle_obj::nmeGetBottom( ){
	HX_STACK_PUSH("Rectangle::nmeGetBottom","neash/geom/Rectangle.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_LINE(218)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,nmeGetBottom,return )

::neash::geom::Rectangle Rectangle_obj::_union( ::neash::geom::Rectangle toUnion){
	HX_STACK_PUSH("Rectangle::union","neash/geom/Rectangle.hx",204);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toUnion,"toUnion");
	HX_STACK_LINE(205)
	Float x0 = (  (((this->x > toUnion->x))) ? Float(toUnion->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(206)
	Float x1 = (  (((this->nmeGetRight() < toUnion->nmeGetRight()))) ? Float(toUnion->nmeGetRight()) : Float(this->nmeGetRight()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(207)
	Float y0 = (  (((this->y > toUnion->y))) ? Float(toUnion->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(208)
	Float y1 = (  (((this->nmeGetBottom() < toUnion->nmeGetBottom()))) ? Float(toUnion->nmeGetBottom()) : Float(this->nmeGetBottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(209)
	return ::neash::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

::neash::geom::Rectangle Rectangle_obj::transform( ::neash::geom::Matrix m){
	HX_STACK_PUSH("Rectangle::transform","neash/geom/Rectangle.hx",172);
	HX_STACK_THIS(this);
	HX_STACK_ARG(m,"m");
	HX_STACK_LINE(173)
	Float tx0 = ((m->a * this->x) + (m->c * this->y));		HX_STACK_VAR(tx0,"tx0");
	HX_STACK_LINE(174)
	Float tx1 = tx0;		HX_STACK_VAR(tx1,"tx1");
	HX_STACK_LINE(175)
	Float ty0 = ((m->b * this->x) + (m->d * this->y));		HX_STACK_VAR(ty0,"ty0");
	HX_STACK_LINE(176)
	Float ty1 = tx0;		HX_STACK_VAR(ty1,"ty1");
	HX_STACK_LINE(178)
	Float tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));		HX_STACK_VAR(tx,"tx");
	HX_STACK_LINE(179)
	Float ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));		HX_STACK_VAR(ty,"ty");
	HX_STACK_LINE(180)
	if (((tx < tx0))){
		HX_STACK_LINE(180)
		tx0 = tx;
	}
	HX_STACK_LINE(181)
	if (((ty < ty0))){
		HX_STACK_LINE(181)
		ty0 = ty;
	}
	HX_STACK_LINE(182)
	if (((tx > tx1))){
		HX_STACK_LINE(182)
		tx1 = tx;
	}
	HX_STACK_LINE(183)
	if (((ty > ty1))){
		HX_STACK_LINE(183)
		ty1 = ty;
	}
	HX_STACK_LINE(185)
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(186)
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(187)
	if (((tx < tx0))){
		HX_STACK_LINE(187)
		tx0 = tx;
	}
	HX_STACK_LINE(188)
	if (((ty < ty0))){
		HX_STACK_LINE(188)
		ty0 = ty;
	}
	HX_STACK_LINE(189)
	if (((tx > tx1))){
		HX_STACK_LINE(189)
		tx1 = tx;
	}
	HX_STACK_LINE(190)
	if (((ty > ty1))){
		HX_STACK_LINE(190)
		ty1 = ty;
	}
	HX_STACK_LINE(192)
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(193)
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(194)
	if (((tx < tx0))){
		HX_STACK_LINE(194)
		tx0 = tx;
	}
	HX_STACK_LINE(195)
	if (((ty < ty0))){
		HX_STACK_LINE(195)
		ty0 = ty;
	}
	HX_STACK_LINE(196)
	if (((tx > tx1))){
		HX_STACK_LINE(196)
		tx1 = tx;
	}
	HX_STACK_LINE(197)
	if (((ty > ty1))){
		HX_STACK_LINE(197)
		ty1 = ty;
	}
	HX_STACK_LINE(199)
	return ::neash::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

Void Rectangle_obj::setEmpty( ){
{
		HX_STACK_PUSH("Rectangle::setEmpty","neash/geom/Rectangle.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_LINE(166)
		this->x = this->y = this->width = this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

Void Rectangle_obj::offsetPoint( ::neash::geom::Point point){
{
		HX_STACK_PUSH("Rectangle::offsetPoint","neash/geom/Rectangle.hx",159);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(160)
		hx::AddEq(this->x,point->x);
		HX_STACK_LINE(161)
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::offset( Float dx,Float dy){
{
		HX_STACK_PUSH("Rectangle::offset","neash/geom/Rectangle.hx",152);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dx,"dx");
		HX_STACK_ARG(dy,"dy");
		HX_STACK_LINE(153)
		hx::AddEq(this->x,dx);
		HX_STACK_LINE(154)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

bool Rectangle_obj::isEmpty( ){
	HX_STACK_PUSH("Rectangle::isEmpty","neash/geom/Rectangle.hx",146);
	HX_STACK_THIS(this);
	HX_STACK_LINE(146)
	return (bool((this->width == (int)0)) && bool((this->height == (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

bool Rectangle_obj::intersects( ::neash::geom::Rectangle toIntersect){
	HX_STACK_PUSH("Rectangle::intersects","neash/geom/Rectangle.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toIntersect,"toIntersect");
	HX_STACK_LINE(134)
	Float x0 = (  (((this->x < toIntersect->x))) ? Float(toIntersect->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(135)
	Float x1 = (  (((this->nmeGetRight() > toIntersect->nmeGetRight()))) ? Float(toIntersect->nmeGetRight()) : Float(this->nmeGetRight()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(136)
	if (((x1 <= x0))){
		HX_STACK_LINE(137)
		return false;
	}
	HX_STACK_LINE(139)
	Float y0 = (  (((this->y < toIntersect->y))) ? Float(toIntersect->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(140)
	Float y1 = (  (((this->nmeGetBottom() > toIntersect->nmeGetBottom()))) ? Float(toIntersect->nmeGetBottom()) : Float(this->nmeGetBottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(141)
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

::neash::geom::Rectangle Rectangle_obj::intersection( ::neash::geom::Rectangle toIntersect){
	HX_STACK_PUSH("Rectangle::intersection","neash/geom/Rectangle.hx",117);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toIntersect,"toIntersect");
	HX_STACK_LINE(118)
	Float x0 = (  (((this->x < toIntersect->x))) ? Float(toIntersect->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(119)
	Float x1 = (  (((this->nmeGetRight() > toIntersect->nmeGetRight()))) ? Float(toIntersect->nmeGetRight()) : Float(this->nmeGetRight()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(120)
	if (((x1 <= x0))){
		HX_STACK_LINE(121)
		return ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(123)
	Float y0 = (  (((this->y < toIntersect->y))) ? Float(toIntersect->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(124)
	Float y1 = (  (((this->nmeGetBottom() > toIntersect->nmeGetBottom()))) ? Float(toIntersect->nmeGetBottom()) : Float(this->nmeGetBottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(125)
	if (((y1 <= y0))){
		HX_STACK_LINE(126)
		return ::neash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(128)
	return ::neash::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

Void Rectangle_obj::inflatePoint( ::neash::geom::Point point){
{
		HX_STACK_PUSH("Rectangle::inflatePoint","neash/geom/Rectangle.hx",111);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(111)
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

Void Rectangle_obj::inflate( Float dx,Float dy){
{
		HX_STACK_PUSH("Rectangle::inflate","neash/geom/Rectangle.hx",104);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dx,"dx");
		HX_STACK_ARG(dy,"dy");
		HX_STACK_LINE(105)
		hx::SubEq(this->x,dx);
		HX_STACK_LINE(105)
		hx::AddEq(this->width,(dx * (int)2));
		HX_STACK_LINE(106)
		hx::SubEq(this->y,dy);
		HX_STACK_LINE(106)
		hx::AddEq(this->height,(dy * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::extendBounds( ::neash::geom::Rectangle r){
{
		HX_STACK_PUSH("Rectangle::extendBounds","neash/geom/Rectangle.hx",83);
		HX_STACK_THIS(this);
		HX_STACK_ARG(r,"r");
		HX_STACK_LINE(84)
		Float dx = (this->x - r->x);		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(85)
		if (((dx > (int)0))){
			HX_STACK_LINE(87)
			hx::SubEq(this->x,dx);
			HX_STACK_LINE(88)
			hx::AddEq(this->width,dx);
		}
		HX_STACK_LINE(90)
		Float dy = (this->y - r->y);		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(91)
		if (((dy > (int)0))){
			HX_STACK_LINE(93)
			hx::SubEq(this->y,dy);
			HX_STACK_LINE(94)
			hx::AddEq(this->height,dy);
		}
		HX_STACK_LINE(96)
		if (((r->nmeGetRight() > this->nmeGetRight()))){
			HX_STACK_LINE(97)
			this->nmeSetRight(r->nmeGetRight());
		}
		HX_STACK_LINE(98)
		if (((r->nmeGetBottom() > this->nmeGetBottom()))){
			HX_STACK_LINE(99)
			this->nmeSetBottom(r->nmeGetBottom());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))

bool Rectangle_obj::equals( ::neash::geom::Rectangle toCompare){
	HX_STACK_PUSH("Rectangle::equals","neash/geom/Rectangle.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toCompare,"toCompare");
	HX_STACK_LINE(77)
	return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->width == toCompare->width)))) && bool((this->height == toCompare->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

bool Rectangle_obj::containsRect( ::neash::geom::Rectangle rect){
	HX_STACK_PUSH("Rectangle::containsRect","neash/geom/Rectangle.hx",71);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(71)
	return (bool(this->contains(rect->x,rect->y)) && bool(this->containsPoint(rect->nmeGetBottomRight())));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

bool Rectangle_obj::containsPoint( ::neash::geom::Point point){
	HX_STACK_PUSH("Rectangle::containsPoint","neash/geom/Rectangle.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(65)
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::contains( Float inX,Float inY){
	HX_STACK_PUSH("Rectangle::contains","neash/geom/Rectangle.hx",59);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inX,"inX");
	HX_STACK_ARG(inY,"inY");
	HX_STACK_LINE(59)
	return (bool((bool((bool((inX >= this->x)) && bool((inY >= this->y)))) && bool((inX < this->nmeGetRight())))) && bool((inY < this->nmeGetBottom())));
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

::neash::geom::Rectangle Rectangle_obj::clone( ){
	HX_STACK_PUSH("Rectangle::clone","neash/geom/Rectangle.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_LINE(53)
	return ::neash::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,clone,return )


Rectangle_obj::Rectangle_obj()
{
}

void Rectangle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rectangle);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(topLeft,"topLeft");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(bottomRight,"bottomRight");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_END_CLASS();
}

void Rectangle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(topLeft,"topLeft");
	HX_VISIT_MEMBER_NAME(top,"top");
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(right,"right");
	HX_VISIT_MEMBER_NAME(left,"left");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(bottomRight,"bottomRight");
	HX_VISIT_MEMBER_NAME(bottom,"bottom");
}

Dynamic Rectangle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return inCallProp ? nmeGetTop() : top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return inCallProp ? nmeGetTopLeft() : size; }
		if (HX_FIELD_EQ(inName,"left") ) { return inCallProp ? nmeGetLeft() : left; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? nmeGetRight() : right; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return inCallProp ? nmeGetBottom() : bottom; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"topLeft") ) { return inCallProp ? nmeGetTopLeft() : topLeft; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setEmpty") ) { return setEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeSetTop") ) { return nmeSetTop_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTop") ) { return nmeGetTop_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeSetSize") ) { return nmeSetSize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetSize") ) { return nmeGetSize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetLeft") ) { return nmeSetLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetLeft") ) { return nmeGetLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"intersects") ) { return intersects_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeSetRight") ) { return nmeSetRight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetRight") ) { return nmeGetRight_dyn(); }
		if (HX_FIELD_EQ(inName,"offsetPoint") ) { return offsetPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return inCallProp ? nmeGetBottomRight() : bottomRight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeSetBottom") ) { return nmeSetBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBottom") ) { return nmeGetBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"intersection") ) { return intersection_dyn(); }
		if (HX_FIELD_EQ(inName,"inflatePoint") ) { return inflatePoint_dyn(); }
		if (HX_FIELD_EQ(inName,"extendBounds") ) { return extendBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"containsRect") ) { return containsRect_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeSetTopLeft") ) { return nmeSetTopLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTopLeft") ) { return nmeGetTopLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"containsPoint") ) { return containsPoint_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeSetBottomRight") ) { return nmeSetBottomRight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetBottomRight") ) { return nmeGetBottomRight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { if (inCallProp) return nmeSetTop(inValue);top=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp) return nmeSetTopLeft(inValue);size=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"left") ) { if (inCallProp) return nmeSetLeft(inValue);left=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { if (inCallProp) return nmeSetRight(inValue);right=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { if (inCallProp) return nmeSetBottom(inValue);bottom=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { if (inCallProp) return nmeSetTopLeft(inValue);topLeft=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { if (inCallProp) return nmeSetBottomRight(inValue);bottomRight=inValue.Cast< ::neash::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rectangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("topLeft"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("bottomRight"));
	outFields->push(HX_CSTRING("bottom"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeSetTopLeft"),
	HX_CSTRING("nmeGetTopLeft"),
	HX_CSTRING("nmeSetTop"),
	HX_CSTRING("nmeGetTop"),
	HX_CSTRING("nmeSetSize"),
	HX_CSTRING("nmeGetSize"),
	HX_CSTRING("nmeSetRight"),
	HX_CSTRING("nmeGetRight"),
	HX_CSTRING("nmeSetLeft"),
	HX_CSTRING("nmeGetLeft"),
	HX_CSTRING("nmeSetBottomRight"),
	HX_CSTRING("nmeGetBottomRight"),
	HX_CSTRING("nmeSetBottom"),
	HX_CSTRING("nmeGetBottom"),
	HX_CSTRING("union"),
	HX_CSTRING("transform"),
	HX_CSTRING("setEmpty"),
	HX_CSTRING("offsetPoint"),
	HX_CSTRING("offset"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("intersects"),
	HX_CSTRING("intersection"),
	HX_CSTRING("inflatePoint"),
	HX_CSTRING("inflate"),
	HX_CSTRING("extendBounds"),
	HX_CSTRING("equals"),
	HX_CSTRING("containsRect"),
	HX_CSTRING("containsPoint"),
	HX_CSTRING("contains"),
	HX_CSTRING("clone"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("width"),
	HX_CSTRING("topLeft"),
	HX_CSTRING("top"),
	HX_CSTRING("size"),
	HX_CSTRING("right"),
	HX_CSTRING("left"),
	HX_CSTRING("height"),
	HX_CSTRING("bottomRight"),
	HX_CSTRING("bottom"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Rectangle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Rectangle_obj::__mClass,"__mClass");
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.Rectangle"), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom
