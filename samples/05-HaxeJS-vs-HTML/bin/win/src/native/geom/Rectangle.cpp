#include <hxcpp.h>

#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace native{
namespace geom{

Void Rectangle_obj::__construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{
HX_STACK_PUSH("Rectangle::new","native/geom/Rectangle.hx",21);
{
	HX_STACK_LINE(23)
	this->x = (  (((inX == null()))) ? Dynamic((int)0) : Dynamic(inX) );
	HX_STACK_LINE(24)
	this->y = (  (((inY == null()))) ? Dynamic((int)0) : Dynamic(inY) );
	HX_STACK_LINE(25)
	this->width = (  (((inWidth == null()))) ? Dynamic((int)0) : Dynamic(inWidth) );
	HX_STACK_LINE(26)
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

::native::geom::Point Rectangle_obj::set_topLeft( ::native::geom::Point p){
	HX_STACK_PUSH("Rectangle::set_topLeft","native/geom/Rectangle.hx",232);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(232)
	this->x = p->x;
	HX_STACK_LINE(232)
	this->y = p->y;
	HX_STACK_LINE(232)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_topLeft,return )

::native::geom::Point Rectangle_obj::get_topLeft( ){
	HX_STACK_PUSH("Rectangle::get_topLeft","native/geom/Rectangle.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_LINE(231)
	return ::native::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_topLeft,return )

Float Rectangle_obj::set_top( Float t){
	HX_STACK_PUSH("Rectangle::set_top","native/geom/Rectangle.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(230)
	hx::SubEq(this->height,(t - this->y));
	HX_STACK_LINE(230)
	this->y = t;
	HX_STACK_LINE(230)
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_top,return )

Float Rectangle_obj::get_top( ){
	HX_STACK_PUSH("Rectangle::get_top","native/geom/Rectangle.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_LINE(229)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_top,return )

::native::geom::Point Rectangle_obj::set_size( ::native::geom::Point p){
	HX_STACK_PUSH("Rectangle::set_size","native/geom/Rectangle.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(228)
	this->width = p->x;
	HX_STACK_LINE(228)
	this->height = p->y;
	HX_STACK_LINE(228)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_size,return )

::native::geom::Point Rectangle_obj::get_size( ){
	HX_STACK_PUSH("Rectangle::get_size","native/geom/Rectangle.hx",227);
	HX_STACK_THIS(this);
	HX_STACK_LINE(227)
	return ::native::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_size,return )

Float Rectangle_obj::set_right( Float r){
	HX_STACK_PUSH("Rectangle::set_right","native/geom/Rectangle.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_ARG(r,"r");
	HX_STACK_LINE(226)
	this->width = (r - this->x);
	HX_STACK_LINE(226)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_right,return )

Float Rectangle_obj::get_right( ){
	HX_STACK_PUSH("Rectangle::get_right","native/geom/Rectangle.hx",225);
	HX_STACK_THIS(this);
	HX_STACK_LINE(225)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_right,return )

Float Rectangle_obj::set_left( Float l){
	HX_STACK_PUSH("Rectangle::set_left","native/geom/Rectangle.hx",224);
	HX_STACK_THIS(this);
	HX_STACK_ARG(l,"l");
	HX_STACK_LINE(224)
	hx::SubEq(this->width,(l - this->x));
	HX_STACK_LINE(224)
	this->x = l;
	HX_STACK_LINE(224)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_left,return )

Float Rectangle_obj::get_left( ){
	HX_STACK_PUSH("Rectangle::get_left","native/geom/Rectangle.hx",223);
	HX_STACK_THIS(this);
	HX_STACK_LINE(223)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_left,return )

::native::geom::Point Rectangle_obj::set_bottomRight( ::native::geom::Point p){
	HX_STACK_PUSH("Rectangle::set_bottomRight","native/geom/Rectangle.hx",222);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(222)
	this->width = (p->x - this->x);
	HX_STACK_LINE(222)
	this->height = (p->y - this->y);
	HX_STACK_LINE(222)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottomRight,return )

::native::geom::Point Rectangle_obj::get_bottomRight( ){
	HX_STACK_PUSH("Rectangle::get_bottomRight","native/geom/Rectangle.hx",221);
	HX_STACK_THIS(this);
	HX_STACK_LINE(221)
	return ::native::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottomRight,return )

Float Rectangle_obj::set_bottom( Float b){
	HX_STACK_PUSH("Rectangle::set_bottom","native/geom/Rectangle.hx",220);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(220)
	this->height = (b - this->y);
	HX_STACK_LINE(220)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottom,return )

Float Rectangle_obj::get_bottom( ){
	HX_STACK_PUSH("Rectangle::get_bottom","native/geom/Rectangle.hx",219);
	HX_STACK_THIS(this);
	HX_STACK_LINE(219)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottom,return )

::native::geom::Rectangle Rectangle_obj::_union( ::native::geom::Rectangle toUnion){
	HX_STACK_PUSH("Rectangle::union","native/geom/Rectangle.hx",201);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toUnion,"toUnion");
	HX_STACK_LINE(203)
	Float x0 = (  (((this->x > toUnion->x))) ? Float(toUnion->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(204)
	Float x1 = (  (((this->get_right() < toUnion->get_right()))) ? Float(toUnion->get_right()) : Float(this->get_right()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(205)
	Float y0 = (  (((this->y > toUnion->y))) ? Float(toUnion->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(206)
	Float y1 = (  (((this->get_bottom() < toUnion->get_bottom()))) ? Float(toUnion->get_bottom()) : Float(this->get_bottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(207)
	return ::native::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

::native::geom::Rectangle Rectangle_obj::transform( ::native::geom::Matrix m){
	HX_STACK_PUSH("Rectangle::transform","native/geom/Rectangle.hx",168);
	HX_STACK_THIS(this);
	HX_STACK_ARG(m,"m");
	HX_STACK_LINE(170)
	Float tx0 = ((m->a * this->x) + (m->c * this->y));		HX_STACK_VAR(tx0,"tx0");
	HX_STACK_LINE(171)
	Float tx1 = tx0;		HX_STACK_VAR(tx1,"tx1");
	HX_STACK_LINE(172)
	Float ty0 = ((m->b * this->x) + (m->d * this->y));		HX_STACK_VAR(ty0,"ty0");
	HX_STACK_LINE(173)
	Float ty1 = tx0;		HX_STACK_VAR(ty1,"ty1");
	HX_STACK_LINE(175)
	Float tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));		HX_STACK_VAR(tx,"tx");
	HX_STACK_LINE(176)
	Float ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));		HX_STACK_VAR(ty,"ty");
	HX_STACK_LINE(177)
	if (((tx < tx0))){
		HX_STACK_LINE(177)
		tx0 = tx;
	}
	HX_STACK_LINE(178)
	if (((ty < ty0))){
		HX_STACK_LINE(178)
		ty0 = ty;
	}
	HX_STACK_LINE(179)
	if (((tx > tx1))){
		HX_STACK_LINE(179)
		tx1 = tx;
	}
	HX_STACK_LINE(180)
	if (((ty > ty1))){
		HX_STACK_LINE(180)
		ty1 = ty;
	}
	HX_STACK_LINE(182)
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(183)
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(184)
	if (((tx < tx0))){
		HX_STACK_LINE(184)
		tx0 = tx;
	}
	HX_STACK_LINE(185)
	if (((ty < ty0))){
		HX_STACK_LINE(185)
		ty0 = ty;
	}
	HX_STACK_LINE(186)
	if (((tx > tx1))){
		HX_STACK_LINE(186)
		tx1 = tx;
	}
	HX_STACK_LINE(187)
	if (((ty > ty1))){
		HX_STACK_LINE(187)
		ty1 = ty;
	}
	HX_STACK_LINE(189)
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(190)
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(191)
	if (((tx < tx0))){
		HX_STACK_LINE(191)
		tx0 = tx;
	}
	HX_STACK_LINE(192)
	if (((ty < ty0))){
		HX_STACK_LINE(192)
		ty0 = ty;
	}
	HX_STACK_LINE(193)
	if (((tx > tx1))){
		HX_STACK_LINE(193)
		tx1 = tx;
	}
	HX_STACK_LINE(194)
	if (((ty > ty1))){
		HX_STACK_LINE(194)
		ty1 = ty;
	}
	HX_STACK_LINE(196)
	return ::native::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

Void Rectangle_obj::setEmpty( ){
{
		HX_STACK_PUSH("Rectangle::setEmpty","native/geom/Rectangle.hx",161);
		HX_STACK_THIS(this);
		HX_STACK_LINE(161)
		this->x = this->y = this->width = this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

Void Rectangle_obj::offsetPoint( ::native::geom::Point point){
{
		HX_STACK_PUSH("Rectangle::offsetPoint","native/geom/Rectangle.hx",153);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(155)
		hx::AddEq(this->x,point->x);
		HX_STACK_LINE(156)
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::offset( Float dx,Float dy){
{
		HX_STACK_PUSH("Rectangle::offset","native/geom/Rectangle.hx",145);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dx,"dx");
		HX_STACK_ARG(dy,"dy");
		HX_STACK_LINE(147)
		hx::AddEq(this->x,dx);
		HX_STACK_LINE(148)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

bool Rectangle_obj::isEmpty( ){
	HX_STACK_PUSH("Rectangle::isEmpty","native/geom/Rectangle.hx",138);
	HX_STACK_THIS(this);
	HX_STACK_LINE(138)
	return (bool((this->width == (int)0)) && bool((this->height == (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

bool Rectangle_obj::intersects( ::native::geom::Rectangle toIntersect){
	HX_STACK_PUSH("Rectangle::intersects","native/geom/Rectangle.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toIntersect,"toIntersect");
	HX_STACK_LINE(126)
	Float x0 = (  (((this->x < toIntersect->x))) ? Float(toIntersect->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(127)
	Float x1 = (  (((this->get_right() > toIntersect->get_right()))) ? Float(toIntersect->get_right()) : Float(this->get_right()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(128)
	if (((x1 <= x0))){
		HX_STACK_LINE(129)
		return false;
	}
	HX_STACK_LINE(131)
	Float y0 = (  (((this->y < toIntersect->y))) ? Float(toIntersect->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(132)
	Float y1 = (  (((this->get_bottom() > toIntersect->get_bottom()))) ? Float(toIntersect->get_bottom()) : Float(this->get_bottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(133)
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

::native::geom::Rectangle Rectangle_obj::intersection( ::native::geom::Rectangle toIntersect){
	HX_STACK_PUSH("Rectangle::intersection","native/geom/Rectangle.hx",108);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toIntersect,"toIntersect");
	HX_STACK_LINE(110)
	Float x0 = (  (((this->x < toIntersect->x))) ? Float(toIntersect->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(111)
	Float x1 = (  (((this->get_right() > toIntersect->get_right()))) ? Float(toIntersect->get_right()) : Float(this->get_right()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(112)
	if (((x1 <= x0))){
		HX_STACK_LINE(113)
		return ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(115)
	Float y0 = (  (((this->y < toIntersect->y))) ? Float(toIntersect->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(116)
	Float y1 = (  (((this->get_bottom() > toIntersect->get_bottom()))) ? Float(toIntersect->get_bottom()) : Float(this->get_bottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(117)
	if (((y1 <= y0))){
		HX_STACK_LINE(118)
		return ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(120)
	return ::native::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

Void Rectangle_obj::inflatePoint( ::native::geom::Point point){
{
		HX_STACK_PUSH("Rectangle::inflatePoint","native/geom/Rectangle.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(101)
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

Void Rectangle_obj::inflate( Float dx,Float dy){
{
		HX_STACK_PUSH("Rectangle::inflate","native/geom/Rectangle.hx",93);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dx,"dx");
		HX_STACK_ARG(dy,"dy");
		HX_STACK_LINE(95)
		hx::SubEq(this->x,dx);
		HX_STACK_LINE(95)
		hx::AddEq(this->width,(dx * (int)2));
		HX_STACK_LINE(96)
		hx::SubEq(this->y,dy);
		HX_STACK_LINE(96)
		hx::AddEq(this->height,(dy * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::extendBounds( ::native::geom::Rectangle r){
{
		HX_STACK_PUSH("Rectangle::extendBounds","native/geom/Rectangle.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_ARG(r,"r");
		HX_STACK_LINE(68)
		Float dx = (this->x - r->x);		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(69)
		if (((dx > (int)0))){
			HX_STACK_LINE(71)
			hx::SubEq(this->x,dx);
			HX_STACK_LINE(72)
			hx::AddEq(this->width,dx);
		}
		HX_STACK_LINE(76)
		Float dy = (this->y - r->y);		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(77)
		if (((dy > (int)0))){
			HX_STACK_LINE(79)
			hx::SubEq(this->y,dy);
			HX_STACK_LINE(80)
			hx::AddEq(this->height,dy);
		}
		HX_STACK_LINE(84)
		if (((r->get_right() > this->get_right()))){
			HX_STACK_LINE(85)
			this->set_right(r->get_right());
		}
		HX_STACK_LINE(87)
		if (((r->get_bottom() > this->get_bottom()))){
			HX_STACK_LINE(88)
			this->set_bottom(r->get_bottom());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))

bool Rectangle_obj::equals( ::native::geom::Rectangle toCompare){
	HX_STACK_PUSH("Rectangle::equals","native/geom/Rectangle.hx",59);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toCompare,"toCompare");
	HX_STACK_LINE(59)
	return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->width == toCompare->width)))) && bool((this->height == toCompare->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

bool Rectangle_obj::containsRect( ::native::geom::Rectangle rect){
	HX_STACK_PUSH("Rectangle::containsRect","native/geom/Rectangle.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(52)
	return (bool(this->contains(rect->x,rect->y)) && bool(this->containsPoint(rect->get_bottomRight())));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

bool Rectangle_obj::containsPoint( ::native::geom::Point point){
	HX_STACK_PUSH("Rectangle::containsPoint","native/geom/Rectangle.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(45)
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::contains( Float inX,Float inY){
	HX_STACK_PUSH("Rectangle::contains","native/geom/Rectangle.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inX,"inX");
	HX_STACK_ARG(inY,"inY");
	HX_STACK_LINE(38)
	return (bool((bool((bool((inX >= this->x)) && bool((inY >= this->y)))) && bool((inX < this->get_right())))) && bool((inY < this->get_bottom())));
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

::native::geom::Rectangle Rectangle_obj::clone( ){
	HX_STACK_PUSH("Rectangle::clone","native/geom/Rectangle.hx",31);
	HX_STACK_THIS(this);
	HX_STACK_LINE(31)
	return ::native::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
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
		if (HX_FIELD_EQ(inName,"top") ) { return inCallProp ? get_top() : top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return inCallProp ? get_size() : size; }
		if (HX_FIELD_EQ(inName,"left") ) { return inCallProp ? get_left() : left; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? get_right() : right; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return inCallProp ? get_bottom() : bottom; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"topLeft") ) { return inCallProp ? get_topLeft() : topLeft; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"setEmpty") ) { return setEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"intersects") ) { return intersects_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_topLeft") ) { return set_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_topLeft") ) { return get_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"offsetPoint") ) { return offsetPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return inCallProp ? get_bottomRight() : bottomRight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"intersection") ) { return intersection_dyn(); }
		if (HX_FIELD_EQ(inName,"inflatePoint") ) { return inflatePoint_dyn(); }
		if (HX_FIELD_EQ(inName,"extendBounds") ) { return extendBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"containsRect") ) { return containsRect_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containsPoint") ) { return containsPoint_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_bottomRight") ) { return set_bottomRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottomRight") ) { return get_bottomRight_dyn(); }
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
		if (HX_FIELD_EQ(inName,"top") ) { if (inCallProp) return set_top(inValue);top=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp) return set_size(inValue);size=inValue.Cast< ::native::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"left") ) { if (inCallProp) return set_left(inValue);left=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { if (inCallProp) return set_right(inValue);right=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { if (inCallProp) return set_bottom(inValue);bottom=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { if (inCallProp) return set_topLeft(inValue);topLeft=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { if (inCallProp) return set_bottomRight(inValue);bottomRight=inValue.Cast< ::native::geom::Point >(); return inValue; }
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
	HX_CSTRING("set_topLeft"),
	HX_CSTRING("get_topLeft"),
	HX_CSTRING("set_top"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_size"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_right"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_left"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_bottomRight"),
	HX_CSTRING("get_bottomRight"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("get_bottom"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.geom.Rectangle"), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace native
} // end namespace geom
