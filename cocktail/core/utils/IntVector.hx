package cocktail.core.utils;

#if flash
import flash.Vector;
typedef IntVector = Vector<Int>;
#else
typedef IntVector = Array<Int>;
#end